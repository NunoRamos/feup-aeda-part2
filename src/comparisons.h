/*
 * comparisons.h
 *
 *  Created on: 20/12/2015
 *      Author: Nuno
 */

#ifndef SRC_COMPARISONS_H_
#define SRC_COMPARISONS_H_

#include "class/advertisement/advertisement.h"

/**
 * @brief Compares Advertisements by ascending price
 */
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

/**
 * @brief Compares Advertisements by ascending category
 */
class CompAscCategory {
public:
	CompAscCategory() { }
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

/**
 * @brief Compares Advertisements by ascending keyword
 */
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

/**
 * @brief Compares Advertisements by ascending city
 */
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

/**
 * @brief Compares Advertisements by ascending county
 */
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

/**
 * @brief Compares Advertisements by ascending district
 */
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
