SRCS = BinarySearch.cpp LinearSearch.cpp ItemType.cpp searchMenu.cpp submitty_driver.cpp
EXE = a.out


ifneq ("$(wildcard SearchDriver.cpp)","")
	# Code.CS student settings
	SRCS = BinarySearch.cpp LinearSearch.cpp ItemType.cpp searchMenu.cpp SearchDriver.cpp
	EXE = Search.out
else ifneq ("$(wildcard BinarySearch.cpp LinearSearch.cpp)","")
	# Submitty submission
    # Do nothing. Leave defaults.
else
    # Code.CS TA settings
    SRCS = ../BinarySearch.cpp ../LinearSearch.cpp ItemType.cpp searchMenu.cpp submitty_driver.cpp
endif

# Everything below this should not have to change ever.

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
