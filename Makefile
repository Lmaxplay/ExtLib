Compiler = 'g++' # Compiler to use
CompilerFlags = I. # Extra flags to use
Include = "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um" # Include path
Main = 'main.cpp' # Main file
Optimization = '3'

#Compile code
compile:
	$(Compiler) -O$(Optimization) -Wall -L $(Include) -o output.exe $(Main)

#Compile code, but also run it
compilerun:
	$(Compiler) -O$(Optimization) -Wall -L $(Include) -o output.exe $(Main)
	./output.exe