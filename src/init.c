#include "asf.h"

void randomize(unsigned char (*bolsonaro)[2][4][8], unsigned char (*lula)[2][4][8]){
    //TEM QUE FAZER
}


//ISSO ERA PRA COMPARAR AS MATRIZES MAS NãO Tá FUNFANDO
int compara_matriz(unsigned char (*bolsonaro)[2][4][8], unsigned char (*lula)[2][4][8]){
    int res = 1; 

    for(int k=0 ; k<4 ; k++){
            for(int i=0 ; i<8 ; i++){
            if((*lula)[0][k][i] != (*bolsonaro)[0][k][i]){res = 0; break;}
        }
    }

    for(int k=0 ; k<4 ; k++){
            for(int i=0 ; i<8 ; i++){
            if((*lula)[1][k][i] != (*bolsonaro)[0][k][i]){res = 0; break;}
        }
    }

    return res;
}

void copy_pasta(int *pos_cursor, int *pos_copy, int *flag_copy, unsigned char (*lula)[2][4][8], int *con_mov){
    if(*flag_copy == 0){*pos_copy = *pos_cursor; *flag_copy = 1; return;} // COPIA POSIÇÃO DO CURSOR

//======================================//
//1 - COPIA POSIÇãO Já MARCADA PARA TEMP//
//2 - COPIA POSIÇãO ATUAL PARA A MARCADA//
//3 - COPIA POSIÇãO DA TEMP PARA A ATUAL//
//======================================//
    unsigned char temp[8];
    if(*flag_copy == 1){
        for(int i=0 ; i <8 ; i++){
            if(*pos_copy < 4){
                temp[i] = (*lula)[0][*pos_copy][i];
                if(*pos_cursor < 4){
                    (*lula)[0][*pos_copy][i] = (*lula)[0][*pos_cursor][i];
                    (*lula)[0][*pos_cursor][i] = temp[i];
                } else{
                    (*lula)[0][*pos_copy][i] = (*lula)[1][*pos_cursor-4][i];
                    (*lula)[1][*pos_cursor-4][i] = temp[i];
                }
            } else{
                temp[i] = (*lula)[1][*pos_copy-4][i];
                if(*pos_cursor < 4){
                    (*lula)[1][*pos_copy-4][i] = (*lula)[0][*pos_cursor][i];
                    (*lula)[0][*pos_cursor][i] = temp[i];
                } else{
                    (*lula)[1][*pos_copy-4][i] = (*lula)[1][*pos_cursor-4][i];
                    (*lula)[1][*pos_cursor-4][i] = temp[i];
                }
            }
        }
        *flag_copy = 0; *con_mov = *con_mov+1;
    }
}