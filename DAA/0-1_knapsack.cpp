#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

vector<int> findSelectedItems(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {
    vector<int> selectedItems;
    int w = W;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i - 1);
            w -= wt[i - 1];              
        }
    }
    return selectedItems;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int* val = new int[n];
    int* wt = new int[n];

    cout << "Enter the weights and values of the items (weight value):\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> wt[i] >> val[i];
    }

    int W;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    int maxProfit = knapSack(W, wt, val, n, dp);
    cout << "Maximum value in the knapsack = " << maxProfit << endl;

    vector<int> selectedItems = findSelectedItems(W, wt, val, n, dp);
    cout << "Number of items selected = " << selectedItems.size() << endl;
    cout << "Selected items (0-indexed): ";
    for (int i : selectedItems) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// // Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and
// // bound strategy.
// // assignment no 4
// #include <bits/stdc++.h>
// using namespace std;

// int knapsack(int* values, int* weights, int n, int capacity) {
//     if (n == 0 || capacity == 0) return 0;
    
//     if (weights[n - 1] <= capacity) {
//         return max(
//             knapsack(values, weights, n - 1, capacity - weights[n - 1]) + values[n - 1],
//             knapsack(values, weights, n - 1, capacity)
//         );
//     } else {
//         return knapsack(values, weights, n - 1, capacity);
//     }
// }

// int main() {
//     int capacity;
//     cout << "Enter the maximum weight of the knapsack: ";
//     cin >> capacity;
    
//     int n;
//     cout << "Enter the number of items: ";
//     cin >> n;
    
//     int values[n], weights[n];
//     cout << "Enter weight and value of each item:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Item " << i + 1 << " - Weight: ";
//         cin >> weights[i];
//         cout << "Item " << i + 1 << " - Value: ";
//         cin >> values[i];
//     }

//     cout << "Maximum value in the knapsack = " << knapsack(values, weights, n, capacity) << endl;
//     return 0;
// }


// // Item arr[] = { { 10, 60 }, { 20, 100 }, { 30, 120 } };   
// //t=50
