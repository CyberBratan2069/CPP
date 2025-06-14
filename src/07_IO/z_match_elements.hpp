#ifndef H_MATCH_LITERALS
#define H_MATCH_LITERALS

#include <string>


/*

common signature:  (std::string src, size_t offset, size_t max_offset)

src         ===> string to search in
offset      ===> first index to search at
max_offset  ===> last index to search at

e.g. valid parameters are:
"a",   0, 0
"abc", 0, 2

"abc", 1, 1
"abc", 1, 2
"abc", 2, 2

*/


size_t  match_hello(std::string src, size_t offset, size_t max_offset);
size_t  match_world(std::string src, size_t offset, size_t max_offset);
size_t  match_COMMA(std::string src, size_t offset, size_t max_offset);
size_t   match_EXCL(std::string src, size_t offset, size_t max_offset);
size_t  match_DIGIT(std::string src, size_t offset, size_t max_offset);
size_t  match_ALPHA(std::string src, size_t offset, size_t max_offset);
size_t match_DIGITS(std::string src, size_t offset, size_t max_offset);

void test_elements();

/** add grammar **/
/** In z_match_elements.cpp **/
std::size_t  match_OPEN(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t match_CLOSE(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t    match_OP(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t  match_TYPE(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t match_WORDS(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t match_SEMMI(std::string src, std::size_t offset, std::size_t max_offset);

/** In z_match_main.cpp **/
std::string       readFile(std::string inputFile);
std::string     preprocess(std::string input);
std::size_t   match_S_EXPR(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t     match_ARGS(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t   match_C_EXPR(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t match_S_EXPR_2(std::string src, std::size_t offset, std::size_t max_offset);
std::size_t match_Rekursiv(std::string src, std::size_t offset, std::size_t max_offset);




#endif
