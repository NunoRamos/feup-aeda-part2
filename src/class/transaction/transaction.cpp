#include "transaction.h"

unsigned int Transaction::nextId = 0;

Transaction::Transaction(User* buyer, User* seller, float price) {
	this->id = nextId;
	this->buyer = buyer;
	this->seller = seller;
	this->price = price;
	this->date = Date::now();
	nextId++;
	buyer->incrementTransactions();
	buyer->setLastTransaction();
	seller->incrementTransactions();
	seller->setLastTransaction();
}

Transaction::Transaction(User* buyer, User* seller, float price, Date date){
	this->id = nextId;
	this->buyer = buyer;
	this->seller = seller;
	this->price = price;
	this->date = date;
	nextId++;
	buyer->incrementTransactions();
	buyer->setLastTransaction(date);
	seller->incrementTransactions();
	seller->setLastTransaction(date);
}

unsigned int Transaction::getId() const{
	return id;
}

User* Transaction::getBuyer() const{
	return buyer;
}

User* Transaction::getSeller() const{
	return seller;
}

float Transaction::getPrice() const{
	return price;
}

Date Transaction::getDate() const{
	return date;
}

Transaction::~Transaction(){

}
