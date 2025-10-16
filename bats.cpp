/******************************************************
** Program: bats.cpp
** Author: Justin Pham
** Date: 11/19/2022
** Description: Bat Event
** Input: N/A
** Output: Output event precepts and encounter depending on which event it is
** Description: Does not have an AOO or CC because it will never be used
** nor will it need to copy a pointer
** Destructor is not here because all values are on the stack
******************************************************/


#include "bats.h"

class Bats;
class Event;
class Player;

Bats::Bats() :Event()
/*********************************************************************
** Function: Bats()
** Description: Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: New object is created
*********************************************************************/
{
	this->event_id = 2;
}

Bats::Bats(int x, int y, int dimension) :Event(x, y)
/*********************************************************************
** Function: Bats( )
** Description: Non Default Constructor
** Parameters: x, y, dimension
** Pre-Conditions: Parameters are inputted
** Post-Conditions: New object is created
*********************************************************************/
{
	this->event_id = 2;
	this->dimension = dimension;
}

bool Bats::precept(Player& player)
/*********************************************************************
** Function: precept
** Description: checks player location for percept
** Parameters: player
** Pre-Conditions: player
** Post-Conditions: return true or false depending on player location
*********************************************************************/
{
	if
	(
	(this->x_coord == player.get_x_coord()) && ((this->y_coord == (player.get_y_coord() + 1)) || (this->y_coord == (player.get_y_coord() - 1)))
	||
	(this->y_coord == player.get_y_coord()) && ((this->x_coord == (player.get_x_coord() + 1)) || (this->x_coord == (player.get_x_coord() - 1)))
	||
	(this->x_coord == (player.get_x_coord() + 1) && ((this->y_coord == (player.get_y_coord() + 1)) || (this->y_coord == (player.get_y_coord() - 1))))
	||
	(this->x_coord == (player.get_x_coord() - 1) && ((this->y_coord == (player.get_y_coord() + 1)) || (this->y_coord == (player.get_y_coord() - 1))))
	) 
	{
		return true;
	}

	return false;
}


void Bats::encounter(Player& player) 
/*********************************************************************
** Function: encounter
** Description: checks player location for encounter
** Parameters: player
** Pre-Conditions: player
** Post-Conditions: does the encounter depending on event type
*********************************************************************/
{
	if (this->x_coord == player.get_x_coord() && this->y_coord == player.get_y_coord())
	{
		player.set_x_coord(rand() % this->dimension); // Sends player to random x
		player.set_y_coord(rand() % this->dimension); // Sends player to random y
	}
}

bool Bats::get_state()
/*********************************************************************
** Function: get_state()
** Description: gets state
** Parameters: N/A
** Pre-Conditions: state exists
** Post-Conditions: Returns state
*********************************************************************/
{
	return true;
}

void Bats::set_state(bool state)
/*********************************************************************
** Function: set_state()
** Description: sets state
** Parameters: N/A
** Pre-Conditions: state exists
** Post-Conditions: sets state
*********************************************************************/
{
	// Nothing
}
