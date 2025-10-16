CC=g++ -std=c++11 -g -lncurses
EXE_FILE = htw

all: $(EXE_FILE)

$(EXE_FILE):  driver.cpp player.o player.h universal.o universal.h room.o room.h event.o event.h bats.o bats.h pit.o pit.h wumpus.o wumpus.h gold.o gold.h map.o map.h
	$(CC) universal.o room.o event.o bats.o pit.o wumpus.o gold.o map.o player.o  driver.cpp -o $(EXE_FILE)

player.o: player.cpp player.h
	$(CC) -c player.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

map.o: map.cpp map.h
	$(CC) -c map.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

pit.o: pit.cpp pit.h
	$(CC) -c pit.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

universal.o: universal.cpp universal.h
	$(CC) -c universal.cpp

clean:
	rm -f *.o $(EXE_FILE)