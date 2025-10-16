#ifndef UNIVERSAL_H
#define UNIVERSAL_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <ncurses.h>
#include "map.h"

class Map;

using namespace std;

bool test_game(int map_size);
void init_screen();
void reload_scenario();
void game_loop();
void start_game(Map& bruh, int map_size);

#endif