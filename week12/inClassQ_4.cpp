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
    // Construct the graph by using the adjacency matrix
    graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();
    vector<int> averageTimes(numCities, 0);

    for (int source = 0; source < numCities; ++source) {
        vector<int> shortestTimes = dijkstra(source);

        int sum = 0;
        int count = 0;
        for (int i = 0; i < shortestTimes.size(); ++i) {
            if (i != source && shortestTimes[i] != INT_MAX) {
                sum += shortestTimes[i];
                count++;
            }
        }

        averageTimes[source] = sum / count;
    }

    // in order to find the city or cities with the smallest average time.
    int smallestAverage = INT_MAX;
    vector<int> smallestCities;

    for (int i = 0; i < averageTimes.size(); ++i) {
        if (averageTimes[i] < smallestAverage) {
            smallestAverage = averageTimes[i];
            smallestCities.clear();
            smallestCities.push_back(i);
        } else if (averageTimes[i] == smallestAverage) {
            smallestCities.push_back(i);
        }
    }

    // Result the average times and the cities with the smallest average time as the output
    cout << "Average times from each source city to other cities:\n";
    for (int i = 0; i < averageTimes.size(); ++i) {
        cout << "City " << i << ": " << averageTimes[i] << " units\n";
    }

    cout << "City/cities with the smallest average time: ";
    for (int i = 0; i < smallestCities.size(); ++i) {
        cout << smallestCities[i] << " ";
    }
    cout << endl;

    return 0;
}
