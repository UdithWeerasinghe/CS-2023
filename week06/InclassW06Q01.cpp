#include <iostream>
#include <chrono>
#define MAX_SIZE 100 // define the stack's maximum size

using namespace std;

struct Stack {
    int top;
    int arr[MAX_SIZE];
};

// Element x is pushed into the stack S
void push(Stack &S, int x) {
    S.top++;
    if (S.top >= MAX_SIZE) {
        cout << "Error: Stack overflow" << endl;
        S.top--;
    } else {
        S.arr[S.top] = x;
        cout << " The number " << x << " has been pushed into the stack." << endl;
    }
}

// Pop and return an element from the stack S
int pop(Stack &S) {
    if (S.top < 0) {
        cout << "Error: Stack underflow" << endl;
        return -1; // Or any other value to indicate an error
    } else {
        int x = S.arr[S.top];
        S.top--;
        cout << " The number " << x << " has been popped into the stack." << endl;
        return x;
    }
}

int main() {
    // Initialization
    Stack S;
    S.top = -1;

    auto start = chrono::high_resolution_clock::now();

    // Pushing few elements for testing
    cout << "Pushing elements into the stack..." << endl;
    push(S, 8);
    push(S, 10);
    push(S, 5);
    push(S, 11);
    push(S, 15);
    push(S, 23);
    push(S, 6);
    push(S, 18);
    push(S, 20);
    push(S, 17);
    push(S, 4);
    push(S, 30);
    push(S, 3);
    push(S, 1);

    // Displaying elements from the stack S
    cout << "Elements in the stack: ";
    for(int i = 0; i <= S.top; i++) {
        cout << S.arr[i] << " ";
    }
    cout << endl;
    
    

    // Popping and displaying elements from the stck S
    cout << "Popping elements out from the stack..." << endl;
    cout << pop(S) << endl; 
    cout << pop(S) << endl; 
    cout << pop(S) << endl; 
    cout << pop(S) << endl;
    cout << pop(S) << endl;

    auto end = chrono::high_resolution_clock::now(); // get current time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // calculate duration in microseconds
    
    
    // Displaying elements from the stack S after popping
    cout << "Elements in the array: ";
    for(int i = 0; i <= S.top; i++) {
        cout << S.arr[i] << " ";
    }
    cout << endl;

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}
