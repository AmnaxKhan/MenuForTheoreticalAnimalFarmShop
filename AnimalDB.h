#ifndef ANIMALDB_H
#define ANIMALDB_H
#include "Animal.h"
//#include <vector>

const int maxAnimal=100; 

class AnimalDB
{
        public: 
        //Constructors
        AnimalDB();
        AnimalDB(const AnimalDB & copy);
        ~AnimalDB();

        //Getters
        int getDonnaInventorySize() const; 
        int getuserCartSize() const; 
        int getNumChoices() const; 
        
        //Most methods are based on the ID of animal, request ID of animal to add it to cart,etc.0
        //Return methods
        Animal getUserAnimal(const int posInCart); 
        Animal getDonnaAnimal(const int posInCart); 
        //Animal animalID(int ID);
        float getCurrentTotal(); 
        
        //Insert Methods 
        bool insertDonnaAnimal(Animal animalID); 
        bool insertUserAnimal(int ID);
        
        //Print Methods
        bool printDonnaInventory() const; 
        bool printUserShoppingCart() const; 
        bool printAnimalType() const; 
        bool printAnimalWeight() const; 
        bool printAnimalAge() const; 
        bool printAnimalPrice() const; 

        /*insertDonnaAnimal(Animal animal);*/
        
        // Transaction attributes
        private:
            //Arrays 
            Animal donnaInventory[100]; 
            Animal userChoiceCart[100]; 
            int numOfAnimals; 
            int numOfChoices; 
            
};

#endif
