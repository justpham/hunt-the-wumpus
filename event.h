#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <ncurses.h>
#include "player.h"

using namespace std;

class Player;

class Event
{
protected:
	int x_coord;
	int y_coord;
	int event_id;
public:
	Event();
	Event(int x, int y);
	virtual bool get_state() = 0;
	virtual void set_state(bool state) = 0;
	virtual bool precept(Player& player) = 0;
	virtual void encounter(Player& player) = 0;
	int get_event_id();
	void set_x(int);
	void set_y(int);
};

#endif 