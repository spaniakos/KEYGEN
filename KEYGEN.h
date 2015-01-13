/*
 Copyright (C) 2014 G. Spanos <spaniakos@gmail.com

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

/**
 * @file KEYGEN.h
 *
 * Class declaration for KeyGenerator
 */

#ifndef __KEYGEN_H__
#define __KEYGEN_H__

#include "KEYGEN_config.h"

class KEYGEN{	
	private:
		#if defined(KEYGEN_LINUX)
			timeval tv;
			char NUMS[NUMS_MAX+1];
			char SYMS[SYMS_MAX+1];
			char CAPS[CAPS_MAX+1];
			char LOWE[LOWE_MAX+1];
		#else
			char NUMS[NUMS_MAX+1] = "0123456789";
			char SYMS[SYMS_MAX+1] = "!@#$^&*()-_=+[]<>,./:";
			char CAPS[CAPS_MAX+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			char LOWE[LOWE_MAX+1] = "abcdefghijklmnopqrstuvwxyz";
		#endif
		int pin;
	public:
			void init(int lpin);
			void gen_pass(void* out,int size);
			void gen_IV(void* out,int size);
			int get_type();
			void printArray(char output[],int sizel);
			#if defined(KEYGEN_LINUX)
				double millis();
				long int rpi_rand(int x);
			#endif
};
#endif //Keygen


