#include "romanos.hpp"

/*
Em algarismos romanos, apenas os símbolos I (1), 
X (10) e C (100) podem ser subtraídos de outros. 
Eles só podem subtrair os dois algarismos imedi-
atamente maiores. Por exemplo, IX é 9 (10-1), XL
é 40 (50-10) e XC é 90 (100-10)

Além disso, os símbolos I, X e C podem ser repe-
tidos até três vezes. Por exemplo, III é 3 (1+1+1),
XX é 20 (10+10) e CCC é 300 (100+100+100).
Os símbolos V (5), L (50) e D (500) não podem 
ser repetidos e não podem ser subtraídos de outros.
Os símbolos V, L e D só podem aparecer uma vez em
cada número romano. Por exemplo, VIV é inválido e 
não pode ser lido como 10 (5+5).
*/

int romanos_para_decimal(char const * num_romano)
{ 
    int decimal = 0;
    int count = 0;
    int V_count, L_count, D_count;
    V_count = L_count = D_count = 0;
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
            V_count++;
            if (V_count > 1)
            {
                return -1;
            }
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
            L_count++;
            if (L_count > 1)
            {
                return -1;
            }         
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
            D_count++;
            if (D_count > 1)
            {
                return -1;
            }
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
 