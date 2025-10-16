/******************************************************
** Program: gold.cpp
** Author: Justin Pham
** Date: 11/19/2022
** Description: gold Event
** Input: N/A
** Output: Output event precepts and encounter depending on which event it is
** Description: Does not have an AOO or CC because it will never be used
** nor will it need to copy a pointer
** Destructor is not here because all values are on the stack
******************************************************/

#include "gold.h"

using namespace std;

class Gold;
class Player;

Gold::Gold():Event()
/*********************************************************************
** Function: __()
** Description: Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: New object is created
*********************************************************************/
{
	this->event_id = 4;
	this->collected = false;
}

Gold::Gold(int x, int y) : Event(x, y)
/*********************************************************************
** Function: Gold( )
** Description: Non Default Constructor
** Parameters: x, y
** Pre-Conditions: Parameters are inputted
** Post-Conditions: New object is created
*********************************************************************/
{
	this->event_id = 4;
	this->collected = false;
}

bool Gold::get_state()
/*********************************************************************
** Function: get_state()
** Description: gets state
** Parameters: N/A
** Pre-Conditions: state exists
** Post-Conditions: Returns state
*********************************************************************/
{
	return this->collected;
}

void Gold::set_state(bool state)
/*********************************************************************
** Function: set_state()
** Description: sets state
** Parameters: state
** Pre-Conditions: state exists
** Post-Conditions: sets state
*********************************************************************/
{
	this->collected = state;
}


bool Gold::precept(Player& player)
/*********************************************************************
** Function: precept
** Description: checks player location for percept
** Parameters: player
** Pre-Conditions: player
** Post-Conditions: return true or false depending on player location
*********************************************************************/
{
	if (this->collected == true)
	{
		return false;
	}

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


void Gold::encounter(Player& player)
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
		player.set_gold(true);
		this->collected = true;
	}
}
