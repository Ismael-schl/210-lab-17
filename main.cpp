//Lab 17 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void prepend(Node *&head);
void append(Node *&head);
void deleteNode(Node *&head);
void insertNode(Node *&head);
void deleteList(Node *&head);
void output(Node *hd);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);
    //Choice menu
    int choice = 0;
        
    while (choice != 6) {
        cout << "How would you like to manipulate this linked list?" << endl  << endl<< "To add a number to the end, press 1, then enter." << endl;
        cout << "To add a a number to the beginning, press 2, then enter." << endl;
        cout << "To delete a certain number in the list, press 3, then enter." << endl;
        cout << "To insert a certain number into the list, press 4, then enter." << endl;
        cout << "To delete the entire list, press 5, then enter." << endl;
        cout << "To end, press 6, then enter." << endl;
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) {
            if (choice == 1) {
                append(head);
            }
            if (choice == 2) {
                prepend(head);
            }
            if (choice == 3) {
                deleteNode(head);
            }
            if (choice == 4) {
                insertNode(head);
            }
            if (choice == 5) {
                deleteList(head);
            }
        }
        else {
            if (cin.fail()) {
                cout << "Error: choice must be in integer form.";
                cin.clear();
                cin.ignore(1000,'\n');
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: please enter a value from 1-6" << endl;
        }
    }
    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void prepend(Node *&head){
    Node *newnode = new Node;
    while (true) {
        cout << "Enter the float value you'd like to prepend: ";
        cin >> newnode->value;
        if (cin.fail()) {
            cout << "Invalid input, must be a float" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }
    if (head == nullptr) {
        head = newnode;
        newnode->next = nullptr;
    }
    else {
        Node* temp = head;
        newnode->next = temp;
        head = newnode;
    }
    output(head);
}

void append(Node *&head) {
    Node *newnode = new Node;
    newnode->next = nullptr;
    while (true) {
        cout << "Enter the float value you'd like to append: ";
        cin >> newnode->value;
        if (cin.fail()) {
            cout << "Invalid input, must be a float" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }
    if (head == nullptr) {
        head = newnode;
        newnode->next = nullptr;
    }
    else {
        Node *current = head;
        while (current->next != nullptr) {
                current = current-> next;
            }
        current->next = newnode;
        }
    output(head);        
}

void deleteNode(Node *&head){
    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);
}

void insertNode(Node *&head) {
    // insert a node
    int entry = 0;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    Node* current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node* prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);
}

void deleteList(Node *&head) {
       // deleting the linked list
    Node* current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}