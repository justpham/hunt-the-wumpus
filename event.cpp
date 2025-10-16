/******************************************************
** Program: Event.cpp
** Author: Justin Pham
** Date: 11/19/2022
** Description: Abstract class for all the events
** Input: N/A
** Output: N/A
** Description: Does not have an AOO or CC because it will never be used
** nor will it need to copy a pointer
** Destructor is not here because all values are on the stack
******************************************************/


#include "event.h"

using namespace std;

class Event;

Event::Event()
/*********************************************************************
** Function: Event()
** Description: Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: New object is created
*********************************************************************/
{
	this->x_coord = -5;
	this->y_coord = -5;
	this->event_id = 0;
}

Event::Event(int x, int y)
/*********************************************************************
** Function: Event( )
** Description: Non Default Constructor
** Parameters: x, y
** Pre-Conditions: Parameters are inputted
** Post-Conditions: New object is created
*********************************************************************/
{
	this->x_coord = x;
	this->y_coord = y;
	this->event_id = 0;
}

void Event::set_x(int x)
/*********************************************************************
** Function: set_x()
** Description: sets x
** Parameters: N/A
** Pre-Conditions: x exists
** Post-Conditions: sets x
*********************************************************************/
{
	this->x_coord = x;
}

void Event::set_y(int y)
/*********************************************************************
** Function: set_y()
** Description: sets y
** Parameters: y
** Pre-Conditions: y exists
** Post-Conditions: sets y
*********************************************************************/
{
	this->y_coord = y;
}

int Event::get_event_id()
/*********************************************************************
** Function: get_event_id()
** Description: gets id
** Parameters: N/A
** Pre-Conditions: id exists
** Post-Conditions: Returns id
*********************************************************************/
{
	return this->event_id;
}