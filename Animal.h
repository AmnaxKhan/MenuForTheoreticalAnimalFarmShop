#ifndef ANIMAL_H
#define ANIMAL_H
#include <fstream>

using namespace std; 
class Animal
{
public:
  // Constructors
  Animal ();
  Animal (const int ID, const string type, const float weight,
	  const int age, const float price);
  Animal (const Animal & copy);
  ~Animal ();

  // Utility methods
  void print () const;

  // Getters
  int getID () const;
  string getType () const;
  float getWeight () const;
  int getAge () const;
  float getPrice () const;

  // Setters
  void setID (const int ID);
  void setType (const string type);
  void setWeight (const float weight);
  void setAge (const int age);
  void setPrice (const float price);

private:
  // Transaction attributes
  int ID;
  string type;
  float weight;
  int age;
  float price;
};

#endif
