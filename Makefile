CC = 'g++'
CFLAGS = "I."
INCLUDEPATH = "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um"

compile:
	$(CC) -Wall -L $(INCLUDEPATH) -o output.exe main.cpp