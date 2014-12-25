#ifndef __KEYGEN_CONFIG_H__
#define __KEYGEN_CONFIG_H__

#define	NUMS_MAX 10
#define SYMS_MAX 21
#define CAPS_MAX 26
#define LOWE_MAX 26
#define	NUMS_TYPE 0
#define SYMS_TYPE 1
#define CAPS_TYPE 2
#define LOWE_TYPE 3

#if  (defined(__linux) || defined(linux)) && !defined(__ARDUINO_X86__)

  #define KEYGEN_LINUX

  #define analogRead(x) 1 
  #define randomSeed(x) srand(x)  
  #define random(x) rpi_rand(x)

  #include <stdint.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/time.h>
  #include <unistd.h> 
#else
  #include <Arduino.h>
#endif

#include <stdint.h>
#include <string.h>

#if defined(__ARDUINO_X86__) || (defined (__linux) || defined (linux))
	#undef PROGMEM
	#define PROGMEM __attribute__(( section(".progmem.data") ))
	#define pgm_read_byte(p) (*(p))
	typedef unsigned char byte;
	#define printf_P printf
	#define PSTR(x) (x)
#else
	#include <avr/pgmspace.h>
#endif

#endif
