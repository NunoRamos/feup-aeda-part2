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

	return out;
}

void Sale::addProposal(Proposal* p){
	proposals.push(p);
}

void Sale::viewProposals(){
	if(proposals.empty()){
		cout << "You have not received any proposals.";
		return;
	}
	Date transactionDate;

	int input;
	cout << "Price offered: " << proposals.top()->getPrice() << endl;
	cout << "Offer from: " << proposals.top()->getOwner()->getName() << endl;
	cout << "1 - Accept\n";
	cout << "2 - Refuse\n";
	cout << "3 - Back\n";

	do{
		cout << "Please select a valid option\n";
		cin >> input;
	} while(input < 0 || input > 3);

	switch(input){
	case 1:
		//TODO negocio feito
		owner->incrementTransactions();
		owner->setLastTransaction(transactionDate);
		//data ultima criação=data atual
		break;
	case 2:
		proposals.pop();
		break;
	case 3:
		break;
	}
}
