CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=run-final.cc block-miner.cc block.cc transaction.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=final

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@
