#include "playlist.h"

/*
    Name: Joanna Lopez          NetID: jjl369

    Date: April 21, 2023        Due Date: April 22, 2023

    Description: This program is able to sort a given file in ascending and descending order.
                 It is also able to search for a given key, in this case a song title. The file
                 is inserted as a linked list. Therefore, the sorting and searching algorithms are 
                 implemented in respect to Linked Lists.
*/






// constructor and destructor (given to you)
Playlist::Playlist()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Playlist::~Playlist()
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

// display and add functions (given to you)
void Playlist::display()
{
    // starts temporary Node at the beginning (head)
    Node *temp = head;

    while(temp != nullptr)
    {
        // displays information
        cout << temp->title << " - " << temp->artist << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
    }
}

void Playlist::append(string title, string artist)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node;

        head->title = title;
        head->artist = artist;
        head->next = nullptr;

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        Node *temp = new Node;

        temp->title = title;
        temp->artist = artist;
        temp->next = nullptr;

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

void Playlist::shuffle()
{
    // seeds random number
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        int num = rand() % size;

        // swaps current "index" with random "index"

        // gets node at current position
        Node *current = head;
        for(int j = 0; j < i; j++)
        {
            current = current->next;
        }

        // gets node at random position
        Node *random = head;
        for(int j = 0; j < num; j++)
        {
            random = random->next;
        }

        // stores the current Node's information
        string tempTitle = current->title;
        string tempArtist = current->artist;

        // reassigns the random Node's information to the current
        current->title = random->title;
        current->artist = random->artist;

        // and the stored current information to the random Node
        random->title = tempTitle;
        random->artist = tempArtist;
    }
}

// ****************************************************************
// ** you should make **
// all of these should work on a TITLE of the song basis
// ****************************************************************

int Playlist::binarySearch(string title)
{
    // calls the sort function in order to search
    // list needs to be sorted first
    sort();

    // "index" of the lower, higher, and middle title
    int low = 0;
    int high = size - 1;;
    int mid;
   
    // while the lower index is smaller or equal to the higher index
    while (low <= high)
    {
        // finds the middle index
        int mid = (low + high) / 2;

        // pointer to go through every node
        // starts at the head and store its content in a string variable
        Node* first = head;
        string second = first->title;

        // iterates until it gets to the item at the middle index
        // and keeps storing it into the string variable
        for (int i = 0; i < mid; i++)
        {
           first = first->next;
           second = first->title;
        }

        // string comparisons
        // if the string variable is less than the title
        if (second < title)
        {
            low = mid + 1;
        }
        // else if the variable is larger than the title
        else if (second  >title)
        {
            high = mid - 1;
        }
        // else it returns the middle "index"
        else 
        {
            return mid;
        }

    }
    // not found
    return -1;
}



// algorithm of choice: Selection Sort
// any links to resources to make it work: https://www.youtube.com/watch?v=EjWiBcpHx4o&ab_channel=BBarters
// although on the link that I put on here it says that this is bubble sort I strongly think it is more 
// like selection sort because in the first iteration you are comparing the first node and continue iterating with a different
// pointer and comparing that to the first one. I don't know if I'm explaining myself well, but you can be the judge of that
void Playlist::sort()
{
    // will start by pointing to head and follow behind the second pointer
    Node* first;

    // first outer loop iteration will keep the first pointer at head
    // first inner loop iteration will move along the list comparing data to the first pointer and so on
    // this is done until it gets to the end of the list hence the use of nullptr
    // i used the same format as the resource listed above
    for (first = head; first->next != nullptr; first = first->next)
    {
        for (Node* second = first->next; second != nullptr; second = second->next)
        {
            // if the data to the "left" is greater than switch with the data coming after it
            // swaps the actual data
            if (first->title > second->title)
            {
                // stores the data for the node the "first" pointer is pointing at
                string tempTitle = first->title;
                string tempArtist = first->artist;

                // reassigns the data of the next node
                first->title = second->title;
                first->artist = second->artist;

                // stores the "first" pointer's data to the node after it
                second->title = tempTitle;
                second->artist = tempArtist;

            }
        }
    }


}

// algorithm of choice: Insertion Sort
// any links to resources to make it work: https://www.youtube.com/watch?v=r4zKLXUxtE4&t=25s&ab_channel=Let%27sPracticeTogether
// i used the overall structure as the resource listed above but just implemented in a way that it
// can sort in descending order
void Playlist::reverseSort()
{
    // points to the head and creates an empty pointer for the sorted partition
    Node* current = head;
    Node* sorted = NULL;
    
    // loop will run while current is not at the end of the list
    while (current != NULL)
    {
        // points to the second node of the list (head->next)
        Node* after = current->next;

        // if there is no data in sorted it will run
        // or if the data in the sorted partition is less than the current data (since we are going backwards)
        // it will "swap" or rather move links and reassign sorted
        if (sorted == NULL || sorted->title <= current->title)
        {
            current->next = sorted;
            sorted = current;
        }
        // else a temporary pointer is created and pointed to the sorted "partition"
        // while the node after the sorted "partition" is not empty
        // AND the data of the node after the sorted "partition" is greater than the current data
        // temp is reassigned to continue comparing through
        else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->title > current->title)
            {
                temp = temp->next;
            }
            
            // if the above case is not true (the data before current's data is smaller)
            // then the links are reassigned
            // current is going to point to node before it
            // temp is pointed to current (so now the order will be "sorted"->current->"temp->next")
            current->next = temp->next;
            temp->next = current;
        }
        
        // after first pass/iteration current is reassigned 
        // to current->next 
        current = after;
    }

    // head is now the largest value 
    // sorted was pointing to, in this case, the largest value 
    // marking the beginning of the list
    head = sorted;
    
}


// ****************************************************************
// ****************************************************************


// HONORS / BONUS credit
// optional unless you're honors
// if not implementing, just leave it here
void Playlist::sortByArtist()
{

}

