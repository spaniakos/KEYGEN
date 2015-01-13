#include "KEYGEN.h"

/*****************************************************************************/

void KEYGEN::init(int lpin){
	#if defined(KEYGEN_LINUX)
		NUMS[0] = '0';NUMS[1] = '1';NUMS[2] = '2';NUMS[3] = '3';NUMS[4] = '4';NUMS[5] = '5';NUMS[6] = '6';NUMS[7] = '7';NUMS[8] = '8';NUMS[9] = '9';
		SYMS[0] = '!';SYMS[1] = '@';SYMS[2] = '#';SYMS[3] = '$';SYMS[4] = '^';SYMS[5] = '&';SYMS[6] = '*';SYMS[7] = '(';SYMS[8] = ')';SYMS[9] = '-';SYMS[10] = '_';SYMS[11] = '=';SYMS[12] = '+';SYMS[13] = '[';SYMS[14] = ']';SYMS[15] = '<';SYMS[16]  = '>';SYMS[17]  = ',';SYMS[18]  = '.';SYMS[19]  = '/';SYMS[20]  = ':';
		CAPS[0] = 'A';CAPS[1] = 'B';CAPS[2] = 'C';CAPS[3] = 'D';CAPS[4] = 'E';CAPS[5] = 'F';CAPS[6] = 'G';CAPS[7] = 'H';CAPS[8] = 'I';CAPS[9] = 'J';CAPS[10] = 'K';CAPS[11] = 'L';CAPS[12] = 'M';CAPS[13] = 'N';CAPS[14] = 'O';CAPS[15] = 'P';CAPS[16] = 'Q';CAPS[17] = 'R';CAPS[18] = 'S';CAPS[19] = 'T';CAPS[20] = 'U';CAPS[21] = 'V';CAPS[22] = 'W';CAPS[23] = 'X';CAPS[24] = 'Y';CAPS[25] = 'Z';
		LOWE[0] = 'a';LOWE[1] = 'b';LOWE[2] = 'c';LOWE[3] = 'd';LOWE[4] = 'e';LOWE[5] = 'f';LOWE[6] = 'g';LOWE[7] = 'h';LOWE[8] = 'i';LOWE[9] = 'j';LOWE[11] = 'k';LOWE[12] = 'l';LOWE[13] = 'm';LOWE[14] = 'n';LOWE[15] = 'o';LOWE[16] = 'p';LOWE[17] = 'q';LOWE[18] = 'r';LOWE[19] = 's';LOWE[20] = 't';LOWE[21] = 'u';LOWE[22] = 'v';LOWE[23] = 'x';LOWE[24] = 'y';LOWE[25] = 'z';
	#endif
	pin = lpin;
	randomSeed(analogRead(pin)*millis());
}
/*****************************************************************************/

void KEYGEN::gen_pass(void* out,int size){
	char psw[size];
	int type = 0;
	for (int i = 0; i<size;i++){
		type = get_type();
		if (type == NUMS_TYPE){
			psw[i] = NUMS[random(NUMS_MAX)];
		}else if(type == SYMS_TYPE){
			psw[i] = SYMS[random(SYMS_MAX)];
		}else if (type == CAPS_TYPE){
			psw[i] = CAPS[random(CAPS_MAX)];
		}else if (type == LOWE_TYPE){
			psw[i] = LOWE[random(LOWE_MAX)];
		}
	}
	memcpy(out,psw,size);
}
/*****************************************************************************/


void KEYGEN::gen_IV(void* out,int size){
	char liv[size];
	int type= 0;
	for (int i = 0; i<size;i++){
		liv[i] = NUMS[random(NUMS_MAX)];
	}
	memcpy(out,liv,size);
}
/*****************************************************************************/

int KEYGEN::get_type(){
	return random(4);
}
/*****************************************************************************/

void KEYGEN::printArray(char output[],int sizel)
{
  for (int i = 0; i < sizel; i++)
  {
    printf_P(PSTR("%c"),output[i]);
  }
  printf_P(PSTR("\n"));
}
/*****************************************************************************/

#if defined(KEYGEN_LINUX)
double KEYGEN::millis(){
	gettimeofday(&tv, NULL);
	return (tv.tv_sec + 0.000001 * tv.tv_usec);
}

/******************************************************************************/

long  int KEYGEN::rpi_rand(int x){
	return rand() % x;
}
/******************************************************************************/
#endif
