// Kathy Saad
// 11-18-13
// Linked List

#pragma once
#include <string>
#include <iostream>

using namespace std;

class StudentRecord{
public:
    StudentRecord();
	// Default constructor - initializes all private member variables.

    StudentRecord(string, string, int, double);
	// Constructor - assigns all private member variables the values passed in.
	// Postconditions: If the GPA is not within 0.0 and 4.0, an error message will be printed to screen
		// prompting the user to try again.

    string getLastName();
	// Returns the private member variable last_name

    string getFirstName();
	// Returns the private member variable first_name

    int getIDNumber();
	// Returns the private member variable ID_number

    double getGPA();
	// Returns the private member variable GPA

    void setLastName(string);
	// Assigns the private member variable last_name to the value passed in

    void setFirstName(string);
	// Assigns the private member variable first_name to the value passed in

    void setIDNumber(int);
	// Assigns the private member variable ID_number to the value passed in

    bool setGPA(double);
	// Assigns the private member variable GPA to the value passed in

private:
    string last_name;
    string first_name;
    int ID_number;
    double GPA;
};

//*************************
// FUNCTION IMPLEMENTATIONS
//*************************

StudentRecord::StudentRecord(){
    last_name = "";
    first_name = "";
    ID_number = 0;
    GPA = 0.0;
}

StudentRecord::StudentRecord(string lName, string fName, int id_num, double gpa){
    setLastName(lName);
    setFirstName(fName);
    setIDNumber(id_num);
    if(!setGPA(gpa)){
		cout << "That's an invalid GPA. It must be between 0.0 and 4.0. Try again.\n\n";
	}
}

string StudentRecord::getLastName(){
    return last_name;
}

string StudentRecord::getFirstName(){
    return first_name;
}

int StudentRecord::getIDNumber(){
    return ID_number;
}

double StudentRecord::getGPA(){
    return GPA;
}

void StudentRecord::setLastName(string lName){
    last_name = lName;
}

void StudentRecord::setFirstName(string fName){
    first_name = fName;
}

void StudentRecord::setIDNumber(int id_num){
    ID_number = id_num;
}

bool StudentRecord::setGPA(double gpa){
    if((gpa < 0.0) || (gpa > 4.0)){
        return false;
    }
    else{
        GPA = gpa;
        return true;
    }
}