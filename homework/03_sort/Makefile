SRCS = InsertionSort.cpp MergeSort.cpp QuickSort.cpp SelectionSort.cpp ItemType.cpp sortMenu.cpp submitty_driver.cpp
EXE = a.out
SUBMITTY_CXXFLAGS = -I.

ifneq ("$(wildcard SortDriver.cpp)","")
	# Code.CS student settings
	SRCS = InsertionSort.cpp MergeSort.cpp QuickSort.cpp SelectionSort.cpp ItemType.cpp sortMenu.cpp SortDriver.cpp
	EXE = Sort.out
else ifneq ("$(submitty_driver.cpp)","")
	# Submitty submission
    # Do nothing. Leave defaults.
else
    # Code.CS TA settings
    SRCS = ../InsertionSort.cpp ../MergeSort.cpp ../QuickSort.cpp ../SelectionSort.cpp ItemType.cpp sortMenu.cpp submitty_driver.cpp
    SUBMITTY_CXXFLAGS = -I.. -I.
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
