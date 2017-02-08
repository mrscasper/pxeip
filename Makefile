EXECUTABLE=pxeip
SOURCES=pxeip.cpp

# Standard C++ stuff, change it only if you need to
CC=g++
CFLAGS=-c -std=c++11 -Wall
LDFLAGS=
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	/bin/rm -f *~
	/bin/rm -f $(EXECUTABLE) $(OBJECTS)
