//
//  main.cpp
//  hw8
//
//  Created by Patricia Antlitz on 4/2/23.
//
/***********************************************
Author: <Patricia Antlitz>
Date: <04/02/23>
Purpose: <Train inheritance>
Sources of Help: <homework/class work>
Time Spent: <3hrs>
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date 04/02/2023:
Name: Patricia Antlitz
*/
#include <iostream>
using namespace std;


class Person
{
public:
    //default
    Person():name("none"){};
    //value
    Person(string theName):name(theName){};
    //copy constructor
    Person(const Person& theObject):name(theObject.name){};
    //modifiers and accessor
    void setName(string ownerName){ name = ownerName; }
    string getName(void) const{ return name; }
    
    //method overload =, <<, >>
    Person& operator=(const Person& rtSide);
    friend istream& operator>>(istream& inStream, Person& pObj);
    friend ostream& operator<<(ostream& outStream, const Person& pObj);
    
private:
    string name;
};

//Create a base class called Vehicle that has the manufacturer’s name (type string), number of cylinders in the engine (type int), and owner type Person
class Vehicle
{
public:
    //default contructor
    Vehicle():manufacturer("Unknown Manufacturer"), numCylinders(0), owner("Unknown Owner"){};
    //value constructor
    Vehicle(string maker, int cylinders, Person ownerName):manufacturer(maker), numCylinders(cylinders), owner(ownerName){};
    //copy contructor
    Vehicle(const Vehicle& theObject);
    
    //modifiers
    void setMaker(string maker){ manufacturer = maker; }
    void setCylinders(int cylinders){ numCylinders = cylinders; }
    void setOwner (Person ownerName){ owner = ownerName; }
    //accessors
    string getMaker() const{ return manufacturer; }
    int getCylinders() const{ return numCylinders; }
    Person getOwner() const{ return owner; }

    //operator overload =
    Vehicle& operator=(const Vehicle& vObj);
    //output insertion
    friend ostream& operator<<(ostream& outStream, const Vehicle& vObj);
    
private:
    //variables
    string manufacturer;
    int numCylinders;
    Person owner;
};

//create a class called Truck that is derived from Vehicle and has additional properties, the load capacity in tons
class Truck : public Vehicle
{
public:
    //default constructor
    Truck():Vehicle(), loadCapacity(0.0), towCapacity(0){};//default
    //value constructor
    Truck(string maker, int cylinder, Person owner, double load, int tow): Vehicle(maker, cylinder, owner), loadCapacity(load), towCapacity(tow){};
    //copy constructor
    Truck(const Truck& theObject):loadCapacity(theObject.loadCapacity), towCapacity(theObject.towCapacity), Vehicle(theObject){};
    
    //modifiers
    void setLoadCapacity(double newLoad){ loadCapacity = newLoad; }
    void setTowingCapacity(int newTowing){ towCapacity = newTowing; }
    //accessors
    double getLoadCapacity() const{ return loadCapacity; }
    int getTowingCapacity() const{ return towCapacity; }

    //overload = and <<
    Truck& operator=(const Truck& rtSide);
    friend ostream& operator<<(ostream& outStream, const Truck& tObj);
    
private:
    //data
    double loadCapacity;
    int towCapacity;
};

//friend functions prototypes
ostream& operator<<(ostream& outStream, const Person& pObj);
istream& operator>>(istream& inStream, Person& pObj);
ostream& operator<<(ostream& outStream, const Vehicle& vObj);
ostream& operator<<(ostream& outStream, const Truck& tObj);

int main(int argc, const char * argv[])
{
    //variable to store the name entered by the user
    string userName;
    //testing Person class
    cout << "///////////////// Testing Person Class ////////////////" << endl << endl;
    cout << "Testing Default Constructor: the person is: ";
    Person newPerson;
    cout << newPerson << endl;
    
    //value contructor
    cout << "Testing Constructor (string): I'm ";
    Person namePerson("Pattie");
    cout << namePerson << endl;
    
    cout << "Testing Copy Constructor: I'm also ";
    Person copyPerson(namePerson);
    cout << copyPerson << endl;
    
    cout << "Testing >> Overloading: Enter your name: ";
    //scans the whole line to get first and last name (or whatever is entered in a line)
    getline(cin, userName);
    Person personName(userName);
    cout << "You are: " << userName << endl << endl;
    
    //assignment operator
    cout << "Testing = Overloading: Another you is: ";
    namePerson = personName;
    cout << namePerson << endl;
    
    //vehicle class test
    cout << "///////////////// Testing Vehicle Class ////////////////" << endl << endl;
    
    cout << "Testing Default Constructor: the vehicle is: ";
    Vehicle newVehicle;
    cout << newVehicle;
    
    //value constructor test
    cout << "Testing Constructor (args) for my car: ";
    Vehicle myVehicle("Honda C-RV", 4, namePerson);
    cout << myVehicle;
    
    cout << "Testing Copy Constructor: the same car is: ";
    Vehicle copyVehicle(myVehicle);
    cout << copyVehicle;

    //assignment constructor test
    cout << "Testing = Overloading:" << endl;
    //Im creating a new vehicle to have two different as first and second
    Vehicle anotherCar("Hyundai Sonata", 4, namePerson);
    // the original vehicle (Honda) is not the Hyundai
    myVehicle = anotherCar;
    //and the copied method retains its copied value (Honda)
    cout << "Your Car is: " << copyVehicle;
    cout << "Your Second Car is: " << myVehicle << endl;
    
    //testing Truck class
    cout << "///////////////// Testing Truck Class ////////////////" << endl << endl;
    
    cout << "Testing Default Constructor: the truck is: ";
    Truck newTruck;
    cout << newTruck << endl;
    
    //value constructor
    cout << "Testing Constructor (args) for a truck: ";
    Truck aTruck("Mac", 8, namePerson, 250, 2000);
    cout << aTruck << endl;
    
    cout << "Testing Copy Constructor: copied truck: ";
    Vehicle copyTruck(aTruck);
    cout << copyTruck;

    cout << "Testing = Overloading:" << endl;
    Truck anotherTruck("Toyota Truck", 8, namePerson, 250, 5000);
    aTruck = anotherTruck;
    cout << "The new truck is: " << aTruck << endl;
    cout << "The same truck is: " << anotherTruck << endl;

    return 0;
}

Person& Person::operator=(const Person& rtSide) {
   this->name = rtSide.name;
   return *this;
}

Vehicle& Vehicle::operator=(const Vehicle& vSide)
{
    manufacturer = vSide.manufacturer;
    numCylinders = vSide.numCylinders;
    owner = vSide.owner;
  
    return *this;
}

Truck& Truck::operator=(const Truck& tSide) {
  
   if ( this == &tSide ) return *this;
  
   this->loadCapacity = tSide.loadCapacity;
   this->towCapacity = tSide.towCapacity;
   (*this).Vehicle::operator=(tSide);
   return *this;
}

Vehicle::Vehicle(const Vehicle& theObject)
{
    manufacturer = theObject.manufacturer;
    numCylinders = theObject.numCylinders;
    owner = theObject.owner;
}

ostream& operator<<(ostream& outStream, const Person& pObj)
{
    outStream << pObj.name << endl;
    return outStream;
}

istream& operator>>(istream& inStream, Person& pObj)
{
   inStream >> pObj.name;
   return inStream;
}

ostream& operator<<(ostream& outStream, const Vehicle& vObj)
{
    outStream << vObj.manufacturer << ", " << vObj.numCylinders << " cylinders, belongs to: " << vObj.owner << endl;
    return outStream;
}

ostream& operator<<(ostream& outStream, const Truck& tObj)
{
    outStream << tObj.getMaker() << ", " << tObj.getCylinders() << " cylinders, belongs to: " << tObj.getOwner() << ", load capacity: " << tObj.loadCapacity << ", towing capacity: " << tObj.towCapacity << endl;
    return outStream;
}
