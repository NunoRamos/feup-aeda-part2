#include "../../../menus.h"
#include "adDisplayMenu.h"
#include "../../../enums.h"
#include "../../advertisement/sale/sale.h"
#include <sstream>
#include <iostream>

AdDisplayMenu::AdDisplayMenu(Data* data, Advertisement* ad, unsigned int height,
		unsigned int width, char borderChar) :
		Menu(data, height, width, borderChar) {
	this->ad = ad;
	if (ad->getOwner() != data->getSignedInUser()) {
		ad->incrementViews();
	}

}

void AdDisplayMenu::print() {
	//first line, only borderChar
	for (unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;

	//includes top margin with is a line full of spaces, with borderChar on either side
	for (unsigned int i = 0; i < topMargin; i++)
		emptyLine();

	cout << borderChar << " ";
	string adType;
	if (ad->getType() == 'P')
		adType = "Purchase";
	else
		adType = "Sale";
	adType += " Ad";

	cout << adType << string(width - 3 - adType.length(), ' ') << borderChar
			<< endl;
	emptyLine();

	//display title
	string title = ad->getTitle();
	cout << borderChar << " Title: " << title
			<< string(width - 2 - 8 - title.length(), ' ') << borderChar
			<< endl;

	//a white line between title and description
	emptyLine();

	cout << borderChar << " Category: " << categoryToString(ad->getCategory())
			<< string(
					width - 2 - 11
							- categoryToString(ad->getCategory()).length(), ' ')
			<< borderChar << endl;

	emptyLine();

	//used to add menu options correctly
	string description = ad->getDescription();
	int tempW = width - 2 - 14 - description.length();

	if (tempW < 0)
		tempW = 0;

	cout << borderChar << " Description: " << description << string(tempW, ' ')
			<< borderChar << endl;

	if (ad->getType() == 'S') {
		emptyLine();
		Sale* sale = static_cast<Sale*>(ad);
		string cond = conditionToString(sale->getCondition());
		cout << borderChar << " Product Condition: " << cond
				<< string(width - 2 - 20 - cond.length(), ' ') << borderChar
				<< endl;
	}

	//a white line between description and contacts
	emptyLine();

	cout << borderChar << " Creation Date: " << ad->getCreationDate()
			<< string(width - 2 - 16 - ad->getCreationDate().length(), ' ')
			<< borderChar << endl;

	bool showEmail = ad->getOwner()->getShowEmail();
	bool showName = ad->getOwner()->getShowName();
	bool showPhoneNumber = ad->getOwner()->getShowPhoneNumber();

	if (showEmail || showName || showPhoneNumber) {
		if (showEmail) {
			string email = ad->getOwner()->getEmail();
			cout << borderChar << " Email: " << email
					<< string(width - 2 - 8 - email.length(), ' ') << borderChar
					<< endl;
		}

		if (showName) {
			string name = ad->getOwner()->getName();
			cout << borderChar << " Name: " << name
					<< string(width - 2 - 7 - name.length(), ' ') << borderChar
					<< endl;
		}

		if (showPhoneNumber) {
			string phoneNumber = ad->getOwner()->getPhoneNumber();
			cout << borderChar << " Phone Number: " << phoneNumber
					<< string(width - 2 - 15 - phoneNumber.length(), ' ')
					<< borderChar << endl;
		}
		emptyLine();
	}
	stringstream ss;
	ss << ad->getViews();
	cout << borderChar << " Views: " << ss.str()
			<< string(width - 2 - 8 - ss.str().length(), ' ') << borderChar
			<< endl;
	emptyLine();

	ss.str("");
	ss << ad->getPrice() << "  ";
	if (!ad->isPriceNegotiable())
		ss << "Non-";
	ss << "Negotiable";
	cout << borderChar << " Price: " << ss.str()
			<< string(width - 2 - 8 - ss.str().length(), ' ') << borderChar
			<< endl;

	if (ad->doesUserPaid())
		cout << borderChar << " Paid " << string(width - 2 - 6, ' ')
				<< borderChar << endl;
	else
		cout << borderChar << " Not Paid " << string(width - 2 - 10, ' ')
						<< borderChar << endl;
	emptyLine();

	unsigned int i = 1;
	if (data->getSignedInUser() == ad->getOwner()) {
		string editTitle = "1 - Edit title";
		cout << borderChar << " " << editTitle
				<< string(width - 3 - editTitle.length(), ' ') << borderChar
				<< endl;
		string editDescription = "2 - Edit description";
		cout << borderChar << " " << editDescription
				<< string(width - 3 - editDescription.length(), ' ')
				<< borderChar << endl;
		string editCategory = "3 - Edit category";
		cout << borderChar << " " << editCategory
				<< string(width - 3 - editCategory.length(), ' ') << borderChar
				<< endl;
		string editPrice = "4 - Edit price";
		cout << borderChar << " " << editPrice
				<< string(width - 3 - editPrice.length(), ' ') << borderChar
				<< endl;
		string removeAd = "5 - Remove advertisement";
		cout << borderChar << " " << removeAd
				<< string(width - 3 - removeAd.length(), ' ') << borderChar
				<< endl;
		string viewProposals = "6 - View proposals";
		cout << borderChar << " " << viewProposals
				<< string(width - 3 - viewProposals.length(), ' ') << borderChar
				<< endl;
		i = 7;
	} else {
		string imInterested = " 1 - I'm interested";
		string sendProposal = " 2 - Send proposal";
		i = 3;
		cout << borderChar << imInterested
				<< string(width - imInterested.length() - 2, ' ') << borderChar
				<< endl;
		cout << borderChar << sendProposal
				<< string(width - sendProposal.length() - 2, ' ') << borderChar
				<< endl;
	}
	ss.str("");
	ss << " " << i << " - Exit";
	cout << borderChar << ss.str() << string(width - ss.str().length() - 2, ' ')
			<< borderChar << endl;

	emptyLine();

	//last line
	for (unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;
}

void AdDisplayMenu::createMenu() {
	clearScreen();
	AdDisplayMenu::print();
	int input;
	string title, description, category, answer;
	unsigned int i = 0;
	cout << "What option would you like to choose?" << endl;
	if (data->getSignedInUser() == ad->getOwner()) {
		do {
			if (i > 0) {
				cout << "Please introduce a valid option." << endl;
			}
			cin >> input;
			cin.ignore();
			cin.clear();
			i++;

		} while (input < 1 || input > 7);
		switch (input) {
		case 1:
			cout << "Please introduce the new title." << endl;
			getline(cin, title);
			ad->setTitle(title);
			break;
		case 2:
			cout << "Please introduce the new description." << endl;
			getline(cin, description);
			ad->setDescription(description);
			break;
		case 3:
			cout << "Please introduce the new category." << endl;
			getline(cin, category);
			do {
				if (validCategory(category)) {
					ad->setCategory(stringToCategory(category));
					break;
				} else {
					cout << "Invalid category, try again. Press 1 to exit."
							<< endl;
					getline(cin, category);
					if (category == "1")
						break;
				}
			} while (true);
			break;
		case 4:
			cout << "Please introduce the new price." << endl;
			float newPrice;
			cin >> newPrice;
			cin.ignore();
			cin.clear();
			ad->setPrice(newPrice);
			cout << "Please introduce if it is negotiable or not(Y/N)." << endl;
			getline(cin, answer);
			if (answer == "Y" || answer == "y")
				ad->setNegotiable(true);
			else
				ad->setNegotiable(false);
			break;
		case 5:
			ad->getOwner()->removeAdvertisement(ad);
			data->removeAdvertisement(ad);
			signedInMenu(data);
			break;
		case 6:
			ad->viewProposals();
			break;
		case 7:
			signedInMenu(data);
			break;
		default:
			AdDisplayMenu::createMenu();
			break;
		}
	} else {
		do {
			if (i > 0)
				cout << "Please introduce a valid option." << endl;
			cin >> input;
			cin.ignore();
			cin.clear();
			i++;
		} while (input < 1 || input > 3);

		switch (input) {
		case 1:
			interested(ad->getOwner());
			break;
		case 2:
			if (data->getSignedInUser() != NULL)
				data->getSignedInUser()->sendProposal(ad);
			else
				cout << "You must be signed in order to send a proposal.\n";
			break;
		}
	}
}
