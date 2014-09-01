CC=gcc
CFLAGS=-c -Wall -O2
LDFLAGS=
SOURCES=main.c l1.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tabsort

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o ${EXECUTABLE}


