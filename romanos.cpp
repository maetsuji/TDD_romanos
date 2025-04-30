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

    // Contadores para V, L e D
    int V_count, L_count, D_count; 
    V_count = L_count = D_count = 0;

    // Contadores consecutivos para I, X, C e M
    int I_consec_count, X_consec_count, C_consec_count, M_consec_count;
    I_consec_count = X_consec_count = C_consec_count = M_consec_count = 0;

    // Contadores totais para I, X, C e M
    int I_count, X_count, C_count, M_count;
    I_count = X_count = C_count = M_count = 0;

    while (num_romano[count] != '\0')
    {  
        switch (num_romano[count])
        {

        case 'I':
            // Atualiza e checa contador total
            I_count++;
            if (I_count > 4)
            {
                return -1;
            }

            // Atualiza e checa contador consecutivo
            // Se o próximo algarismo não for I, reseta o contador
            I_consec_count++;
            if (I_consec_count > 3)
            {
                return -1;
            }
            else if (num_romano[count + 1] != 'I')
            {
                I_consec_count = 0;
            }
            
            // Checa se o algarismo subtrai do próximo ou não
            // Se o próximo algarismo for V ou X, subtrai 1
            // Se não, soma 1
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
            // Atualiza e checa contador, V não pode ser repetido
            V_count++;
            if (V_count > 1)
            {
                return -1;
            }
            decimal += 5;
            break;

        case 'X':
            // Atualiza e checa contador total
            X_count++;
            if (X_count > 4)
            {
                return -1;
            }

            // Atualiza e checa contador consecutivo
            // Se o próximo algarismo não for X, reseta o contador
            X_consec_count++;
            if (X_consec_count > 3)
            {
                return -1;
            }
            else if (num_romano[count + 1] != 'X')
            {
                X_consec_count = 0;
            }
            
            // Checa se o algarismo subtrai do próximo ou não
            // Se o próximo algarismo for L ou C, subtrai 10
            // Se não, soma 10
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
            // Atualiza e checa contador, L não pode ser repetido
            L_count++;
            if (L_count > 1)
            {
                return -1;
            }         
            decimal += 50;
            break;

        case 'C':
            // Atualiza e checa contador total
            C_count++;
            if (C_count > 4)
            {
                return -1;
            }
            // Atualiza e checa contador consecutivo
            // Se o próximo algarismo não for C, reseta o contador
            C_consec_count++;
            if (C_consec_count > 3)
            {
                return -1;
            }
            else if (num_romano[count + 1] != 'C')
            {
                C_consec_count = 0;
            }
            
            // Checa se o algarismo subtrai do próximo ou não
            // Se o próximo algarismo for D ou M, subtrai 100
            // Se não, soma 100
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
            // Atualiza e checa contador, D não pode ser repetido
            D_count++;
            if (D_count > 1)
            {
                return -1;
            }
            decimal += 500;
            break;

        case 'M':
            // Atualiza e checa contador total
            M_count++;
            if (M_count > 4)
            {
                return -1;
            }

            // Atualiza e checa contador consecutivo
            // Se o próximo algarismo não for M, reseta o contador
            M_consec_count++;
            if (M_consec_count > 3)
            {
                return -1;
            }
            else if (num_romano[count + 1] != 'M')
            {
                M_consec_count = 0;
            }

            // M nao subtrai de nenhum algarismo
            decimal += 1000;
            break;
        
        default:
            // Se o algarismo não for válido, retorna -1
            return -1;
            break;
        }
        count++;
    }
    if (decimal < 0 || decimal > 3000)
    {
        return -1;
    }
    return decimal; 
}
 

