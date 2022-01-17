Compiler = 'g++' # Compiler to use
CompilerFlags = "I."
Include = "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um"
Main = 'main.cpp'

compile:
	$(Compiler) -Wall -L $(Include) -o output.exe $(Main)

compilerun:
	$(Compiler) -Wall -L $(Include) -o output.exe $(Main)
	./output.exe