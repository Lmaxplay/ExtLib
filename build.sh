if [[ -f /usr/bin/pwsh ]]
then
    echo "PowerShell is installed"
    echo "Running build.ps1 using PowerShell"
    pwsh -Command ./build $@
else
    echo "Please install PowerShell"
    echo "To install PowerShell, run one of the following commands (based on distros):"
    echo "https://docs.microsoft.com/en-us/powershell/scripting/install/installing-powershell-on-linux"
    echo "Sorry for the inconvenience"
    echo "If you have already installed PowerShell and this message is still showing, please make an issue on GitHub"
    echo "https://github.com/Lmaxplay/ExtLib/issues"
    echo "Exiting..."
    exit 1
fi