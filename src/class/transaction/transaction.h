/**
 * @file transaction.h
 *
 * @brief Header file for class Transaction*/

/**
 * @file transaction.cpp
 *
 * @brief Code for class Transaction*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../PtrUser/PtrUser.h"
#include "../date/date.h"
#include "../user/user.h"

class PtrUser;

/**
 * @brief Transaction class
 */
class Transaction{
private:
	static unsigned int nextId;
	unsigned int id;
	PtrUser *buyer;
	PtrUser *seller;
	float price;
	Date date;
public:
	/**
	 * @brief Constructor for Transaction class
	 *
	 * @param buyer Buyer
	 * @param seller Seller
	 * @param price Price
	 */
	Transaction(PtrUser buyer, PtrUser seller, float price);

	/**
	 * @brief Constructor for Transaction class
	 *
	 * @param buyer Buyer
	 * @param seller Seller
	 * @param price Price
	 * @param date Date
	 */
	Transaction(PtrUser buyer, PtrUser seller, float price, Date date);

	/**
	 * @brief Returns transaction id
	 *
	 * @return Returns transaction id
	 */
	unsigned int getId() const;

	/**
	 * @brief Returns buyer
	 *
	 * @return Returns buyer
	 */
	PtrUser getBuyer() const;

	/**
	 * @brief Returns seller
	 *
	 * @return Returns seller
	 */
	PtrUser getSeller() const;

	/**
	 * @brief Returns price
	 *
	 * @return Returns price
	 */
	float getPrice() const;

	/**
	 * @brief Returns date
	 *
	 * @return Returns date
	 */
	Date getDate() const;

	/**
	 * @brief Destructor for Transaction class
	 */
	~Transaction();
};


#endif
