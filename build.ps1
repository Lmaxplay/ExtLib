param(
    [Parameter(Mandatory=$False)][System.String]$Compiler = 'g++',
    [Parameter(Mandatory=$False)][System.String]$Main = 'main.cpp',
    [Parameter(Mandatory=$False)][System.Byte]$O = 3,
    [Parameter(Mandatory=$False)][System.String]$IncludePath = "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um"
)

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

    g++ $OOption -Wall -L -std=20 $IncludePath -o "output/output.exe" "src/${Main}"

} catch {
    $PreviousColor = $Host.UI.RawUI.ForegroundColor # Store previous foreground color, so we can restore it
    Write-Output "An error occured"
    $Host.UI.RawUI.ForegroundColor = 'Red'
    Write-Output "$Error"
    $Host.UI.RawUI.ForegroundColor = $PreviousColor # Restore the previous foreground color
}