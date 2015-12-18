#include "purchase.h"
#include "../advertisement.h"

Purchase::Purchase(User* owner, string title, Category category, string description, float price):
	Advertisement(owner, title, category, description, price){}

Purchase::~Purchase(){ }

char Purchase::getType() const{
	return 'P';
}

ostream& Purchase::print(ostream& out){ }
