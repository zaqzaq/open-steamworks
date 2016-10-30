UNAME := $(shell uname)
CPP = g++
SUFFIX = Unknown
CPPFLAGS = -m32 -I"../Open Steamworks"

ifeq ($(UNAME), Linux)
	LDFLAGS = -m32
	SUFFIX = Linux32
else ifeq ($(UNAME), Darwin)
	LDFLAGS = -m32
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
