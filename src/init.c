#include "asf.h"

void randomize(unsigned char (*bolsonaro)[2][4][8], unsigned char (*lula)[2][4][8]){
    int fat_random = 2;


}

int compara_matriz(unsigned char (*bolsonaro)[2][4][8], unsigned char (*lula)[2][4][8]){
    int res = 1, k = 0, i = 0; 

    for(k=0 ; k<4 ; k++){
            for(int i=0 ; i<8 ; i++){
            if((*lula)[0][k][i] != (*bolsonaro)[0][0][i]){res = 0; break;}
        }
    }

    for(k=0 ; k<4 ; k++){
            for(int i=0 ; i<8 ; i++){
            if((*lula)[1][k][i] != (*bolsonaro)[0][0][i]){res = 0; break;}
        }
    }

    return res;
}