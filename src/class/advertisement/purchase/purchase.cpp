#include "purchase.h"
#include "../advertisement.h"
#include <iostream>
#include "../../data/data.h"

Purchase::Purchase(User* owner, string title, Category category, string description, float price):
Advertisement(owner, title, category, description, price){}

Purchase::~Purchase(){ }

char Purchase::getType() const{
	return 'P';
}

ostream& Purchase::print(ostream& out){ return out; }

Transaction* Purchase::viewProposals(){
	if(proposals.empty()){
		cout << "You have not received any proposals.";
		return NULL;
	}

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
	case 1:{
		User* seller = proposals.top()->getOwner();
		float price = proposals.top()->getPrice();

		while(!proposals.empty()){
			delete proposals.top();
			proposals.pop();
		}
		return new Transaction(owner, seller, price);
		break;
	}
	case 2:
		proposals.pop();
		return NULL;
		break;
	case 3:
		return NULL;
		break;
	}
}

void Purchase::addProposal(Proposal* p){
	proposals.push(p);
}
