#include"menu.h"
#include<iostream>
#include<string>
#include<sstream>


Menu::Menu(Data* data, unsigned int height, unsigned int width, char borderChar){
	this->data = data;
	this->height = height;
	this->width = width;
	this->borderChar = borderChar;
	topMargin = 1;
	leftMargin = 1;
}

void Menu::setBorderChar(char borderChar){
	this->borderChar = borderChar;
}

char Menu::getBorderChar(){
	return borderChar;
}

void Menu::emptyLine() const{
	cout << borderChar << string(width-2, ' ') << borderChar << endl;
}
