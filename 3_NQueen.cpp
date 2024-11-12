#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to create the board configuration from current positions of queens
    void create(vector<vector<string>> &ans, int n, vector<int> curr) {
        vector<string> v;
        string s(n, '#');  // Create a row filled with '#'
        
        for (int i = 0; i < curr.size(); i++) {
            string m = s;   // Copy the blank row
            m[curr[i]] = 'Q';  // Place the Queen ('Q') at the correct position
            v.push_back(m);  // Add the row to the current board configuration
        }
        ans.push_back(v);  // Add this configuration to the result
    }

    // Function to check if placing a queen at (x, y) is valid
    bool isValid(int x, int y, vector<int> &vis) {
        for (int i = 0; i < vis.size(); i++) {
            // Check for vertical and diagonal conflicts
            if (vis[i] == y || (abs(x - i) == abs(y - vis[i]))) {
                return false;
            }
        }
        return true;
    }

    // Backtracking function to explore all possible placements
    void Back_T(vector<vector<string>> &ans, int x, int n, vector<int> &curr) {
        if (x == n) {
            // If all queens are placed successfully, create the board
            create(ans, n, curr);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isValid(x, i, curr)) {
                curr.push_back(i);  // Place the queen at (x, i)
                Back_T(ans, x + 1, n, curr);  // Recur for the next row
                curr.pop_back();  // Backtrack by removing the queen
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<int> curr;  // To store the current configuration of queens
        Back_T(answer, 0, n, curr);  // Start backtracking from the first row
        return answer;
    }
};

int main() {
    int input;
    cout << "Enter size of board: ";
    cin >> input;

    vector<vector<string>> res;
    Solution S1;
    res = S1.solveNQueens(input);

    int i = 1;
    for (auto it : res) {
        cout << i << " Configuration: " << endl << endl;
        for (auto row : it) {
            for (auto ch : row) {
                cout << ch << "     ";  // Print the board row
            }
            cout << endl;
        }
        cout << endl;
        i++;
    }
    return 0;
}
