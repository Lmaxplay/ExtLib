param(
    [Parameter(Mandatory=$False)][System.String]$Compiler = 'C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/bin/clang++.exe',
    [Parameter(Mandatory=$False)][System.String]$Main = 'main.cpp',
    [Parameter(Mandatory=$False)][System.Byte]$Wall = 0,
    [Parameter(Mandatory=$False)][System.Byte]$O = 3,
    [Parameter(Mandatory=$False)][System.String]$IncludePath = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um"
)

# MSVC is C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.30.30705/bin/Hostx64/x64/cl
# Clang is C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/bin/clang++.exe

$PreviousColor = 'White'
$Host.UI.RawUI.ForegroundColor = $PreviousColor

function Write-Green {
    $Host.UI.RawUI.ForegroundColor = 'Green'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Yellow {
    $Host.UI.RawUI.ForegroundColor = 'Yellow'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Red {
    $Host.UI.RawUI.ForegroundColor = 'Red'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Purple {
    $Host.UI.RawUI.ForegroundColor = 'DarkMagenta'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Magenta {
    $Host.UI.RawUI.ForegroundColor = 'Magenta'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-White {
    $Host.UI.RawUI.ForegroundColor = 'White'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Black {
    $Host.UI.RawUI.ForegroundColor = "Black"
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Cyan {
    $Host.UI.RawUI.ForegroundColor = "Cyan"
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-DarkBlue {
    $Host.UI.RawUI.ForegroundColor = "DarkBlue"
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

try {
    Write-Green 'Lmaxplay CPP build script v0.9.2' 'Licensed under the MIT License' 'Copyright 2022 Lmaxplay' # TODO Update this bit to be more informative

    $OOption = "-O3"

    if($O -eq 0) {$OOption = '-O0'}
    if($O -eq 1) {$OOption = '-O1'}
    if($O2 -eq 2) {$OOption = '-O2'}
    if($O3 -eq 3) {$OOption = '-O3'}
    if($O3 -eq 4) {$OOption = '-OFast'}

    if($Wall -eq 0) {$WallOption = ''}
    if($Wall -eq 1) {$WallOption = '-Wall'}
    Write-Yellow 'Running compiler...'

    $CompilerTimer = [Diagnostics.Stopwatch]::StartNew()
    C:/"Program Files"/"Microsoft Visual Studio"/"2022"/Community/VC/Tools/Llvm/x64/bin/clang++.exe -masm=intel -std=c++20 $OOption $WallOption -I$IncludePath -o 'output/app.exe' 'src/*.cpp' 'src/lib/*.cpp' -g
    $CompilerTimer.Stop()
    $CompileTime = $CompilerTimer.Elapsed
    Write-Yellow "Compile took $CompileTime"

    $CompileOut = $LASTEXITCODE
    if($CompileOut -ne 0) {
        Write-Red "exited with error code $CompileOut"
    } else {
        Write-Yellow "Compile completed succesfully"
    }
    Write-Output ""

} catch {
    $PreviousColor = $Host.UI.RawUI.ForegroundColor # Store previous foreground color, so we can restore it
    Write-Output "An error occured"
    Write-Red "$Error"
}