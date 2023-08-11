#include "Animal.h"
#include "AnimalDB.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std; 

void readFile(const string filename, AnimalDB &animals) {
    // open file, check if failed
    ifstream din;
    din.open(filename.c_str());

    if (din.fail()) {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // declare local temp. class variables for reading data
    int id = 1;
    string type;
    float weight;
    int age;
    float price;
    string extra;
    char dollar;

    while (!din.eof()) {
        // logic for reading in data, ignoring unwanted data
        din >> type >> weight;
        getline(din, extra);
        din >> age;
        getline(din, extra);
        din.get(dollar);
        din >> price;
        getline(din, extra);

        // define new Animal object and insert new animal into Donna's inventory
        Animal newAnimal(id++, type, weight, age, price);
        if (!din.eof())
            animals.insertDonnaAnimal(newAnimal);
    }
    din.close();
}

 void writeFile(const string filename, AnimalDB &animals) {
     // open file for output, check if failed
     ofstream dout;
     dout.open(filename.c_str());

     if (dout.fail()) {
         cout << "Error; file " << filename << " could not be opened" << endl;
         return;
     }

     // loop for each index in the userCart array, write data of each Animal object to output file in CSV formats
     for (int i = 0; i < animals.getNumChoices(); i++) {
         Animal currentAnimal = animals.getUserAnimal(i);
         dout << currentAnimal.getID() << ','
         << currentAnimal.getType() << ','
         << currentAnimal.getWeight() << ','
         << currentAnimal.getAge() << ','
         << currentAnimal.getPrice() << ',' << endl;
     }
     dout << ",,,," << animals.getCurrentTotal();
     dout.close();
 }

void printMenu() {
    cout << "\nWelcome to Donna's Farm! Here are your choices:"
    << "\n1: Print all animals in Donna's inventory"
    << "\n2: Print your current shopping cart"
    << "\n3: Print animals of a certain type"
    << "\n4: Print animals within a range of weight"
    << "\n5: Print animals within a range of age"
    << "\n6: Add an animal to your shopping cart"
    << "\n7: Print your current shopping cart total"
    << "\n8: Complete your order, print receipt and exit the program\n";
}

char getUserChoice() {
    char userChoice = '\0';

    do {
        cout << "\nEnter menu selection: ";
        cin >> userChoice;
        if (userChoice < '1' || userChoice > '8')
            cout << "\nError: invalid input. Please try again." << endl;
    } while (userChoice < '1' || userChoice > '8');

    return userChoice;
}

int main() {
    //you will be writing this code!
    //Animal penguin (0, "penguin", 10.5, 8, 30.0);
    //Animal lion (1, "lion", 10.5, 8, 10.0);
    //AnimalDB something; 
    //something.insertUserAnimal(penguin);
    //something.insertUserAnimal(lion);
    //something.insertDonnaAnimal(penguin); 
    //something.insertDonnaAnimal(lion);
    //cout << something.getCurrentTotal(); 
    //cout << penguin.getPrice() << endl;
    //something.printDonnaInventory(); 
    //something.printUserShoppingCart();
    //something.printAnimal("lion", 10.5, 8, 10.0); 
    AnimalDB animalDB; 
    readFile("donnaInventory.txt", animalDB);
    char choice; 
    int animalID; 

    //cout << animalDB.getUserAnimal(0); 
    //choice = getUserChoice(); 
    do {
        printMenu();

        choice = getUserChoice(); 
        switch(choice){
            case '1': if (animalDB.printDonnaInventory() == false){
                cout << "Method failed to execute." << endl; 
            }; break; 
            case '2': if (animalDB.printUserShoppingCart()==false){
                cout << "Method failed to execute. There is nothing in the shopping cart. " << endl; 
            };break; 
            case '3': if (animalDB.printAnimalType()==false) {
                cout << "Method failed." << endl; 
            }; break; 
            case '4': if (animalDB.printAnimalWeight()==false){
                cout << "There are no animals that fit this criteria." << endl;  
            };break;  
            case '5': if (animalDB.printAnimalAge()==false){
                cout << "There are no animals that fit this criteria." << endl; 
            }; break; 
            case '6': cout << "What is the ID of the animal you want to insert? "; 
                      cin >> animalID; 
                      if (animalDB.insertUserAnimal(animalID)==false){
                          cout << "Insertion into cart failed" << endl; 
                      } 
                      break; 
            case '7': cout << endl << "Total cost of shopping cart: $" << fixed << setprecision(2) << animalDB.getCurrentTotal() << endl; break; 
            case '8': cout << "Order completed! Exiting program now." << endl; 
                writeFile("userCart.csv", animalDB); 

                break; 
            //default: cout << "This is not an option. Please try again!";
        }
 
    } while (choice!='8');


    return 0;
}