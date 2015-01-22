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
			timeval tv; /**< Used to get time on linux boards */
			char NUMS[NUMS_MAX+1]; /**< Hold the Numbers */
			char SYMS[SYMS_MAX+1]; /**< Holds the Symbols */
			char CAPS[CAPS_MAX+1]; /**< Holds the Caps letters */
			char LOWE[LOWE_MAX+1]; /**< Hold the Lower letters */
		#else
			char NUMS[NUMS_MAX+1] = "0123456789"; /**< Hold the Numbers */
			char SYMS[SYMS_MAX+1] = "!@#$^&*()-_=+[]<>,./:"; /**< Holds the Symbols */
			char CAPS[CAPS_MAX+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; /**< Holds the Caps letters */
			char LOWE[LOWE_MAX+1] = "abcdefghijklmnopqrstuvwxyz"; /**< Hold the Lower letters */
		#endif
		int pin; /**< Pin to gain noise from, Used for random seed */
	public:
			/**
			* Begin operation of the Algorythm and set the pin to be used for noise
			* 
			* Call this in setup(), before calling any other methods.
			* @param lpin  integer value of the pin
			* @code keyg.init(5); @endcode
			*/
			void init(int lpin);
			
			/**
			* Generate a password of specified size and stores it in the out pointer.
			* The password includes characters from types NUMS , SYMS, CAPS, LOWE
			* @note be sure that the out size is equal or greater that the size specidied.
			* @param out pointer that the generated password will be saved.
			* @param size integer value, indicating the size of the password to be generated
			* @return No return value. the generated password is stored at the out pointer
			*/
			void gen_pass(void* out,int size);
			
			/**
			* Generate an IV of specified size and stores it in the out pointer.
			* The IV is a numerical value.
			* @note be sure that the out size is equal or greater that the size specidied.
			* @param out pointer that the generated IV will be saved.
			* @param size integer value, indicating the size of the password to be generated
			* @return No return value. the generated IV is stored at the out pointer
			*/
			void gen_IV(void* out,int size);
			
			/**
			* return a random number from 0 to 3.
			* This function is mainly used from gen_pass in order to randomlly get a character from 
			* NUMS or SYMS  or CAPS or LOWE
			* 
			* @return returns an interger from 0 to 3
			*/
			int get_type();
			
			/**
			* Gets an array and its size and prints it in the standard output character by character.
			* 
			* @param output[] array of any size.
			* @param sizel integer values indicating the size of the array.
			* @return No return value.
			*/
			void printArray(char output[],int sizel);
			#if defined(KEYGEN_LINUX)
				/**
				* used in linux in order to retrieve the time in milliseconds.
				*
				* @return returns the milliseconds in a double format.
				*/
				double millis();
				
				/**
				* used in Raspberry pi in order to generate a random number.
				* 
				* @note there is a definition in KEYGEN_config that defined random(x) as rpi_rand(x).
				* @param x get an integer that is te upper limit-1 of the random number.
				* @return returns a random number from 0 to x
				*/
				long int rpi_rand(int x);
			#endif
};

/**
 * @example RANDOM.ino
 * <b>For Arduino</b><br>
 * <b>Updated: spaniakos 2015 </b><br>
 *
 * This is an example of hot to generate passwords and IVs of varius sizes
 */

/**
 * @example RANDOM.cpp
 * <b>For Raspberry Pi</b><br>
 * <b>Updated: spaniakos 2015 </b><br>
 *
 * This is an example of hot to generate passwords and IVs of varius sizes
 * @note Tere is a definiton in KEYGEN_config that defined #define analogRead(x) 1, so it has less entropy that Arduino. 
 */

/**
 * @mainpage Library for Generating random passwords and IVs of various sizes.
 *
 * @section Goals Design Goals
 *
 * This library is designed to be...
 * @li Fast and efficient
 * @li Able to generate high entropy passwords and numerical IVs
 *
 * @section News News
 *
 * If issues are discovered with the documentation, please report them <a href="https://github.com/spaniakos/spaniakos.github.io/issues"> here</a>
 * @section Useful Useful References
 *
 * Please refer to:
 *
 * @li <a href="http://spaniakos.github.io/KEYGEN/classKEYGEN.html"><b>KEYGEN</b> Class Documentation</a>
 * @li <a href="https://github.com/spaniakos/KEYGEN/archive/master.zip"><b>Download</b></a>
 * @li <a href="https://github.com/spaniakos/KEYGEN/"><b>Source Code</b></a>
 * @li <a href="http://spaniakos.github.io/">All spaniakos Documentation Main Page</a>
 *
 * @section Board_Support Board Support
 *
 * Most standard Arduino based boards are supported:
 * - Arduino
 * - Intel Galileo support
 * - Raspberry Pi Support
 * 
 * - The library has not been tested to other boards, but it should suppport ATMega 328 based boards,Mega Boards,Arduino Due,ATTiny board
 */

#endif //Keygen


