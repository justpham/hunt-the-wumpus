#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <ncurses.h>
#include "player.h"
#include "room.h"
#include "wumpus.h"
#include "pit.h"
#include "bats.h"
#include "gold.h"

using namespace std;

class Room;
class Player;
class Wumpus;
class Pit;
class Bats;
class Gold;

class Map
{
private:
	vector<vector<Room*> > board;
	Player plyr;
	int dimension;
	int start_x;
	int start_y;
	WINDOW* win;
	WINDOW* directions;
	WINDOW* precepts;
	WINDOW* inventory;

public:
	Map();
	Map(int dim);
	~Map();
	void create_map(int dim);

	void display_map(bool);
	void display_directions();
	void display_precepts();
	void display_inventory();
	void display_inventory_2();

	void create_events();

	void clear_board();
	void move_player();

	Player& get_player();
	bool check_events();

	void fire_arrow();
	void move_wumpus();

	bool escape_rope();


};

#endif