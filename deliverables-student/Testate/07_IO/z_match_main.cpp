#include "../90_aux_src/helpers/println.hpp"
#include "z_match_elements.hpp"
#include "z_match_patterns.hpp"
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>


int loglevel = 0;  /// needed by log.hpp


void test_1(){
  test_elements();
  test_patterns();
}


std::string readFile(std::string inputFile) {
    std::string all_lines;

    std::ifstream readFile(inputFile);
    std::string line;

    while (std::getline(readFile, line)) {
        std::stringstream ss(line);
        all_lines += line + '\n';
    }
    return all_lines;
}


std::string preprocess(std::string input) {
    for(std::string::iterator it = input.begin(); it< input.end(); it++) {
        if(std::isspace(static_cast<unsigned char>(*it))) {
            input.erase(it); // löschen an der pos:
        }
    }
    return input;
}


std::size_t match_OPEN(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset > max_offset) return 0;
    return src[offset] == '(' ? 1 : 0;
}


std::size_t match_CLOSE(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset > max_offset) return 0;
    return src[offset] == ')' ? 1 : 0;
}


std::size_t match_OP(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset > max_offset) return 0;
    if(src[offset] == '+' || src[offset] == '-') return 1;
    return 0;
}


std::size_t match_S_EXPR(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset > max_offset) return 0;

    std::size_t currentPos = offset;

    std::size_t open = match_OPEN(src, currentPos, max_offset);
    if(open == 0) return 0;
    else currentPos++;

    std::size_t op = match_OP(src, currentPos, max_offset);
    if(op == 0) return 0;
    else currentPos++;

    std::size_t digits = match_DIGITS(src, currentPos, max_offset);
    if(digits <= 2) return 0;
    else currentPos += digits;

    std::size_t close = match_CLOSE(src, currentPos, max_offset);
    if(close == 0) return 0;
    else currentPos++;

    return currentPos - offset;
}

/** C Grammatik Modi 1 ************************************************************************************************/
std::size_t match_TYPE(std::string src, std::size_t offset, std::size_t max_offset) {
    if (offset >= src.length() || max_offset >= src.length()) return 0;
    std::vector<std::string> types = {"int", "double", "void", "float", "char"};
    for(std::string type : types) {
        if(src.compare(offset, type.length(), type) == 0) {
            return type.length();
        }
    }
    return 0;
}

std::size_t match_SEMMI(std::string src, std::size_t offset, std::size_t max_offset) {
    if (offset >= src.length() || max_offset >= src.length()) return 0;
    return src[offset] == ';' ? 1 : 0;
}

std::size_t match_ARGS(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset > max_offset) return 0;

    std::size_t currentPos = offset;

    std::size_t args = match_TYPE(src, currentPos, max_offset);
    if(args == 0) return 0;
    else currentPos += args;

    std::size_t variableName = match_ALPHA(src, currentPos, max_offset);
    if(variableName == 0) return 0;
    else currentPos++;

    std::size_t comma = match_COMMA(src, currentPos, max_offset);
    if(comma == 1) {
        currentPos++;

        std::size_t args2 = match_TYPE(src, currentPos, max_offset);
        if(args2 == 0) return 0;
        else currentPos += args2;

        std::size_t variableName2 = match_ALPHA(src, currentPos, max_offset);
        if(variableName2 == 0) return 0;
        else currentPos++;
    }

    return currentPos - offset;
}

std::size_t match_C_EXPR(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset > max_offset) return 0;

    std::size_t currentPos = offset;

    std::size_t type = match_TYPE(src, currentPos, max_offset);
    if(type == 0) return 0;
    else currentPos += type;

    std::size_t words = match_WORDS(src, currentPos, max_offset);
    if(words == 0) return 0;
    else currentPos += words;

    std::size_t open = match_OPEN(src, currentPos, max_offset);
    if(open == 0) return 0;
    else currentPos++;

    std::size_t args = match_ARGS(src, currentPos, max_offset);
    if(args == 0) return 0;
    else currentPos += args;

    std::size_t close = match_CLOSE(src, currentPos, max_offset);
    if(close == 0) return 0;
    else currentPos++;

    std::size_t semmi = match_SEMMI(src, currentPos, max_offset);
    if (semmi == 0) return 0;
    else currentPos++;

    return currentPos - offset;
}
/**********************************************************************************************************************/

/** modi 3 ************************************************************************************************************/
std::size_t match_S_EXPR_2(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset > max_offset) return 0;

    std::size_t currentPos = offset;

    std::size_t open = match_OPEN(src, currentPos, max_offset);
    if(open == 0) return 0;
    else currentPos++;

    std::size_t op = match_OP(src, currentPos, max_offset);
    if(op == 0) return 0;
    else currentPos++;

    std::size_t digits = match_DIGITS(src, currentPos, max_offset);
    if(digits == 0) return 0;
    else currentPos += digits;

    std::size_t close = match_CLOSE(src, currentPos, max_offset);
    if(close == 0) {
        std::size_t match_s_expr = match_S_EXPR(src, currentPos, max_offset);
        if(match_s_expr == 0) return 0;
        currentPos += match_s_expr;
    }

    std::size_t close2 = match_CLOSE(src, currentPos, max_offset);
    if(close2 == 0) return 0;
    else currentPos++;

    return currentPos - offset;
}
/**********************************************************************************************************************/


int main() {

    test_1();

    /** TextFile Test *************************************************************************************************/
    println("TextFile Test \n");

    std::string inputTextFile = readFile("InputFile.txt");
    println("Input: \n" + inputTextFile);

    std::string outputTextFile = preprocess(inputTextFile);
    println("Output: \n" + outputTextFile + "\n");
    /******************************************************************************************************************/

    /** Grammatik Test ************************************************************************************************/
    println("Grammatik Test");

    std::string inputGrammatik = readFile("Grammatik.txt");
    println("Input: " + inputGrammatik);

    std::string inputPreprocessed = preprocess(inputGrammatik);
    println("Input preprocessed: " + inputPreprocessed);

    std::size_t outputGrammatik = match_S_EXPR(inputPreprocessed, 0, inputPreprocessed.length()-1);
    println("Output: ", outputGrammatik, "\n");
    /******************************************************************************************************************/

    /** C Grammatik Test Modi *****************************************************************************************/
    println("C Grammatik Test");

    std::string inputCGrammatik = readFile("C-Grammatik.txt");
    println("Input: " + inputCGrammatik);

    std::string inputCPreprocessed = preprocess(inputCGrammatik);
    println("Input C preprocessed: " + inputCPreprocessed);

    std::size_t outputCGrammatik = match_C_EXPR(inputCPreprocessed, 0, inputCPreprocessed.length()-1);
    println("Output: ", outputCGrammatik, "\n");
    /******************************************************************************************************************/

    /** Modi 3 Test ***************************************************************************************************/
    println("Modi 3");

    std::string inputModi3 = readFile("Modi3.txt");
    println("Input: " + inputModi3);

    std::string inputModi3Preprocessed = preprocess(inputModi3);
    println("Input Modi3 preprocessed: " + inputModi3Preprocessed);

    std::size_t outputModi3 = match_S_EXPR_2(inputModi3Preprocessed, 0, inputModi3Preprocessed.length()-1);
    println("Output: ", outputModi3, "\n");

    /******************************************************************************************************************/

    std::string h1 = "Hello";
   /** 
    println("h1 a", match_hello(h1, 0, h1.length()));
    println("h1 b", match_hello(h1, 1, h1.length()));

 
    std::string h3 = "HelloHello";
    int ml;
    ml=match_hello(h3, 0, h3.length());
    println("h3 a", ml);
    ml=match_hello(h3, 0+ml, h3.length());
    println("h3 b", ml);
      */

      /** std::string h2 = "HELLO";
    println("h2 a", match_hello(h2, 1, h2.length()-1));


*/


    std::string hello_w    = "Hello,World!";
    std::string hello_one  = "Hello,James!";
    std::string hello_many = "Hello,Bruce,Lemmy,Bon!";

    println("match_greet_world()");
    println("mgw a", match_greet_world(hello_w, 0, hello_w.length()-1));
    println("mgw b", match_greet_world(hello_one, 0, hello_one.length()-1));

    println("match_greet_match_greet_one()");
    println("mgo a", match_greet_one(hello_one, 0, hello_one.length()-1));

    println("match_greet_many()");
    println("mgm a", match_greet_many(hello_one, 0, hello_one.length()-1));
    println("mgm b", match_greet_many(hello_many, 0, hello_many.length()-1));

    return 0;
}
