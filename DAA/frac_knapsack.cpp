#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
    Item(int w, int v) : weight(w), value(v) {}
};

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    
    for (auto &item : items) {
        if (item.weight <= W) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / (double)item.weight);
            break; 
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<Item> items;
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    double maxProfit = fractionalKnapsack(W, items);
    cout << "Maximum value in the knapsack = " << maxProfit << endl;

    return 0;   
	// Item arr[] = { { 10, 60 }, { 20, 100 }, { 30, 120 } };    
}
