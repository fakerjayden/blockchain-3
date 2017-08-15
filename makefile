#forUbuntu
#CC=g++
#CFLAGS=-c -Wall -std=c++11 
#forMacbook
CC=clang++
CXXFLAGS=-std=c++11 -stdlib=libc++
LDFLAGS=
SOURCES=run-final.cc block-miner.cc block.cc transaction.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=final

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(SOURCES) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@
