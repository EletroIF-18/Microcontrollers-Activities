#include "LCD/LCD.h"
#include "asf.h"

int main(){
	DDRB = 0xFF; DDRD = 0xFF; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0xFF;
	int em_ordem = 0, con_mov = 0, pos_cursor = 0x80;

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

	_delay_ms(1000);

//===========================================//
// RANDOMIZA E ESCREVE OS VALORES NA MEMORIA //
//===========================================//
	randomize(&bolsonaro, &lula);
	//ESCREVE LINHA 1 RANDOMIZADA
	for (int i = 0; i < 4; i++){ 
		cmd_LCD(64 + 8 * i, 0);
		for (int j = 0; j < 8; j++){cmd_LCD(bolsonaro[0][i][j], 1);}
	}
	//ESCREVE LINHA 2 RANDOMIZADA
	for (int i = 0; i < 4; i++){
		cmd_LCD(96 + 8 * i, 0);
		for (int j = 0; j < 8; j++){cmd_LCD(bolsonaro[1][i][j], 1);}
	}


//=======================================================================//
// ESSA PARTE IRÁ REPETIR ATÉ O JOGADOR ACERTAR A ORDEM OU ACABAR O TEMPO//
//=======================================================================//
	while (1){
		if(!tst_bit(PINC, 0)){
			clear_disp();
			//IMPRIME LINHA 1 NA TELA
			for (int i = 0; i < 4; i++){ cmd_LCD(128 + i, 0); cmd_LCD(i, 1);}
			//IMPRIME LINHA 2 NA TELA
			for (int i = 0; i < 4; i++){ cmd_LCD(192 + i, 0); cmd_LCD(i + 4, 1);}

			pos_cursor++;
			if(pos_cursor < 4 && pos_cursor < 8){set_cursor(1 + pos_cursor, 1);}

			if(pos_cursor >= 4 && pos_cursor < 8){set_cursor(1 + pos_cursor -4, 2);}

			if(pos_cursor >= 8){pos_cursor = 0;}
			while(!tst_bit(PINC, 0));
			_delay_ms(10);
		}
		cmd_LCD(0x0F, 0);

		em_ordem = compara_matriz(&bolsonaro, &lula); //sempre no fim!!

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
		_delay_ms(2);
	}

	for(;;); //fim de jogo
	return 0;
}