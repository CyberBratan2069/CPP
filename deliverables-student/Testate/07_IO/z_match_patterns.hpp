#ifndef H_MATCH_RULES
#define H_MATCH_RULES

#include <string>


size_t match_name(std::string src, size_t offset, size_t max_offset);

int match_name_list(std::string src, size_t offset, size_t max_offset);

int match_greet_world(std::string src, size_t offset, size_t max_offset);

int match_greet_one(std::string src, size_t offset, size_t max_offset);

int match_greet_many(std::string src, size_t offset, size_t max_offset);



void test_patterns();

#endif
