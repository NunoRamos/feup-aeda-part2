/*
 * PtrUser.cpp
 *
 *  Created on: 23/12/2015
 *      Author: Utilizador
 */

#include "PtrUser.h"
#include <iostream>
using namespace std;

PtrUser::PtrUser(User* userPtr){

	this->userPtr=userPtr;
}

User* PtrUser::getUserPtr() const{
	return userPtr;
}


bool PtrUser:: operator< (const PtrUser &right) const{


	if(this->userPtr->getTransactions()< right.getUserPtr()->getTransactions())
		return false;
	else if (this->userPtr->getTransactions()== right.getUserPtr()->getTransactions()){
		if(this->userPtr->getlastTransaction()< right.getUserPtr()->getlastTransaction()){
			cout<<"passei no overloading"<<endl;
			return false;
		}
		else if (this->userPtr->getlastTransaction()< right.getUserPtr()->getlastTransaction())
		{
			if (this->userPtr->getEmail() < right.getUserPtr()->getEmail())
				return false;
		}
	}

	return true;

}
