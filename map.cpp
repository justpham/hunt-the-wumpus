/******************************************************
** Program: map.cpp
** Author: Justin Pham
** Date: 11/19/2022
** Description: holds the map and control game functions
** Input: anything that has to do with the game
** Output: game board display
** Description: Does not have an AOO or CC because it will never be used
** nor will it need to copy a pointer
******************************************************/

#include "map.h"

using namespace std;

class Map;
class Player;
class Room; 

Map::Map()
/*********************************************************************
** Function: Map()
** Description: Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: New object is created
*********************************************************************/
{
	this->dimension = 4;

	this->start_x = rand() % this->dimension;
	this->start_y = rand() % this->dimension;

	this->plyr.put_player(start_x, start_y);

	this->plyr.put_player(rand() % dimension, rand() % dimension);
	
	for (int i = 0; i < dimension; i++)
	{
		vector <Room*> row;
		for (int j = 0; j < dimension; j++)
		{
			row.push_back(new Room(i, j)); //Possible seg fault if not deleted
		}
		this->board.push_back(row);
	}

	this->precepts = newwin(
		6, // Height
		34, // Width
		1, 1); // Starting position

	this->directions = newwin(
		6, // Height
		36, // Width
		1, 36); // Starting position

	this->inventory = newwin(
		6, // Height
		36, // Width
		1, 74); // Starting position

	this->win = newwin(
		(4 * this->dimension) + 1,
		(6 * this->dimension) + 1,
		8, 1);

	box(precepts, 0, 0);
	box(directions, 0, 0);
	box(inventory, 0, 0);
	refresh();
}

Map::Map(int dim)
/*********************************************************************
** Function: Map()
** Description: Non Default Constructor
** Parameters: int
** Pre-Conditions: N/A
** Post-Conditions: New object is created
*********************************************************************/
{
	this->dimension = dim;

	this->start_x = rand() % this->dimension;
	this->start_y = rand() % this->dimension;

	this->plyr.put_player(start_x, start_y);

	for (int i = 0; i < dimension; i++)
	{
		vector <Room*> row;
		for (int j = 0; j < dimension; j++)
		{
			row.push_back(new Room(i, j)); //Possible seg fault if not deleted
		}
		this->board.push_back(row);
	}

	this->precepts = newwin(
		6, // Height
		34, // Width
		1, 1); // Starting position

	this->directions = newwin(
		6, // Height
		36, // Width
		1, 36); // Starting position

	this->inventory = newwin(
		6, // Height
		36, // Width
		1, 74); // Starting position

	this->win = newwin(
		(4 * this->dimension) + 1,
		(6 * this->dimension) + 1,
		8, 1);

	box(precepts, 0, 0);
	box(directions, 0, 0);
	box(inventory, 0, 0);
	refresh();


}

Map::~Map()
/*********************************************************************
** Function: ~Map()
** Description: Destructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: The object is deleted
*********************************************************************/
{
	clear_board();

	if (precepts != NULL) // Protects from double free
	{
		wclear(precepts);
		delwin(precepts);
		this->precepts = NULL;
	}

	if (directions != NULL) // Protects from double free
	{
		wclear(directions);
		delwin(directions);
		this->directions = NULL;
	}
	if (inventory != NULL) // Protects from double free
	{
		wclear(inventory);
		delwin(inventory);
		this->inventory = NULL;
	}

}

void Map::create_map(int dim) 
/*********************************************************************
** Function: create_map()
** Description: initalizes the map
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Map is initalized
*********************************************************************/
{
	clear_board();

	this->dimension = dim;

	this->start_x = rand() % this->dimension;
	this->start_y = rand() % this->dimension;

	this->plyr.put_player(start_x, start_y);

	for (int i = 0; i < dimension; i++)
	{
		vector <Room*> row;
		for (int j = 0; j < dimension; j++) 
		{
			row.push_back(new Room(j, i)); // Creates a new room for how many rooms
		}
		this->board.push_back(row);
	}

	this->win = newwin(
		(4 * this->dimension) + 1,
		(6 * this->dimension) + 1,
		8, 1);

	box(this->win, 0, 0); // N curses init displays
	wrefresh(win);
	wrefresh(precepts);
	wrefresh(directions);
	wrefresh(inventory);
}

void Map::clear_board()
/*********************************************************************
** Function: clear_board()
** Description: clears the board
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: board is cleared
*********************************************************************/
{
	if (!this->board.empty())  // Protects from double free
	{
		for (int i = 0; i < this->dimension; i++) 
		{
			for (int j = 0; j < this->dimension; j++)
			{
				delete this->board[i][j];
				this->board[i][j] = NULL;
			}
		}

		for (int i = this->dimension; i < 0; i--) // Deletes the vector
		{
			this->board[i].resize(0);
			this->board[i].shrink_to_fit();
		}
		this->board.resize(0);
		this->board.shrink_to_fit();
	}

	if (win != NULL)  // Protects from double free
	{
		wclear(this->win);
		wrefresh(win);
		delwin(win);
		this->win = NULL;
	}
}

void Map::display_directions()
/*********************************************************************
** Function: display_directions()
** Description: Displays the directions
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: directions are displayed
*********************************************************************/
{
	mvwprintw(this->directions, 0, 11, "| DIRECTIONS |");
	mvwprintw(this->directions, 1, 3, "Please enter WASD to move");
	mvwprintw(this->directions, 2, 3, "If you want to fire an arrow,");
	mvwprintw(this->directions, 3, 3, "press 'SPACE' and one WASD key");
	mvwprintw(this->directions, 4, 3, "The wumpus moves when you miss");
	wrefresh(this->directions);
}

void Map::display_precepts()
/*********************************************************************
** Function: display_precepts()
** Description: Displays the precepts
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: precepts are displayed
*********************************************************************/
{
	wclear(this->precepts);
	wrefresh(this->precepts);

	box(this->precepts, 0, 0);
	mvwprintw(this->precepts, 0, 11, "| PRECEPTS |");

	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			if (this->board[i][j]->get_event() != NULL)
			{
				if (this->board[i][j]->get_event()->get_event_id() == 1 && this->board[i][j]->get_event()->precept(this->plyr)) // If player is nearby for a precept
				{
					mvwprintw(this->precepts, 1, 3, "You smell a terrible stench");
				}
				if (this->board[i][j]->get_event()->get_event_id() == 2 && this->board[i][j]->get_event()->precept(this->plyr)) // If player is nearby for a precept
				{
					mvwprintw(this->precepts, 2, 3, "You hear wings flapping");
				}
				if (this->board[i][j]->get_event()->get_event_id() == 3 && this->board[i][j]->get_event()->precept(this->plyr)) // If player is nearby for a precept
				{
					mvwprintw(this->precepts, 3, 3, "You feel a breeze");
				}
				if (this->board[i][j]->get_event()->get_event_id() == 4 && this->board[i][j]->get_event()->precept(this->plyr)) // If player is nearby for a precept
				{
					mvwprintw(this->precepts, 4, 3, "You see a glimmer nearby");
				}
			}
		}
	}
	wrefresh(this->precepts);

}

void Map::display_inventory()
/*********************************************************************
** Function: display_inventory()
** Description: Displays the inventory
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: inventory are displayed
*********************************************************************/
{
	int x = 99;
	int y = 99;

	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			if (this->board[i][j]->get_event() != NULL)
			{
				if (this->board[i][j]->get_event()->get_event_id() == 1) // Finds the wumpus location
				{
					x = j;
					y = i;
				}
			}
		}
	}

	display_inventory_2();

	if (this->board[y][x]->get_event()->get_state() == false) // Prints wumpus alive or not
	{
		mvwprintw(this->inventory, 3, 3, "You have the wumpus's head");
	}
	else
	{
		mvwprintw(this->inventory, 3, 3, "The wumpus is still alive...");
	}
	wrefresh(this->inventory);
}

void Map::display_inventory_2()
/*********************************************************************
** Function: display_inventory_2()
** Description: Displays the inventory
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: inventory are displayed
*********************************************************************/
{
	wclear(this->inventory);
	wrefresh(this->inventory);
	box(this->inventory, 0, 0);

	mvwprintw(this->inventory, 0, 14, "| PLAYER |");

	string arrows = to_string(this->plyr.get_n_arrows()); // Prints arrows
	mvwprintw(this->inventory, 1, 3, "You have ");
	mvwprintw(this->inventory, 1, 12, arrows.c_str());
	mvwprintw(this->inventory, 1, 14, "arrows");

	if (!this->plyr.get_gold()) // Prints player state of gold
	{
		mvwprintw(this->inventory, 2, 3, "You do not have the gold");
	}
	else
	{
		mvwprintw(this->inventory, 2, 3, "You have the gold");
	}
	wrefresh(this->inventory);
}

void Map::display_map(bool debug)
/*********************************************************************
** Function: display_map()
** Description: Displays the map
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Map is displayed
*********************************************************************/
{
	wclear(this->win);
	display_precepts();

	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++) // Top line
		{
			wprintw(this->win, "+-----");
		}
		wprintw(this->win, "+");


		for (int j = 0; j < 3; j++) // Body
		{
			wprintw(this->win, "|");
			for (int k = 0; k < this->dimension; k++)
			{
				if (j == 1) // Checks if there is anything
				{	
					wprintw(this->win, this->board[i][k]->map_room(debug, this->plyr).c_str());
				}
				else // Empty Space above and below
				{
					wprintw(this->win, "     |");
				}
			}
		}
	}
	for (int j = 0; j < this->dimension; j++) // Bottom Line
	{
		wprintw(this->win, "+-----");
	}
	wprintw(this->win, "+");
	wrefresh(this->win);

	//Check for failure

}

bool Map::check_events()
/*********************************************************************
** Function: check_events()
** Description: checks the events
** Parameters: N/A
** Pre-Conditions: events exist
** Post-Conditions: see if what events to play
*********************************************************************/
{
	// If there is an event on the square play the event
	if (this->board[this->plyr.get_y_coord()][this->plyr.get_x_coord()]->get_event() != NULL)
	{
		int bat_check = this->board[this->plyr.get_y_coord()][this->plyr.get_x_coord()]->get_event()->get_event_id(); // Checks event id
		this->board[this->plyr.get_y_coord()][this->plyr.get_x_coord()]->get_event()->encounter(this->plyr); // Plays the encounter
		if (bat_check == 2)
		{
			return true;
		}

		return false;
	}
	else
	{
		return false;
	}
}


void Map::move_player()
/*********************************************************************
** Function: move_player()
** Description: moves the player or fires arrow
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: reads input
*********************************************************************/
{
	
	char ch = wgetch(win);
	if (ch == ' ' && this->plyr.get_n_arrows() > 0) // If the player has an arrow go into arrow function
	{
		this->fire_arrow();
	}
	else // If no valid input
	{
		bool cond = this->plyr.move(ch, this->dimension); // Move the player
		while (cond == false)
		{
			if (ch == ' ' && this->plyr.get_n_arrows() > 0) // If the player has an arrow go into arrow function
			{
				this->fire_arrow();
				cond = true;
			}
			else
			{
				ch = wgetch(win);
				cond = this->plyr.move(ch, this->dimension); // Move the player
			}
		}
	}
	refresh();
}

void Map::fire_arrow()
/*********************************************************************
** Function: fire_arrow()
** Description: fires arrow
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: reads input
*********************************************************************/
{
	int x = 99;
	int y = 99;

	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			if (this->board[i][j]->get_event() != NULL)
			{
				if (this->board[i][j]->get_event()->get_event_id() == 1) // Finds the wumpus location
				{
					x = j;
					y = i;
				}
			}
		}
	}

	mvwprintw(this->inventory, 4, 3, "You are in arrow firing mode");
	wrefresh(this->inventory);
	char ch = wgetch(win);

	string cond = this->plyr.fire_arrow(ch, this->dimension, x, y);
	while (cond[0] == '0')
	{
		ch = wgetch(win);
		cond = this->plyr.fire_arrow(ch, this->dimension, x, y);
	}

	this->plyr.set_n_arrows(this->plyr.get_n_arrows() - 1); // Subtracts an arrow

	if (cond[2] == '1')
	{
		this->board[y][x]->get_event()->set_state(false); // Kills the wumpus
		mvwprintw(this->inventory, 4, 3, "You hit the wumpus. It is dead");
		mvwprintw(this->inventory, 5, 3, "Press any key to continue");
	}
	else if (cond[2] = '0')
	{
		mvwprintw(this->inventory, 4, 3, "You hit nothing. It wakes up");

		int random = rand() % 4;

		if (random != 3)
		{
			if (this->board[y][x]->get_event()->get_state() == true) move_wumpus();
		}
		mvwprintw(this->inventory, 5, 3, "Press any key to continue");
	}

	wrefresh(this->inventory);
	char bruh = wgetch(win);
}

void Map::move_wumpus()
/*********************************************************************
** Function: move_wumpus()
** Description: moves wumpus
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: moves_wumpus
*********************************************************************/
{
	int x;
	int y;
	
	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			if (this->board[i][j]->get_event() != NULL)
			{
				if (this->board[i][j]->get_event()->get_event_id() == 1) // Finds the wumpus
				{
					x = j;
					y = i;
				}
			}
		}
	}

	this->board[y][x]->delete_wumpus(); // deletes the wumpus
	
	bool cond = true;
	while (cond == true)
	{
		int y = rand() % this->dimension;
		int x = rand() % this->dimension;

		if ((board[y][x]->get_event() == NULL)) // Sets it to a position, can be inside of the player.
		{
			board[y][x]->set_event(4, this->dimension);
			cond = false;
		}
	}
}

void Map::create_events()
/*********************************************************************
** Function: create_events()
** Description: create events
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: puts events in random rooms
*********************************************************************/
{
	for (int i = 0; i < 6; i++) // 6 Events Created [1] Wumpus [2] Pits [2] Bats [1] Gold
	{
		int y = rand() % this->dimension;
		int x = rand() % this->dimension;

		if ((board[y][x]->get_event() == NULL) && !(this->plyr.get_y_coord() == y && this->plyr.get_x_coord() == x))
		{
			board[y][x]->set_event(i, this->dimension);
		}
		else
		{
			i--;
		}
	}
}

Player& Map::get_player()
/*********************************************************************
** Function: get_player()
** Description: get player
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: gets the player
*********************************************************************/
{
	return this->plyr;
}

bool Map::escape_rope()
/*********************************************************************
** Function: escape_rope()
** Description: creates escape rope
** Parameters: N/A
** Pre-Conditions: player has finished tasks
** Post-Conditions: ends the game
*********************************************************************/
{


	if ((this->plyr.get_y_coord() == this->start_y && this->plyr.get_x_coord() == this->start_x) && (this->plyr.get_gold()) && (this->plyr.get_wumpus_head() == true))
	{
		return true;
	}
	else
	{
		return false;
	}
}