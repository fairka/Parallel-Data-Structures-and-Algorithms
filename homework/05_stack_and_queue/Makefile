SRCS = StackType.cpp QueueType.cpp QueueMenu.cpp submitty_driver.cpp
EXE = a.out
SUBMITTY_CXXFLAGS = -I.

ifneq ("$(wildcard QueueDriver.cpp)","")
	# Code.CS settings
	SRCS = StackType.cpp QueueType.cpp QueueMenu.cpp QueueDriver.cpp
	EXE = Queue.out
else ifneq ("$(wildcard QueueType.cpp)","")
	# Submitty setting -- no changes
else
	# Homework library settings
	SRCS = StackType.cpp ../QueueType.cpp QueueMenu.cpp submitty_driver.cpp
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
	-rm solutions.txt
