/******************************************************
** Program: room.cpp
** Author: Justin Pham
** Date: 11/19/2022
** Description: holds all the room information and functions
** Input: N/A
** Output: all room information
** Description: Does not have an AOO or CC because it will never be used
** nor will it need to copy a pointer
******************************************************/


#include "room.h"

using namespace std;

class Room;
class Player;
class Bats;
class Pit;
class Gold;
class Wumpus;

Room::Room()
/*********************************************************************
** Function: Room()
** Description: Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: New object is created
*********************************************************************/
{
	this->evnt = NULL;
	this->evnt_state = false;
	this->x_coord = -1;
	this->y_coord = -1;
}

Room::Room(int x, int y)
/*********************************************************************
** Function: Room()
** Description: Non Default Constructor
** Parameters: x, y
** Pre-Conditions: Parameters are inputted
** Post-Conditions: New object is created
*********************************************************************/
{
	this->x_coord = x;
	this->y_coord = y;
	this->evnt_state = false;
	this->evnt = NULL;
}

Room::~Room()
/*********************************************************************
** Function: Room()
** Description: Destructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: The object is deleted
*********************************************************************/
{
	if (this->evnt != NULL)
	{
		delete this->evnt;
		this->evnt = NULL;
	}
}

string Room::map_room(bool debug, Player& player)
/*********************************************************************
** Function: map_room()
** Description: Converts room information into printable string
** Parameters: debug mode, player
** Pre-Conditions: a room must exist
** Post-Conditions: returns a string depending on parameters
*********************************************************************/
{
	if (debug)
	{
		if (player.get_x_coord() == this->x_coord && player.get_y_coord() == this->y_coord) // Player
		{
			return "  T  |";
		}
		else if (this->evnt != NULL)
		{
			if (this->evnt->get_event_id() == 1 && (this->evnt->get_state() == true)) // Wumpus
			{
				return "  W  |";
			}
			else if (this->evnt->get_event_id() == 2) // Bats
			{
				return "  B  |";
			}
			else if (this->evnt->get_event_id() == 3) // Pit
			{
				return "  P  |";
			}
			else if (this->evnt->get_event_id() == 4 && (this->evnt->get_state() == false)) // Gold
			{
				return "  $  |";
			}
			else
			{
				return "     |"; // nothing
			}
		}
		else
		{
			return "     |";
		}
	}
	else
	{
		if (player.get_x_coord() == this->x_coord && player.get_y_coord() == this->y_coord) // Player
		{
			return "  T  |";
		}
		else
		{
			return "     |"; // nothing
		}
	}
}	

bool Room::get_event_state()
/*********************************************************************
** Function: get_event_state()
** Description: get the evnt_state
** Parameters: N/A
** Pre-Conditions: evnt_state exists
** Post-Conditions: gets evnt_state
*********************************************************************/
{
	return this->evnt_state;
}

void Room::set_event(int i, int dimension)
/*********************************************************************
** Function: set_event()
** Description: set the event
** Parameters: i, dimension
** Pre-Conditions: event exists
** Post-Conditions: sets event
*********************************************************************/
{
	if (i == 0 || i == 1)
	{
		this->evnt = new Bats(this->x_coord,this->y_coord, dimension);
		this->evnt_state = true;
	}
	if (i == 2 || i == 3)
	{
		this->evnt = new Pit(this->x_coord, this->y_coord);
		this->evnt_state = true;
	}
	if (i == 4)
	{
		this->evnt = new Wumpus(this->x_coord, this->y_coord);
		this->evnt_state = true;
	}
	if (i == 5)
	{
		this->evnt = new Gold(this->x_coord, this->y_coord);
		this->evnt_state = true;
	}
}

void Room::delete_wumpus()
/*********************************************************************
** Function: delete_wumpus()
** Description: deletes the wumpus
** Parameters: N/A
** Pre-Conditions: wumpus exists
** Post-Conditions: deletes x_coord
*********************************************************************/
{
	if (this->evnt != NULL)
	{
		delete this->evnt;
		this->evnt = NULL;
	}
}

int Room::get_x_coord()
/*********************************************************************
** Function: get_x_coord()
** Description: get the x_coord
** Parameters: N/A
** Pre-Conditions: x_coord exists
** Post-Conditions: gets x_coord
*********************************************************************/
{
	return this->x_coord;
}

int Room::get_y_coord()
/*********************************************************************
** Function: get_y_coord()
** Description: get the y_coord
** Parameters: N/A
** Pre-Conditions: y_coord exists
** Post-Conditions: gets y_coord
*********************************************************************/
{
	return this->y_coord;
}

Event* Room::get_event()
/*********************************************************************
** Function: get_event()
** Description: get the evnt
** Parameters: N/A
** Pre-Conditions: evnt exists
** Post-Conditions: gets evnt
*********************************************************************/
{
	if (this->evnt != NULL)
	{
		return this->evnt;
	}
	else
	{
		return NULL;
	}
}