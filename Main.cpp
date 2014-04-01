// Kathy Saad
// 11-18-13
// Linked List

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "StudentRecord.h"

using namespace std;

void addRecord(List<StudentRecord> & list);
// Adds a record to the list (from keyboard) and maintains sorted order (by ID number).
// Postconditions: Record is inserted into the list.

void retrieveRecord(List<StudentRecord> list);
// User must enter an ID of a student whose record they want to retrieve. Function retrieves and prints a record to screen.
	// If list was empty to begin with, an error message will be printed to screen.
	// If ID number couldn't be found, an error message is printed to screen.

void deleteRecord(List<StudentRecord> & list);
// User must enter an ID of a student whose record they want to delete.
	// If list was empty to begin with, an error message will be printed to screen.
	// If ID number couldn't be found, an error message is printed to screen.
	// If found, function attempts to confirm deletion.
	// If yes, record is deleted and the new list is printed to screen. If no, list remains unchanged.

void modifyRecord(List<StudentRecord> & list);
// User must enter an ID of a student whose record they want to modify.
	// If list was empty to begin with, an error message will be printed to screen.
	// If ID number couldn't be found, an error message is printed to screen.
	// If found, function prompts user to enter which item they'd like to change (excluding ID number),
	// modifies the parts requested, and prints out the new, altered record to screen.

void quitProgram(List<StudentRecord> list);
// Function prompts user to enter whether the list should be saved to file or not.
	// If yes, the list of records is printed to file.
	// Either way, the list is destroyed by the end of the function.
	// If list was empty to begin with, nothing happens.

void printRecords(List<StudentRecord> list);
// This function prints the list of records to screen
// Preconditions: List is initialized
// Postconditions: List is printed to screen
// Note: Since list is passed by value, there is no need to save the current position of the list before any changes are made
    // If list was passed in by reference, you would need to save the current position, and then get back to that position after printing

int main(){
    List<StudentRecord> list;
    char response,
        ans;
    ifstream inFile;
	string fName,
		lName;
	int id_num;
	double gpa;

    cout << "Would you like to read in from a file (F) or type the input through keyboard?\n";
    cin >> ans;

    if((ans == 'F') || (ans == 'f')){
		inFile.open("STUDENT.DAT");

		if(inFile){
			while(!inFile.eof()){
				inFile >> id_num >> fName >> lName >> gpa;
			
				StudentRecord newStudent(lName, fName, id_num, gpa);

				while((!list.isEmpty()) && (list.currentItem().getIDNumber() < newStudent.getIDNumber())){
					list.goToNext();
				}

				list.insert(newStudent);
			}
		}
		else{
			cout << "File didn't open.\n";
		}
    }

	inFile.close();

    do{
        cout << endl
			 << "Choose an option from the following menu:\n"
             << "A - Add a student record\n"
             << "R - Retrieve a student record\n"
             << "D - Delete a student record\n"
             << "M - Modify a student record\n"
             << "Q - Quit program\n"
             << "P - Print out all student data\n";
        cin  >> response;

        switch(response){
        case 'A':
        case 'a':
            addRecord(list);
            break;
        case 'R':
        case 'r':
            retrieveRecord(list);
            break;
        case 'D':
        case 'd':
            deleteRecord(list);
            break;
        case 'M':
        case 'm':
            modifyRecord(list);
            break;
        case 'Q':
        case 'q':
			quitProgram(list);
            break;
        case 'P':
        case 'p':
            printRecords(list);
            break;
        default:
            cout << "That was an invalid response.\n";
            break;
        }

    }while((response != 'Q') && (response != 'q'));

    return 0;
}

void addRecord(List<StudentRecord> & list){
    string lName,
        fName;
    int id_num;
    double gpa;

    cout << "Enter last name: ";
    cin  >> lName;
    cout << endl;
    cout << "Enter first name: ";
    cin  >> fName;
    cout << endl;
    cout << "Enter ID number: ";
    cin  >> id_num;
    cout << endl;
    cout << "Enter GPA: ";
    cin  >> gpa;
    cout << endl;

	StudentRecord newStudent(lName, fName, id_num, gpa);

	while(!newStudent.setGPA(gpa)){
		cin >> gpa;
	}

	newStudent.setGPA(gpa);

	while((!list.isEmpty()) && (list.currentItem().getIDNumber() < newStudent.getIDNumber())){
        list.goToNext();
    }

    list.insert(newStudent);
}

void retrieveRecord(List<StudentRecord> list){
	int ID_to_retrieve;
	cout << "Enter the ID of the student whose record you want to retrieve: ";
	cin  >> ID_to_retrieve;

	while((!list.isEmpty()) && (list.currentItem().getIDNumber() < ID_to_retrieve) && (!list.isAtLastNode())){
		list.goToNext();
	}

	if(list.currentItem().getIDNumber() == ID_to_retrieve){
		cout << endl
			 << "First name: "
			 << list.currentItem().getFirstName()
			 << endl << "Last name: "
			 << list.currentItem().getLastName()
			 << endl << "GPA: "
			 << list.currentItem().getGPA()
			 << endl << endl;
	}
	else{
		cout << "ID number not found.\n";
	}
}

void deleteRecord(List<StudentRecord> & list){
	int ID_to_delete;
	char response;

	cout << "Enter the ID number of the student whose record you want to delete: ";
	cin  >> ID_to_delete;



	while((!list.isEmpty()) && (list.currentItem().getIDNumber() < ID_to_delete) && (!list.isAtLastNode())){
		list.goToNext();
	}

	if(list.currentItem().getIDNumber() == ID_to_delete){
		cout << endl
			 << "First name: "
			 << list.currentItem().getFirstName()
			 << endl << "Last name: "
			 << list.currentItem().getLastName()
			 << endl << "GPA: "
			 << list.currentItem().getGPA()
			 << endl << endl << "Are you sure you want to delete this record? (y/n)\n";
		cin  >> response;

		if((response == 'Y') || (response == 'y')){
			list.deleteCurrentItem();
			cout << "New list:\n";
			printRecords(list);
		}
	}
	else{
		cout << "ID number not found.\n";
	}
}

void modifyRecord(List<StudentRecord> & list){
	int ID_to_modify;
	char response;
	string fName,
		lName;
	double gpa;

	cout << "Enter the ID number of the student whose record you want to modify: ";
	cin  >> ID_to_modify;

	while((!list.isEmpty()) && (list.currentItem().getIDNumber() < ID_to_modify) && (!list.isAtLastNode())){
		list.goToNext();
	}

	if(list.currentItem().getIDNumber() == ID_to_modify){
		cout << endl
			 << "First name: "
			 << list.currentItem().getFirstName()
			 << endl << "Last name: "
			 << list.currentItem().getLastName()
			 << endl << "GPA: "
			 << list.currentItem().getGPA()
			 << endl << endl << "Which part would you like to modify? (f/l/g)\n"
			 << "Note: ID number cannot be modified.\n";
		cin  >> response;

		if((response == 'F') || (response == 'f')){
			cout << "Enter the new first name: ";
			cin  >> fName;
			list.currentItem().setFirstName(fName);
		}
		else if((response == 'L') || (response == 'l')){
			cout << "Enter the new last name: ";
			cin  >> lName;
			list.currentItem().setLastName(lName);
		}
		else{
			cout << "Enter the new GPA: ";
			cin  >> gpa;

			while((gpa < 0.0) || (gpa > 4.0)){
				cout << "That's an invalid GPA. Try again.\n";
				cin >> gpa;
			}

			list.currentItem().setGPA(gpa);
		}

		cout << endl << "New record:\n"
			 << endl
			 << "First name: "
			 << list.currentItem().getFirstName()
			 << endl << "Last name: "
			 << list.currentItem().getLastName()
			 << endl << "GPA: "
			 << list.currentItem().getGPA()
			 << endl << endl;
	}
	else{
		cout << "ID number not found.\n";
	}
}

void quitProgram(List<StudentRecord> list){
	ofstream outFile;
	char answer;

	outFile.open("STUDENT.DAT");

	if(!list.isEmpty()){
		cout << "Should the records be saved to STUDENT.DAT? (y/n)\n";
		cin  >> answer;
		if((answer == 'Y') || (answer == 'y')){
			list.goToStart();

			while(!list.isAtEnd()){
				outFile << list.currentItem().getGPA()
						<< " "
						<< list.currentItem().getFirstName()
						<< " "
						<< list.currentItem().getLastName()
						<< " "
						<< list.currentItem().getGPA()
						<< endl;
				list.goToNext();
			}
		}
		list.makeEmpty();
	}

	outFile.close();

    cout << "Now quitting program.\n";
}

void printRecords(List<StudentRecord> list){
	list.goToStart();

	while((!list.isAtEnd()) && (!list.isEmpty())){
		cout << endl << "First name: "
			 << list.currentItem().getFirstName()
			 << endl << "Last name: "
			 << list.currentItem().getLastName()
			 << endl << "GPA: "
			 << list.currentItem().getGPA()
			 << endl << endl;
		list.goToNext();
	}
	if(list.isEmpty()){
		cout << "List is empty.\n";
	}
}