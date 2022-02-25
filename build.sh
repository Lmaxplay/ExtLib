if [[ -f /usr/bin/pwsh ]]
then
    pwsh -Command ./build $@
else
    [ "$UID" -eq 0 ] || exec sudo bash "$0" "$@"
    wget -q https://packages.microsoft.com/config/ubuntu/20.04/packages-microsoft-prod.deb
    dpkg -i packages-microsoft-prod.deb
    rm packages-microsoft-prod.deb
    apt-get install pwsh
fi