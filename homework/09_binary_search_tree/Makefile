SRCS = QueType.cpp TreeDriver.cpp TreeType.cpp CountNodes.cpp submitty_driver.cpp
EXE = a.out
SUBMITTY_CXXFLAGS = -I.

ifneq ("$(wildcard TreeDriver.cpp)","")
	# Code.CS student settings (put student driver filename)
	SRCS = TreeDriver.cpp TreeMenu.cpp CountNodes.cpp QueType.cpp TreeType.cpp
	EXE = Tree.out
else ifneq ("$(wildcard CountNodes.cpp)","")
	# Submitty submission (put one of the student submission filenames)
    # Do nothing. Leave defaults.
else
	# Homework library settings
	SRCS = TreeMenu.cpp QueType.cpp TreeType.cpp ../CountNodes.cpp submitty_driver.cpp
endif

# Everything below that should not have to change ever.

CXX=g++
LD=g++
CC=g++

TARGET = all 

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g -std=c++17 $(SUBMITTY_CXXFLAGS)

LDFLAGS = -g 
LIBS =

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS) $(LIBS)

.SUFFIXES: .cpp

.cpp.o:  
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(EXE)

clean:
	-rm -f $(OBJS)
	-rm -f $(EXE)
	-rm -f solutions.txt