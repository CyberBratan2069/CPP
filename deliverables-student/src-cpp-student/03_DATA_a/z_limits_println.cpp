#include "../90_aux_src/helpers/println.hpp"
#include <limits>
#include <cstdint>


#define lowest_of(x) std::numeric_limits<x>::lowest()
#define max_of(x) std::numeric_limits<x>::max()

int main()
{
  println("=======================================================");
  println("type\t|sizeof\t|\t lowest\t\t|\t highest");
  println("-------------------------------------------------------");
  println("int   \t| ",sizeof(int), "\t|\t",
          lowest_of(int), "\t|\t",
          max_of(int));
  println("long  \t| ",sizeof(long), " \t|\t",
          lowest_of(long), "\t|\t",
          max_of(long));
  println("uint32_t| ",sizeof(uint32_t), "\t|\t\t",
          lowest_of(uint32_t), "\t|\t",
          max_of(uint32_t));
  println("float \t| ",sizeof(float), "\t|\t",
          lowest_of(float), "\t|\t",
          max_of(float));
  println("double\t| ",sizeof(double), "\t|\t",
          lowest_of(double), "\t|\t",
          max_of(double));
  println("=======================================================");
}

