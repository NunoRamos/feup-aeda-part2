#include "advertisement.h"
#include "../menu/adDisplayMenu/adDisplayMenu.h"
#include<iostream>
#include<sstream>

unsigned int Advertisement::nextId = 0;

Advertisement::Advertisement(User* owner, string title, Category category,
		string description, float price) {
	this->owner = owner;
	this->title = title;
	this->category = category;
	this->description = description;
	this->price = price;
	negotiable = true;
	id = nextId;
	nextId++;
	views = 0;
	//TODO: get time and save as creationDate

}

Advertisement::~Advertisement() {
	nextId--;
}

unsigned int Advertisement::getId() const {
	return id;
}

User* Advertisement::getOwner() {
	return owner;
}

string Advertisement::getTitle() const {
	return title;
}

Category Advertisement::getCategory() const {
	return category;
}

string Advertisement::getDescription() const {
	return description;
}

unsigned int Advertisement::getViews() const {
	return views;
}

float Advertisement::getPrice() const {
	return price;
}

string Advertisement::getCreationDate() const {
	return creationDate.toString();

}

bool Advertisement::isPriceNegotiable() const {
	return negotiable;
}

void Advertisement::setNegotiable(bool negotiable) {
	this->negotiable = negotiable;
}

void Advertisement::setTitle(string newTitle) {
	this->title = newTitle;
}

void Advertisement::setDescription(string newDescription) {
	this->description = newDescription;
}

void Advertisement::setCreationDate(Date creationDate) {
	this->creationDate = creationDate;
}

void Advertisement::setPrice(float newPrice) {
	this->price = newPrice;
}

void Advertisement::setCategory(Category newCategory) {
	this->category = newCategory;
}

string Advertisement::getImageAt(unsigned int index) const {
	return imagesPath[index];
}

void Advertisement::addImage(string path) {
	imagesPath.push_back(path);
}

void Advertisement::incrementViews() {
	views++;

}

bool Advertisement::searchForText(string text) const {
	if (title.find(text, 0) != -1)
		return true;

	if (description.find(text, 0) != -1)
		return true;

	return false;
}

bool Advertisement::operator==(Advertisement* ad) const {
	return (this->id == ad->id);
}

ostream& operator<<(ostream& out, Advertisement &ad) {
	char separationChar = '\n';
	//TODO print category to file, not sure how.
	//does not print id

	out << separationChar << ad.getType() << separationChar << ad.title
			<< separationChar << ad.views << separationChar
			<< categoryToString(ad.category) << separationChar << ad.description
			<< separationChar << ad.creationDate << separationChar << ad.price
			<< separationChar << ad.negotiable;

	ad.print(out);

	return out;
}

istream& operator>>(istream& in, Advertisement &ad) {
	stringstream ss;
	string temp;
	//TODO print category from file to variable, not sure how.

	getline(in, ad.title);
	getline(in, temp);
	ss << temp;
	ss >> ad.views;
	ss.str("");
	getline(in, temp);
	ad.category = stringToCategory(temp);
	getline(in, ad.description);
	getline(in, temp);
	Date date(temp);
	ad.creationDate = date;
	getline(in, temp);
	ss << temp;
	ss >> ad.price;
	ss.str("");
	getline(in, temp);
	if (temp == "1")
		ad.negotiable = true;
	else
		ad.negotiable = false;
	return in;
}

Location Advertisement::getLocation() const {
	return owner->getLocation();
}

void Advertisement::setOwner(User* owner) {
	this->owner = owner;
}

