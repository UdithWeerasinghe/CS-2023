#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> graph;

vector<int> dijkstra(int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    // Construct the graph by using the weighted adjacency matrix
    graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source;  // Specify the required source city
    cout << "Enter the source city: ";
    cin >> source;

    vector<int> shortestTimes = dijkstra(source);

    // Output the shortest times from the source city to every other cities
    cout << "Shortest times from city " << source << " to all other cities:\n";
    for (int i = 0; i < shortestTimes.size(); ++i) {
        if (i != source) {
            cout << "City " << source << " to City " << i << ": ";
            if (shortestTimes[i] == INT_MAX) {
                cout << "Not reachable\n";
            } else {
                cout << shortestTimes[i] << " units\n";
            }
        }
    }

    return 0;
}
