/**
 * @file menu.h
 *
 * @brief Header file for class Menu*/

/**
 * @file menu.cpp
 *
 * @brief Code for class Menu*/


#ifndef MENU_H
#define MENU_H

#include"../data/data.h"

using namespace std;

/**
 * @brief Menu class
 */
class Menu{
protected:
	char borderChar; ///< Border character
	unsigned int height; ///< Menu height
	unsigned int width; ///< Menu width
	unsigned int topMargin; ///< Top margin
	unsigned int leftMargin; ///< Left margin
	Data* data; ///< data

	/**
	 * @brief Prints empty line
	 */
	void emptyLine() const;
public:
	/**
	 * @brief Constructor for Menu class
	 *
	 * @param data Data
	 * @param height Menu height
	 * @param width Menu width
	 * @param borderChar Border character
	 */
	Menu(Data* data, unsigned int height, unsigned int width, char borderChar);

	/**
	 * @brief Sets borderChar
	 *
	 * @param borderChar Border Character
	 */
	void setBorderChar(char borderChar);

	/**
	 * @brief Gets borderChar
	 *
	 * @return Return border character
	 */
	char getBorderChar();

	/**
	 * @brief Prints menu to screen
	 */
	virtual void print() = 0;

	/**
	 * @brief Handles user interaction
	 */
	virtual void createMenu() = 0;
};

#endif
