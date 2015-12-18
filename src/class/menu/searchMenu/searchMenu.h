/**
 * @file searchMenu.h
 *
 * @brief Header file for class SearchMenu*/

/**
 * @file searchMenu.cpp
 *
 * @brief Code for class SearchMenu*/

#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include"../menu.h"

using namespace std;

/**
 * @brief SearchMenu class
 */
class SearchMenu : public Menu{
private:
	vector<Advertisement* > results; ///< Results to display
	unsigned int page; ///< Current page
	unsigned int pageMax; ///< Max page
	unsigned int adsPerPage; ///< Advertisements per page
public:
	/**
	 * @brief Constructor for SearchMenu class
	 *
	 * @param data Data
	 * @param results Results to display
	 * @param height Menu height
	 * @param width Menu width
	 * @param borderChar Border character
	 */
	SearchMenu(Data* data, vector<Advertisement* > &results, unsigned int height = 20, unsigned int width = 75, char borderChar = '#');

	/**
	 * @brief Sets ads per page
	 *
	 * @param adsPerPage Advertisements per page
	 */
	void setAdsPerPage(unsigned int adsPerPage);

	/**
	 * @brief Gets ads per page
	 *
	 * @return Returns ads per page
	 */
	unsigned int getAdsPerPage();

	/**
	 * @brief Prints menu to screen
	 */
	void print();

	/**
	 * @brief Handles user interaction
	 */
	void createMenu();
};

#endif
