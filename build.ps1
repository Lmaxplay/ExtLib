param(
    [Parameter(Mandatory=$False)][System.String]$Compiler = 'g++',
    [Parameter(Mandatory=$False)][System.String]$Main = 'main.cpp',
    [Parameter(Mandatory=$False)][System.Byte]$Wall = 0,
    [Parameter(Mandatory=$False)][System.Byte]$O = 3,
    [Parameter(Mandatory=$False)][System.String]$IncludePath = "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um"
)

function Write-Green {
    $PreviousColor = $Host.UI.RawUI.ForegroundColor # Store previous foreground color, so we can restore it
    $Host.UI.RawUI.ForegroundColor = 'Green'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Yellow {
    $PreviousColor = $Host.UI.RawUI.ForegroundColor # Store previous foreground color, so we can restore it
    $Host.UI.RawUI.ForegroundColor = 'Yellow'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

function Write-Red {
    $PreviousColor = $Host.UI.RawUI.ForegroundColor # Store previous foreground color, so we can restore it
    $Host.UI.RawUI.ForegroundColor = 'Red'
    Write-Output $args # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color    
}

try {

    $PreviousColor = $Host.UI.RawUI.ForegroundColor # Store previous foreground color, so we can restore it
    $Host.UI.RawUI.ForegroundColor = 'Green'
    Write-Output 'Lmaxplay CPP build script v0.9.0' 'Licensed under the MIT License' 'Copyright 2022 Lmaxplay' # TODO Update this bit to be more informative
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color
    
    $OOption = "-O3"

    if($O -eq 0) {$OOption = '-O0'}
    if($O -eq 1) {$OOption = '-O1'}
    if($O2 -eq 2) {$OOption = '-O2'}
    if($O3 -eq 3) {$OOption = '-O3'}
    if($O3 -eq 4) {$OOption = '-OFast'}

    if($Wall -eq 0) {$WallOption = ''}
    if($Wall -eq 1) {$WallOption = '-Wall'}
    Write-Yellow 'Running G++ compiler...'

    $CompilerTimer = [Diagnostics.Stopwatch]::StartNew()
    g++ -m64 -std=c++20 $OOption $WallOption -L $IncludePath -o "output/app.exe" "src/*.cpp" "src/lib/*.cpp"
    $CompilerTimer.Stop()
    $CompileTime = $CompilerTimer.Elapsed
    Write-Yellow "Compile took $CompileTime"

    $CompileOut = $LASTEXITCODE
    if($CompileOut -ne 0) {
        Write-Red "G++ exited with error code $CompileOut"
    } else {
        Write-Yellow "G++ Compile completed succesfully"
    }

    Copy-Item -Force -Recurse './src/data' './output/' 

} catch {
    $PreviousColor = $Host.UI.RawUI.ForegroundColor # Store previous foreground color, so we can restore it
    Write-Output "An error occured"
    $Host.UI.RawUI.ForegroundColor = 'Red'
    Write-Output "$Error"
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color
}