#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Function to print the table of items
void printTable(vector<vector<float>> items, bool isResult) {
    const int cellWidth = 10;

    // Header row
    cout << setw(cellWidth) << left << "Profit" << " |";     
    cout << setw(cellWidth) << left << "Weight" << " |";     
    if (isResult)
        cout << setw(cellWidth) << left << "Fraction" << " |";     
    else
        cout << setw(cellWidth) << left << "P/W" << " |";  // Profit/Weight ratio
    cout << endl;

    // Line separators
    for (int i = 0; i < 3; ++i)         
        cout << "+----------+";
    cout << endl;

    // Print each item
    for (int i = 0; i < items.size(); i++) {
        cout << setfill(' ') << setw(cellWidth) << left << items[i][1] << " |";  // Profit
        cout << setw(cellWidth) << left << items[i][2] << " |";  // Weight
        cout << setw(cellWidth) << left << items[i][0] << " |";  // P/W or Fraction
        cout << endl;
    }
    cout << endl;
}

// Function to take input from user
void takeInput(vector<vector<float>> &items, int &n, float &maxWeight) {
    cout << "Enter number of items: ";
    cin >> n;

    // Input each item's profit and weight
    for (int i = 0; i < n; i++) {
        float profit, weight, pw; 
        cout << "Enter profit for item " << i + 1 << ": ";
        cin >> profit;
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> weight;
        pw = profit / weight;  // Calculate profit/weight ratio

        // Add item to vector
        vector<float> item = {pw, profit, weight};
        items.push_back(item);
    }

    // Input the maximum allowable weight
    cout << "Enter maximum weight allowed: ";
    cin >> maxWeight;
    cout << endl;
}

// Main function
int main() {
    vector<vector<float>> items;  // To store items (P/W ratio, profit, weight)
    int n;  // Number of items
    float maxWeight;  // Maximum weight allowed

    takeInput(items, n, maxWeight);  // Take user input

    // Display entered elements
    cout << "Entered Elements are: " << endl;
    printTable(items, false);

    // Sort items based on Profit/Weight ratio (first column)
    sort(items.begin(), items.end());

    // Result vector is initialized as a copy of items
    vector<vector<float>> result = items;
    float totalProfit = 0;

    // Iterate from the item with the highest P/W ratio
    for (int i = n - 1; i >= 0; i--) {
        if (items[i][2] <= maxWeight) {  // If item can be fully taken
            maxWeight -= items[i][2];  // Reduce the remaining weight
            totalProfit += items[i][1];  // Add full profit
            result[i][0] = 1;  // Fully taken
        } else {  // If only part of the item can be taken
            totalProfit += items[i][1] * (maxWeight / items[i][2]);  // Add partial profit
            result[i][0] = (maxWeight / items[i][2]);  // Fraction taken
            maxWeight = 0;  // No more weight can be taken
            break;
        }
    }

    // Display final result
    cout << "Final Result: " << endl;
    printTable(result, true);
    
    // Display total profit
    cout << "Final Profit: " << totalProfit << endl;

    return 0;
}
