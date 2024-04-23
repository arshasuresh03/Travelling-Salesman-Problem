#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // Infinity value for distances

// Function to calculate the total distance of a path
int calculateTotalDistance(const vector<vector<int>>& graph, const vector<int>& path) {
    int n = graph.size();
    int totalDistance = 0;
    for (int i = 0; i < n - 1; ++i) {
        totalDistance += graph[path[i]][path[i + 1]];
    }
    totalDistance += graph[path[n - 1]][path[0]]; // Return to the starting city
    return totalDistance;
}

// Function to find the shortest path using brute force
vector<int> findShortestPath(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        path[i] = i;
    }

    int minDistance = INF;
    vector<int> shortestPath;

    do {
        int currentDistance = calculateTotalDistance(graph, path);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            shortestPath = path;
        }
    } while (next_permutation(path.begin() + 1, path.end())); // Generate permutations

    return shortestPath;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<int> shortestPath = findShortestPath(graph);

    cout << "Shortest Path: ";
    for (int city : shortestPath) {
        cout << city << " ";
    }
    cout << shortestPath[0] << endl; // Return to the starting city

    cout << "Total Distance: " << calculateTotalDistance(graph, shortestPath) << endl;

    return 0;
}
