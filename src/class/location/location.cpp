#include "location.h"


Location::Location(){

}

Location::Location(string city, string county, string district){
	this->city = city;
	this->county = county;
	this->district = district;
}

Location::Location(string location){
	string temp = location.substr(location.find(",")+2);
	this->city = trimSpaces(location.substr(0, location.find(",")));
	this->county = trimSpaces(temp.substr(0, temp.find(",")));
	this->district = trimSpaces(temp.substr(temp.find(",")+2));
}

string Location::toString() const{
	return city + ", " + county + ", " + district;
}

string Location::getCity() const{
	return city;
}

string Location::getCounty() const{
	return county;
}

string Location::getDistrict() const{
	return district;
}

Location& Location::operator=(const Location& rhs){
	this->city = rhs.city;
	this->county = rhs.county;
	this->district = rhs.district;
	return *this;
}

ostream& operator<<(ostream & os, const Location &location){
	os << location.toString();
	return os;
}

string Location::trimSpaces(string str){
	unsigned int i = 0;
	while(str[i] == ' '){
		i++;
	}
	str.erase(0, i);

	i = 0;
	while(str[str.size()-i-1] == ' '){
		i++;
	}
	str.erase(str.size()-i);

	return str;
}



