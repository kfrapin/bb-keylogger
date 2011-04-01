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
* File containing the declarations of all the functions used to retrieve 
* informations from the keyboard.
* -----------------------------------------------------------------------------
*/

#ifndef BB_KEYLOGGER_KEYBOARD_H
#define BB_KEYLOGGER_KEYBOARD_H

//------------------------------------------------------------- INCLUDES SYSTEM
#include <stdio.h>

//------------------------------------------------------------------- FUNCTIONS

void log_alphabetic_keystrokes( FILE * log_file );
void log_keystrokes( FILE * log_file );
void log_mathematical_operators_keystrokes( FILE * log_file );
void log_numeric_keystrokes( FILE * log_file, char * keyboard_state );
void log_others_keystrokes( FILE * log_file );
void log_stream_keystrokes( FILE * log_file );


#endif /* BB_KEYLOGGER_KEYBOARD_H */