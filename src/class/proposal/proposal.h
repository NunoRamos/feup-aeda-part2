#ifndef PROPOSAL_H
#define PROPOSAL_H

#include "../user/user.h"

class User;

class Proposal {
	float price;
	User* proposalOwner;
public:
	Proposal(User* proposalOwner, float price);
	float getPrice();
	User* getOwner();
	bool operator<(const Proposal &p) const;
};

class CompareProposal{
public:
	bool operator()(const Proposal *p1, const Proposal *p2);
};

#endif
