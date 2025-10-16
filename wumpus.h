#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <ncurses.h>
#include "event.h"

using namespace std;

class Event;
class Player;

class Wumpus : public Event
{
private:
	bool alive;

public:
	Wumpus();
	Wumpus(int x, int y);
	bool get_state();
	void set_state(bool state);
	bool precept(Player& player);
	void encounter(Player& player);
};

#endif 