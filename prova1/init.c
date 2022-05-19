#include "asf.h"

void randomize(unsigned char bolsonaro[2][4][8], unsigned char lula[2][4][8]){

}

int compara_matriz(unsigned char bolsonaro[2][4][8], unsigned char lula[2][4][8]){
    int res = 1;

    for(int i=0 ; i<8 ; i++){
        if(lula[0][0][i] != bolsonaro[0][0][i]){res = 0; break}
    }

    return res;
}