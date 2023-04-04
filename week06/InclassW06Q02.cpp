#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// defining the Node structure
struct Node {
    int data;
    Node* next;
};

// defining the Stack structure
struct Stack {
    Node* head;
    Node* top;
};

// function to check whether the Stack is empty
bool isEmpty(Stack* S) {
    return S->head == NULL;
}

// function to push a new element
void push(Stack* S, int n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    
    if(isEmpty(S)) {
        S->head = newNode;
        S->top = newNode;
    } else {
        S->top->next = newNode;
        S->top = newNode;
        cout << " The number " << n << " has been pushed into the stack." << endl;
    }
}

// function to pop the top element
int pop(Stack* S) {
    if(isEmpty(S)) {
        cerr << "Stack Underflow" << endl;
        exit(1);
    } else {
        int x = S->top->data;
        
        if(S->top == S->head) {
            S->top = NULL;
            S->head = NULL;
        } else {
            Node* tmp = S->head;
            while(tmp->next != S->top) {
                tmp = tmp->next;
            }
            tmp->next = NULL;
            S->top = tmp;
        }
        return x;
    }
}
void display(Stack* S) {
    Node* tmp = S->head;
    while(tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


// driver function to test the Stack implementation
int main() {
    Stack* myStack = new Stack;
    myStack->head = NULL;
    myStack->top = NULL;

    auto start = high_resolution_clock::now(); // start measuring execution time
    
    // Pushing few elements for testing
    cout << "Pushing elements into the stack..." << endl;
    push(myStack, 8);
    push(myStack, 10);
    push(myStack, 5);
    push(myStack, 11);
    push(myStack, 15);
    push(myStack, 23);
    push(myStack, 6);
    push(myStack, 18);
    push(myStack, 20);
    push(myStack, 17);
    push(myStack, 4);
    push(myStack, 30);
    push(myStack, 3);
    push(myStack, 1);

    cout << "Linked List after above pushes: ";
    display(myStack);


    // Popping and displaying elements from the stck S
    cout << "Popping elements out from the stack..." << endl;
    for( int i = 1; i< 6 ; i++){
        cout << pop(myStack) << endl;
    }

    auto stop = high_resolution_clock::now(); // stop measuring execution time
    auto duration = duration_cast<microseconds>(stop - start); // calculate execution time
    
    cout << "Linked List after pop operations: ";
    display(myStack);
    
    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    

    
    
    return 0;
}
