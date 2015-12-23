/**
 * @file date.h
 *
 * @brief Header file for class Date*/

/**
 * @file date.cpp
 *
 * @brief Code for class Date*/

#ifndef DATE_H
#define DATE_H

#include<string>

using namespace std;

/**
 * @brief Date class
 */
class Date {
private:
	unsigned int day; ///< Day
	unsigned int month; ///< Month
	unsigned int year; ///< Year
public:
	/**
	 * @brief Constructor for class Date
	 */
	Date();

	/**
	 * @brief Constructor for class Date
	 *
	 * @param day Day
	 * @param month Month
	 * @param year Year
	 */
	Date(unsigned int day, unsigned int month, unsigned int year);

	/**
	 * @brief Constructor for class Date. Converts string to day, month, year.
	 *
	 * @param date Date in string form.
	 */
	Date(string date);

	/**
	 * @brief Sets day attribute
	 *
	 * @param day Day
	 */
	void setDay(unsigned int day);

	/**
	 * @brief Sets month attribute
	 *
	 * @param month Month
	 */
	void setMonth(unsigned int month);

	/**
	 * @brief Sets year attribute
	 *
	 * @param year Year
	 */
	void setYear(unsigned int year);

	/**
	 * @brief Gets day attribute
	 *
	 * @return Returns day
	 */
	unsigned int getDay() const;

	/**
	 * @brief Gets month attribute
	 *
	 * @return Returns month
	 */
	unsigned int getMonth() const;

	/**
	 * @brief Gets year attribute
	 *
	 * @return Returns year
	 */
	unsigned int getYear() const;

	/**
	 * @brief Gets date in format day/month/year
	 *
	 * @return Returns date in string format
	 */
	string toString() const;

	/**
	 * @brief Date assignment operator
	 *
	 * @return Returns date
	 */
	Date& operator=(Date rhs);

	/**
	 * @brief Checks if a date is valid
	 *
	 * @return Returns true if the date given is valid. Returns false otherwise.
	 */
	static bool isDateValid(unsigned int day, unsigned int month,
			unsigned int year);

	/**
	 * @brief Checks if a date is valid
	 *
	 * @return Returns true if the date given is valid. Returns false otherwise.
	 */
	static bool isDateValid(const Date& date);

	/**
	 * @brief Checks if a year is a leap year.
	 *
	 * @return Returns true if the parameter is a leap year. Returns false otherwise.
	 */
	static bool isLeapYear(unsigned int year);

	/**
	 * @brief Checks if a month ends in 30 , 31 , 28 or 29
	 *
	 * @return Returns the number of days that a determinate month have
	 */
	static unsigned int numberOfDaysInAMonth(unsigned int month, unsigned int year);

	/**
	 * @brief Prints date to out stream
	 *
	 * @param out Out stream
	 * @param date Date to be printed
	 *
	 * @return Returns out stream
	 */
	friend ostream& operator<<(ostream& out, const Date &date);
	/**
	 * @brief Checks if date is less than d1
	 *
	 * @param d1 Date to be compared
	 *
	 * @return Returns true if the date given d1 is bigger than this date
	 */
	bool operator < (const Date &d1) const;
	/*
	 * @brief overloading of operator ==
	 *
	 * @param d1 Date to be compared
	 *
	 * @return Returns true if the date given d1 is bigger than this date
	 */
	 bool operator==(const Date &d1) const;

	/**
	 * @brief Returns today's date
	 *
	 * @return Returns today's date
	 */
	static Date now();
};

#endif
