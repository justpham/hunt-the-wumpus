#ifndef BATS_H	
#define BATS_H

#include "universal.h"
#include "event.h"

using namespace std;

class Event;
class Player;

class Bats : public Event
{
private:
	int dimension;
public:
	Bats();
	Bats(int x, int y, int dimension);
	bool get_state();
	void set_state(bool state);
	bool precept(Player& player);
	void encounter(Player& player);
};

#endif