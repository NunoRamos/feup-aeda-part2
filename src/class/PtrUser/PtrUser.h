/*
 * PtrUser.h
 *
 *  Created on: 23/12/2015
 *      Author: Utilizador
 */

#ifndef SRC_CLASS_PTRUSER_PTRUSER_H_
#define SRC_CLASS_PTRUSER_PTRUSER_H_

#include "../date/date.h"
#include "../user/user.h"

class User;

class PtrUser{
protected:
	User* userPtr;
public:
	/**
	 * @brief constructor using class User
	 *
	 * @param userPtr Apontador para user
	 */
	PtrUser(User* userPtr);
	/**
	 * @brief Retorna apontador para User
	 *
	 */
	User* getUserPtr() const;
	/**
	 * @brief overloading of operator < for users pointers
	 *
	 * @param left 1ºobjeto a comparar
	 *
	 * @param right segundo objeto a comparar
	 */
	bool operator< (const PtrUser &right) const;


};


#endif /* SRC_CLASS_PTRUSER_PTRUSER_H_ */
