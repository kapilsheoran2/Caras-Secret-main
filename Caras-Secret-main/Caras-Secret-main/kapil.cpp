#include <iostream>

using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

// LinkedList class to manage the linked list operations
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // Function to add a node to the end of the list
    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to swap the first and last nodes of the list
    void swapFirstAndLast() {
        if (head == nullptr || head->next == nullptr) {
            // List is empty or has only one element, no need to swap
            return;
        }

        Node* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }

        Node* last = secondLast->next;
        Node* first = head;

        // Swap data values
        int temp = first->data;
        first->data = last->data;
        last->data = temp;
    }

    // Function to display the elements of the list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to deallocate memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    // Adding elements to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    cout << "Original list: ";
    list.displayList();

    // Swapping first and last nodes
    list.swapFirstAndLast();

    cout << "List after swapping first and last nodes: ";
    list.displayList();

    return 0;
}
