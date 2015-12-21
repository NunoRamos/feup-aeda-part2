#include "data.h"
#include "../../sequentialSearch.h"
#include "../advertisement/purchase/purchase.h"
#include "../../menus.h"

#include<fstream>
#include <iostream>
#include <sstream>

Data::Data() {
	signedInUser = NULL;
}

Data::~Data() {
	int i;
	//	saveUsers();
	for (int i = 0; i < advertisements.size(); i++) {
		delete advertisements[i];
	}
	cin >> i;
}

bool Data::signIn(const string &email, const string &password) {
	if (users.size() == 0)
		return false;

	User tmp;
	tmp.setEmail(email);
	int user = sequentialSearch(users, tmp);

	if (user == -1)
		return false;

	if (users[user].signIn(password)) {
		signedInUser = &users[user];
		return true;
	}
	return false;
}

bool Data::signUp(User &user) { //may add a condition to see if a user with the same email already exists
	int i = sequentialSearch(users, user);
	if (i != -1)
		cout << "Client is already created\n";
	else
		users.push_back(user);
	return true;
}

bool Data::loadUsers() {
	ifstream userFile;
	unsigned int numberOfFiles;
	stringstream ss;

	userFile.open((path + "info.txt").c_str());
	if (!userFile.is_open())
		return false;

	userFile >> numberOfFiles;
	userFile.close();

	User temp;

	for (unsigned int i = 0; i < numberOfFiles; i++) {
		ss << "user" << i << ".txt";
		userFile.open((path + ss.str()).c_str());
		if (userFile.is_open()) {
			userFile >> temp;
			users.push_back(temp);
			users[i].setAdsOwner();
			vector<Advertisement*> ads = users[i].getAdvertisements();
			for (unsigned int j = 0; j < ads.size(); j++) {
				advertisements.push_back(ads[j]);
			}
		}
		userFile.close();
		ss.str("");
	}

	return true;
}

bool Data::saveUsers() {
	char separationChar = '\n';
	ofstream userFile;
	stringstream ss;

	userFile.open((path + "info.txt").c_str()); //ofstream::out | ofstream::trunc
	if (!userFile.is_open())
		return false;

	userFile << users.size();
	userFile.close();

	for (unsigned int i = 0; i < users.size(); i++) {
		ss << "user" << i << ".txt";
		userFile.open((path + ss.str()).c_str());
		if (userFile.is_open()) {
			userFile << users[i];
			userFile.close();
		}
		ss.str("");
	}
	return true;
}

void Data::removeAdvertisement(Advertisement* ad) {
	ad->getOwner()->removeAdvertisement(ad);
	int adIndex = sequentialSearch(advertisements, ad);

	if (adIndex == -1)
		return;

	delete advertisements[adIndex];
	advertisements.erase(advertisements.begin() + adIndex);
}

void Data::addAdvertisement(Advertisement* ad) {
	advertisements.push_back(ad);
	ad->getOwner()->addAdvertisement(ad);
}

vector<Advertisement*> Data::searchForAds(string text) {
	vector<Advertisement*> results;

	for (unsigned int i = 0; i < advertisements.size(); i++) {
		if (advertisements[i]->searchForText(text))
			results.push_back(advertisements[i]);
	}

	return results;
}

vector<Advertisement*> Data::searchForAdsCategory(Category text) {
	vector<Advertisement*> results;

	for (unsigned int i = 0; i < advertisements.size(); i++) {
		if (advertisements[i]->getCategory() == text)
			results.push_back(advertisements[i]);
	}

	return results;
}

vector<Advertisement*> Data::searchForAdsPrice(float inicialPrice,
		float finalPrice) {
	vector<Advertisement*> results;

	for (unsigned int i = 0; i < advertisements.size(); i++) {
		if (advertisements[i]->getPrice() >= inicialPrice
				&& advertisements[i]->getPrice() <= finalPrice)
			results.push_back(advertisements[i]);
	}

	return results;
}

vector<Advertisement*> Data::vectorOfSaleOrPurchase(vector<Advertisement*> ads,
		char saleOrPurchase) {
	vector<Advertisement*> results;

	if (saleOrPurchase == 'S') {
		for (int i = 0; i < ads.size(); i++) {
			if (ads[i]->getType() == 'S')
				results.push_back(ads[i]);
		}
	} else if (saleOrPurchase == 'P') {
		for (int i = 0; i < ads.size(); i++) {
			if (ads[i]->getType() == 'P')
				results.push_back(ads[i]);
		}
	}

	return results;
}

void Data::signOut() {
	signedInUser = NULL;
}

User* Data::getSignedInUser() const {
	return signedInUser;
}

vector<Advertisement*> Data::getAdsInSameCity(string city) {
	vector<Advertisement*> results;
	for (unsigned int i = 0; i < advertisements.size(); i++) {
		Location location = advertisements[i]->getLocation();
		if (location.getCity() == city)
			results.push_back(advertisements[i]);
	}

	return results;
}

vector<Advertisement*> Data::getAdsInSameCounty(string county) {
	vector<Advertisement*> results;
	for (unsigned int i = 0; i < advertisements.size(); i++) {
		Location location = advertisements[i]->getLocation();
		if (location.getCounty() == county)
			results.push_back(advertisements[i]);
	}

	return results;
}

vector<Advertisement*> Data::getAdsInSameDistrict(string district) {
	vector<Advertisement*> results;
	for (unsigned int i = 0; i < advertisements.size(); i++) {
		Location location = advertisements[i]->getLocation();
		if (location.getDistrict() == district)
			results.push_back(advertisements[i]);
	}

	return results;
}

void Data::removeUser(User* user){
	unsigned int index = sequentialSearch(users, *user);
	users[index].deleteAds();
	for(unsigned int i = 0; i < advertisements.size(); i++){
		if(advertisements[i]->getOwner() == user){
			delete advertisements[i];
			advertisements.erase(advertisements.begin()+i);
			i--;
		}
	}
	users.erase(users.begin()+index);
}

void Data::orderResults(vector<Advertisement*> toOrder, sort::Order orderType){

}
