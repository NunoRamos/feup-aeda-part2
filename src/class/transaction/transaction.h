#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../date/date.h"
#include "../user/user.h"

class User;

class Transaction{
private:
	static unsigned int nextId;
	unsigned int id;
	User* buyer;
	User* seller;
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
	Transaction(User* buyer, User* seller, float price);

	/**
	 * @brief Constructor for Transaction class
	 *
	 * @param buyer Buyer
	 * @param seller Seller
	 * @param price Price
	 * @param date Date
	 */
	Transaction(User* buyer, User* seller, float price, Date date);

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
	User* getBuyer() const;

	/**
	 * @brief Returns seller
	 *
	 * @return Returns seller
	 */
	User* getSeller() const;

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

	/**
	 * @brief Print to out stream
	 *
	 * @param out Output stream
	 * @param t Transaction to print
	 */
	friend void operator<<(ostream& out, const Transaction& t);

	/**
	 * @brief Read from in stream
	 *
	 * @param in Input stream
	 * @param t Transaction to read
	 */
	friend void operator>>(istream& in, Transaction& t);
};


#endif
