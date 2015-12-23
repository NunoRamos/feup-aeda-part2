/**
 * @file purchase.h
 *
 * @brief Header file for class Purchase*/

/**
 * @file purchase.cpp
 *
 * @brief Code for class Purchase*/

#ifndef PURCHASE_H
#define PURCHASE_H

#include "../advertisement.h"
#include "../../proposal/proposal.h"
#include <queue>
#include <vector>

using namespace std;

/**
 * @brief Purchase class
 */
class Purchase : public Advertisement{
private:
	priority_queue<Proposal*, vector<Proposal*>, CompareProposal> proposals; ///< Receive proposals
public:
	/**
	 * @brief Purchase constructor
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 * @param category Advertisement category
	 * @param description Advertisement description
	 * @param price Product price
	 */
	Purchase(PtrUser owner, string title, Category category, string description, float price);

	/**
	 * @brief Purchase destructor
	 */
	~Purchase();

	/**
	 * @brief Returns a P if is a purchase ad or a S if is a sale ad
	 *
	 * @return Returns a char ( P(urchase) / S(ale))
	 */
	char getType() const;

	/**
	 * @brief Shows ad proposals
	 */
	Transaction* viewProposals();

	/**
	 * @brief Add proposal
	 *
	 * @param p Proposal to add
	 */
	void addProposal(Proposal* p);

	/**
	 * @brief Prints to out
	 *
	 * @param out Out stream
	 */
	ostream& print(ostream& out);
};

#endif
