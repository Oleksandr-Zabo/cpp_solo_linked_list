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

    ~LinkedList() {
        DeleteAll();
    }
};

int main() {
    LinkedList<int> list;
    list.AddToHead(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.Show(); // Output: 1 2 3
    system("pause");

    //menu
    do
    {
        system("cls");
        int choice;
        cout << "Menu" << endl;
        cout << "1. Add to head" << endl;
        cout << "2. Add to tail" << endl;
        cout << "3. Delete from head" << endl;
        cout << "4. Delete from tail" << endl;
        cout << "5. Delete all" << endl;
        cout << "6. Show" << endl;
        cout << "7. Insert at position" << endl;
        cout << "8. Delete at position" << endl;
        cout << "9. Search" << endl;
        cout << "10. Search and replace" << endl;
        cout << "11. Reverge the list" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        int value;
        int position;

        case 1: {
            
            cout << "Enter value: ";
            cin >> value;
            list.AddToHead(value);
        }break;

        case 2: {
            cout << "Enter value: ";
            cin >> value;
            list.AddToTail(value);
        }break;

        case 3: {
            list.DeleteFromHead();
        }break;

        case 4: {
            list.DeleteFromTail();
        } break;

        case 5: {
            list.DeleteAll();
        }break;

        case 6: {
            list.Show();
        }break;

        case 7: {
            
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            list.InsertAtPosition(value, position);
        }break;

        case 8: {
            cout << "Enter position: ";
            cin >> position;
            list.DeleteAtPosition(position);
        }break;

        case 9: {
            cout << "Enter value: ";
            cin >> value;
            cout << "Position of " << value << ": " << list.Search(value) << endl;
        }break;

        case 10:
            int oldValue, newValue;
            cout << "Enter old value: ";
            cin >> oldValue;
            cout << "Enter new value: ";
            cin >> newValue;
            cout << "Replaced count: " << list.SearchAndReplace(oldValue, newValue) << endl;
            break;

        case 11: {
            list.Reverse();
        }break;

        case 12: {
            exit(0);
        }break;

        default: {
            cout << "Invalid choice" << endl;
        }break;

        }

        system("pause");
    } while (1);

    return 0;
}
