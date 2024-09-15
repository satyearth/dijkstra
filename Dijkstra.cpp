#include <iostream>
#include <set>

using namespace std;

const int MAX_DISTANCE = 999;

void dijkstra(int graph[20][20], int source, int distance[], int n) 
{
    fill(distance, distance + n, MAX_DISTANCE);
    distance[source] = 0;

    set<pair<int, int>> s = {{0, source}};

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != MAX_DISTANCE && distance[u] + graph[u][v] < distance[v]) {
                s.erase({distance[v], v});
                distance[v] = distance[u] + graph[u][v];
                s.insert({distance[v], v});
            }
        }
    }
}
int main() {
    int n, graph[20][20], source, distance[20];
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the cost adjacency matrix for the graph [999 for no edge, 0 for self loops]: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(graph, source, distance, n);
    cout << "Shortest distances from city " << source << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "City " << i << ": " << (distance[i] == MAX_DISTANCE ? "Not reachable" : to_string(distance[i]) + " units") << "\n";
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <chrono> 

using namespace std;
using namespace std::chrono;

const int INF = numeric_limits<int>::max();
void dijkstra(vector<vector<int>>& graph, int source, vector<int>& distance) {
    int n = graph.size();
    distance.assign(n, INF);
    distance[source] = 0;

    set<pair<int, int>> s = {{0, source}};

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != INF && distance[u] + graph[u][v] < distance[v]) {
                s.erase({distance[v], v});
                distance[v] = distance[u] + graph[u][v];
                s.insert({distance[v], v});
            }
        }
    }
}
int main() {
    int n = 5;
    vector<vector<int>> graph = {{INF, 2, 4, INF, INF},
                                 {INF, INF, 1, 7, INF},
                                 {INF, INF, INF, INF, 3},
                                 {INF, INF, INF, INF, 1},
                                 {INF, INF, INF, INF, INF}};

    int source = 1;
    vector<int> distance;

    auto start = high_resolution_clock::now();
    dijkstra(graph, source, distance);
    auto end = high_resolution_clock::now();

    cout << "Shortest distances from city " << source << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "City " << i << ": " << (distance[i] == INF ? "Not reachable" : to_string(distance[i]) + " units") << "\n";

    duration<double> duration = end - start;
    cout << "Time Complexity: " << duration.count() << " seconds"<<endl;
    return 0;
}
*/
