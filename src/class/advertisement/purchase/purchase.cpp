#include "purchase.h"
#include "../advertisement.h"
#include <iostream>

Purchase::Purchase(User* owner, string title, Category category, string description, float price):
	Advertisement(owner, title, category, description, price){}

Purchase::~Purchase(){ }

char Purchase::getType() const{
	return 'P';
}

ostream& Purchase::print(ostream& out){ }

void Purchase::viewProposals(){
	int input;
	cout << "Price offered: " << proposals.top()->getPrice() << endl;
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
		break;
	case 2:
		proposals.pop();
		break;
	case 3:
		break;
	}
}

void Purchase::addProposal(Proposal* p){
	proposals.push(p);
}
