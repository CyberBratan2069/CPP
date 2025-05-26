#ifndef MP_LOGGER_HPP
#define MP_LOGGER_HPP
#include <string>

/** code below can be read as:
    void log_msg(std::string category, std::string message);
    but: the effective function behind this name may change at runtime */

typedef void (*logger_func)(std::string category, std::string message);
extern logger_func log_msg;     /// pseudonym of effective logging function

extern std::string DEBUG;
extern std::string WARNING;
extern std::string ERROR;

void setup_logger(int argc, char* argv[]);

#endif
