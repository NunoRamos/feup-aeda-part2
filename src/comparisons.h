/*
 * comparisons.h
 *
 *  Created on: 20/12/2015
 *      Author: Nuno
 */

#ifndef SRC_COMPARISONS_H_
#define SRC_COMPARISONS_H_

#include "class/advertisement/advertisement.h"

class CompAscPrice {
public:
	CompAscPrice() {
	}
	;
	bool operator()(const Advertisement* lhs, const Advertisement* rhs) const {
		if (lhs->hasUserPaid() && rhs->hasUserPaid())
			return (lhs->getPrice() > rhs->getPrice());
		else if (lhs->hasUserPaid())
			return false;
		else if (rhs->hasUserPaid())
			return true;

		return (lhs->getPrice() > rhs->getPrice());
	}

};

class CompAscCategory {
public:
	CompAscCategory() {
	}
	;
	bool operator()(const Advertisement* lhs, const Advertisement* rhs) const {
		if (lhs->hasUserPaid() && rhs->hasUserPaid())
			return (lhs->getCategory() > rhs->getCategory());
		else if (lhs->hasUserPaid())
			return false;
		else if (rhs->hasUserPaid())
			return true;

		return (lhs->getCategory() > rhs->getCategory());
	}
};

class CompAscKeyword {
public:
	CompAscKeyword() {
	}
	;
	bool operator()(const Advertisement* lhs, const Advertisement* rhs) const {
		if (lhs->hasUserPaid() && rhs->hasUserPaid()) {
			if (lhs->getTitle() == rhs->getTitle())
				return (lhs->getDescription() > rhs->getDescription());
			else
				return (lhs->getTitle() > rhs->getTitle());
		} else if (lhs->hasUserPaid())
			return false;
		else if (rhs->hasUserPaid())
			return true;

		if (lhs->getTitle() == rhs->getTitle())
			return (lhs->getDescription() > rhs->getDescription());

		return (lhs->getTitle() > rhs->getTitle());
	}
};

class CompAscLocCity {
public:
	CompAscLocCity() {
	}
	;
	bool operator()(const Advertisement* lhs, const Advertisement* rhs) const {
		if (lhs->hasUserPaid() && rhs->hasUserPaid())
			return (lhs->getLocation().getCity() > rhs->getLocation().getCity());
		else if (lhs->hasUserPaid())
			return false;
		else if (rhs->hasUserPaid())
			return true;

		return (lhs->getLocation().getCity() > rhs->getLocation().getCity());
	}
};

class CompAscLocCounty {
public:
	CompAscLocCounty() {
	}
	;
	bool operator()(const Advertisement* lhs, const Advertisement* rhs) const {
		if (lhs->hasUserPaid() && rhs->hasUserPaid())
			return (lhs->getLocation().getCounty()
					> rhs->getLocation().getCounty());
		else if (lhs->hasUserPaid())
			return false;
		else if (rhs->hasUserPaid())
			return true;

		return (lhs->getLocation().getCounty() > rhs->getLocation().getCounty());
	}
};

class CompAscLocDistrict {
public:
	CompAscLocDistrict() {
	}
	;
	bool operator()(const Advertisement* lhs, const Advertisement* rhs) const {
		if (lhs->hasUserPaid() && rhs->hasUserPaid())
			return (lhs->getLocation().getDistrict()
					> rhs->getLocation().getDistrict());
		else if (lhs->hasUserPaid())
			return false;
		else if (rhs->hasUserPaid())
			return true;

		return (lhs->getLocation().getDistrict()
				> rhs->getLocation().getDistrict());
	}
};

#endif /* SRC_COMPARISONS_H_ */
