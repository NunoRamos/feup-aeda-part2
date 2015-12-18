#include "sale.h"
#include "../../menu/adDisplayMenu/adDisplayMenu.h"
#include "../../../enums.h"
#include <iostream>

using namespace std;

Sale::Sale(User* owner, string title, Category category, string description, Condition productCondition, float price) :
Advertisement(owner, title, category, description, price){
	this->productCondition = productCondition;
}

Sale::~Sale(){ }

char Sale::getType() const{
	return 'S';
}

Condition Sale::getCondition() const{
	return productCondition;
}

ostream& Sale::print(ostream& out){
	out << endl << conditionToString(productCondition);
}
