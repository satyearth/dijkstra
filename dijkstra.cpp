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
