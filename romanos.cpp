#include "romanos.hpp"
int romanos_para_decimal(char const * num_romano)
{
  int decimal = 0;
  switch (num_romano[0])
  {
  case 'I':
    decimal = 1;
    break;
  
  default:
    return -1;
    break;
  }
  return decimal; 
}
 