#ifndef GOLD_H
#define GOLD_H

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

class Gold : public Event
{
private: 
	bool collected;
public:
	Gold();
	Gold(int x, int y);
	bool get_state();
	void set_state(bool state);
	bool precept(Player& player);
	void encounter(Player& player);
};

#endif 