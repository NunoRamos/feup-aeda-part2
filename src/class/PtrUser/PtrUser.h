/**
 * @file PtrUser.h
 *
 * @brief Header file for class PtrUser*/

/**
 * @file PtrUser.cpp
 *
 * @brief Code for class PtrUser*/

#ifndef SRC_CLASS_PTRUSER_PTRUSER_H_
#define SRC_CLASS_PTRUSER_PTRUSER_H_

#include "../date/date.h"
#include "../user/user.h"

class User;

/**
 * @brief Pointer to User class. Used with BST.
 */
class PtrUser{
protected:
	User* userPtr; ///< Pointer to User
public:
	/**
	 * @brief Default construtor for PtrUser
	 */
	PtrUser();

	/**
	 * @brief Constructor using class user
	 *
	 * @param userPtr Pointer to user
	 */
	PtrUser(User* userPtr);
	/**
	 * @brief Gets pointer to user
	 *
	 * @return Returns pointer to user
	 */
	User* getUserPtr() const;
	/**
	 * @brief overloading of operator< for user pointers
	 *
	 * @param right right object to compare
	 *
	 * @return Returns true if left operand is lesser than right
	 */
	bool operator< (const PtrUser &right) const;
};


#endif /* SRC_CLASS_PTRUSER_PTRUSER_H_ */
