/**
 * @file data.h
 *
 * @brief Header file for class Data*/

/**
 * @file data.cpp
 *
 * @brief Code for class Data*/


#ifndef DATA_H
#define DATA_H

#include<vector>
#include<unordered_set>

#include "../user/user.h"
#include "../transaction/transaction.h"
#include "../../BST.h"

using namespace std;

typedef struct {
	size_t operator() (const Transaction *t) const{
		return t->getId();
	}
	bool operator() (const Transaction *t1, const Transaction *t2) const{
		return t1->getId() == t2->getId();
	}
} TransactionHash;

//the different types of searches
namespace sort{
enum Order{
	PriceAsc, CategoryAsc, KeywordAsc, LocCityAsc, LocCountyAsc, LocDistrictAsc
};
}

/**
 * @brief User and Advertisement data class
 */
class Data{
private:
	const string path = "C:/Users/Bernardo/git/AEDA_OLZ_part2/data/";//const string path = "/data/"; ///< used to save and load users.
	vector<Advertisement*> advertisements; ///< Vector of pointers to all advertisements
	vector<User> users; ///< Vector of all users
	User* signedInUser; ///< Pointer to user that is currently signed in
	BST<User*> usersTransactions; ///< BST about users transactions
	unordered_set<Transaction*, TransactionHash> transactions;

public:
	/**
	 * @brief Constructor for class Data
	 */
	Data();

	/**
	 * @brief Destructor for class Data. Deletes all advertisements.
	 */
	~Data();

	/**
	 * @brief Sign user in
	 *
	 * @param email Email of user to try to sign in
	 * @param password Password of user to try to sign in
	 *
	 * @return Returns true if the user has successfully signed in
	 */
	bool signIn(const string &email, const string &password);

	/**
	 * @brief Add user to User vector
	 *
	 * @param user User to be added in
	 *
	 * @return Returns true if the user has been successfully added
	 */
	bool signUp(User &user);

	/**
	 * @brief Loads users to user vector from path
	 *
	 * @return Returns true if the users have been successfully loaded
	 */
	bool loadUsers();

	/**
	 * @brief Save users to path from user vector
	 *
	 * @return Returns true if the users have been successfully saved
	 */
	bool saveUsers();

	/**
	 * @brief Removes advertisement from advertisement vector
	 */
	void removeAdvertisement(Advertisement* ad);

	/**
	 * @brief Added advertisement to advertisement vector
	 */
	void addAdvertisement(Advertisement* ad);

	/**
	 * @brief Searches for ads with text in it.
	 *
	 * @param text  string used to search
	 *
	 * @return Returns vector of pointers to Advertisement with ads that have text either in their title or their description
	 */
	vector<Advertisement*> searchForAds(string text);

	/**
	 * @brief Searches for ads category with text in it.
	 *
	 * @param text category used to search
	 *
	 * @return Returns vector of pointers to Advertisement with ads that have same category
	 */
	vector<Advertisement*> searchForAdsCategory(Category text);

	/**
	 * @brief Searches for ads that have similar price to price
	 *
	 * @param inicialPrice lower price the user want to spend
	 * @param finalPrice higher price the user want to spend
	 *
	 * @return Returns vector of pointers to Advertisement with ads that have similar price
	 */
	vector<Advertisement*> searchForAdsPrice(float inicialPrice,float finalPrice);

	/**
	 * @brief Creates a sub vector of vector ads, that only contained sale or purchase ads depending saleOrPurchase
	 *
	 * @param ads vector to create a sub vector
	 * @param saleOrPurchase decided if is a sub vector of sale ads or purchase ads
	 *
	 * @return Returns a vector with sale ads only or purchase ads only
	 */
	vector<Advertisement*> vectorOfSaleOrPurchase(vector<Advertisement*> ads, char saleOrPurchase);

	/**
	 * @brief Signs user out
	 */
	void signOut();

	/**
	 * @brief Gets signed in user
	 *
	 * @return Returns pointer to signed in user
	 */
	User* getSignedInUser() const;

	/**
	 * @brief Gets ads in same city as parameter
	 *
	 * @param city City
	 *
	 * @return Returns vector of advertisements whose owners are from the same city as parameter
	 */
	vector<Advertisement*> getAdsInSameCity(string city);

	/**
	 * @brief Gets ads in same county as parameter
	 *
	 * @param county County
	 *
	 * @return Returns vector of advertisements whose owners are from the same county as parameter
	 */
	vector<Advertisement*> getAdsInSameCounty(string county);

	/**
	 * @brief Gets ads in same district as parameter
	 *
	 * @param district District
	 *
	 * @return Returns vector of advertisements whose owners are from the same district as parameter
	 */
	vector<Advertisement*> getAdsInSameDistrict(string district);

	/**
	 * @brief Removes user
	 *
	 * @param user User to remove
	 */
	void removeUser(User* user);
	
	/*
	 * @brief get usersTransactions bst
	 *
	 */
	BST<User*> getUsersTransactions() const;
	/*
	 *@brief add user to bst
	 *
	 *@param u1 User
	 */
	void addUserToBst(User* u1);

	/*
	 *@brief remove userf from bst
	 *
	 *@param u1 User
	 */
	void removeUserFromBst(User* u1);

	/**
	 * @brief Adds completed transaction
	 *
	 * @param t Transaction to be added
	 */
	void addTransaction(Transaction* t);

	/**
	 * @brief Loads transactions
	 */
	void loadTransactions();

	/**
	 * @brief Saves transactions
	 */
	void saveTransactions();

	/**
	 * @brief Gets user from email
	 *
	 * @param email User email
	 *
	 * @return User
	 */
	User* getUser(string email);

	/**
	 * @brief Delete advertisement
	 *
	 * @param ad Advertisement to delete
	 *
	 * @return Returns true if the advertisement was deleted, returning false otherwise.
	 */
	bool deleteAd(Advertisement* ad);

	/**
	 * @brief Adds all users with at least one transaction to the BST
	 */
	void addUsersToBst();

	/**
	 * @brief Updates tree
	 */
	void updateTree();
	
	/*
	 * @brief Orders a vector by transforming in a priority queue
	 *
	 * @param toOrder vector to order
	 * @param orderType to helping on choosing comparing function
	 */
	void orderResults(vector<Advertisement*>& toOrder, sort::Order orderType);
	
	/**
	 * @brief Updates transactions
	 */
	void updateTransactions();
};

#endif
