#ifndef LOG_HPP
#define LOG_HPP

#include "println.hpp"

extern int loglevel;

template <typename ...U>
inline void log_T(const U& ...u){
  if (loglevel>1) println(u...);
}


template <typename ...U>
inline void err_T(const U& ...u){
  if (loglevel>0) println(u...);
}


#endif
