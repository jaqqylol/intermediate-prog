#include "Stack.h"

Stack::Stack()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

//deconstructor
Stack::~Stack()
{
	if (size > 0)
	{
		Node* temp;
		while (head != nullptr)
		{
			//grabs node after the head
			temp = head->next;

			//deletes head
			delete head;

			//makes head the temp node
			head = temp;
		}
	}
}

//should add at the head according to stack principles
// add from the end
void Stack::add(char item)
{
	// if stack is empty
	if (size == 0)
	{
		// create a new node at the head
		head = new Node;
		head->data = item;
		head->next = nullptr;

		// assings tail to the head (only 1 node in list)
		tail = head;
	}
	// if stack is not empty
	else
	{
		// creates a new node
		Node* temp = new Node;
		temp->data = item;
		temp->next = nullptr;

		// point current tail new node
		tail->next = temp;

		// make new node the new tail
		tail = temp;
	}
	
	size++;

}


// should remove from the head according to stack principles
// remove from the end
// shoulrd return what is being removed
char Stack::remove()
{
	// initialize variable to store data and return later
	char var;

	if (size == 0)
	{
		cout << "Stack is empty -- remove failed!" << endl;
		return 1;		// ends program
	}
	if (size == 1)
	{
		// store current head or tail in this case it won't matter
		Node* temp = tail;

		// store data in variable
		var = tail->data;

		// clear head and tail
		head = nullptr;
		tail = nullptr;

		// delete tail
		delete temp;
	}
	else
	{
		// store current head to iterate through stack
		Node* temp = head;
		
		// loop to node before tail to keep track of it
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}

		// store data in tail before deleting
		var = tail->data;

		// delete the tail
		delete tail;

		// assign new tail
		tail = temp;
		tail->next = nullptr;		// just to make sure
	}

	size--;
	return var;
}

