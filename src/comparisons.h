/*
 * comparisons.h
 *
 *  Created on: 20/12/2015
 *      Author: Nuno
 */

#ifndef SRC_COMPARISONS_H_
#define SRC_COMPARISONS_H_

#include "class/advertisement/advertisement.h"

class CompAscPrice{
public:
	CompAscPrice(){};
	bool operator() (const Advertisement& lhs, const Advertisement& rhs) const{
		if(lhs.hasUserPaid() && rhs.hasUserPaid())
			return (lhs.getPrice() < rhs.getPrice());
		else if(lhs.hasUserPaid())
			return false;

		return true;
	}

};



#endif /* SRC_COMPARISONS_H_ */
