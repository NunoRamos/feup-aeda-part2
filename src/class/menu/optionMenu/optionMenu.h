/**
 * @file optionMenu.h
 *
 * @brief Header file for class OptionMenu*/

/**
 * @file optionMenu.cpp
 *
 * @brief Code for class OptionMenu*/


#ifndef OPTIONMENU_H
#define OPTIONMENU_H

#include "../menu.h"
#include<string>
#include<utility>
#include<vector>

using namespace std;

/**
 * @brief OptionMenu class
 */
class OptionMenu : public Menu{
private:
	vector<pair<string, void (*)(Data*)>> functions; ///< Functions to call and display in menu
public:
	/**
	 * @brief OptionMenu constructor
	 *
	 * @param data Data
	 * @param height Menu height
	 * @param width Menu width
	 * @param borderChar Border character
	 */
	OptionMenu(Data* data, unsigned int height = 20, unsigned int width = 75, char borderChar = '#');

	/**
	 * @brief Prints menu to screen
	 */
	void print();

	/**
	 * @brief Adds option to function
	 *
	 * @param name Name to display
	 * @param function Function to call when selected
	 */
	void addOption(string name, void(*function)(Data* data));

	/**
	 * @brief Handles user interaction
	 */
	void createMenu();
};

#endif
