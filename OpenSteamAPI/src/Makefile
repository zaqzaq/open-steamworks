UNAME := $(shell uname)
CXX = g++
FLAGS = -m32 -fPIC -O2 -c -I../../OpenSteamworks

LIBNAME = ../lib/Linux32/OpenSteamAPI.a
SRCS = CallbackManager.cpp ClientWrap.cpp Interface_OSW.cpp

ifeq ($(UNAME), Darwin)
	SRCS += OSXPathHelper.mm
endif

all: objs
	ar rcsv $(LIBNAME) *.o

objs:
	$(CXX) $(FLAGS) $(SRCS)

clean:
	rm -f *.o *.a
