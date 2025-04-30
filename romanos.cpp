#include "romanos.hpp"

/*
Em algarismos romanos, apenas os símbolos I (1), 
X (10) e C (100) podem ser subtraídos de outros. 
Eles só podem subtrair os dois algarismos imedi-
atamente maiores. Por exemplo, IX é 9 (10-1), XL
é 40 (50-10) e XC é 90 (100-10)
*/

int romanos_para_decimal(char const * num_romano)
{ 
    int decimal = 0;
    int count = 0;
    while (num_romano[count] != '\0')
    {  
        switch (num_romano[count])
        {

        case 'I':
            if (num_romano[count + 1] == 'V' || num_romano[count + 1] == 'X')
            {
                decimal -= 1;
            }
            else
            {
                decimal += 1;
            }
            break;

        case 'V':
            decimal += 5;
            break;

        case 'X':
            if (num_romano[count + 1] == 'L' || num_romano[count + 1] == 'C')
            {
                decimal -= 10;
            }
            else
            {
                decimal += 10;
            }
            break;

        case 'L':         
            decimal += 50;
            break;

        case 'C':
            if (num_romano[count + 1] == 'D' || num_romano[count + 1] == 'M')
            {
                decimal -= 100;
            }
            else
            {
                decimal += 100;
            }
            break;

        case 'D':
            decimal += 500;
            break;
            
        case 'M':
            decimal += 1000;
            break;
        
        default:
            return -1;
            break;
        }
        count++;
    }
    return decimal; 
}
 