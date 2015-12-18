#include "enums.h"

using namespace enums;

bool validCategory(string isValidCategory){
	if (isValidCategory=="Agriculture"){
		return true;
	}
	else if (isValidCategory=="BabyAndChildren"){
		return true;
	}
	else if (isValidCategory=="Fashion"){
		return true;
	}
	else if (isValidCategory=="Home"){
		return true;
	}
	else if (isValidCategory=="Job"){
		return true;
	}
	else if (isValidCategory=="Leisure"){
		return true;
	}
	else if (isValidCategory=="PhonesAndTablets"){
		return true;
	}
	else if (isValidCategory=="RealEstate"){
		return true;
	}
	else if (isValidCategory=="Services"){
		return true;
	}
	else if (isValidCategory=="Sports"){
		return true;
	}
	else if (isValidCategory=="Technology"){
		return true;
	}
	else if (isValidCategory=="Vehicles"){
		return true;
	}
	else if (isValidCategory=="Others"){
		return true;
	}
	else if (isValidCategory=="Animals")
		return true;

	return false;
}

Category stringToCategory(string validCategory){
	if (validCategory=="Agriculture"){
		return Agriculture;;
	}
	else if (validCategory=="BabyAndChildren"){
		return BabyAndChildren;
	}
	else if (validCategory=="Fashion"){
		return Fashion;
	}
	else if (validCategory=="Home"){
		return Home;
	}
	else if (validCategory=="Job"){
		return Job;
	}
	else if (validCategory=="Leisure"){
		return Leisure;
	}
	else if (validCategory=="PhonesAndTablets"){
		return PhonesAndTablets;
	}
	else if (validCategory=="RealEstate"){
		return RealEstate;
	}
	else if (validCategory=="Services"){
		return Services;
	}
	else if (validCategory=="Sports"){
		return Sports;
	}
	else if (validCategory=="Technology"){
		return Technology;
	}
	else if (validCategory=="Vehicles"){
		return Vehicles;
	}
	else if (validCategory=="Others"){
		return Others;
	}
	else if (validCategory=="Animals")
		return Animals;

}

string categoryToString(Category validCategory){
	if (validCategory==Agriculture){
		return "Agriculture";
	}
	else if (validCategory==BabyAndChildren){
		return "BabyAndChildren";
	}
	else if (validCategory==Fashion){
		return "Fashion";
	}
	else if (validCategory==Home){
		return "Home";
	}
	else if (validCategory==Job){
		return "Job";
	}
	else if (validCategory==Leisure){
		return "Leisure";
	}
	else if (validCategory==PhonesAndTablets){
		return "PhonesAndTablets";
	}
	else if (validCategory==RealEstate){
		return "RealEstate";
	}
	else if (validCategory==Services){
		return "Services";
	}
	else if (validCategory==Sports){
		return "Sports";
	}
	else if (validCategory==Technology){
		return "Technology";
	}
	else if (validCategory==Vehicles){
		return "Vehicles";
	}
	else if (validCategory==Others){
		return "Others";
	}
	else if (validCategory==Animals)
		return "Animals";

}

bool validCondition(string isValidCondition){
	if(isValidCondition=="New"){
		return true;
	}
	else if(isValidCondition=="UsedAsNew"){
		return true;
	}
	else if(isValidCondition=="Functional"){
		return true;
	}
	else if(isValidCondition=="ForParts"){
		return true;
	}

	return false;
}


Condition stringToCondition(string validCondition){
	if(validCondition=="New"){
		return New;
	}
	else if(validCondition=="UsedAsNew"){
		return UsedAsNew;
	}
	else if(validCondition=="Functional"){
		return Functional;
	}
	else if(validCondition=="ForParts"){
		return ForParts;
	}

}

string conditionToString(Condition validCondition){
	if(validCondition==New){
		return "New";
	}
	else if(validCondition==UsedAsNew){
		return "UsedAsNew";
	}
	else if(validCondition==Functional){
		return "Functional";
	}
	else if(validCondition==ForParts){
		return "ForParts";
	}

}
