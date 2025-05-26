// based on http://www.stroustrup.com/dc.c
// by Bjarne Stroustrup
// The desk calculator
// pp 107-117, sec 6.1, A Desk calculator
// No guarantees offered. Constructive comments to bs@research.att.com

/*
 Aufgaben:
 
 - Grammatik in EBNF bringen (z.B. wie PL/0  https://en.wikipedia.org/wiki/PL/0 )
 - Zusammenhang zwischen Grammatik und den Funktionen herausfinden
 - neue Funktion einbauen z.B. 'A' für bitwise AND oder 'V' für bitwise OR (gleiche Prio wie '*' '/')
 - neue Funktion einbauen z.B. '#' Exponenten (höhere Prio als '*' '/')

 
 */



/*
 expr_list:
	expression .
	expression ; expr_list
 
 expression:
	expression + term
	expression - term
	term
 
 term:
	term / power
	term * power
	power
 
 power:
    power # primary         // char '^' produces problems with terminal input
    primary
 
 
 primary:
	NUMBER
	( expression )
 
 

 */


#include <string>
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;

enum Token_value {
    NUMBER, // '0' ... '9'
    SEMICOL = ';', DOT = '.',
    PLUS='+',  MINUS='-',  MUL='*',  DIV='/',
    //PRINT='\n',
    POWER='#',  LP='(',    RP=')',
    ERROR = '?'
};



Token_value global_token = ERROR;
unsigned int number_value;



//int no_of_errors;	// note: default initialized to 0
bool doPrintCalculations = false;
bool doPrintCalls = false;
std::string tokenCharTrace;

stringstream s1("2+3+(4*5)-10.");

//istream & input = cin;
istream & input = s1;



struct FunctionPrinter{
    std::string funcName;
  static int indentation;
  
    FunctionPrinter(std::string functionName) : funcName(functionName) {
        indentation++;
      if (doPrintCalls) {
        printIndent();
        std::cout << "enter " << funcName << "tokenCharTrace=" << tokenCharTrace << std::endl;
      }
    }
    ~FunctionPrinter(){
      if (doPrintCalls){
        printIndent();
        std::cout << "leave " << funcName << "tokenCharTrace=" << tokenCharTrace << std::endl;
      }
      indentation--;
    }
  private:
  void printIndent(){
    for(int i=0; i< indentation; i++){
      std::cout << "    " ;
    }
  }
};

int FunctionPrinter::indentation = 0;


void error(std::string s)
{
    cerr << "error: " << s << " global_token=" << static_cast<char>(global_token) << '\n';
  exit(1);
}


unsigned int asciToInt(string string_value){
    unsigned int result = 0;
    for(size_t i=0; i<string_value.length();i++){
        result *= 10;
        result += string_value[i] - 48;
    }
    return result;
}

Token_value get_token()
{
    char ch;
    
    do {	// skip whitespace except '\n'
        if(!input.get(ch)) {error("EOF"); exit(1);} //return curr_tok = END;
    } while (ch!='\n' && isspace(ch));

    tokenCharTrace += ch;
    switch (ch) {
        //case ';':
      //case '\n':
      //    return global_token=PRINT;
      case ';':
      case '.':
      case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '#':
            return global_token=Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':{
            // the easy way: input.putback(ch);
            // the easy way: input >> number_value;
            string string_value;
            string_value = ch;
            while (input.get(ch) && isdigit(ch)){
                string_value += ch;	// string_value.push_back(ch); // to work around library bug
                tokenCharTrace += ch;
            }
          input.putback(ch);
            number_value = asciToInt(string_value);
            return global_token=NUMBER;
        }
        default:
            error(std::string("bad token '") + ch + "'");
            return global_token=ERROR;
    }
}


unsigned int expression();	// cannot do without (indirect recursion)


unsigned int primary()		// handle primaries
{
    FunctionPrinter fp("primary()");

    Token_value current_token = get_token();
    
    switch (current_token) {
        case NUMBER:{
            unsigned int v = number_value;
            get_token();        // proceed global_token to next token (i.e. operator or '\n')
            return v;
        }
        case LP:{
            unsigned int e = expression();
          if (global_token != RP) {
            error(") expected");
            return 0;
          }
            get_token();		// eat ')' in order to proceed global_token to next token
            return e;
        }
        default:
        error("primary expected");
        return 0;
    }
}

unsigned int power()		// 2 ^ 3
{
    FunctionPrinter fp("power()");
  
    unsigned int left = primary();
    unsigned int right = 0;
    
    for (;;)
        switch (global_token) {
            case POWER:{
                right = primary();
                if (doPrintCalculations) printf("power() %u # %u\n", left, right);
                unsigned int base = left;
                left = 1;
                for (int i=0; i<right; i++)
                    left *= base;
                break;
            }
            default:
                return left;
        }
}


unsigned int term()		// multiply or divide
{
    FunctionPrinter fp("term()");
  
    unsigned int left = power();
    unsigned int right = 0;
    
    for (;;)
        switch (global_token) {
            case MUL:{
                right = power();
                if (doPrintCalculations) printf("term() %u * %u\n", left, right);
                left *= right;
                break;
            }
            case DIV:{
                if ((right = power())) {
                    if (doPrintCalculations) printf("term() %u / %u\n", left, right);
                    left /= right;
                    break;
                }
              error("divide by 0");
              return 0;
            }
            default:
                return left;
        }
}

/*
unsigned int ops_level_a()		        // e.g. add or subtract
{
    unsigned int left = ops_level_b();  // e.g. multiply or divide (which in turn calls ops_level_c() immediately)
    unsigned int right = 0;
    
    for (;;)
        switch (global_token) {
            case TOKEN_LEVELA_1:{
                right = ops_level_b();  // e.g. multiply or divide
                left = left TOKEN_LEVELA_1 right;
                break;
            }
            case TOKEN_LEVELA_2:{
                right = ops_level_b();  // e.g. multiply or divide
                left = left TOKEN_LEVELA_1 right;
                break;
            }
            default:                   // an operator of another (lower) level, or \n
                return left;           // there is no further operator (and operands) of this level
        }
}
*/

unsigned int expression()		// add or subtract
{
    FunctionPrinter fp("expression()");
  
    unsigned int left = term();
    unsigned int right = 0;
    
    for (;;)				// ``forever''
        switch (global_token) {
            case PLUS:{
                right = term();
                if (doPrintCalculations) printf("expr() %u + %u\n", left, right);
                left += right;
                break;
            }
            case MINUS:{
                right = term();
                if (doPrintCalculations) printf("expr() %u - %u\n", left, right);
                left -= right;
                break;
            }
            default:
                return left;
        }
}


unsigned int expression_list()    // expr { ';' expr } '.'
{
  FunctionPrinter fp("expression_list()");
  
  int expr_count=1;
  unsigned int result = expression();
  cout << "expression_" << expr_count << " result = " << result << endl;
  
  for (;;)        // ``forever''
      switch (global_token) {
          case SEMICOL:{
            //get_token();        // proceed global_token to next token
            result = expression();
            expr_count++;
            cout << "expression_" << expr_count << " result = " << result << endl;
            //get_token();        // proceed global_token to next token
            break;
          }
        case DOT:{
          cout << "finnished.   expr_count = " << expr_count << endl;
          return expr_count;
        }
          default:
          error(" . or ; expected");
          return 0;
      }
}


int main(int argc, char* argv[])
{
  if (argc == 2 ){  // ./dc.out "1+2*3-4"
    std::string inp = std::string(argv[1]) ;
    s1.str(inp);
  }
  unsigned int num = expression_list();
  cout << " main(): number of expressions = " << num << '\n';

  return 0;
}
