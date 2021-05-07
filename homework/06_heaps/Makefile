SRCS = PriorityQueueMenu.cpp submitty_driver.cpp
EXE = a.out
SUBMITTY_CXXFLAGS = -I.

ifneq ("$(wildcard PriorityQueueDriver.cpp)","")
	# Code.CS student settings (put student driver filename)
    SRCS = PriorityQueueMenu.cpp PriorityQueueDriver.cpp
	EXE = Queue.out
else ifneq ("$(wildcard reheap.tpp)","")
	# Submitty submission (put one of the student submission filenames)
    # Do nothing. Leave defaults.
else
	# Homework library settings
	SUBMITTY_CXXFLAGS = -I. -I..
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
	-rm $(OBJS)
	-rm $(EXE)
	-rm -f solutions.txt
