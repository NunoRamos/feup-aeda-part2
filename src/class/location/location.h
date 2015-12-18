/**
 * @file location.h
 *
 * @brief Header file for class Location*/

/**
 * @file location.cpp
 *
 * @brief Code for class Location*/


#ifndef LOCATION_H_
#define LOCATION_H_

#include<string>

using namespace std;

/**
 * @brief Code for class Location. A county has many cities; a district has various counties.
 */
class Location{
protected:
	string city; ///< City
	string county; ///< County
	string district; ///< District

	/**
	 * @brief Trims spaces from right and left
	 *
	 * @param str String to trim
	 *
	 * @return Returns trimmed string
	 */
	string trimSpaces(string str);
public:
	/**
	 * @brief Default constructor for Location class
	 */
	Location();

	/**
	 * @brief Constructor for Location class
	 *
	 * @param city City
	 * @param county County
	 * @param district District
	 */
	Location(string city, string county, string district);

	/**
	 * @brief Constructor for Location class. Covnerts string into city, county, district
	 *
	 * @param location Location
	 */
	Location(string location);

	/**
	 * @brief Gets location in format city, county, district
	 *
	 * @return Returns location in string format
	 */
	string toString() const;

	/**
	 * @brief Gets city attribute
	 *
	 * @return Returns city
	 */
	string getCity() const;

	/**
		 * @brief Gets county attribute
		 *
		 * @return Returns county
		 */
	string getCounty() const;

	/**
		 * @brief Gets district attribute
		 *
		 * @return Returns district
		 */
	string getDistrict() const;

	/**
	 * @brief Location assignment operator
	 *
	 * @return Returns location
	 */
	Location& operator=(const Location &rhs);

	/**
	 * @brief Location << operator
	 *
	 * @return Returns output stream
	 */
	friend ostream& operator<<(ostream & os, const Location &location);
};



#endif
