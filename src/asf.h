#ifndef ASF_H
#define ASF_H

void randomize(unsigned char (*bolsonaro)[2][4][8], unsigned char (*lula)[2][4][8]);
int compara_matriz(unsigned char (*bolsonaro)[2][4][8], unsigned char (*lula)[2][4][8]);
void copy_pasta(int *pos_cursor, int *pos_copy, int *flag_copy, unsigned char (*lula)[2][4][8], int *con_mov);

#endif // ASF_H
