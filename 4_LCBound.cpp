#include <bits/stdc++.h>
using namespace std;

int minCost = INT_MAX;
vector<int> bestPath;

void tsp(int currPos, vector<vector<int>> &dist, vector<bool> &visited, vector<int> &path, int n, int currCost) {
    if (path.size() == n) {
        if (dist[currPos][path[0]] > 0) {  // check if there is an edge to the starting point
            currCost += dist[currPos][path[0]];
            if (currCost < minCost) {
                minCost = currCost;
                bestPath = path;
            }
        }
        return;
    }

    for (int next = 0; next < n; next++) {
        if (!visited[next] && dist[currPos][next] > 0) {
            visited[next] = true;
            path.push_back(next);
            tsp(next, dist, visited, path, n, currCost + dist[currPos][next]);
            path.pop_back();
            visited[next] = false;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<bool> visited(n, false);
    vector<int> path;
    path.push_back(0);
    visited[0] = true;

    tsp(0, dist, visited, path, n, 0);

    cout << "Minimum cost is " << minCost << endl;
    cout << "Path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << bestPath[0] << endl;
    return 0;
}
