#include "user.h"
#include "../../sequentialSearch.h"
#include "../advertisement/purchase/purchase.h"
#include "../advertisement/sale/sale.h"
#include "../../enums.h"
#include <iostream>
#include<sstream>

User::User() {
	showEmail = true;
	showName = true;
	showPhoneNumber = true;
}

User::User(string email, string password, string name, string phoneNumber,
		Location location) :
				User() {
	this->email = email;
	this->password = password;
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->location = location;
}

User::User(string email, string password, string name, string phoneNumber,
		string location) :
				User(email, password, name, phoneNumber, Location(location)) {
}

bool User::signIn(string password) const {
	if (this->password == password)
		return true;
	return false;
}

string User::getEmail() const {
	return email;
}

string User::getPassword() const {
	return password;
}

string User::getName() const {
	return name;
}

string User::getPhoneNumber() const {
	return phoneNumber;
}

Location User::getLocation() const {
	return location;
}

string User::getLocationString() const {
	return location.toString();
}

bool User::getShowEmail() const {
	return showEmail;
}

bool User::getShowName() const {
	return showName;
}

bool User::getShowPhoneNumber() const {
	return showPhoneNumber;
}

void User::setEmail(string email) {
	this->email = email;
}

void User::setShowEmail(bool show) {
	this->showEmail = show;
}

void User::setShowName(bool show) {
	this->showName = show;
}

void User::setShowPhoneNumber(bool show) {
	this->showPhoneNumber = show;
}

istream& operator>>(istream& in, User &user) {
	int numberOfAds;
	unsigned int views;
	float price;
	bool negotiable;
	bool paid;
	Category category;
	string temp, title, description;
	stringstream ss;
	Date creationDate;
	string type;

	getline(in, user.email);
	getline(in, user.password);
	getline(in, user.name);
	getline(in, user.phoneNumber);
	getline(in, temp);
	user.location = Location(temp);
	in >> user.showEmail;
	in >> user.showName;
	in >> user.showPhoneNumber;
	in >> numberOfAds;
	in.ignore(1000,'\n');
	ss.str("");
	for (unsigned int i = 0; i < numberOfAds; i++) {
		getline(in, type);
		ss.str("");
		getline(in, title);
		getline(in, temp);
		ss << temp;
		ss >> views;
		ss.str("");
		getline(in, temp);
		category = stringToCategory(temp);
		getline(in, description);
		getline(in, temp);
		Date date(temp);
		creationDate = date;
		in >> price;
		in.ignore(100000, '\n');
		ss.str("");
		getline(in, temp);
		if (temp == "1")
			negotiable = true;
		else
			negotiable = false;
		getline(in,temp);
		if(temp == "1")
			paid = true;
		else
			paid = false;
		if (type == "P") {
			Advertisement* ad = new Purchase(NULL, title, category, description,
					price);
			ad->setNegotiable(negotiable);
			ad->setCreationDate(creationDate);
			ad->setFeatured(paid);
			user.advertisements.push_back(ad);
		} else {
			string cond;
			getline(in, cond);
			Advertisement* ad = new Sale(NULL, title, category, description,
					stringToCondition(cond), price);
			ad->setNegotiable(negotiable);
			ad->setCreationDate(creationDate);
			user.advertisements.push_back(ad);
		}
	}

	return in;
}

void User::removeAdvertisement(Advertisement* ad) {
	int adIndex = sequentialSearch(advertisements, ad);
	if (adIndex != -1) {
		advertisements.erase(advertisements.begin() + adIndex);
	}
}

void User::addAdvertisement(Advertisement *newAdvertisement) {
	advertisements.push_back(newAdvertisement);
}

bool User::operator==(const User & u1) const {
	return (this->email == u1.email);
}

ostream& operator<<(ostream& out, const User &user) {
	char separationChar = '\n';

	out << user.email << separationChar << user.password << separationChar
			<< user.name << separationChar << user.phoneNumber << separationChar
			<< user.location << separationChar << user.showEmail
			<< separationChar << user.showName << separationChar
			<< user.showPhoneNumber << separationChar
			<< user.advertisements.size();

	for (unsigned int i = 0; i < user.advertisements.size(); i++) {
		out << *user.advertisements[i];
	}
	return out;
}
vector<Advertisement *> User::getAdvertisements() {
	return advertisements;
}

void User::setAdsOwner() {
	for (unsigned int i = 0; i < advertisements.size(); i++) {
		advertisements[i]->setOwner(this);
	}
}

void User::deleteAds(){
	while(advertisements.size() != 0)
		advertisements.pop_back();
}

void User::sendProposal(Advertisement* ad){
	float price;
	cout << "What price would you like to offer?\n";
	cin >> price;
	ad->addProposal(new Proposal(this, price));
	cout << "Proposal sent.";
}
