#ifndef ASF_H
#define ASF_H

int compara_matriz(unsigned char (*bolsonaro)[2][4][8], unsigned char (*lula)[2][4][8]);
void copy_pasta(int *pos_cursor, int *pos_copy, int *flag_copy, unsigned char (*lula)[2][4][8], int *con_mov);
void genRandArrIndex(unsigned char (*base)[2][4][8], unsigned char (*randomized)[2][4][8], int seed);
int start_screen();

#endif // ASF_H
