#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        head = tail = nullptr;
    }

    // Add element to the head of the list
    void AddToHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Add element to the tail of the list
    void AddToTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete element from the head of the list
    void DeleteFromHead() {
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }

    // Delete element from the tail of the list
    void DeleteFromTail() {
        if (tail == nullptr) {
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    // Delete all elements
    void DeleteAll() {
        while (head != nullptr) {
            DeleteFromHead();
        }
    }

    // Show all elements
    void Show() const {
        Node<T>* temp = head;
        if (temp != nullptr) {
            cout << "List: ";
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert element at a given position
    void InsertAtPosition(T value, int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0) {
            AddToHead(value);
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = head;
        for (int i = 1; i < position && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            AddToTail(value);
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete element at a given position
    void DeleteAtPosition(int position) {
        if (position < 0 || head == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 0) {
            DeleteFromHead();
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < position && temp->next != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        Node<T>* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete == tail) {
            tail = temp;
        }
        delete nodeToDelete;
    }

    // Search for an element and return its position
    int Search(T value) const {
        Node<T>* temp = head;
        int position = 0;
        while (temp != nullptr) {
            if (temp->data == value) {
                return position;
            }
            temp = temp->next;
            ++position;
        }
        return -1; // Element not found
    }

    // Search and replace an element, return the count of replaced elements
    int SearchAndReplace(T oldValue, T newValue) {
        Node<T>* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                ++count;
            }
            temp = temp->next;
        }
        return count > 0 ? count : -1; // Return -1 if no elements were replaced
    }

    // Reverse the list
    void Reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        tail = head;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }


    
    // Clone the list
    LinkedList<T>* Clone() const {
        LinkedList<T>* newList = new LinkedList<T>();
        Node<T>* temp = head;
        while (temp != nullptr) {
            newList->AddToTail(temp->data);
            temp = temp->next;
        }
        return newList;
    }

    // Overload operator +
    LinkedList<T>* operator+(const LinkedList<T>& other) const {
        LinkedList<T>* newList = new LinkedList<T>();
        Node<T>* temp = head;
        while (temp != nullptr) {
            newList->AddToTail(temp->data);
            temp = temp->next;
        }
        temp = other.head;
        while (temp != nullptr) {
            newList->AddToTail(temp->data);
            temp = temp->next;
        }
        return newList;
    }

    // Overload operator *
    LinkedList<T>* operator*(const LinkedList<T>& other) const {
        LinkedList<T>* newList = new LinkedList<T>();
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (other.Search(temp->data) != -1) {
                newList->AddToTail(temp->data);
            }
            temp = temp->next;
        }
        return newList;
    }

    ~LinkedList() {
        DeleteAll();
    }
};


int main() {
    LinkedList<int> list1;
    list1.AddToHead(1);
    list1.AddToTail(2);
    list1.AddToTail(3);
    cout << "Standart: " << endl;
    list1.Show(); // Output: 1 2 3
    cout << endl;

    LinkedList<int>* clonedList = list1.Clone();
	cout << "Cloned: " << endl;
    clonedList->Show(); // Output: 1 2 3
    cout << endl;

    LinkedList<int> list2;
    list2.AddToHead(4);
    list2.AddToTail(5);
    list2.AddToTail(3);
	cout << "List2: " << endl;
    list2.Show(); // Output: 4 5 3
    cout << endl;

    LinkedList<int>* combinedList = list1 + list2;
	cout << "Combined: " << endl;
    combinedList->Show(); // Output: 1 2 3 4 5 3
    cout << endl;

    LinkedList<int>* commonList = list1 * list2;
	cout << "Common: " << endl;
    commonList->Show(); // Output: 3
    cout << endl;

    delete clonedList;
    delete combinedList;
    delete commonList;

    return 0;
}