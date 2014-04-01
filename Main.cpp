// Kathy Saad
// 11-6-13
// Linked List ADT

#include <iostream>
#include "ListADT.h"

using namespace std;

void printList(List<int> list_to_print);
// List is printed to screen
// Preconditions: List is initialized
// Postconditions: List is printed to screen
// Note: Since list is passed by value, there is no need to save the current position of the list before any changes are made
    // If list was passed in by reference, you would need to save the current position, and then get back to that position after printing

int main(){
    List<int> List1;
    char response;
    int number;

    do{
        cout << "Choose an option from the following menu to begin testing the list:\n"
             << "M - Make the list empty\n"
             << "C - Check if list is empty\n"
             << "S - Go to start\n"
             << "N - Go to next\n"
             << "E - Checks if at the end of the list\n"
             << "R - Print current item from the list\n"
             << "I - Insert an item into the list\n"
             << "D - Delete the current item from the list\n"
             << "P - Print current position in the list\n"
             << "L - Print list\n"
             << "Q - Quit program\n";
        cin  >> response;

        switch(response){
        case 'M':
        case 'm':
            if(!(List1.isEmpty())){
                List1.makeEmpty();
                cout << "List is now empty.\n";
            }
            else{
                List1.makeEmpty();
            }
            break;
        case 'C':
        case 'c':
            if(List1.isEmpty()){
                cout << "List is empty.\n";
            }
            else{
                cout << "List is not empty.\n";
            }
            break;
        case 'S':
        case 's':
            if(List1.isEmpty()){
                cout << "I can't go to the start of an empty list.\n";
            }
            else{
                List1.goToStart();
            }
            break;
        case 'N':
        case 'n':
            if(List1.isEmpty()){
                cout << "I can't go to the next node of an empty list.\n";
            }
            else if(List1.isAtEnd()){
                cout << "I can't go to the next node, already at the end of the list.\n";
            }
            else{
                List1.goToNext();
            }
            break;
        case 'E':
        case 'e':
            if(List1.isAtEnd()){
                cout << "Currently at the end of the list.\n";
            }
            else{
                cout << "Not at the end of the list.\n";
            }
            break;
        case 'R':
        case 'r':
            cout << "Current item: " << List1.currentItem() << endl;
            break;
        case 'I':
        case 'i':
            cout << "Enter a number to insert into the list.\n";
            cin  >> number;
            List1.insert(number);
            break;
        case 'D':
        case 'd':
            List1.deleteCurrentItem();
            break;
        case 'P':
        case 'p':
            cout << "Current position: " << List1.currentPosition() << endl;
            break;
        case 'L':
        case 'l':
            if(List1.isEmpty()){
                cout << "List is empty.\n";
            }
            else{
                printList(List1);
            }
            break;
        case 'Q':
        case 'q':
            cout << "Now quitting program.\n";
            break;
        default:
            cout << "That is an invalid response.\n";
            break;
        }
    }while((response != 'Q') && (response != 'q'));

    return 0;
}

void printList(List<int> list_to_print){
    list_to_print.goToStart();

    while(!(list_to_print.isAtEnd())){
        cout << list_to_print.currentItem() << " ";
        list_to_print.goToNext();
    }
    cout << endl;
}