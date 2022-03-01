build:
ifdef OS
	@pwsh -Command ./build.ps1 $(ARGS)
else
ifneq ("$(whereis pwsh)", "pwsh:")
	@pwsh -Command ./build.ps1 $(ARGS)
else
	@echo PowerShell not found
#	@echo Installing PowerShell on ubuntu... (if you have a different distro, follow instructions on microsofts site to install PowerShell)
#	wget -q https://packages.microsoft.com/config/ubuntu/20.04/packages-microsoft-prod.deb
#	dpkg -i packages-microsoft-prod.deb
#	rm packages-microsoft-prod.deb
endif
endif

run: build
	output/app.exe