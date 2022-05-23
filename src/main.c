#include "LCD/LCD.h"

int main(){
	DDRB = 0xFF; DDRD = 0xFF; PORTB = 0x00;
	int em_ordem = 0, con_mov = 0;

	set_bit(PORTB, 2);
	inic_LCD_4bits();

	//MATRIZ COM OS CARACTERES CORRETOS
	unsigned char bolsonaro[2][4][8] = {
		{// linha1
		 {0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1E,
		  0x18,
		  0x10},
		 {0x1F,
		  0x1F,
		  0x1F,
		  0x1C,
		  0x10,
		  0x03,
		  0x0F,
		  0x0F},
		 {0x1F,
		  0x1F,
		  0x1F,
		  0x07,
		  0x01,
		  0x18,
		  0x1E,
		  0x1F},
		 {0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x0F,
		  0x03,
		  0x01}},

		{// linha 2
		 {0x10,
		  0x18,
		  0x1E,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F},
		 {0x0F,
		  0x07,
		  0x03,
		  0x10,
		  0x1C,
		  0x1F,
		  0x1F,
		  0x1F},
		 {0x1E,
		  0x1E,
		  0x18,
		  0x01,
		  0x07,
		  0x1F,
		  0x1F,
		  0x1F},
		 {0x01,
		  0x03,
		  0x0F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F,
		  0x1F}}

	};
	
	//MATRIZ COM OS CARACTERES NA POSIÇÃO RANDOMIZADA
	unsigned char lula[2][4][8];

//====================================================//
//    APRESENTA A IMAGEM AO USUARIO E ESPERA 5s       //
//====================================================//
	//ESCREVE LINHA 1
	for (int i = 0; i < 4; i++){ 
		cmd_LCD(64 + 8 * i, 0);
		for (int j = 0; j < 8; j++){cmd_LCD(bolsonaro[0][i][j], 1);}
	}
	//ESCREVE LINHA 2
	for (int i = 0; i < 4; i++){
		cmd_LCD(96 + 8 * i, 0);
		for (int j = 0; j < 8; j++){cmd_LCD(bolsonaro[1][i][j], 1);}
	}
	
	//IMPRIME LINHA 1
	for (int i = 0; i < 4; i++){ cmd_LCD(128 + i, 0); cmd_LCD(i, 1);}
	//IMPRIME LINHA 2
	for (int i = 0; i < 4; i++){ cmd_LCD(192 + i, 0); cmd_LCD(i + 4, 1);}

	_delay_ms(5000);

	randomize(bolsonaro, lula);


//=======================================================================//
// ESSA PARTE IRÁ REPETIR ATÉ O JOGADOR ACERTAR A ORDEM OU ACABAR O TEMPO//
//=======================================================================//
	while (1){
		
		em_ordem = compara_matriz(bolsonaro, lula); //sempre no fim!!
		set_cursor(8,1); char mov=16-con_mov; escreve_LCD(mov);
		if(em_ordem == 1){
			clear_disp();
			set_cursor(1,1); escreve_LCD("Fim de jogo");
			set_cursor(1,2); escreve_LCD("Voce venceu");
			break;
		}
		if(con_mov > 16){
			clear_disp();
			set_cursor(1,1); escreve_LCD("Fim de jogo");
			set_cursor(1,2); escreve_LCD("Voce perdeu");
			break;
		}
		_delay_ms(2); clear_disp();
	}
	for(;;); //fim de jogo
	return 0;
}