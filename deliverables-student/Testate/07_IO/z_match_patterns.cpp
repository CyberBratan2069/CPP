#include "z_match_elements.hpp"
#include "z_match_patterns.hpp"
#include "../90_aux_src/helpers/println.hpp"
#include "z_log.hpp"
#include <cassert>





/// name        ::= (LETTER)*
size_t match_name(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  size_t match_len = 0;
  size_t is_digit = 0;
  do {
    is_digit = match_ALPHA(src, offset + match_len, max_offset);
    match_len += is_digit;
  } while (is_digit > 0 && (offset + match_len <= max_offset));
  return match_len;
}

/// name_list   ::= name (comma name)*
int match_name_list(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  size_t match_len = 0;
  size_t ml = 0;
  do {
    ml = match_name(src, offset + match_len, max_offset);
    if(ml>0){
      std::string name = src.substr(offset + match_len, ml);
      log_T("mnl: found name '", name, "'");
      match_len += ml;
      ml = match_COMMA(src, offset + match_len, max_offset);
      if(ml>0){
        match_len += ml;
      } else {
        log_T("mnl: end of list");
        return match_len;
      }
    } else {
      err_T("mnl: no name found");
      return 0;
    }
    
  } while (ml > 0);
  return match_len;
}



/// greet_world ::= hello COMMA world EXCL
int match_greet_world(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  size_t match_len = 0;
  size_t ml = 0;
  
  ml = match_hello(src, offset + match_len, max_offset);
  if(ml>0){                          // need 'Hello' 
    match_len += ml;
    ml = match_COMMA(src, offset + match_len, max_offset);
    if(ml>0){                        // need ','
      match_len += ml;
      ml = match_world(src, offset + match_len, max_offset);
      if (ml>0){                     // need 'World' 
        match_len += ml;
        ml = match_EXCL(src, offset + match_len, max_offset);
        if(ml>0){                    // need '!'
            match_len += ml;
            return match_len;        // finally ... success!
          } else {
            err_T("no '!' found");
            return 0;                // no '!' found
          }
      } else {
        err_T("no 'World' found");
        return 0;                    // no 'World' found
      }
    } else {
      err_T("no ',' found");
      return 0;                      // no ',' found
    }
  } else {
    err_T("no 'Hello' found");
    return 0;                        // no 'Hello' found
  }
}

/// greet_one   ::= hello COMMA name EXCL
int match_greet_one(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  size_t match_len = 0;
  size_t ml = 0;
  
  ml = match_hello(src, offset + match_len, max_offset);
  if(ml>0){                          // need 'Hello' 
    match_len += ml;
    ml = match_COMMA(src, offset + match_len, max_offset);
    if(ml>0){                        // need ','
      match_len += ml;
      ml = match_name(src, offset + match_len, max_offset);
      if (ml>0){                     // need name 
        std::string name = src.substr(offset+match_len, ml);
        log_T("found name '", name, "'");
        match_len += ml;
        ml = match_EXCL(src, offset + match_len, max_offset);
        if(ml>0){                    // need '!'
            match_len += ml;
            return match_len;        // finally ... success!
          } else {
            err_T("no '!' found");
            return 0;                // no '!' found
          }
      } else {
        err_T("no name found");
        return 0;                    // no 'World' found
      }
    } else {
      err_T("no ',' found");
      return 0;                      // no ',' found
    }
  } else {
    err_T("no 'Hello' found");
    return 0;                        // no 'Hello' found
  }
}


/// greet_many  ::= hello COMMA name_list EXCL
int match_greet_many(std::string src, size_t offset, size_t max_offset){
  if ( offset >= src.length() || max_offset >= src.length()) return 0;
  size_t match_len = 0;
  size_t ml = 0;
  
  ml = match_hello(src, offset + match_len, max_offset);
  if(ml>0){                          // need 'Hello' 
    match_len += ml;
    ml = match_COMMA(src, offset + match_len, max_offset);
    if(ml>0){                        // need ','
      match_len += ml;
      ml = match_name_list(src, offset + match_len, max_offset);
      if (ml>0){                     // need name_list 
        match_len += ml;
        ml = match_EXCL(src, offset + match_len, max_offset);
        if(ml>0){                    // need '!'
            match_len += ml;
            return match_len;        // finally ... success!
          } else {
            err_T("no '!' found");
            return 0;                // no '!' found
          }
      } else {
        err_T("no name_list found");
        return 0;                    // no name_list found
      }
    } else {
      err_T("no ',' found");
      return 0;                      // no ',' found
    }
  } else {
    err_T("no 'Hello' found");
    return 0;                        // no 'Hello' found
  }
}



void test_patterns(){
    
  if (loglevel>0) println("test_patterns()   begin");
  
  std::string name1="JohnDoe";
  assert( match_name(name1, 0, name1.length()-1) == name1.length());
  assert( match_name(name1, 0, name1.length()-0) == 0);
  std::string name2="JohnDoe??????";
  assert( match_name(name2, 0, name2.length()-1) == 7);
  assert( match_name(name2, 0, name2.length()-0) == 0);
  std::string name3="???JohnDoe";
  assert( match_name(name3, 3, name3.length()-1) == 7);
  assert( match_name(name3, 3, name3.length()-0) == 0);
  assert( match_name("?JohnDoe?", 1, 8) == 7);

  assert( match_name_list("a", 0, 0) == 1);
  assert( match_name_list("a,b", 0, 2) == 3);
  assert( match_name_list("a,b?", 0, 3) == 3);
  assert( match_name_list("a,b,c", 0, 4) == 5);
  assert( match_name_list("a,b,c?", 0, 4) == 5);
  assert( match_name_list("?a,b,c", 1, 5) == 5);

  assert( match_name_list("a,", 0, 1) == 0);
  assert( match_name_list("a,,", 0, 2) == 0);
  assert( match_name_list("a,b,", 0, 3) == 0);

  if (loglevel>0) println("test_patterns()   end");
}


