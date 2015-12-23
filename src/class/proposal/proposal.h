/**
 * @file proposal.h
 *
 * @brief Header file for class Proposal*/

/**
 * @file proposal.cpp
 *
 * @brief Code for class Proposal*/

#ifndef PROPOSAL_H
#define PROPOSAL_H

#include "../PtrUser/PtrUser.h"
#include "../user/user.h"

class PtrUser;

/**
 * @brief Proposal class
 */
class Proposal {
	float price; ///< Price proposed
	PtrUser *proposalOwner; ///< Who made the proposal
public:
	/**
	 * @brief Construtor for class Proposal
	 *
	 * @param proposalOwner Who made the proposal
	 * @param price Price proposed
	 */
	Proposal(PtrUser proposalOwner, float price);

	/**
	 * @brief Gets proposed price
	 *
	 * @return Returns proposed price
	 */
	float getPrice();

	/**
	 * @brief Gets proposal owner
	 *
	 * @return Returns proposal owner
	 */
	PtrUser getOwner();

	/**
	 * @brief Compares two proposals
	 *
	 * @param p Second proposal to be compared
	 *
	 * @return Returns true if this is lesser than p
	 */
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
