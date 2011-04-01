rem Compile the executable from the sources
gcc -Wall -O3 -m32 ../main.c ../bb-keylogger-utils.c ../bb-keylogger-keyboard.c ../bb-keylogger-system.c -o ../bin/bb-keylogger-32bits.exe