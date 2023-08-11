//includes
#include "Animal.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>


// Constructors
Animal::Animal(){
    this->ID = 999999;
    this->type = "99999";
    this->weight = 999999;
    this->age = 999999; 
    this->price = 999999999; 
}
Animal::Animal(const int ID, const string type, const float weight, const int age, const float price){
    this->ID = ID; 
    this->type = type;
    this->weight = weight;
    this->age = age; 
    this->price = price;
}
Animal::Animal(const Animal & copy){
    this->ID = copy.ID; 
    this->type = copy.type;
    this->weight = copy.weight;
    this->age = copy.age; 
    this->price = copy.price;
}
Animal::~Animal(){
    
}

// Utility methods
void Animal::print() const{
    cout << "ID: " << this->ID << endl << this->type << endl << this->weight << " kg\n" << this->age << " years old\n$" << this->price << endl << endl; 
}
/*void Animal::print() const {
  cout << setw(10) << left << this->getID();
  cout << setw(10) << this->getType();
  cout << setw(10) << this->getAge();
  cout << setw(15) << this->getWeight();
  cout << fixed << setprecision(2) << "$ " << this->getPrice();
  cout << endl;
}*/
// Getters
int Animal::getID() const{
    return this->ID; 
}
string Animal::getType() const{
    return this->type; 
}
float Animal::getWeight() const{
    return this->weight;
}
int Animal::getAge() const{
    return this->age;
}
float Animal::getPrice() const{
    return this->price; 
} 

// Setters
void Animal::setID(const int ID){
    this->ID = ID; 
}
void Animal::setType(const string type){
    this->type = type; 
}
void Animal::setWeight(const float weight){
    this->weight = weight; 
}
void Animal::setAge(const int age){
    this->age = age; 
}
void Animal::setPrice(const float price){
    this->price = price; 
}
