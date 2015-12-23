#include "date.h"

#include <sstream>
#include <stdlib.h>
#include <stdexcept>
#include <ctime>

Date::Date() {
	day = 1;
	month = 1;
	year = 1900;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
	if (isDateValid(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
	} else
		throw out_of_range("Invalid date.");
}

#include<iostream>

Date::Date(string date) {
	stringstream ss;
	char temp;
	ss.str(date);
	ss >> day >> temp >> month >> temp >> year;
	if (!isDateValid(day, month, year))
		throw out_of_range("Invalid date.");

}

void Date::setDay(unsigned int day) {
	if (isDateValid(day, month, year))
		this->day = day;
	else
		throw out_of_range("Invalid day.");
}

void Date::setMonth(unsigned int month) {
	if (isDateValid(day, month, year))
		this->month = month;
	else
		throw out_of_range("Invalid month.");
}

void Date::setYear(unsigned int year) {
	this->year = year;
}

unsigned int Date::getDay() const {
	return day;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getYear() const {
	return year;
}

string Date::toString() const {
	stringstream ss;
	ss << day << '/' << month << '/' << year;
	return ss.str();
}

bool Date::isLeapYear(unsigned int year) {

	if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else if (year % 4 == 0)
		return true;

	return false;
}

bool Date::isDateValid(unsigned int day, unsigned int month,
		unsigned int year) {

	if (day < 1 || day > 31 || month < 1 || month > 12)
		return false;

	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
			return false;
		break;
	case 2:
		if (isLeapYear(year)) {
			if (day > 29)
				return false;
		} else {
			if (day > 28)
				return false;
		}
		break;
	}

	return true;
}

bool Date::isDateValid(const Date& date) {
	return Date::isDateValid(date.day, date.month, date.year);
}

unsigned int Date::numberOfDaysInAMonth(unsigned int month, unsigned int year){
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
		break;
	}

	return 31;
}

Date& Date::operator=(Date rhs) {
	this->day = rhs.day;
	this->month = rhs.month;
	this->year = rhs.year;
	return *this;
}

ostream& operator<<(ostream& out, const Date &date){
	out << date.toString();
	return out;
}

bool Date::operator < (const Date &d1)const{

	if(this->getYear()<d1.getYear())
		return true;
	else if (this->getYear()==d1.getYear()){
		if (this->getMonth()<d1.getMonth())
			return true;
		else if(this->getMonth()==d1.getMonth()){
			if(this->getDay()<d1.getDay())
				return true;
		}
	}
	return false;
}

bool Date::operator==(const Date &d1) const{

	if(	this->day == d1.day)
		if(this->month == d1.month)
			if(this->year == d1.year)
				return true;

	return false;
}

Date Date::now(){
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	int year=now->tm_year + 1900;
	int month=now->tm_mon + 1 ;
	int day= now->tm_mday;
	return Date(day, month, year);
}
