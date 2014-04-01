// Kathy Saad
// 11-6-13
// Linked List ADT

#pragma once

#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType{
    ItemType info;
    NodeType * next;
};

template<class ItemType>
class List{
public:
    List();
    // Used before any operations are done on the linked list. Initializes the list to empty.
    // Postconditions: List is an empty linked list. The current position is 1.

    void makeEmpty();
    // Makes the linked list empty if it is not empty already.
    // Preconditions: The list may be empty or have items in it.
    // Postconditions: List is now an empty linked list. Any dynamically allocated memory which is no longer used is returned to the system.
        // The current position is 1.

    bool isEmpty();
    // Returns true if linked list is an empty list; returns false otherwise.
    // Postconditions: List remains unchanged.

    void goToStart();
    // Moves the current position to the start of the list.
    // Postconditions: Current position is set to 1.

    void goToNext();
    // If current position is not at the end of the list, moves the current position to next position.
    // Postconditions: Position has been moved to the next position, unless position had been already at the end of the list.
        // If the position had already been at the end of the list, it is unchanged. If the list is empty, nothing is changed.

    bool isAtEnd();
    // Returns true if the list is empty or if the current position is at the end of the list.
    // Postconditions: List remains unchanged.

    ItemType currentItem();
    // Returns the object of the current item in the linked list. Assumes that the current item exists;
        // i.e., the current position is not at the end of the list.
    // Preconditions: List is not empty, and the current position is not at the end of the list.
    // Postconditions: List and current position remain unchanged.

    void insert(ItemType);
    // Inserts the given newItem in the linked list *before* the item at the current position. After the insertion,
        // the current position remains unchanged, but the newly inserted item is there. If there was an item at the current position before the insertion,
        // that item would now be at current position + 1.
    // Preconditions: The list may be empty.
    // Postconditions: newItem is inserted into the linked list before any item that was at the current position.
        // The current position is unchanged and the newly inserted item will now be at that position.

    void deleteCurrentItem();
    // Deletes the item in the linked list at the current position. Assumes that the current item exists.
    // Preconditions: List is not empty, and the current position is not at the end of the list.
    // Postconditions: The item at the current position has been deleted. The current position remains unchanged with respect to the list:
        // If the item had been the last item, the current position will be at the end of the list.

    int currentPosition();
    // Returns the number of the current position. If there is an item at the current position, it will return the relative position of the item in the list.
        // If the position is at the end of the list, it will return 1 + the number of items in the list.
    // Postconditions: List and current position remain unchanged.

private:
    NodeType<ItemType> * head;
    NodeType<ItemType> * current;
    NodeType<ItemType> * previous;
    int position;
};

template<class ItemType>
List<ItemType>::List(){
    position = 1;
    head = NULL;
    current = NULL;
    previous = NULL;
}

template<class ItemType>
void List<ItemType>::makeEmpty(){
    if(head == NULL){
        cout << "List is empty already.\n";
    }
    else{
        previous = NULL;
        current = head;
        while(head != NULL){
            head = head->next;
            delete current;
            current = head;
        }
        position = 1;
    }
}

template<class ItemType>
bool List<ItemType>::isEmpty(){
    return (head == NULL);
}

template<class ItemType>
void List<ItemType>::goToStart(){
    position = 1;
    current = head;
    previous = NULL;
}

template<class ItemType>
void List<ItemType>::goToNext(){
    if(current != NULL){
        position++;
        previous = current;
        current = current->next;
    }
}

template<class ItemType>
bool List<ItemType>::isAtEnd(){
    return (current == NULL);
}

template<class ItemType>
ItemType List<ItemType>::currentItem(){
    return (current->info);
}

template<class ItemType>
void List<ItemType>::insert(ItemType newItem){
    if(head == current){
        current = new NodeType<ItemType>;
        current->info = newItem;
        current->next = head;
        head = current;
    }
    else{
        NodeType<ItemType> * temp = new NodeType<ItemType>;
        temp->info = newItem;
        previous->next = temp;
        temp->next = current;
        current = temp;
    }
}

template<class ItemType>
void List<ItemType>::deleteCurrentItem(){
    if(head == current){
        head = head->next;
        delete current;
        current = head;
    }
    else{
        previous->next = current->next;
        delete current;
        current = previous->next;
    }
}

template<class ItemType>
int List<ItemType>::currentPosition(){
        return position;
}