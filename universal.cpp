/******************************************************
** Program: htw
** Author: Justin Pham
** Date: 11/19/2022
** Description: Hunt the wumpus game
** Input: game inputs WASD and such
** Output: game information about the game
******************************************************/


/******************************************************
** Program: universal.cpp
** Author: Justin Pham
** Date: 11/19/2022
** Description: holds general game functions
** Input: map size, debug mode, replay
** Output: game information
******************************************************/


#include "universal.h"

using namespace std;

class Map;

bool test_game(int map_size)
/*********************************************************************
** Function: test_game
** Description: runs the game
** Parameters: map_size
** Pre-Conditions: arguement is passed
** Post-Conditions: ends game
*********************************************************************/
{
	bool check = false;
	bool debug;

	cout << "debug? (1 for debug) ";
	cin >> debug;

	init_screen();

	Map bruh;
	start_game(bruh, map_size);

	while (true)
	{
		bruh.display_map(debug); // displays map
		bruh.move_player(); // player moves
		bruh.display_map(debug);

		check = bruh.check_events();
		while (check == true) // Checks if its a bat
		{
			check = bruh.check_events(); // checks for events
			bruh.display_inventory();
		}
		if (bruh.get_player().get_alive() == false) // if the player isn't alive game over
		{
			return false;
		}
		if (bruh.escape_rope() == true) // if the player escapes they win
		{
			return true;
		}
		bruh.display_inventory();
	}
}

void init_screen()
/*********************************************************************
** Function: init_screen
** Description: init screen
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: makes the screen
*********************************************************************/

{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
}

void start_game(Map& bruh, int map_size)
/*********************************************************************
** Function: start_game
** Description: starts the game
** Parameters: Map
** Pre-Conditions: argument is passed
** Post-Conditions: init game
*********************************************************************/
{
	bruh.create_map(map_size);
	bruh.create_events();
	bruh.display_directions();
	bruh.display_inventory();
}

void reload_scenario()
/*********************************************************************
** Function: reload_scenario
** Description: reloads the scenario with the same presets
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: game has the same presets
*********************************************************************/
{
	srand(time(NULL));
}

void game_loop()
/*********************************************************************
** Function: game_loop
** Description: game loops
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: game loops
*********************************************************************/
{
	string replay = "1";
	int test = 4;


	while (replay == "1" || replay == "2") // replays the game
	{
		cout << "Size? " << endl; // asks for map size
		cin >> test;

		bool win_cond;
		win_cond = test_game(test); // starts game

		endwin();

		if (win_cond == false)
		{
			cout << endl << "You lost because you died!" << endl; // end message
		}
		else if (win_cond == true)
		{
			cout << endl << "You won and escaped the cave!" << endl; // win message
		}
		cout << "Play again? (1 for replay, 2 for same scenario, 0 for end) ";
		cin >> replay;
		
		reload_scenario();

	}
}