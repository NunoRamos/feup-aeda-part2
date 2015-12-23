#ifndef PROPOSAL_H
#define PROPOSAL_H

#include "../PtrUser/PtrUser.h"
#include "../user/user.h"

class PtrUser;

/**
 * @brief Proposal class
 */
class Proposal {
	float price;
	PtrUser *proposalOwner;
public:
	Proposal(PtrUser proposalOwner, float price);
	float getPrice();
	PtrUser getOwner();
	bool operator<(const Proposal &p) const;
};

/**
 * @brief Compares two proposals
 */
class CompareProposal{
public:
	bool operator()(const Proposal *p1, const Proposal *p2);
};

#endif
