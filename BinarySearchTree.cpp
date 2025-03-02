//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Dylan Lovin
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>
#include <time.h>
#include <Windows.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// Internal structure for tree node
struct Node {
    Bid bid;
    Node* left;
    Node* right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a bid
    Node(Bid aBid) {
        bid = aBid;
        left = nullptr;
        right = nullptr;
    }

    //// create the key for the given bid
    //unsigned int key = hash(atoi(bidId.c_str()));
    //Node* node = &(nodes.at(key));

    //// if entry found for the key
    //if (node != nullptr && node->key != UINT_MAX
    //        && node->bid.bidId.compare(bidId) == 0) {
    //    return node->bid;
    //}

    //// if no entry found for the key
    //if (node == nullptr || node->key == UINT_MAX) {
    //    return bid;
    //}

    //while (node != nullptr) {
    //    // if the current node matches, return it
    //    if (node->key != UINT_MAX && node->bid.bidId.compare(bidId) == 0) {
    //        return node->bid;
    //    }
    //    node = node->next;
    //}

    //return bid;


};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    //void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    //Node* removeNode(Node* node, string bidId);
    int size = 0;

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
    int Size();

};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // FixMe (1): initialize housekeeping variables
    //root is equal to nullptr
    this->root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // FixMe (2): In order root
    // call inOrder fuction and pass root 

    inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
 //void BinarySearchTree::PostOrder() {
     // FixMe (3): Post order root
     // postOrder root
 //}

 /**
  * Traverse the tree in pre-order
  */
  //void BinarySearchTree::PreOrder() {
  //    // FixMe (4): Pre order root
  //    // preOrder root
  //}

  /**
   * Insert a bid
   */
void BinarySearchTree::Insert(Bid bid) {
    // FIXME (5) Implement inserting a bid into the tree
    // if root equarl to null ptr
      // root is equal to new node bid
    // else
      // add Node root and bid

    Node* currentNode = root;

    if (root == NULL) {

        root = new Node(bid);

    }
    else {

        while (currentNode != NULL) {

            if (bid.bidId < currentNode->bid.bidId) {

                if (currentNode->left == nullptr) {

                    currentNode->left = new Node(bid);
                    currentNode = NULL;
                }
                else {

                    currentNode = currentNode->left;
                }
            }
            else {

                if (currentNode->right == nullptr) {

                    currentNode->right = new Node(bid);
                    currentNode = NULL;
                }
                else {

                    currentNode = currentNode->right;
                }
            }
        }
    }
    size++;
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    // FIXME (6) Implement removing a bid from the tree
    // remove node root bidID

    Node* par = NULL;
    Node* curr = root;

    while (curr != NULL) {

        if (curr->bid.bidId == bidId) {
            if (curr->left == NULL && curr->right == NULL) {
                if (par == NULL) {
                    root = nullptr;
                }
                else if (par->left == curr) {
                    par->left = NULL;
                }
                else {
                    par->right = NULL;
                }
            }
            else if (curr->right == NULL) {
                if (par == NULL) {
                    root = curr->left;
                }
                else if (par->left == curr) {
                    par->left = curr->left;
                }
                else {
                    par->right = curr->left;
                }
            }
            else if (curr->left == NULL) {
                if (par == NULL) {
                    root = curr->right;
                }
                else if (par->left == curr) {
                    par->left = curr->right;
                }
                else {
                    par->right = curr->right;
                }
            }
            else {
                Node* suc = curr->right;

                while (suc->left != NULL) {
                    suc = suc->left;

                }

                Node successorData = Node(suc->bid);
                Remove(suc->bid.bidId);
                curr->bid = successorData.bid;
            }
            //cout << "\nNode found and removed" << endl;
            return;
        }
        else if (curr->bid.bidId < bidId) {
            par = curr;
            curr = curr->right;
        }
        else {
            par = curr;
            curr = curr->left;
        }
    }
    cout << "\nValue not found" << endl;
    return;
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    // FIXME (7) Implement searching the tree for a bid
    // set current node equal to root

    // keep looping downwards until bottom reached or matching bidId found
        // if match found, return current bid

        // if bid is smaller than current node then traverse left
        // else larger so traverse right
    Bid bid;

    Node* currentNode = root;

    while (currentNode != NULL) {

        if (currentNode->bid.bidId == bidId) {

            return currentNode->bid;
        }
        else if (bidId < currentNode->bid.bidId) {

            currentNode = currentNode->left;
        }
        else {

            currentNode = currentNode->right;
        }
    }

    //not found
    //cout << "Value not found." << endl;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    // FIXME (8) Implement inserting a bid into the tree
    // if node is larger then add to left
        // if no left node
            // this node becomes left
        // else recurse down the left node
    // else
        // if no right node
            // this node becomes right
        //else
            // recurse down the left node
}
void BinarySearchTree::inOrder(Node* node) {
    // FixMe (9): Pre order root
    //if node is not equal to null ptr
    //InOrder not left
    //output bidID, title, amount, fund
    //InOder right


    if (node == NULL) {

        return;
    }
    inOrder(node->left);

    //print the node
    cout << node->bid.bidId << ": " << node->bid.title << " | " << node->bid.amount
        << " | " << node->bid.fund << endl;

    inOrder(node->right);
}
//void BinarySearchTree::postOrder(Node* node) {
//      // FixMe (10): Pre order root
//      //if node is not equal to null ptr
//      //postOrder left
//      //postOrder right
//      //output bidID, title, amount, fund
//
//}
//
//void BinarySearchTree::preOrder(Node* node) {
//      // FixMe (11): Pre order root
//      //if node is not equal to null ptr
//      //output bidID, title, amount, fund
//      //postOrder left
//      //postOrder right      
//}

int BinarySearchTree::Size() {

    return size;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
        << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    //for (auto const& c : header) {
    //    cout << c << " | ";
    //}
    //cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bst->Insert(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
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
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
        //bidKey = "98061";
        bidKey = "97990"; //root

    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst = new BinarySearchTree();

    Bid bid;

    const int GLOBAL_SLEEP_VALUE = 5000;
    int choice = 0;
    string anyKey = " ";
    bool goodInput;

    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";

        try {
            cin >> choice;

            if ((choice > 0 && choice < 5) || (choice == 9)) {// limit the user menu inputs to good values
                goodInput = true;
            }
            else {//throw error for catch
                goodInput = false;
                throw 1;
            }


            switch (choice) {

            case 1:
                //bst = new BinarySearchTree();

                // Initialize a timer variable before loading bids
                ticks = clock();

                // Complete the method call to load the bids
                loadBids(csvPath, bst);

                cout << bst->Size() << " bids read" << endl;

                // Calculate elapsed time and display result
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

                Sleep(GLOBAL_SLEEP_VALUE);

                break;

            case 2:
                bst->InOrder();

                cout << "\nEnter \'y\' to continue..." << endl;

                cin >> anyKey;

                break;

            case 3:
                ticks = clock();

                bid = bst->Search(bidKey);

                ticks = clock() - ticks; // current clock ticks minus starting clock ticks

                if (!bid.bidId.empty()) {
                    displayBid(bid);
                }
                else {
                    cout << "Bid Id " << bidKey << " not found." << endl;
                }

                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

                Sleep(GLOBAL_SLEEP_VALUE);

                break;

            case 4:
                bst->Remove(bidKey);

                Sleep(GLOBAL_SLEEP_VALUE);

                break;

            case 9:
                break;

            default:
                throw 2;
            }



        }

        catch (int err) {
            std::cout << "\nPlease check your input." << endl;
            Sleep(GLOBAL_SLEEP_VALUE);
        }

        //need to clear the cin operator of extra input, e.g., 9 9, or any errors generated by bad input, e.g., 'a'
        cin.clear();
        cin.ignore();

        //clear the consolse to redraw a fresh menu
        system("cls");

    }



    cout << "Good bye." << endl;

    Sleep(GLOBAL_SLEEP_VALUE);

    return 0;
}
