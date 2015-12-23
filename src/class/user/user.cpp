#include "user.h"
#include "../../sequentialSearch.h"
#include "../advertisement/purchase/purchase.h"
#include "../advertisement/sale/sale.h"
#include "../../enums.h"
#include "../date/date.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include "../../BST.h"

User::User() {
	showEmail = true;
	showName = true;
	showPhoneNumber = true;
	transactions = 0;
	lastTransaction = Date();
}

User::User(const User& u){
	this->email = u.email;
	this->password = u.password;
	this->name = u.name;
	this->phoneNumber = u.phoneNumber;
	this->location = u.location;
	this->lastTransaction = u.lastTransaction;
	this->transactions = u.transactions;
	this->showEmail = u.showEmail;
	this->showName = u.showName;
	this->showPhoneNumber = u.showPhoneNumber;
	this->advertisements = u.advertisements;
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
int User::getTransactions() const {
	return transactions;
}

void User::incrementTransactions() {
	transactions++;
}

Location User::getLocation() const {
	return location;
}

Date User::getlastTransaction() const {
	return lastTransaction;
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
	in.ignore(1000, '\n');
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

		if (type == "P") {
			Advertisement* ad = new Purchase(&user, title, category,
					description, price);
			ad->setNegotiable(negotiable);
			ad->setCreationDate(creationDate);
			user.advertisements.push_back(ad);
		} else {
			string cond;
			getline(in, cond);
			Advertisement* ad = new Sale(&user, title, category, description,
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

void User::deleteAds() {
	while (advertisements.size() != 0)
		advertisements.pop_back();
}

void User::sendProposal(Advertisement* ad) {
	if (ad->isPriceNegotiable()) {
		float price;
		cout << "What price would you like to offer?\n";
		cin >> price;
		ad->addProposal(new Proposal(this, price));
		cout << "Proposal sent.";
	} else {
		cout << "The price is not negotiable. Would you like to offer "
				<< ad->getPrice() << "? (Y/N)\n";
		char input;
		cin >> input;
		if (input == 'Y' || input == 'y') {
			ad->addProposal(new Proposal(this, ad->getPrice()));
			cout << "Proposal sent.";
		}
	}
}

void User::setLastTransaction(const Date &transaction) {
	if (lastTransaction < transaction)
		this->lastTransaction = transaction;
}

bool User::operator <( User* u1) const {
	if (this->getTransactions() > u1->getTransactions())
		return true;
	else if (this->getTransactions() == u1->getTransactions()) {
		if (u1->getlastTransaction() < this->getlastTransaction())
			return true;
		else if (this->getlastTransaction() == u1->getlastTransaction())
			return this->getEmail() < u1->getEmail();
	}

	return false;
}

bool User::operator==(const User &u1) const {
	return (this->email == u1.email);
}

void User::setLastTransaction() {
	lastTransaction = Date::now();
}

void User::RefreshProfile(User &u1) {
	/*
	 RemoveUserFromBst(u1);
	 setLastTransaction();
	 incrementTransactions();
	 addUserToBst(u1);

	 */
}

bool User::deleteAd(Advertisement* ad) {
	for (unsigned int i = 0; i < advertisements.size(); i++) {
		if (advertisements[i]->getId() == ad->getId()) {
			for (unsigned int j = i; j < advertisements.size() - 1; j++) {
				*advertisements[j] = *advertisements[j + 1];
			}

			advertisements.resize(advertisements.size() - 1);

			return true;
		}
	}

	return false;
}

User::~User(){ }

User& User::operator=(const User& u){
	vector<Advertisement*> advertisements;
	this->email = u.email;
	this->password = u.password;
	this->name = u.name;
	this->phoneNumber = u.phoneNumber;
	this->location = u.location;
	this->lastTransaction = u.lastTransaction;
	this->transactions = u.transactions;
	this->showEmail = u.showEmail;
	this->showName = u.showName;
	this->showPhoneNumber = u.showPhoneNumber;
	return *this;
}
