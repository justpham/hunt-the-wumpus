#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <ncurses.h>

using namespace std;

class Player
{
private:
	int x_coord;
	int y_coord;
	bool gold;
	int n_arrows;
	bool alive;
	bool wumpus_head;
public:
	Player();
	Player(int, int);
	void put_player(int x, int y);
	void set_x_coord(int x);
	void set_y_coord(int y);
	int get_x_coord();
	int get_y_coord();
	bool get_gold();
	void set_gold(bool state);
	int get_n_arrows();
	void set_n_arrows(int n);
	bool move(char input, int dimension);
	string fire_arrow(char input, int dimension, int wumpus_x, int wumpus_y);
	bool arrow_travel(char input, int direction, int dimension, int wumpus_x, int wumpus_y);
	bool get_alive();
	void set_alive(bool state);
	bool get_wumpus_head();

};

#endif 