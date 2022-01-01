#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    const char *A_MOS = "10111";
    const char *B_MOS = "111010101";
    const char *C_MOS = "11101011101";
    const char *D_MOS = "1110101";
    const char *E_MOS = "1";
    const char *F_MOS = "101011101";
    const char *G_MOS = "111011101";
    const char *H_MOS = "1010101";
    const char *I_MOS = "101";
    const char *J_MOS = "1011101110111";
    const char *K_MOS = "111010111";
    const char *L_MOS = "101110101";
    const char *M_MOS = "1110111";
    const char *N_MOS = "11101";
    const char *O_MOS = "11101110111";
    const char *P_MOS = "10111011101";
    const char *Q_MOS = "1110111010111";
    const char *R_MOS = "1011101";
    const char *S_MOS = "10101";
    const char *T_MOS = "111";
    const char *U_MOS = "1010111";
    const char *V_MOS = "101010111";
    const char *W_MOS = "101110111";
    const char *X_MOS = "11101010111";
    const char *Y_MOS = "1110101110111";
    const char *Z_MOS = "11101110101";

    const char*one_MOS = "10111011101110111";
    const char*two_MOS = "101011101110111";
    const char*three_MOS = "1010101110111";
    const char*four_MOS = "10101010111";
    const char*five_MOS = "101010101";
    const char*six_MOS = "11101010101";
    const char*seven_MOS = "1110111010101";
    const char*eight_MOS = "111011101110101";
    const char*nine_MOS = "11101110111011101";
    const char*zero_MOS = "1110111011101110111";
    const char*side_MOS = "000";
    const char*blank_MOS = "0";

    const char*Mos_Number[10] = {zero_MOS, one_MOS, two_MOS, three_MOS, four_MOS, five_MOS, six_MOS, seven_MOS, eight_MOS, nine_MOS};
    const char*Mos_Alhabet[26] = {A_MOS, B_MOS, C_MOS, D_MOS, E_MOS, F_MOS, G_MOS, H_MOS, I_MOS, J_MOS, K_MOS, L_MOS, M_MOS ,N_MOS, O_MOS, P_MOS, Q_MOS, R_MOS, S_MOS, T_MOS, U_MOS, V_MOS, W_MOS, X_MOS, Y_MOS, Z_MOS};
    char temp;

    int M[100000];
    int idx = 0;
    int Input_Size = 0;
    while(Input_Size < 101)
    {

        temp = getchar();
        if(temp == '\n')
        {
            break;
        }

        if((int)temp >= 65 && (int)temp <= 90)// 소문자로 변환
        {
            temp = temp + 32; // strlwr(temp);
        }

        if((int)temp >= 97 && (int)temp <= 122) // 입력받은 문자가 알파벳이라면
        {
            temp = temp - 97;
            if(strlen(Mos_Alhabet[temp])>10) //오버플로우 막기
            {
                for(int i = 0; i <strlen(Mos_Alhabet[temp]); i++)
                {
                    M[idx] = Mos_Alhabet[temp][i] - '0';
                    idx++;
                }
            }
            else
            {
                M[idx] = atoi(Mos_Alhabet[temp]);
                idx++;
            }
            
            
        }
        else if((int)temp >= 48 && (int)temp <= 57)
        {
            temp = temp - 48;
            if(strlen(Mos_Number[temp])>10) //오버플로우 막기
            {
                for(int i = 0; i <strlen(Mos_Number[temp]); i++)
                {
                    M[idx] = Mos_Number[temp][i] - '0';
                    idx++;
                }
            }
            else
            {
                M[idx] = atoi(Mos_Number[temp]);
                idx++;
            }
        }
        else if(temp == ' ')
        {
            M[idx] = 0; // 2 = 공백
            idx++;
        }
        

        for(int i =0; i < 3; i++)
        {
            M[idx] = 0; // 3 = 글자 사이
            idx++;
        }
        
        Input_Size++;
    }

    for(int i = 0; i < idx; i++)
    {
        printf("%d", M[i]);
        

    }

    printf("\n");

}

