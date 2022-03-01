#!/usr/bin/env pwsh
$ScriptVersion = "2.2.0"

# Header start
$OS = "Unknown OS"
if ($IsWindows) {
    $OS = "Windows"
} elseif ($IsMacOS) {
    $OS = "Mac OS"
} elseif ($IsLinux) {
    $OS = "Linux" + $Env:OS
}

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

# Unused values under here
# $IncludePath = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/"

# Header end

# Arguments check
$oargs = $args

function Get-Parameter([String]$param) {
    $value = ""
    for ($id = 0; $id -lt $oargs.Length; $id = $id + 1) {
        $itemraw = $oargs[$id]
        $item = $itemraw.ToString() # Make sure item is a string
        if ($item.StartsWith("-") -or $item.StartsWith("/")) {
            if($item.StartsWith("--")) {
                $item = $item.Substring(2)
            } else {
                $item = $item.Substring(1)
            }

            if ($item.Contains("=")) {
                $temp = $item.Split("=")
                $prefix = $temp[0]
                if ($prefix -eq $param) {
                    $value = $temp[1]
                }
            }

            if ($id + 1 -lt $oargs.Length -and $item.Contains(":")) {
                    #if ($oargs[$id + 1].ToString().StartsWith(":")) {
                    
                    $temp = $item.Split(":")
                    $prefix = $temp[0]
                    if ($prefix -eq $param) {
                        return $oargs[$id + 1].ToString()
                    }
            #}
            } elseif ($item.Contains(":")) {
                $temp = $item.Split(":")
                $prefix = $temp[0]
                if ($prefix -eq $param) {
                    $value = $temp[1]
                }
            }
        }
    }
    return $value
}

$PSMinVersion = 7
$PSVersion = $PSVersionTable.PSVersion.Major
if($PSVersionTable.PSVersion.Major -lt 6) {
    $PSVersionFull = $PSVersionTable.PSVersion.Major.ToString() + "." + $PSVersionTable.PSVersion.Minor.ToString() + "." + $PSVersionTable.PSVersion.Revision.ToString()
} else {
    $PSVersionFull = $PSVersionTable.PSVersion.Major.ToString() + "." + $PSVersionTable.PSVersion.Minor.ToString() + "." + $PSVersionTable.PSVersion.Patch.ToString()
}

$Location = Get-Location
$LocationPath = $Location.Path

function Compile {
    if ($PSVersion -lt $PSMinVersion) {
        Write-Red "You are using PowerShell version $PSVersionFull, which is not officially supported by this script, using PowerShell 7"
        Write-Blue "Running PowerShell 7+ to execute script..."
        $InvocationName = "./build"
        $PowerShell7Exists = Test-Path "C:\Program Files\powershell\"
        if ($PowerShell7Exists -eq $False) {
            if($IsWindows -and [System.Environment]::OSVersion.Version.Major -ge 10) {
                Write-Red "PowerShell 7 not found"
                Write-Blue "Installing PowerShell 7 using WinGet"
                WinGet install Microsoft.PowerShell
            } elseif ($IsWindows) {
                Write-Red "Unable to install PowerShell since you don't have WinGet"
            } elseif($IsLinux) {
                Write-Red "WARNING: Unable to automatically install PowerShell 7+ on linux, please install it using your package manager to continue"
            }
        }
        try {
            pwsh.exe -Command "./$InvocationName $args" 
            Write-Green 'Run "pwsh" to use PowerShell 7+'
            exit
        } catch {
            Write-Red "PowerShell 7+ doesn't seem to be installed, please install it at https://aka.ms/PSWindows to use this"
            exit
        }
    }


    Write-Green "Lmaxplay CPP build script $ScriptVersion" 'Licensed under the MIT License' 'Copyright 2022 Lmaxplay' ""

    # TODO Possibly re-add this as an argument?
    # Write-Cyan "Running on PowerShell version $PSVersionFull" ""

    
    $Wall = Get-Parameter "Wall" 
    if($Wall -eq "") {$Wall = "0"}

    $Compiler = Get-Parameter "Compiler"
    if($Compiler -eq "") {$Compiler = "0"}

    $O = Get-Parameter "O"
    if($O -eq "") {$O = "3"}

    if($Wall -eq "0") {$WallOption = ''}
    if($Wall -eq "1") {$WallOption = '-Wall'}
    Write-Cyan 'Running compiler...'

    $Compiler = Get-Parameter "compiler"
    if($Compiler -eq "") {
        $Compiler = "0"
    }

    $OOption = "-O" + "$O"

    $CompilerTimer = [Diagnostics.Stopwatch]::StartNew()
    if ($IsWindows) {
        switch($Compiler) {
        0 {
            Write-Blue "Using GCC on Windows from Chocolatey"
            # Includepath = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/"
            C:/ProgramData/Chocolatey/bin/g++.exe -std=c++20 $OOption $WallOption -I$IncludePath -o"./output/app.exe" "$LocationPath/src/main.cpp" -g
        }
        1 {
            Write-Blue "Using Clang"
            C:/"Program Files"/"Microsoft Visual Studio"/"2022"/Community/VC/Tools/Llvm/x64/bin/clang++.exe -masm=intel -std=c++20 $OOption $WallOption -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/ucrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/winrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/cppwinrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um" -I$IncludePath -o 'output/app.exe' 'src/**.cpp' 'src/lib/**.cpp'# -g
        }
        2 {
            Write-Blue "Using MSVC"
            if($O -eq "3") {$O = "2"}
            $OOption = "-O$O"
            C:/"Program Files"/"Microsoft Visual Studio"/"2022"/Community/VC/Tools/MSVC/14.30.30705/bin/Hostx64/x64/cl -Zi -DDEBUG -Fe:'output/app.exe' -std:c++20 $OOption $WallOption -nologo -I"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\include" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/ucrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/winrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/shared" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/cppwinrt" 'src/*.cpp' 'src/lib/*.cpp' -EHsc -Fo:"output/" -Fd:"output/app.output.pdb" /link -LIBPATH:'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\lib\x64' -LIBPATH:'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\lib\x64' -LIBPATH:'C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64' -LIBPATH:'C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\ucrt\x64'
        }
        3 {
            Write-Blue "Using GCC on Windows from MSYS2"
            # Includepath = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/"
            if($env:Path.Contains("C:/msys64/mingw64/bin") -eq $false) {
                $env:Path += ';C:/msys64/mingw64/bin'
            }
            C:/msys64/mingw64/bin/g++.exe -std=c++20 $OOption $WallOption -I$IncludePath -o"./output/app.exe" "$LocationPath/src/main.cpp" -g
        }
        default {
            Write-Blue "Invalid compiler, Compiler number $Compiler is not configured"
        }
    }
    } elseif ($IsLinux) {
        switch($Compiler) {
            0 {
                Write-Blue "Using GCC-11 on Linux"
                g++-11 -std=c++20 $OOption $WallOption -o 'output/app' "./src/main.cpp" -g
            }
            1 {
                Write-Blue "Using GCC-system on Linux"
                g++-11 -std=c++20 $OOption $WallOption -o 'output/app' "./src/main.cpp" -g
            }
            2 {
                Write-Blue "Using Clang on Linux"
                clang++ -std=c++20 $OOption $WallOption -iquote -I"/usr/lib/clang/10/include" -o 'output/app' "./src/main.cpp" -g
            }
            default {
                Write-Blue "$Compiler is not supported"
            }
        }
    } elseif ($IsMacOS) {
        Write-Red "Mac OS is not supported"
        exit
    } else {
        Write-Red "Could not determine OS, thus no compilation was done"
    }
    $CompilerTimer.Stop()
    $CompileTime = $CompilerTimer.Elapsed
    Write-Cyan "Compile took $CompileTime"

    $CompileOut = $LASTEXITCODE
    if($CompileOut -ne 0) {
        Write-Red "exited with error code $CompileOut"
    } else {
        Write-Cyan "Compile completed succesfully"
    }
    Write-White ""
    Set-Location $LocationPath
}

try {
    Compile
} catch {
    Write-Cyan "An error occured"
    Write-Red $Error
    $Error.Clear()
    Set-Location $LocationPath
}
