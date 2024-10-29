#include<iostream>
using namespace std;

void IterativeFibonacci(int n){

    int a = 0, b = 1;
    cout << "Fibonacci sequence up to the " << n << "th number:" << endl;
    cout << a << " "; 
    for (int i = 1; i <= n; ++i) {
        cout << b << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int RecursiveFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}

int main(){
    int n=0, choice = 0;
    cout<<"Enter the value of N: ";
    cin>>n;

    cout << "Choose method:\n";
    cout << "1. Iterative (prints all numbers up to nth)\n";
    cout << "2. Recursive (prints only the nth Fibonacci number)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            IterativeFibonacci(n);
            break;
        case 2:
            cout << "The " << n << "th Fibonacci number (recursive): " << RecursiveFibonacci(n) << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2." << endl;
    }
    
    return 0;
}