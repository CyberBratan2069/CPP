#include "logger.hpp"

logger_func log_msg = no_logging;

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
