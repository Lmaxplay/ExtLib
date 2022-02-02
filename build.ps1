param(
    [Parameter(Mandatory=$False)][System.String]$Main = 'main.cpp',
    [Parameter(Mandatory=$False)][System.Byte]$Wall = 0,
    [Parameter(Mandatory=$False)][System.Byte]$Compiler = 1,
    [Parameter(Mandatory=$False)][System.Byte]$O = 3,
    [Parameter(Mandatory=$False)][System.String]$IncludePath = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um"
)

# MSVC is C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.30.30705/bin/Hostx64/x64/cl
# Clang is C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/bin/clang++.exe

$PreviousColor = 'White'
$Host.UI.RawUI.ForegroundColor = $PreviousColor

function Write-Green {
    $Host.UI.RawUI.ForegroundColor = 'Green'
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Yellow {
    $Host.UI.RawUI.ForegroundColor = 'Yellow'
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Red {
    $Host.UI.RawUI.ForegroundColor = 'Red'
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Purple {
    $Host.UI.RawUI.ForegroundColor = 'DarkMagenta'
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Magenta {
    $Host.UI.RawUI.ForegroundColor = 'Magenta'
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-White {
    $Host.UI.RawUI.ForegroundColor = 'White'
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Black {
    $Host.UI.RawUI.ForegroundColor = "Black"
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Cyan {
    $Host.UI.RawUI.ForegroundColor = "Cyan"
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Blue {
    $Host.UI.RawUI.ForegroundColor = "Blue"
    Write-Output $args
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

try {
    Write-Green 'Lmaxplay CPP build script v1.1.3' 'Licensed under the MIT License' 'Copyright 2022 Lmaxplay'

    $OOption = "-O3"

    if($O -eq 0) {$OOption = '-O0'}
    if($O -eq 1) {$OOption = '-O1'}
    if($O -eq 2) {$OOption = '-O2'}
    if($O -eq 3) {$OOption = '-O3'}
    if($O -eq 4) {$OOption = '-OFast'}

    if($Wall -eq 0) {$WallOption = ''}
    if($Wall -eq 1) {$WallOption = '-Wall'}
    Write-Yellow 'Running compiler...'

    $CompilerTimer = [Diagnostics.Stopwatch]::StartNew()
    if ($Compiler -eq 0) {
        Write-Blue "Using Clang/Clang++"
        C:/"Program Files"/"Microsoft Visual Studio"/"2022"/Community/VC/Tools/Llvm/x64/bin/clang++.exe -masm=intel -std=c++20 $OOption $WallOption -I$IncludePath -o 'output/app.exe' 'src/*.cpp' 'src/lib/*.cpp' -g
    } elseif ($Compiler -eq 1) {
        Write-Blue "Using GCC/G++"
        g++ -std=c++20 $OOption $WallOption -I$IncludePath -o'output/app.exe' 'src/**.cpp' 'src/lib/*.cpp' -g
    } elseif ($Compiler -eq 2) {
        Write-Blue "Using MSVC"
        C:/"Program Files"/"Microsoft Visual Studio"/"2022"/Community/VC/Tools/MSVC/14.30.30705/bin/Hostx64/x64/cl -Zi -DDEBUG -Fe:'output/app.exe' -std:c++20 $OOption $WallOption -nologo -I"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\include" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/ucrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/winrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/shared" 'src/*.cpp' 'src/lib/*.cpp' -EHsc -Fo:"output/" -Fd:"output/app.output.pdb" /link -LIBPATH:'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\lib\x64' -LIBPATH:'C:\Program Files\Microsoft Visual Studio\2022\Community\SDK\ScopeCppSDK\vc15\SDK\lib'
    } else {
        Write-Blue "Invalid compiler, Compiler number $Compiler is not configured"
    }
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