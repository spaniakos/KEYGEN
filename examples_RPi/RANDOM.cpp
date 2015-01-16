#include <KEYGEN.h>
#include "./printf.h"

KEYGEN keyg;

int main(int argc, char** argv) {
  printf_begin();  

  printf("\n============================================\n");
  printf(" Password Generation sample for Arduino/Raspberry pi\n");
  printf("============================================\n");
  keyg.init(5);
  
  while(1){
	char psw_8[8];
	char psw_16[16];
	char IV_8[8];
	char IV_16[16];
	printf("\n===========8 char sample for password===========\n");
	keyg.gen_pass(psw_8,8);
	keyg.printArray(psw_8,8);
	printf("\n===========16 char sample for password===========\n");
	keyg.gen_pass(psw_16,16);
	keyg.printArray(psw_16,16);
	printf("\n===========8 char sample for IV===========\n");
	keyg.gen_IV(IV_8,8);
	keyg.printArray(IV_8,8);
	printf("\n===========16 char sample for IV===========\n");
	keyg.gen_IV(IV_16,16);
	keyg.printArray(IV_16,16);
	sleep(2);
 }
}
