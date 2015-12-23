#include "transaction.h"

unsigned int Transaction::nextId = 0;

Transaction::Transaction(PtrUser buyer, PtrUser seller, float price) {
	this->id = nextId;
	this->buyer = new PtrUser(buyer.getUserPtr());
	this->seller = new PtrUser(seller.getUserPtr());
	this->price = price;
	this->date = Date::now();
	nextId++;
	buyer.getUserPtr()->incrementTransactions();
	buyer.getUserPtr()->setLastTransaction();
	seller.getUserPtr()->incrementTransactions();
	seller.getUserPtr()->setLastTransaction();
}

Transaction::Transaction(PtrUser buyer, PtrUser seller, float price, Date date){
	this->id = nextId;
	this->buyer = new PtrUser(buyer.getUserPtr());
	this->seller = new PtrUser(seller.getUserPtr());
	this->price = price;
	this->date = date;
	nextId++;
	buyer.getUserPtr()->incrementTransactions();
	buyer.getUserPtr()->setLastTransaction(date);
	seller.getUserPtr()->incrementTransactions();
	seller.getUserPtr()->setLastTransaction(date);
}

unsigned int Transaction::getId() const{
	return id;
}

PtrUser Transaction::getBuyer() const{
	return *buyer;
}

PtrUser Transaction::getSeller() const{
	return *seller;
}

float Transaction::getPrice() const{
	return price;
}

Date Transaction::getDate() const{
	return date;
}

Transaction::~Transaction(){

}
