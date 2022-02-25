build:
ifdef OS
	@pwsh -Command ./build.ps1 $(ARGS)
else
ifneq ("$(whereis pwsh)", "pwsh:")
	@pwsh -Command ./build.ps1 $(ARGS)
else
	wget -q https://packages.microsoft.com/config/ubuntu/20.04/packages-microsoft-prod.deb
	dpkg -i packages-microsoft-prod.deb
	rm packages-microsoft-prod.deb
	apt-get install pwsh
endif
endif

run: build
	output/app.exe