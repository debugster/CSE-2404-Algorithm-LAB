#include <bits/stdc++.h>

using namespace std;

#define MAX 1000
#define INF 1000000

struct PAIR
{
    int node;
    int cost;
};

struct compare
{
    bool operator()(const PAIR& x, const PAIR& y)
    {
        return x.cost > y.cost;
    }
};

int numberOfNodes;
int numberOfEdges;
int sourceNode;

vector<int>adjList[MAX];
int costMatrix[MAX][MAX];
int distMatrix[MAX];

void initialize(int totalNode);
void shortestPath(int source);

int main()
{
    freopen("Dijkstra-In.txt", "r", stdin);
    //freopen("Dijkstra-Out.txt", "w", stdout);

    int u, v, w, i;

    printf("Number of Nodes: ");
    scanf("%d", &numberOfNodes);
    printf("Number of Edges: ");
    scanf("%d", &numberOfEdges);

    initialize(numberOfNodes);

    printf("Enter start node<>end node<>cost:\n");
    for (i = 1; i <= numberOfEdges; i++) {
        scanf("%d%d%d", &u, &v, &w);

        adjList[u - 1].push_back(v - 1);
        costMatrix[u - 1][v - 1] = w;
    }

    printf("Source Node: ");
    scanf("%d", &sourceNode);

    shortestPath(sourceNode - 1);

    printf("\nDistance from %d to all nodes\n", sourceNode);
    for (i = 1; i <= numberOfNodes; i++) {
        printf("DISTANCE[%d] = ", i);
        if (distMatrix[i - 1] == INF) {
            printf("Unreachable.\n");
        }
        else {
            printf("%d\n", distMatrix[i - 1]);
        }
    }

    return 0;
}

void initialize(int totalNode)
{
    int i, j;

    for (i = 0; i < totalNode; i++) {
        distMatrix[i] = INF;
        adjList[i].clear();
        for (j = 0; j < totalNode; j++) {
            costMatrix[i][j] = INF;
        }
    }
}

void shortestPath(int source)
{
    priority_queue<PAIR, vector<PAIR>, compare>PQ;
    PAIR u, v;
    int i;

    u.cost = 0;
    u.node = source;

    PQ.push(u);
    costMatrix[source][source] = 0;
    distMatrix[source] = 0;

    while (!PQ.empty()) {
        u = PQ.top();
        PQ.pop();

        for (i = 0; i < adjList[u.node].size(); i++) {
            v.node = adjList[u.node][i];
            if (distMatrix[v.node] > distMatrix[u.node] + costMatrix[u.node][v.node]) {
                v.cost = distMatrix[v.node] = distMatrix[u.node] + costMatrix[u.node][v.node];
                PQ.push(v);
            }
        }
    }
}



