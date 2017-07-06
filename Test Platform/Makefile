UNAME := $(shell uname)
CPP = g++
SUFFIX = Unknown
CPPFLAGS = -m32 -I"../OpenSteamworks"

ifeq ($(UNAME), Linux)
	LDFLAGS = -m32 -Wl,--no-as-needed -ldl ../OpenSteamAPI/lib/Linux32/OpenSteamAPI.a
	SUFFIX = Linux32
else ifeq ($(UNAME), Darwin)
	LDFLAGS = -m32 -framework Foundation ../OpenSteamAPI/lib/OSX32/OpenSteamAPI.a
	SUFFIX = OSX32
else
	UNAMEO := $(shell uname -o)
	ifeq ($(UNAMEO), Msys)
		LDFLAGS = -m32
		SUFFIX = Win32
	endif
endif

all:
	$(CPP) main.cpp $(CPPFLAGS) $(LDFLAGS) -o TestPlatform$(SUFFIX)

clean:
	unlink TestPlatform$(SUFFIX)
