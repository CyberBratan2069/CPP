#include "../90_aux_src/helpers/println.hpp"
#include "z_match_elements.hpp"
#include "z_match_patterns.hpp"
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>


int loglevel = 0;  /// needed by log.hpp

void test_1() {
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
    for (std::string::iterator it = input.begin(); it < input.end(); it++) {
        if (std::isspace(static_cast<unsigned char>(*it))) {
            input.erase(it); // löschen an der pos:
        }
    }
    return input;
}



std::size_t match_DIGIT(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset >= src.size() || offset > max_offset) return 0;
    if(std::isdigit(src[offset])) return 1;
    return 0;
}


std::size_t match_DIGITS(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset >= src.size() || offset > max_offset) return 0;
    std::size_t match_len = 0;

    for(std::string::iterator it = src.begin()+offset; it < src.begin()+std::min(src.size(), offset + max_offset); it++) {
        if(std::isdigit(static_cast<unsigned char>(*it))) {
            match_len++;
        }
        else break;
    }
    return match_len;
}


std::size_t match_OP(std::string src, std::size_t offset, std::size_t max_offset) {
    for(std::string::iterator it = src.begin()+offset; it < src.begin()+std::min(src.size(), offset + max_offset);) {
        if(static_cast<char>(*it) == '+' || static_cast<char>(*it) == '-') {
            return 1;
        }
    }
    return 0;
}


std::size_t match_OPEN(std::string src, std::size_t offset, std::size_t max_offset) {
    for(std::string::iterator it = src.begin()+offset; it < src.begin()+std::min(src.size(), offset + max_offset);) {
        if(static_cast<unsigned char>(*it) == '(') return 1;
        else break;
    }
    return 0;
}


std::size_t match_CLOSE(std::string src, std::size_t offset, std::size_t max_offset) {
    for(std::string::iterator it = src.begin()+offset; it != src.end()+max_offset; it++) {
        if(static_cast<char>(*it) == ')') return 1;
    }
    return 0;
}


std::size_t match_COMMA(std::string src, std::size_t offset, std::size_t max_offset) {
    if(offset >= src.size() || offset > max_offset) return 0;

    for(std::string::iterator it = src.begin()+offset; it != src.end()+max_offset;) {
        if(static_cast<char>(*it) != ',') {
            it++;
        }
        if(static_cast<char>(*it) == ',') {
            return 1;
        }
    }
    return 0;
}


void match_ALL_GRAMMATIK(std::string input) {
    std::string preprocessInput = preprocess(input);
    println("Input: " + preprocessInput);
    println(match_OPEN  (preprocessInput, 0, preprocessInput.length() -1));
    println(match_OP    (preprocessInput, 0, preprocessInput.length() -1));
    println(match_DIGIT (preprocessInput, 2, preprocessInput.length() -1));
    println(match_DIGITS(preprocessInput, 2, preprocessInput.length() -1));
}


int main() {
    test_1();

    std::string g2 = "(+ 1 2 3 456)";
    match_ALL_GRAMMATIK(g2);


    /*
    std::string all_lines = readFile("InputFile.txt");
    println("Input Text File= " + all_lines);

    std::string preOutput = preprocess(all_lines);
    println("Output Preprocess = " + preOutput);
    */

    //match_DIGIT(all_lines);
    //println("DIGIT match_len: ", match_DIGITS(all_lines));



    /*
    std::string all_lines;

    std::ifstream readFile("InputFile.txt"); //Read each line
    std::string line;

    if(!readFile) {
        println("Invalid Input File!");
        return 1;
    }

    while (std::getline(readFile, line)) {
        std::stringstream ss(line);
        all_lines += line + '\n';
    }

    println("All Lines = " + all_lines);

    std::string output = preprocess(all_lines);
    println("Output = " + output);
    */

    //println("TEST!!!");
    //std::string preTest = "Hallo World Mit Leerzeichen";
    //println(preprocess(preTest));
    //println("TEST ENDE !!!");

    //println("TEST MIT GRAMMATIK");
    //std::string g1 = "(+ 12 34), (- 78 9)";
    //std::string g2 = "(+ 1 2 3 456)";
    //std::string g3 = "(- 78 9";
    //std::string g4 = "(1 2 3 456)";


  
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
