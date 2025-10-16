/******************************************************
** Program: Player.cpp
** Author: Justin Pham
** Date: 11/19/2022
** Description: all player commands and holds the player
** Input: N/A
** Output: outputs player information and modifies it
** Description: Does not have an AOO or CC because it will never be used
** nor will it need to copy a pointer
** Destructor is not here because all values are on the stack
******************************************************/


#include "player.h"

using namespace std;

class Player;

Player::Player()
/*********************************************************************
** Function: Player()
** Description: Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: New object is created
*********************************************************************/
{
	this->x_coord = -1;
	this->y_coord = -1;
	this->gold = false;
	this->n_arrows = 3;
	this->alive = true;
	this->wumpus_head = false;
}

Player::Player(int x, int y)
/*********************************************************************
** Function: Player()
** Description: Non Default Constructor
** Parameters: x, y
** Pre-Conditions: parameters are entered
** Post-Conditions: object is created
*********************************************************************/
{
	this->x_coord = x;
	this->y_coord = y;
	this->gold = false;
	this->n_arrows = 3;
	this->alive = true;
	this->wumpus_head = false;
}

void Player::put_player(int x, int y)
/*********************************************************************
** Function: put_player()
** Description: Sets the x and y coord of the player in its starting place
** Parameters: x_lim, y_lim
** Pre-Conditions: parameters are entered
** Post-Conditions: places the player in that position
*********************************************************************/
{
	this->x_coord = x;
	this->y_coord = y;
	this->gold = false;
	this->n_arrows = 3;
}

void Player::set_x_coord(int x)
/*********************************************************************
** Function: set_x_coord()
** Description: sets the x_coord
** Parameters: N/A
** Pre-Conditions: x_coord exists
** Post-Conditions: sets x_coord
*********************************************************************/
{
	this->x_coord = x;
}

void Player::set_y_coord(int y)
/*********************************************************************
** Function: set_y_coord()
** Description: sets the y_coord
** Parameters: N/A
** Pre-Conditions: y_coord exists
** Post-Conditions: sets y_coord
*********************************************************************/
{
	this->y_coord = y;
}

int Player::get_x_coord()
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

int Player::get_y_coord()
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

bool Player::move(char input, int dimension)
/*********************************************************************
** Function: move()
** Description: move the player
** Parameters: char, int
** Pre-Conditions: input is read
** Post-Conditions: move the player
*********************************************************************/
{
	if ((input == 'W' || input == 'w') && (this->y_coord - 1) >= 0) // Error handles for outside bounds
	{
		this->y_coord--;
		return true;
	}
	else if ((input == 'S' || input == 's') && (this->y_coord + 1) < dimension) // Error handles for outside bounds
	{
		this->y_coord++;
		return true;
	}
	else if ((input == 'A' || input == 'a') && (this->x_coord - 1) >= 0) // Error handles for outside bounds
	{
		this->x_coord--;
		return true;
	}
	else if ((input == 'D' || input == 'd') && (this->x_coord + 1) < dimension) // Error handles for outside bounds
	{
		this->x_coord++;
		return true;
	}
	else
	{
		return false;
	}
}

int Player::get_n_arrows()
/*********************************************************************
** Function: get_n_arrows()
** Description: get the n_arrows
** Parameters: N/A
** Pre-Conditions: n_arrows exists
** Post-Conditions: gets n_arrows
*********************************************************************/
{
	return this->n_arrows;
}

bool Player::get_gold()
/*********************************************************************
** Function: get_gold()
** Description: get state of gold
** Parameters: N/A
** Pre-Conditions: gold exists
** Post-Conditions: gets gold
*********************************************************************/
{
	return this->gold;
}

void Player::set_alive(bool state)
/*********************************************************************
** Function: set_alive()
** Description: set if they are alive or not
** Parameters: N/A
** Pre-Conditions: alive exists
** Post-Conditions: sets alive
*********************************************************************/
{
	this->alive = state;
}

bool Player::get_alive()
/*********************************************************************
** Function: get_alive()
** Description: get alive
** Parameters: N/A
** Pre-Conditions: alive exists
** Post-Conditions: gets alive
*********************************************************************/
{
	return this->alive;
}

void Player::set_gold(bool state)
/*********************************************************************
** Function: set_gold()
** Description: set gold
** Parameters: N/A
** Pre-Conditions: gold exists
** Post-Conditions: sets gold
*********************************************************************/
{
	this->gold = state;
}

void Player::set_n_arrows(int n)
/*********************************************************************
** Function: set_n_arrows()
** Description: set n_arrows
** Parameters: N/A
** Pre-Conditions: n_arrows exists
** Post-Conditions: sets n_arrows
*********************************************************************/
{
	this->n_arrows = n;
}

string Player::fire_arrow(char input, int dimension, int wumpus_x, int wumpus_y)
/*********************************************************************
** Function: fire_arrow()
** Description: fire an arrow
** Parameters: char, int
** Pre-Conditions: input is read
** Post-Conditions: fires an arrow
*********************************************************************/
{
	bool check = false;
	
	/*
	 "0 0" represents no hit and no arrow fired
	 "1 0" represents no hit and arrow fired
	 "1 1" represents hit and arrow fired
	*/

	if ((input == 'W' || input == 'w') ) // Error handles for outside bounds
	{
		check = arrow_travel('y', -1, dimension, wumpus_x, wumpus_y);
		if (check){ return "1 1"; }
		else{ return "1 0"; }
	}
	else if ((input == 'S' || input == 's') ) // Error handles for outside bounds
	{
		check = arrow_travel('y', 1, dimension, wumpus_x, wumpus_y);
		if (check) { return "1 1"; }
		else { return "1 0"; }
	}
	else if ((input == 'A' || input == 'a') ) // Error handles for outside bounds
	{
		check = arrow_travel('x', -1, dimension, wumpus_x, wumpus_y);
		if (check) { return "1 1"; }
		else { return "1 0"; }
	}
	else if ((input == 'D' || input == 'd') ) // Error handles for outside bounds
	{
		check = arrow_travel('x', 1, dimension, wumpus_x, wumpus_y);
		if (check) { return "1 1"; }
		else { return "1 0"; }
	}
	else
	{
		return "0 0";
	}
}

bool Player::arrow_travel(char axis, int direction, int dimension, int wumpus_x, int wumpus_y)
/*********************************************************************
** Function: arrow_travel()
** Description: fire an arrow
** Parameters: char, int
** Pre-Conditions: input is read
** Post-Conditions: fires an arrow
*********************************************************************/
{
	// Checks the spot
	if (axis == 'x') // Moves the arrow in the x axis
	{
		for (int i = 0; i < 3; i++)
		{
			if (((this->x_coord + direction * (i + 1) < dimension) && ((this->x_coord + direction * (i + 1)) >= 0))  // If the position is within the board
				&& 
				((this->x_coord + direction * (i + 1)) == wumpus_x) && (this->y_coord == wumpus_y)) // If that arrow in that position matches the wumpus
			{
				this->wumpus_head = true;
				return true;
			}
			else if (i == 2)
			{
				return false;
			}
		}
	}
	if (axis == 'y') // Moves the arrow in the y axis
	{
		for (int i = 0; i < 3; i++)
		{
			if (((this->y_coord + direction * (i + 1) < dimension) && ((this->y_coord + direction * (i + 1)) >= 0))  // If the position is within the board
				&&
				((this->x_coord == wumpus_x && (this->y_coord + direction * (i + 1) == wumpus_y)))) // If that arrow in that position matches the wumpus
			{
				this->wumpus_head = true;
				return true;
			}
			else if (i == 2)
			{
				return false;
			}
		}
	}
}

bool Player::get_wumpus_head()
/*********************************************************************
** Function: get_wumpus_head()
** Description: gets variable
** Parameters: N/A
** Pre-Conditions: variable exists
** Post-Conditions: gets variable
*********************************************************************/
{
	return this->wumpus_head;
}