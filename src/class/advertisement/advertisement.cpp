#include "advertisement.h"
#include "../menu/adDisplayMenu/adDisplayMenu.h"
#include<iostream>
#include<sstream>

unsigned int Advertisement::nextId = 0;

Advertisement::Advertisement(PtrUser owner, string title, Category category,
		string description, float price) {
	this->owner = new PtrUser(owner.getUserPtr());
	this->title = title;
	this->category = category;
	this->description = description;
	this->price = price;
	negotiable = true;
	featured = false;
	id = nextId;
	nextId++;
	views = 0;
}

Advertisement::~Advertisement() {
	nextId--;
}

unsigned int Advertisement::getId() const {
	return id;
}

PtrUser Advertisement::getOwner() {
	return *owner;
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

string Advertisement::gethighlightEndDate() const {
	return highlightEndDate.toString();
}

bool Advertisement::isPriceNegotiable() const {
	return negotiable;
}

bool Advertisement::hasUserPaid() const {
	return featured;
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

void Advertisement::setFeatured(bool newValue) {
	this->featured = newValue;
}

void Advertisement::sethighlightEndDate(Date newDate) {
	this->highlightEndDate = newDate;
}

void Advertisement::extendDurationHighligh(unsigned int duration) {
	if (featured) {
		if (highlightEndDate.getDay() + duration
				> Date::numberOfDaysInAMonth(highlightEndDate.getMonth(),
						highlightEndDate.getYear())) {
			highlightEndDate.setDay(
					duration
							- (Date::numberOfDaysInAMonth(
									highlightEndDate.getMonth(),
									highlightEndDate.getYear())
									- highlightEndDate.getDay()));
			if (highlightEndDate.getMonth() + 1 > 12) { //happy new year!!!!!!!!!!
				highlightEndDate.setMonth(1);
				highlightEndDate.setYear(highlightEndDate.getYear() + 1);
			} else
				highlightEndDate.setMonth(highlightEndDate.getMonth() + 1);
		} else {
			highlightEndDate.setDay(highlightEndDate.getDay() + duration);
		}
	} else {
		highlightEndDate.setDay(0);
		highlightEndDate.setMonth(0);
		highlightEndDate.setYear(0);
	}
}

void Advertisement::incrementViews() {
	views++;

}

bool Advertisement::searchForText(const string& text) const {
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

	out << separationChar << ad.getType() << separationChar << ad.title
			<< separationChar << ad.views << separationChar
			<< categoryToString(ad.category) << separationChar << ad.description
			<< separationChar << ad.creationDate << separationChar << ad.price
			<< separationChar << ad.negotiable << separationChar << ad.featured;
	if (ad.featured)
		out << separationChar << ad.highlightEndDate;

	ad.print(out);

	return out;
}

istream& operator>>(istream& in, Advertisement &ad) {
	stringstream ss;
	string temp;

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
	getline(in, temp);
	if (temp == "1")
		ad.featured = true;
	else
		ad.featured = false;

	return in;
}

Location Advertisement::getLocation() const {
	return owner->getUserPtr()->getLocation();
}

void Advertisement::setOwner(PtrUser owner) {
	this->owner = new PtrUser(owner.getUserPtr());
}

