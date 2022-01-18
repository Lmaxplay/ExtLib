# Compiler to use
Compiler = 'g++'

# Compiler flags
CompilerFlags = I.

# Include path
Include = "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um"

# Path for source
SourcePath = ./src/

# Main file
Main = main.cpp

# Output folder
OutputPath = ./output/

# Optimization level
Optimization = '3'

#Compile code
compile:
	$(Compiler) -std=c++20 -O$(Optimization) -Wall -L $(Include) -o '$(OutputPath)output.exe' '$(SourcePath)$(Main)'
	cp -r ./src/data ./output/
