//============================================================================
// Name        : LinkedList.cpp
// Author      : Dylan Lovin
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 3-2 Lists and Searching
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>

#include "CSVparser.cpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid
{
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid()
    {
        amount = 0.0;
    }
};

//============================================================================
// Linked-List class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a linked-list.
 */
class LinkedList
{

private:
    // Internal structure for list entries, housekeeping variables
    struct Node
    {
        Bid bid;
        Node* next;
        Node* prev;

        // default constructor
        Node()
        {
            next = nullptr;
            prev = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid)
        {
            bid = aBid;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size = 0;

public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void Prepend(Bid bid);
    void PrintList();
    void Remove(string bidId);
    Bid Search(string bidId);
    int Size();
};

/**
 * Default constructor
 */
LinkedList::LinkedList()
{
    // FIXME (1): Initialize housekeeping variables
    // set head and tail equal to null
    head = NULL;
    tail = NULL;
}

/**
 * Destructor
 */
LinkedList::~LinkedList()
{
    // start at the head
    Node* current = head;
    Node* temp;

    // loop over each node, detach from list then delete
    while (current != nullptr)
    {
        temp = current;          // hang on to current node
        current = current->next; // make current the next node
        delete temp;             // delete the orphan node
        return;
    }
}

/**
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid)
{
    // FIXME (2): Implement append logic
    // Create new node
    Node* newNode = new Node(bid);
    // if there is nothing at the head...
    //  new node becomes the head and the tail
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        ++size;
    }
    // else
    //  make current tail node point to the new node
    //  and tail becomes the new node
    else
    {
        tail->next = newNode;
        tail = newNode;
        // increase size count
        ++size;
    }
}

/**
 * Prepend a new bid to the start of the list
 */
void LinkedList::Prepend(Bid bid)
{
    // FIXME (3): Implement prepend logic
    // Create new node
    Node* newNode = new Node(bid);

    // if there is already something at the head...
    // new node points to current head as its next node
    if (head != NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
        head = newNode;
    tail = newNode;

    // head now becomes the new node
    // increase size count
    ++size;
}

/**
 * Simple output of all bids in the list
 */
void LinkedList::PrintList()
{
    Bid bid;
    // FIXME (4): Implement print logic
    // start at the head
    Node* currNode = head;
    Node* temp = new Node();

    // while loop over each node looking for a match
    // output current bidID, title, amount and fund
    // set current equal to next

    while (currNode != nullptr)
    {
        temp->bid = currNode->bid;

        /*for (int i = 1; i < size + 1; i++) {
            cout << i <<". " << temp->bid.bidId << endl;
        }
        currNode = currNode->next;
    }*/

        cout << temp->bid.bidId << ": " << temp->bid.title << "|" << temp->bid.amount << "|" << temp->bid.fund << "|" << endl;
        currNode = currNode->next;
    }
}

/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove(string bidId)
{

    // *** COULD NOT GET TO WORK AS INTENDED.
    // THE CODE RUNS AND LOCATES THE INTENDED NODE FOR REMOVAL BUT IT DOESN'T FULLY DELETE.
    //    Node* current = head;
    //    Node* temp = new Node;
    ////
    //    while (current != NULL) {
    //        if (current->bid.bidId.compare(bidId) == 0) {
    //            temp = current;
    //            current = current->next;
    //            delete temp;
    //            return;
    //        }
    //    }
    //}
    //    /***************************** WORKING CODE ******************************/
    Node* current = head;

    Node* nextNode = current->next; // stores the next node in variable nextNode.
    Node* prevNode = nullptr;       // points the current nodes previous node to null.

    if (nextNode != nullptr)
    {                              // traverses the list checking if the next node IS NOT null.
        nextNode->prev = prevNode; // assigns previous node value to nextNode previous pointer
    }
    if (prevNode != nullptr)
    {                              // checks for prevNode value for null
        prevNode->next = nextNode; // assigns current nodes next value to previous nodes next
    }
    if (current == head)
    {                    // checks if the current value is EQUAL to the head.
        head = nextNode; // If so, points nextnode to head.
    }
    if (current == tail)
    {
        tail = prevNode;
    }
    --size;
    cout << size << endl;
    /***************************** WORKING CODE ******************************/
}
/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(string bidId)
{
    // FIXME (6): Implement search logic

    // special case if matching node is the head
    // make head point to the next node in the list
    // decrease size count
    // return

    // start at the head of the list
    Node* currNode = head;
    Node* temp = new Node;
    temp->bid.bidId = "";

    // keep searching until end reached with while loop (next != nullptr
    while (currNode != nullptr)
    {
        if (currNode->bid.bidId.compare(bidId) != 0)
        {
            return currNode->bid;
        }
        // currNode = currNode;
    }
    // if the current node matches, return it
    // else current node is equal to next node

    // return bid
    return temp->bid;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size()
{
    return size;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid)
{
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount
        << " | " << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid()
{
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void loadBids(string csvPath, LinkedList* list)
{
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser
    csv::Parser file = csv::Parser(csvPath);

    try
    {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++)
        {

            // initialize a bid using data from current row (i)
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            // cout << bid.bidId << ": " << bid.title << " | " << bid.fund << " | " << bid.amount << endl;

            // add this bid to the end
            list->Append(bid);
        }
    }
    catch (csv::Error& e)
    {
        cerr << e.what() << endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch)
{
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 *
 * @param arg[1] path to CSV file to load from (optional)
 * @param arg[2] the bid Id to use when searching the list (optional)
 */
int main(int argc, char* argv[])
{

    // process command line arguments
    string csvPath, bidKey;
    switch (argc)
    {
    case 2:
        csvPath = argv[1];
        bidKey = "97990";
        // bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "97990";
        // bidKey = "98109";
    }

    clock_t ticks;

    LinkedList bidList;

    Bid bid;

    int choice = 0;
    while (choice != 9)
    {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  4. Find Bid" << endl;
        cout << "  5. Remove Bid" << endl;
        cout << "  6. Prepend Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bid = getBid();
            bidList.Append(bid);
            displayBid(bid);

            break;

        case 2:
            ticks = clock();

            loadBids(csvPath, &bidList);

            cout << bidList.Size() << " bids read" << endl;

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " milliseconds" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            fflush(stdin);

            break;

        case 3:
            bidList.PrintList();

            break;

        case 4:
            ticks = clock();

            bid = bidList.Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.compare(bidKey) != 0)
            {
                displayBid(bid);
            }
            else
            {
                cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 5:
            bidList.Remove(bidKey);

            break;
        case 6:
            bid = getBid();
            bidList.Prepend(bid);
            displayBid(bid);

            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
