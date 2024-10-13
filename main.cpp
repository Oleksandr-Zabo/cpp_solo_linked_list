#include <iostream>
using namespace std;

enum ProjConstants {
    MAX_SIZE = 5,
    ALLOCATED_MEMORY = 5
};

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;
    int size;
    int allocated_memory;

    void IncreaseMemory() {
        allocated_memory += ProjConstants::ALLOCATED_MEMORY;
        cout << "Increased allocated memory to: " << allocated_memory << endl;
    }

public:
    Stack() {
        cout << "Constructor called" << endl;
        top = nullptr;
        size = 0;
        allocated_memory = ProjConstants::MAX_SIZE;
    }

    // Push element onto the stack
    void Push(T value) {
        if (size == allocated_memory) {
            IncreaseMemory();
        }
        Node<T>* newNode = new Node<T>(value);
        cout << "Pushed: " << value << endl;
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Check if the stack is empty
    bool IsEmpty() const {
        return top == nullptr;
    }

    // Pop element from the stack
    void Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node<T>* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
        size--;
    }

    // Get the top element of the stack
    T Top() const {
        if (IsEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        cout << "Returned top element: " << top->data << endl;
        return top->data;
    }

    // Display all elements in the stack
    void Display() const {
        Node<T>* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        cout << "Destructor called" << endl;
        while (top != nullptr) {
            Pop();
        }
    }
};

int main() {
    Stack<int>* stack = new Stack<int>();
    //menu
    stack->Push(1);
    stack->Push(2);
    stack->Push(3);
    stack->Display(); // Output: 3 2 1

    system("pause");
    bool running = true;
    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1: {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            stack->Push(value);
            break; // Ensure the loop continues after this case
        }

        case 2: {
            stack->Pop();
            break;
        }

        case 3: {
            stack->Top();
            break;
        }

        case 4: {
            stack->Display();
            break;
        }

        case 5: {
            running = false;
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
        system("pause");
    } while (running);

    delete stack;
    return 0;
}
