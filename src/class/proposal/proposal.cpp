/*
 * proposal.cpp
 *
 *  Created on: 18/12/2015
 *      Author: Bernardo
 */

#include "proposal.h"

Proposal::Proposal(User* proposalOwner, float price) {
	this->proposalOwner = proposalOwner;
	this->price = price;
}

bool Proposal::operator<(const Proposal &p) const{
	return this->price > p.price;
}

float Proposal::getPrice(){
	return price;
}

User* Proposal::getOwner(){
	return proposalOwner;
}



bool CompareProposal::operator()(const Proposal *p1, const Proposal *p2){
	return !(*p1 < *p2);
}
