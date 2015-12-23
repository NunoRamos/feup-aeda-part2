/**
 * @file sale.h
 *
 * @brief Header file for class Sale*/

/**
 * @file sale.cpp
 *
 * @brief Code for class Sale*/

#ifndef SALE_H
#define SALE_H

#include <queue>
#include <vector>

#include"../../../enums.h"
#include "../advertisement.h"
#include "../../proposal/proposal.h"

using namespace enums;

/**
 * @brief Sale class
 */
class Sale : public Advertisement{
private:
	Condition productCondition; ///< Condition of product being sold
	priority_queue<Proposal*> proposals; ///< Receive proposals
public:
	/**
	 * @brief Sale constructor
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 * @param category Advertisement category
	 * @param description Advertisement description
	 * @param productCondition Product condition
	 * @param price Product price
	 */
	Sale(PtrUser owner, string title, Category category, string description, Condition productCondition, float price);

	/**
	 * @brief Sale destructor
	 */
	~Sale();

	/**
	 * @brief Returns a P if is a purchase ad or a S if is a sale ad
	 *
	 * @return Returns a char ( P(urchase) / S(ale))
	 */
	char getType() const;

	/**
	 * @brief Gets condition
	 *
	 * @return Returns condition
	 */
	Condition getCondition() const;

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
