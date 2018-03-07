#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE 1000
#define MAX_EDGE 2000
#define INF 1000000

struct EDGE
{
    int u;
    int v;
    int cost;
};

int numberOfNodes;
int numberOfEdges;
int sourceNode;

int dist[MAX_NODE + 1];
EDGE Graph[MAX_EDGE + 1];

bool BellmanFord(); /// returns false if negative cycle exists, true otherwise

int main()
{
    freopen("BF-In.txt", "r", stdin);
    //freopen("BF-Out.txt", "w", stdout);

    int i;

    printf("Number of Nodes: ");
    scanf("%d", &numberOfNodes);
    printf("Number of Edges: ");
    scanf("%d", &numberOfEdges);

    printf("Enter start node<>end node<>cost:\n");
    for (i = 1; i <= numberOfEdges; i++) {
        scanf("%d%d%d", &Graph[i].u, &Graph[i].v, &Graph[i].cost);
    }

    printf("Source Node: ");
    scanf("%d", &sourceNode);

    if (BellmanFord()) {
        printf("No negative cycle exists.\n");
    }
    else {
        printf("Negative cycle exists.\n");
    }

    return 0;
}

bool BellmanFord()
{
    int i, j, u, v, c;

    for (i = 1; i <= numberOfNodes; i++) {
        dist[i] = INF;
    }

    dist[sourceNode] = 0;

    for (i = 1; i < numberOfNodes; i++) {
        for (j = 1; j <= numberOfEdges; j++) {
            u = Graph[j].u;
            v = Graph[j].v;
            c = Graph[j].cost; /// cost for u to v
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
            }
        }
    }

    for (i = 1; i <= numberOfEdges; i++) {
        u = Graph[i].u;
        v = Graph[i].v;
        c = Graph[i].cost; /// cost for u to v
        if (dist[u] + c < dist[v]) {
            return false;
        }
    }

    return true;
}
