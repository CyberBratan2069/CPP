//MPINCLUDE1
#include "logger.hpp"
//MPINCLUDE2
#include <iostream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>

std::string DEBUG   = "DEBUG: ";
std::string WARNING = "WARNING: ";
std::string ERROR   = "ERROR: ";

void no_logging(std::string , std::string);

//MPINCLUDE3

logger_func log_msg = no_logging;

//MPINCLUDE4



void write_to_file(std::string message){
  std::stringstream s;
  std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  s << std::put_time( std::localtime( &t ), "%FT%T%z" );  //TBD fix formating
  message = s.str() + " " + message;
  std::ofstream log_file;
  log_file.open ("log.txt", std::ios::app);      // open and close every time to make it more robust in case of crashes
  log_file << message << std::endl;
}


// see https://stackoverflow.com/a/75965534 to suppress warning                             
//MPINCLUDE5
void no_logging(std::string , std::string){
}

void log_level1(std::string category, std::string message){
  if (category == ERROR || category == WARNING) {
    std::cout << category + message << std::endl;
  }
}

void log_level2(std::string category, std::string message){
  std::cout << category + message << std::endl;
}

void log_level3(std::string category, std::string message){
  write_to_file(category + message);
}
//MPINCLUDE6

/**
 * TBD: use a decent getopt-library, e.g.
 * https://github.com/docopt/docopt.cpp
 * https://github.com/CLIUtils/CLI11
 * https://llvm.org/docs/CommandLine.html
 * */

//MPINCLUDE7

// do the wiring of logging functions in effect
// (based on log level provided at the command line)
void setup_logger(int argc, char* argv[]){
  if(argc == 2){
	if (std::string(argv[1]) == std::string("-l3")) {
      log_msg = log_level3;
    } else if (std::string(argv[1]) == std::string("-l2")) {
      log_msg = log_level2;
    } else if (std::string(argv[1]) == std::string("-l1")) {
      log_msg = log_level1;
    } else { /// "-0" is also the default case
      log_msg = no_logging;
    } 
  }
}
//MPINCLUDE8

