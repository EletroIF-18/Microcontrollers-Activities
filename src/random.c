#include "asf.h"

int areInArray(unsigned (*array)[8], int size, unsigned int value) {
    int i;
    for (i = 0; i < size; i++) {
        if ((*array)[i] == value) {
            return 1;
        }
    }
    return 0;
}

void genRandomArray(unsigned int (*arr)[8], int size, int seed) {
    int arr_size = 0, counter = seed;
    unsigned int value;

    while (arr_size < size) {
        value = (*arr)[counter] % size;
        if(value >= 0 && !areInArray(arr, arr_size, value)) {
            (*arr)[arr_size] = value;
            arr_size++;
        }
        counter++;
    }

}

void breakArray(unsigned int (*arr)[8], int size, unsigned int (*new_arr)[2][4]) {

    for(int i=0 ; i<size/2 ; i++) {
        (*new_arr)[0][i] = (*arr)[i * 2];
        (*new_arr)[1][i] = (*arr)[i * 2 + 1];
    }

}
/*
void printArray(unsigned char (*arr)[2][4][8]) {
    for(int i=0 ; i<2 ; i++) {
        printf("Line %d: \n", i+1);
        for(int j=0 ; j<4 ; j++) {
            printf("[ ");
            for(int k=0 ; k<8 ; k++) {
                printf("'%c' ", (*arr)[i][j][k]);
            }
            printf("]\n");
        }
        printf("\n");
    }
}
*/
void cloneArr(unsigned char (*base)[2][4][8], const unsigned char value[8], int line, unsigned int column) {
    //printf("[%d][%d]  [ ", line, column);
    for(int i = 0; i < 8; i++) {
        //printf("'%c' ", value[i]);
        (*base)[line][column][i] = value[i];
    }
    //printf("]\n");
}

void genRandArrIndex(unsigned char (*base)[2][4][8], unsigned char (*randomized)[2][4][8], int seed) {
    unsigned int arr[8], new_arr[2][4];
    unsigned int value;

    genRandomArray(&arr, 8, seed);
    breakArray(&arr, 8, &new_arr);



    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            value = new_arr[i][j];
            if(value >= 4){
                value -= 4;
                cloneArr(randomized, (*base)[1][value], i, j);
            } else {
                cloneArr(randomized, (*base)[0][value], i, j);
            }
        }
    }

    //printf("Array base\n");
    //printArray(base);
    //printf("Array randomized\n");
    //printArray(randomized);


}

/*
int main() {
    unsigned char base[2][4][8] = {
            {
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'
            },
            {
                '1', '2', '3', '4', '5', '6', '7', '8',
                '9', '0', '1', '2', '3', '4', '5', '6',
                '7', '8', '9', '0', '1', '2', '3', '4',
                '5', '6', '7', '8', '9', '0', '1', '2'
            }
    }, randomized[2][4][8];
    genRandArrIndex((&base), (&randomized), 8);

    printf("Array Base\n");
    for(int i=0 ; i<2 ; i++) {
        printf("Line %d: \n", i+1);
        for(int j=0 ; j<4 ; j++) {
            printf("[ ");
            for(int k=0 ; k<8 ; k++) {
                printf("'%c' ", base[i][j][k]);
            }
            printf("]\n");
        }
        printf("\n");
    }

    printf("Array Randomized\n");
    for(int i=0 ; i<2 ; i++) {
        printf("Line %d: \n", i+1);
        for(int j=0 ; j<4 ; j++) {
            printf("[ ");
            for(int k=0 ; k<8 ; k++) {
                printf("'%c' ", randomized[i][j][k]);
            }
            printf("]\n");
        }
        printf("\n");
    }

    return 0;
}
*/