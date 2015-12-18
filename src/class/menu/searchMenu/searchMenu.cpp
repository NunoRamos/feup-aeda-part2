#include "searchMenu.h"
#include "../adDisplayMenu/adDisplayMenu.h"
#include"../../../menus.h"
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h>

SearchMenu::SearchMenu(Data* data, vector<Advertisement* > &results, unsigned int height, unsigned int width, char borderChar) :
Menu(data, height, width, borderChar){
	this->results = results;
	page = 0;
	adsPerPage = 7;
	pageMax = results.size() / adsPerPage;
}

void SearchMenu::setAdsPerPage(unsigned int adsPerPage){
	this->adsPerPage = adsPerPage;
}

unsigned int SearchMenu::getAdsPerPage(){
	return adsPerPage;
}

void SearchMenu::print(){
	//first line, only borderChar
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;

	//includes top margin with is a line full of spaces, with borderChar on either side
	for (unsigned int i = 0; i < topMargin; i++){
		cout << borderChar << string(width-2, ' ') << borderChar << endl;
	}

	//calculates how many ads in page
	unsigned int adLimit = adsPerPage;
	if(trunc(static_cast<double> (results.size() / adsPerPage)) == page)
		adLimit = results.size() % adsPerPage;

	//used to add menu options correctly
	stringstream ss;
	for(unsigned int i = 0; i < adLimit; i++){
		string line(leftMargin, ' ');
		ss.str("");
		ss << i+1 << " - ";
		unsigned int widthLeft = width -
				(1 + leftMargin + ss.str().length() + results[page*adsPerPage+i]->getTitle().length());
		cout << borderChar << line
				<< ss.str() << results[page*adsPerPage+i]->getTitle()
				<< string(widthLeft-1, ' ') << borderChar << endl;
	}

	//add back, next, and exit options
	ss.str("");
	ss << adLimit+1;
	cout << borderChar << " " << adLimit + 1 << " - " << "Back" << string(width-10-ss.str().size(), ' ') << borderChar << endl;
	ss.str("");
	ss << adLimit+2;
	cout << borderChar << " " << adLimit + 2 << " - " << "Next" << string(width-10-ss.str().size(), ' ') << borderChar << endl;
	ss.str("");
	ss << adLimit+3;
	cout << borderChar << " " << adLimit + 3 << " - " << "Exit" << string(width-10-ss.str().size(), ' ') << borderChar << endl;

	//fills the rest of the menu with empty lines, with border
	for (unsigned int i = adLimit; i < height-(2+topMargin); i++){
		cout << borderChar << string(width-2, ' ') << borderChar << endl;
	}

	//last line
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;
}

void SearchMenu::createMenu(){
	clearScreen();
	unsigned int input;
	unsigned int adLimit = adsPerPage;
	if(trunc(static_cast<double> (results.size() / adsPerPage)) == page)
		adLimit = results.size() % adsPerPage;
	print();
	cin >> input;
	while (input <= 0 || input > adLimit + 3){
		cout << "Please introduce a valid option.\n";
		cin >> input;


	}
	cin.ignore();
	cin.clear();

	if(input <= adLimit){ //ad options
		AdDisplayMenu displayAd(data, results[page*adsPerPage+input-1], height, width, borderChar);
		displayAd.createMenu();
	}
	else if(input == adLimit + 1){ //back
		if(page!=0)
			page--;
	}
	else if(input == adLimit + 2){ //next
		if(page != pageMax)
			page++;
	}


	if(input != adLimit + 3) //exit
		createMenu();
}
