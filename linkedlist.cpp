/*
*   Name: Joanna Lopez      NetID: jjl369
*   Date: April 2, 2023     Due Date: April 7, 2023
*
*   Description: I created three different functions for this linked list. These functions
*                include the insert, remove, and view functions. With these functions the
*                position was given as an argument indicating the exact position they wanted
*                to perform the function on. The insert function inserts a new node in the given
*                position either it be at the front, end, or in the middle. The remove function
*                removes from any position in the linked list. And lastly, the view functions displays
*                the item in the indicated position.

*/


#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// ***************************************************
// GIVEN TO STUDENTS
// ***************************************************

void LinkedList::append(string title, string author)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node(title, author);

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        Node *temp = new Node(title, author);

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

int LinkedList::pop()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- pop failed!" << endl;
        return 1; // exits from the function with fail flag
    }

    // if removing a node will empty the list
    if(size == 1)
    {
        // store current head
        Node *temp = head;

        // sanity check clear head and tail
        head = nullptr;
        tail = nullptr;

        // delete node
        delete temp;
    }

    // otherwise, if it won't
    else
    {
        // start a temporary node at the head
        Node *temp = head;

        // loop to one before the tail
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }

    size--;

    return 0;
}

int LinkedList::display()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- display failed!" << endl;
        return 1; // exits from the function with fail flag
    }

    // starts temporary Node at the beginning (head)
    Node *temp = head;
    int count = 0;

    while(temp != nullptr)
    {
        // displays information
        cout << "Book " << count << ": ";
        cout << temp->title << " by " << temp->author << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;

        count++;
    }

    return 0;
}

// ***************************************************
// END GIVEN TO STUDENTS
// ***************************************************


int LinkedList::insert(string title, string author, int position)
{
    // ERROR CHECKING FOR OUT OF RANGE POSITIONS
    if (position < 0 || position > size)
    {
        cout << "Not a valid insert -- out of range!" << endl;
        return 1;   // ends program with fail flag
    }
   
    // if node is to be inserted at the head AKA position 0
    else if (position == 0)
    {
        // creates new node with information put in
        Node* temp = new Node(title, author);
        Node *temp2 = head;               // grabs node at current head 
        head = temp;                      // sets the new node to head head
        temp->next = temp2;               // new node's next points to the old head
    }
    // if node is to be inserted at the tail AKA the size plus one
    else if (position == size)
    {
        // creates new node with information put in
        Node* temp = new Node(title, author);
        tail->next = temp;                // points current tail to new node
        tail = temp;                      // sets the tail as the new tail
        tail->next = nullptr;
    }
    // if node is to be inserted in the middle
    else
    {
        // creates new node with information put in
        Node* temp = new Node(title, author);
        
        // creates a temporary node to reference the head
        // uses count to keep track at what position it is at
        // keeps track of the item before the indicated position
        Node* temp2 = head;
        Node* var = temp2->next;
        int count = 0;
        
        while (count != (position - 1))
        {
            temp2 = temp2->next;            // points the temp2 to the next item in list to continue iterating through
            var = temp2->next;              // points the item after node to the next node
            count++;                        // adds 1 to count to continue the while loop
        }
        temp2->next = temp;                 //points current item (the one before position) to the new node
        temp->next = var;                   // points the new node to the item that used to be in that position
    }
    
    size++;

    return 0;
}

int LinkedList::remove(int position)
{
    //ERROR CHECK
    if (position < 0 || position > (size - 1))
    {
        cout << "Not a valid remove -- out of range!" << endl;
        return 1; 
    }
    else if (position == 0)
    {
        // stores the item after the current head
        Node* temp = head->next;
        delete head;            // deletes the current head(item at position 0)
        head = temp;            // assigns new head
    }
    else if (position == (size - 1))
    {
        // creates temporary node to keep track of head
        Node* temp = head;

        //iterates through until it is at the item before the tail
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        //deletes the current tail
        delete tail;

        // assigns the item that was before the tail as the new tail
        // makes sure that it clears the next pointer
        tail = temp;
        tail->next = nullptr;
    }
    else
    {
       // grabs the head to iterate
       // grabs the item after the 'next' item
       // begins counter at 0 which will indicate the current position
       // and loops until the position before the indicated position
        Node* temp = head;
        Node* var = temp->next->next;
        int count = 0;
        while (count != (position - 1))
        {
            temp = temp->next;          // moves temp to the next item
            var = temp->next->next;     // moves var to the next item after it
            count++;                    // adds 1 to counter 
        }
        delete temp->next;              // deletes the next item
        temp->next = var;               // points current temp(item before deleted item) 
                                        // to the item after the deleted item
    }
    
    size--;

    return 0;
}

int LinkedList::view(int position)
{
    //ERROR CHECKING
    if (position < 0 || position > size)
    {
        cout << "Not a valid view -- out of range!" << endl;
        return 1;
    }
    // creates counter and grabs head to start iterating
    int count = 0;
    Node* temp = head;

    while (count != position)
    {
        // moves temp node to the next node in list
        temp = temp->next;

        // adds one to counter
        count++;
    }
    // if count == position it will display the information
    cout << temp->title << " by " << temp->author << endl;
    
    return 0;
}
