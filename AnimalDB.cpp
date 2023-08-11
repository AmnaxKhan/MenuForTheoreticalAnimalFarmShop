//includes
#include "AnimalDB.h"
#include <iostream>
#include <fstream>
//#include <cstdlib>

//int maxAnimal=100; 
// Constructors
AnimalDB::AnimalDB(){
    this->numOfAnimals = 0;
    this->numOfChoices = 0; 
}
AnimalDB::AnimalDB(const AnimalDB & copy){
    this->numOfAnimals = copy.numOfAnimals; 
    this->numOfChoices = copy.numOfChoices; 
}
AnimalDB::~AnimalDB(){
}

//Getters
int AnimalDB::getDonnaInventorySize() const {
    return numOfAnimals; 
} 
/*int AnimalDB::getuserCartSize(){
    return numOfChoices; 
} */
int AnimalDB::getNumChoices() const {
    return numOfChoices; 
}
        
//Most methods are based on the ID of animal, request ID of animal to add it to cart,etc.0
//Return methods
Animal AnimalDB::getUserAnimal(const int posInCart){
    return userChoiceCart[posInCart]; 
} 
Animal AnimalDB::getDonnaAnimal(const int posInCart){
    //Animal fromIndex(donnaInventory[posInCart].getID(), donnaInventory[posInCart].getType(), donnaInventory[posInCart].getWeight(), donnaInventory[posInCart].getPrice()); 
    return donnaInventory[posInCart-1]; 
} 
/*Animal AnimalDB::animalID(int ID){
    for(int i =0; i<numOfAnimals; i++){
        if(donnaInventory[i].getID()==ID){
            Animal fromID(ID, donnaInventory[i].getType(), donnaInventory[i].getWeight(), donnaInventory[i].getAge(), donnaInventory[i].getPrice());
             return fromID; 
        }
    }
}*/

float AnimalDB::getCurrentTotal(){
    float totalCost=0; 
    for(int i= 0; i<numOfChoices; i++){
        totalCost = totalCost + userChoiceCart[i].getPrice();
    }
    return totalCost;
} 
        
//Insert Methods 
bool AnimalDB::insertDonnaAnimal(Animal animal){
    if(numOfAnimals==maxAnimal){
        return false; 
    }
    donnaInventory[numOfAnimals]=animal;
    numOfAnimals++; 
    return true;
} 
bool AnimalDB::insertUserAnimal(int id){
    if(numOfChoices==maxAnimal){
        return false; 
    }
    userChoiceCart[numOfChoices]=donnaInventory[id-1]; 
    numOfChoices++; 
    return true;
}
        
//Print Methods
bool AnimalDB::printDonnaInventory() const{
    if (numOfAnimals==0){
        return false;
    }
    for(int i =0; i<numOfAnimals; i++){
        donnaInventory[i].print();
    }
    return true; 
} 
bool AnimalDB::printUserShoppingCart() const{
    if (numOfChoices==0){
        return false; 
    }
    cout << "--------------------------------" << endl; 
    cout << "Shopping Cart: " << endl; 
    cout << "--------------------------------" << endl; 

    for(int i = 0; i<numOfChoices; i++){
        userChoiceCart[i].print(); 
    }
    return true; 
} 
bool AnimalDB::printAnimalType() const{
    string animalChoice;
    bool animalExists=false; 
    cout << "Please type in an animal(first letter capitalized):"; 
    /*if(donnaInventory[numOfAnimals]>maxAnimal){
        cout << "The array has reached maximum size." << endl; 
        return false; 
    }*/
    cin >> animalChoice;
    for(int i =0; i<maxAnimal; i++){
        if(animalChoice == donnaInventory[i].getType()){
            donnaInventory[i].print();
            animalExists = true; 
        }
        
    }
    if (animalExists ==false){
        cout << endl << "This animal is not available in the database." << endl; 
    }
    return true; 
} 

bool AnimalDB::printAnimalWeight() const{
    float minWeight; 
    float maxWeight; 
    bool empty = true; 

    cout << "Enter the minimum weight: "; 
    cin >> minWeight; 
    cout << "Enter the maximum weight: "; 
    cin >> maxWeight; 
    for (int i=0; i < maxAnimal;i++){
        if((donnaInventory[i].getWeight()<=maxWeight) && (donnaInventory[i].getWeight()>=minWeight)){
            donnaInventory[i].print();
            empty=false; 

        }
    }
    return (empty == false); 
}

bool AnimalDB::printAnimalAge() const{
    int maxAge; 
    int minAge; 
    bool empty = true; 
    cout << "Insert minimum age: "; 
    cin >> minAge;
    cout << "Insert maximum age: "; 
    cin >> maxAge; 

    for (int i = 0; i<maxAnimal; i++){
        if((donnaInventory[i].getAge()<=maxAge) && (donnaInventory[i].getAge()>=minAge)){
            donnaInventory[i].print(); 
            empty=false; 
        }
    }
    /*if(empty = true){
        return false; 
    }
    else{
        return true; 
    }*/
    return (empty == false); 
}

//Extra unused method
/*bool AnimalDB::printAnimalPrice() const{
    float maxPrice; 
    float minPrice; 
    bool empty = true; 

    cout << "Insert minimum price: " << endl; 
    cin >> minPrice; 
    cout << "Insert maximum price: " << endl; 
    cin >> maxPrice; 
    for (int i = 0; i<maxAnimal; i++){
        if((donnaInventory[i].getPrice()<=maxPrice) && (donnaInventory[i].getPrice()>=minPrice)){
            donnaInventory[i].print(); 
            empty=false; 
        }
    }
        return (empty == false); 
}*/
        

