/**
 * @file user.h
 *
 * @brief Header file for class User*/

/**
 * @file user.cpp
 *
 * @brief Code for class User*/

#ifndef USER_H
#define USER_H

#include<string>
#include<vector>

#include "../advertisement/advertisement.h"
#include "../date/date.h"
#include "../location/location.h"


using namespace std;

class Advertisement;//had to do this to allow cyclic calling of class

/**
 * @brief User class
 */
class User{
protected:
	vector<Advertisement*> advertisements; ///< Advertisements owned by the user
	string email; ///< User email
	string password; ///< User password
	string name; ///< User name
	string phoneNumber; ///< User phone number
	Location location; ///< User location
	bool showEmail; ///< Whether the user's email should be displayed in his/hers ads
	bool showName; ///< Whether the user's name should be displayed in his/hers ads
	bool showPhoneNumber; ///< Whether the user's phone number should be displayed in his/hers ads
public:
	/**
	 * @brief User default constructor
	 */
	User();

	/**
	 * @brief User constructor
	 *
	 * @param email User email
	 * @param password User Password
	 * @param name User name
	 * @param phoneNumber User phone number
	 * @param location User location
	 */
	User(string email, string password, string name, string phoneNumber, Location location);

	/**
	 * @brief User constructor
	 *
	 * @param email User email
	 * @param password User Password
	 * @param name User name
	 * @param phoneNumber User phone number
	 * @param location User location as string
	 */
	User(string email, string password, string name, string phoneNumber, string location);

	/**
	 * @brief Gets user email
	 *
	 * @return Returns user email
	 */
	string getEmail() const;

	/**
	 * @brief Gets user name
	 *
	 * @return Returns user name
	 */
	string getName() const;

	/**
	 * @brief Gets user phone number
	 *
	 * @return Returns user phone number
	 */
	string getPhoneNumber() const;

	/**
	 * @brief Gets user password
	 *
	 * @return Returns user password
	 */
	string getPassword() const;
	/**
	 * @brief Gets user location
	 *
	 * @return Returns user location
	 */
	Location getLocation() const;

	/**
	 * @brief Gets user location as string
	 *
	 * @return Returns user location as string
	 */
	string getLocationString() const;

	/**
	 * @brief Gets user showEmail attribute
	 *
	 * @return Returns user showEmail
	 */
	bool getShowEmail() const;

	/**
	 * @brief Gets user showName attribute
	 *
	 * @return Returns user showName
	 */
	bool getShowName() const;

	/**
	 * @brief Gets user showPhoneNumber attribute
	 *
	 * @return Returns user showPhoneNumber
	 */
	bool getShowPhoneNumber() const;

	/**
	 * @brief Sets user email
	 *
	 * @param email User email
	 */
	void setEmail(string email);

	/**
	 * @brief Sets user showEmail attribute
	 *
	 * @param show Whether showEmail should be true or not
	 */
	void setShowEmail(bool show);

	/**
	 * @brief Sets user showName attribute
	 *
	 * @param show Whether showName should be true or not
	 */
	void setShowName(bool show);

	/**
	 * @brief Sets user showPhoneNumber attribute
	 *
	 * @param show Whether showPhoneNumber should be true or not
	 */
	void setShowPhoneNumber(bool show);


	/**
	 * @brief Signs in user
	 *
	 * @param password User password
	 *
	 * @return Returns if the user has successfully signed in
	 */
	bool signIn(string password) const;

	/**
	 * @brief User >> operator
	 *
	 * @return Returns input stream
	 */
	friend istream& operator>>(istream& in, User &user);

	/**
	 * @brief Removes advertisement from advertisements the user owns.
	 *
	 * @param ad Pointer to advertisement to remove
	 */
	void removeAdvertisement(Advertisement* ad);

	/**
	 * @brief Add advertisement to user advertisements.
	 *
	 * @param newAdvertisement Pointer to New Advertisement
	 */
	void addAdvertisement(Advertisement *newAdvertisement);

	/**
	 * @brief Edits a user advertisement.
	 */
	void editAdvertisement();

	/**
	 * @brief Compares if this user is equal to u1, using email attribute.
	 *
	 * @param u1 User to be compared with
	 *
	 * @return Returns true if this and u1 have the same email. Returns false otherwise.
	 */
	bool operator==(const User & u1) const;

	/**
	 * @brief Saves user and every advertisement he/she owns
	 *
	 * @param out Output file
	 * @param user User to print
	 *
	 * @return Returns out stream
	 */
	friend ostream& operator<<(ostream& out, const User &user);

	/**
	 * @brief Gets all advertisements the user has
	 *
	 * @return Returns all advertisements the user has
	 */
	vector<Advertisement *> getAdvertisements();
	
	/**
	 * @brief Sets all ads in user advertisement to have the user as owner
	 */
	void setAdsOwner();

	/**
	 * @brief Deletes all ads
	 */
	void deleteAds();

	/**
	 * @brief Send proposal
	 *
	 * @param ad Advertisement
	 */
	void sendProposal(Advertisement* ad);
};

#endif
