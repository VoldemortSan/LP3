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




// #include <bits/stdc++.h>
// using namespace std;

// int knapSack(int W, int wt[], int val[], int n) {
//     // Base Case
//     if (n == 0 || W == 0)
//         return 0;

//     if (wt[n - 1] > W)
//         return knapSack(W, wt, val, n - 1);

//     return max(knapSack(W, wt, val, n - 1), 
//                val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1));
// }

// int main() {
//     int n;

//     cout << "Enter the number of items: ";
//     cin >> n;

//     int* profit = new int[n];
//     int* weight = new int[n];

//     cout << "Enter the weights and values of the items (weight value):\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Item " << i + 1 << ": ";
//         cin >> weight[i] >> profit[i];
//     }

//     int W;
//     cout << "Enter the maximum weight of the knapsack: ";
//     cin >> W;

//     int maxProfit = knapSack(W, weight, profit, n);
//     cout << "Maximum value in the knapsack = " << maxProfit << endl;
    
//     return 0;
// }
