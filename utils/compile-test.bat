rem Compile the executable from the sources
rem ---------------------------------------
rem Compilation used for test:
rem ---------------------------------------
gcc -Wall -O3 -m32 ../bb-keylogger.c ../bb-keylogger-file.c ../bb-keylogger-keyboard.c ../bb-keylogger-system.c -o ../bin-test/bb-keylogger-32bits.exe