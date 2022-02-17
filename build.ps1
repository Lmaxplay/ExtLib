# param(
#     [Parameter(Mandatory=$False)][System.String]$Main = 'main.cpp',
#     [Parameter(Mandatory=$False)][System.Byte]$Wall = 0,
#     [Parameter(Mandatory=$False)][System.Byte]$Compiler = 0,
#     [Parameter(Mandatory=$False)][System.String]$O = "3",
#     [Parameter(Mandatory=$False)][System.String]$IncludePath = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/"
# )

$ScriptVersion = "2.0.0"

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

Write-White $oargs

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

try {
    if ($PSVersion -lt 7) {
        Write-Red "This version of powershell is not supported, please use Powershell version $PSMinVersion or higher" "You are using Powershell version $PSVersionFull"
        exit
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
    Write-Magenta $CompilerParam
    $OOption = "-O" + "$O"

    $CompilerTimer = [Diagnostics.Stopwatch]::StartNew()
    if ($IsWindows) {
        if ($Compiler -eq 0) {
            Write-Blue "Using Clang"
            C:/"Program Files"/"Microsoft Visual Studio"/"2022"/Community/VC/Tools/Llvm/x64/bin/clang++.exe -masm=intel -std=c++20 $OOption $WallOption -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/ucrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/winrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/cppwinrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um" -I$IncludePath -o 'output/app.exe' 'src/**.cpp' -g
        } elseif ($Compiler -eq 1) {
            Write-Blue "Using GCC on Windows from MSYS2"
            # Includepath = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/"
            if($env:Path.Contains("C:/msys64/mingw64/bin") -eq $false) {
                $env:Path += ';C:/msys64/mingw64/bin'
            }
            g++.exe -std=c++20 $OOption $WallOption -I$IncludePath -o"./output/app.exe" "$LocationPath/src/main.cpp" -g
        } elseif ($Compiler -eq 2) {
            Write-Blue "Using MSVC"
            if($O -eq "3") {$O = "2"}
            $OOption = "-O$O"
            C:/"Program Files"/"Microsoft Visual Studio"/"2022"/Community/VC/Tools/MSVC/14.30.30705/bin/Hostx64/x64/cl -Zi -DDEBUG -Fe:'output/app.exe' -std:c++20 $OOption $WallOption -nologo -I"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\include" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/ucrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/winrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/shared" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/cppwinrt" 'src/*.cpp' 'src/lib/*.cpp' -EHsc -Fo:"output/" -Fd:"output/app.output.pdb" /link -LIBPATH:'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\lib\x64' -LIBPATH:'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\lib\x64' -LIBPATH:'C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\um\x64' -LIBPATH:'C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22000.0\ucrt\x64'
        } else {
            Write-Blue "Invalid compiler, Compiler number $Compiler is not configured"
        }
    } elseif ($IsLinux) {
        if ($Compiler -eq 0) {
            Write-Blue "Using GCC on Linux"
            g++-11 -std=c++20 $OOption $WallOption -o 'output/app' 'src/main.cpp' -g
        } else {
            Write-Blue "$Compiler is not supported"
        }
    } elseif ($IsMacOS) {
        Write-Red "Mac OS is not supported"
        exit
    } else {
        Write-Red "Could not determine OS, thus no compilation executed"
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

} catch {
    Write-Cyan "An error occured"
    Write-Red $Error
    $Error.Clear()
    Set-Location $LocationPath
}