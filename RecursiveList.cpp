// Kathy Saad
// 11-20-13
// Linked Lists Using Recursion

#include <iostream>

using namespace std;

struct NodeType{
	int info;
	NodeType * next;
};

void insertNode(NodeType * & head, int value);
// This function inserts a new node into the list and that new node contains the value that the user has entered in
// Postconditions: A new node has been inserted into the list with the new value

void insertAtEnd(NodeType * & head, int value);
// This function inserts a new node at the end of the list recursively
	// and that new node contains the value that the user has entered in
// Postconditions: A new node has been inserted at the end of the list with the new value;
	// if the list was empty, there is no change

void deleteFrontNode(NodeType * & head);
// This function deletes the very first node of the list
// Postconditions: The front node of the list has been deleted; if the list was empty, there is no change

void deleteAtEnd(NodeType * & head);
// This function deletes the very last node of the list recursively
// Postconditions: The last node of the list has been deleted; if the list was empty, there is no change

void deleteKey(NodeType * & head, int value);
// This function finds and deletes the node with the value that the user wants deleted from the list recursively
// Postconditions: The node with the value that the user wants deleted has been deleted from the list

void find(NodeType * head);
// This function attempts to find a number that the user wants to look for in the list
// Postconditions: Whether the number was found or not, the program outputs the appropriate message to screen

void printList(NodeType * head);
// This function prints the entire list recursively. If it's empty, it prints an appropriate message
// Postconditions: List printed to screen. If list is empty, program prints an appropriate message

void printListBackwards(NodeType * head);
// This function prints the entire list backwards recursively. If it's empty, it prints an appropriate message
// Postconditions: List printed to screen backwards. If list is empty, program prints an appropriate message

int main(){
// This function presents a menu to the user and calls the functions that are appropriate based on the user's response
	NodeType * head = NULL;
	char response;
	int value;

	do{
		cout << "Choose an option from the following menu:\n"
			 << "A - Add\n"
			 << "E - Add (at end of list)\n"
			 << "D - Delete (first number in list)\n"
			 << "L - Delete (last number in list)\n"
			 << "K - Delete (any number in list)\n"
			 << "F - Find\n"
			 << "P - Print\n"
			 << "B - Print backwards\n"
			 << "Q - Quit\n";

		cin  >> response;

		switch(response){
		case 'A':
		case 'a':
			cout << "Enter the number that you would like to insert into the list.\n";
			cin  >> value;
			insertNode(head, value);
			break;
		case 'E':
		case 'e':
				if(head == NULL){
					cout << "\nList is empty.\n";
				}
				else{
					cout << "Enter the number that you would like to insert at the end of the list.\n";
					cin  >> value;
					insertAtEnd(head, value);
				}
			break;
		case 'D':
		case 'd':
			if(head == NULL){
				cout << "\nList is empty.\n";
			}
			else{
				cout << "\nCurrent list:\n";
				printList(head);
				cout << endl;

				deleteFrontNode(head);

				cout << endl << endl << "New list:\n";
				printList(head);
				cout << endl;
			}
			break;
		case 'L':
		case 'l':
			if(head == NULL){
				cout << "\nList is empty.\n";
			}
			else if(head->next == NULL){
				deleteFrontNode(head);
			}
			else{
				cout << "\nCurrent list:\n";
				printList(head);
				cout << endl;

				deleteAtEnd(head);

				cout << endl << endl << "New list:\n";
				printList(head);
				cout << endl;
			}
			break;
		case 'K':
		case 'k':
			if(head == NULL){
				cout << "\nList is empty.\n";
			}
			else{
				cout << "Enter a number that you'd like to delete from the list.\n";
				cin  >> value;

				cout << "\nCurrent list:\n";
				printList(head);
				cout << endl;

				deleteKey(head, value);

				cout << endl << endl << "New list:\n";
				printList(head);
				cout << endl;
			}
			break;
		case 'F':
		case 'f':
			if(head == NULL){
				cout << "List is empty.\n";
			}
			else{
				find(head);
			}
			break;
		case 'P':
		case 'p':
			if(head == NULL){
				cout << "List is empty.\n";
			}
			else{
				cout << endl << "List:\n";
				printList(head);
				cout << endl;
			}
			break;
		case 'B':
		case 'b':
			if(head == NULL){
				cout << "List is empty.\n";
			}
			else{
				cout << endl << "List backwards:\n";
				printListBackwards(head);
				cout << endl;
			}
			break;
		case 'Q':
		case 'q':
			cout << "Now quitting program.\n";
			break;
		default:
			cout << "That is an invalid response.\n";
		}
	}while((response != 'q') && (response != 'Q'));

	return 0;
}

void insertNode(NodeType * & head, int value){
	NodeType * temp = new NodeType;
	temp->info = value;
	temp->next = head;
	head = temp;
}

void insertAtEnd(NodeType * & head, int value){
	NodeType * currentPtr = head;
	if(currentPtr->next->next != NULL){
		insertAtEnd(currentPtr->next, value);
	}
	else{
		NodeType * temp = new NodeType;
		temp->info = value;
		temp->next = NULL;
		currentPtr->next->next = temp;
		currentPtr = temp;
	}
}

void deleteFrontNode(NodeType * & head){
	NodeType * currentPtr = head;

	head = head->next;
	delete currentPtr;
	currentPtr = head;
}

void deleteAtEnd(NodeType * & head){
	NodeType * currentPtr = head;
	if(currentPtr->next->next != NULL){
		deleteAtEnd(currentPtr->next);
	}
	else{
		NodeType * temp = currentPtr->next;
		currentPtr->next = NULL;
		delete temp;
	}
}

void deleteKey(NodeType * & head, int value){
	NodeType * currentPtr = head;
	NodeType * previous = NULL;

	if(currentPtr == NULL){
		cout << "Value not found.\n";
	}
	else if(currentPtr->info == value){
		if(currentPtr == head){
			deleteFrontNode(head);
		}
		else if(currentPtr->next == NULL){
			delete currentPtr;
			currentPtr = NULL;
			previous->next = NULL;
		}
		else{
			previous->next = currentPtr->next;
			delete currentPtr;
			currentPtr = previous->next;
		}
	}
	else{
		previous = currentPtr;
		deleteKey(currentPtr->next, value);
	}
}

void find(NodeType * head){
	int value;
	NodeType * currentPtr = head;

	cout << "Enter a number and I'll find out if it's in the list.\n";
	cin  >> value;

	while((currentPtr != NULL) && (currentPtr->info != value)){
		currentPtr = currentPtr->next;
	}
	if(currentPtr == NULL){
		cout << endl << "Not found!\n\n";
	}
	else{
		cout << endl << "Found!\n\n";
	}
}

void printList(NodeType * head){
	NodeType * currentPtr = head;
	if(currentPtr != NULL){
		cout << currentPtr->info << endl;
		printList(currentPtr->next);
	}
}

void printListBackwards(NodeType * head){
	NodeType * currentPtr = head;
	if(currentPtr != NULL){
		printListBackwards(currentPtr->next);
		cout << currentPtr->info << endl;
	}
}
