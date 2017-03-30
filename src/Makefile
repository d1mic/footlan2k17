CC=g++
CFLAGS= -c -Wall -std=c++0x
LDFLAGS=
LIBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = main.cpp Game.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=/usr/bin

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)
clean:
	rm *.o $(EXECUTABLE)

.PHONY: all clean .cpp.o


install:
	#install -s $(EXECUTABLE) $(BINDIR)
	#sudo cp -u $(EXECUTABLE) $(BINDIR)
#uninstall:
	#sudo rm $(BINDIR)/$(EXECUTABLE)

#	za svaki slucaj:	g++ main.cpp -lsfml-window -lsfml-system -lsfml-graphics
