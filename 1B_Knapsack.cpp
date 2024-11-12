#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum of two integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapSack(int W, int w[], int v[], int n) {
    // Create a 2D array to store the maximum value for each weight and item
    int K[n + 1][W + 1];

    // Build table K[][] in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int wt = 0; wt <= W; wt++) {
            if (i == 0 || wt == 0)  // Base case: If no items or weight is 0
                K[i][wt] = 0;
            else if (w[i - 1] <= wt)  // If weight of the current item <= current capacity
                K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
            else  // If the current item's weight exceeds the current capacity
                K[i][wt] = K[i - 1][wt];
        }
    }

    // Return the maximum value that can be carried in the knapsack
    return K[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items in the Knapsack: ";
    cin >> n;

    int v[n], w[n];  // Arrays to store values and weights of items

    // Input value and weight for each item
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> v[i] >> w[i];
    }

    // Input the capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    // Calculate the maximum value that can be obtained
    cout << "Maximum value in Knapsack = " << knapSack(W, w, v, n) << endl;

    return 0;
}
