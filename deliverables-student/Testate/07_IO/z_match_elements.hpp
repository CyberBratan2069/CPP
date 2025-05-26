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
//size_t  match_COMMA(std::string src, size_t offset, size_t max_offset);
size_t   match_EXCL(std::string src, size_t offset, size_t max_offset);
//size_t  match_DIGIT(std::string src, size_t offset, size_t max_offset);
size_t  match_ALPHA(std::string src, size_t offset, size_t max_offset);
//size_t match_DIGITS(std::string src, size_t offset, size_t max_offset);


/** METHODEN IN MAIN */
std::string readFile  (std::string inputFile);
std::string preprocess(std::string input);
size_t  match_DIGIT(std::string src, size_t offset, size_t max_offset);
size_t match_DIGITS(std::string src, size_t offset, size_t max_offset);
size_t     match_OP(std::string src, size_t offset, size_t max_offset);
size_t   match_OPEN(std::string src, size_t offset, size_t max_offset);
size_t  match_CLOSE(std::string src, size_t offset, size_t max_offset);
size_t  match_COMMA(std::string src, size_t offset, size_t max_offset);
void match_ALL_GRAMMATIK(std::string src);


void test_elements();


#endif
