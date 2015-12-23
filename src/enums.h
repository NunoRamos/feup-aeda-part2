/**
 * @file enums.h
 *
 * @brief Header file with enumerations and their conversion*/

/**
 * @file enums.cpp
 *
 * @brief Code for enumerations and their conversion*/

#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

using namespace std;

namespace enums{
/**
 * @brief Categories for the different kinds of advertisements.
 */
enum Category{
	Agriculture, Animals, BabyAndChildren, Fashion, Home, Job, Leisure,
	PhonesAndTablets, RealEstate, Services, Sports, Technology, Vehicles,
	Others
};

/**
 * @brief Condition for the different kinds of product being sold.
 */
enum Condition{
	New, UsedAsNew, Functional, ForParts
};

}

using namespace enums;

/**
 * @brief See if validCategory is a valid category then changes the value of category
 *
 * @param isValidCategory to compare with the enums
 *
 * @return Returns true if is a valid category
 */
bool validCategory(string isValidCategory);

/**
 * @brief Changes a string to a category
 *
 * @param validCategory to transform in a category
 *
 * @return Returns one Category
 */
Category stringToCategory(string validCategory);

/**
 * @brief Changes a string to a category
 *
 * @param validCategory  to transform in a string
 *
 * @return Returns one string
 */
string categoryToString(Category validCategory);

/**
 * @brief See if validCategory is a valid category then changes the value of category
 *
 * @param isValidCondition to compare with the enums
 *
 * @return Returns true if is a valid category
 */
bool validCondition(string isValidCondition);

/**
 * @brief Changes a string to a condition
 *
 * @param validCondition to transform in a condition
 *
 * @return Returns one condition
 */
Condition stringToCondition(string validCondition);
/**
 * @brief Changes a condition to a string
 *
 * @param validCondition  to transform in a string
 *
 * @return Returns one string
 */
string conditionToString(Condition validCondition);

#endif
