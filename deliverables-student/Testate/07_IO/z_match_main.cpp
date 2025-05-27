#include "../90_aux_src/helpers/println.hpp"
#include "z_match_elements.hpp"
#include "z_match_patterns.hpp"
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cassert>


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
    for(std::string::iterator it = input.begin(); it < input.end(); it++) {
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
    //std::size_t digitCount = 0;

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
    println("Input: \n" + inputGrammatik);

    std::string inputPreprocessed = preprocess(inputGrammatik);
    println("Input preprocessed: \n" + inputPreprocessed);

    std::size_t outputGrammatik = match_S_EXPR(inputPreprocessed, 0, inputPreprocessed.length()-1);
    println("Output: \n", outputGrammatik);
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
