#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <ncurses.h>
#include "player.h"
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std;

class Player;
class Event;

class Room
{
private:
	Event* evnt;
	bool evnt_state;
	int x_coord;
	int y_coord;
public:
	Room();
	Room(int x, int y);
	~Room();
	string map_room(bool debug, Player& player);
	bool get_event_state();
	int get_x_coord();
	int get_y_coord();
	Event* get_event();
	void set_event(int i, int dimension);
	void delete_wumpus();
};


#endif