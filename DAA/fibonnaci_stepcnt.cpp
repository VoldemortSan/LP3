#include <iostream>
using namespace std;

int fibonacci_iter(int n, int& steps) {
    if (n < 0) {
        steps = 1;
        return -1;
    }
    if (n == 0 || n == 1) {
        steps = 1;
        return n;
    }
    steps = 1; 
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
        steps++;
    }
    return c;
}

int fibonacci_recur(int n, int& steps) {
    steps++; 
    if (n < 0) return -1; 
    if (n == 0 || n == 1) return n;

    int steps1 = 0, steps2 = 0;
    int fib1 = fibonacci_recur(n - 1, steps1);
    int fib2 = fibonacci_recur(n - 2, steps2);

    steps += steps1 + steps2;
    return fib1 + fib2;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Iterative approach
    int iter_steps = 0;
    int iter_fib = fibonacci_iter(n, iter_steps);
    cout << "Iterative Fibonacci: " << iter_fib << "\n";
    cout << "Steps (Iterative): " << iter_steps << "\n";

    // Recursive approach
    int recur_steps = 0;
    int recur_fib = fibonacci_recur(n, recur_steps);
    cout << "Recursive Fibonacci: " << recur_fib << "\n";
    cout << "Steps (Recursive): " << recur_steps << "\n";

    return 0;
}
// #include<iostream>
// using namespace std;

// void IterativeFibonacci(int n){

//     int a = 0, b = 1;
//     cout << "Fibonacci sequence up to the " << n << "th number:" << endl;
//     cout << a << " "; 
//     for (int i = 1; i <= n; ++i) {
//         cout << b << " ";
//         int next = a + b;
//         a = b;
//         b = next;
//     }
//     cout << endl;
// }

// int RecursiveFibonacci(int n) {
//     if (n <= 0) return 0;
//     if (n == 1) return 1;
    
//     return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
// }

// int main(){
//     int n=0, choice = 0;
//     cout<<"Enter the value of N: ";
//     cin>>n;

//     cout << "Choose method:\n";
//     cout << "1. Iterative (prints all numbers up to nth)\n";
//     cout << "2. Recursive (prints only the nth Fibonacci number)\n";
//     cout << "Enter your choice (1 or 2): ";
//     cin >> choice;

//     switch (choice) {
//         case 1:
//             IterativeFibonacci(n);
//             break;
//         case 2:
//             cout << "The " << n << "th Fibonacci number (recursive): " << RecursiveFibonacci(n) << endl;
//             break;
//         default:
//             cout << "Invalid choice. Please enter 1 or 2." << endl;
//     }
    
//     return 0;
// }
