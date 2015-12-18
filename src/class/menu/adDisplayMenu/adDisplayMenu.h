/**
 * @file adDisplayMenu.h
 *
 * @brief Header file for class AdDisplayMenu*/

/**
 * @file adDisplayMenu.cpp
 *
 * @brief Code for class AdDisplayMenu*/

#ifndef ADDISPLAYMENU_H
#define ADDISPLAYMENU_H

#include "../menu.h"
#include "../../advertisement/advertisement.h"

using namespace std;
using namespace enums;

/**
 * @brief Code for class AdDisplayMenu.
 */
class AdDisplayMenu: public Menu {
private:
	Advertisement* ad; ///< Advertisement to display
public:
	/**
	 * @brief Constructor for AdDisplayMenu class
	 *
	 * @param data Data
	 * @param ad Advertisement to display
	 * @param height Menu height
	 * @param width Menu width
	 * @param borderChar Character with which to fill the menu borders
	 */
	AdDisplayMenu(Data* data, Advertisement* ad, unsigned int height = 20,
			unsigned int width = 75, char borderChar = '#');

	/**
	 * @brief Prints the menu to the screen.
	 */
	void print();

	/**
	 * @brief Calls print and creates the interaction with the user
	 */
	void createMenu();

};

#endif
