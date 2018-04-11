#include<bits/stdc++.h>
#include<stdio.h>
#define V 200
using namespace std;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = 1000000, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// for printing the solution
int printSolution(int dist[], int n)
{
   printf("Vertex  Distance from Source\n");
   for (int i = 0; i < V; i++)
      cout<<i<<"--->"<<dist[i]<<endl;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
     int dist[V];
     bool sptSet[V];

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = 1000000, sptSet[i] = false;
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < V; v++)

         if (!sptSet[v] && graph[u][v] && dist[u] != 1000000
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     printSolution(dist, V);
}
int main() {
int graph[V][V];
memset(graph,0,sizeof(graph));
ifstream infile;
infile.open("dijkstraData.txt", ios::in);

string line;
vector<string> tokens;
while(getline(infile, line)) {     // '\n' is the default delimiter

    istringstream iss(line);
    string token;

    while(getline(iss, token, '\t')){ // but we can specify a different one
    tokens.push_back(token);
    }
    for(int i=1;i<tokens.size();i++){


        string dst = tokens[i].substr( 0, tokens[i].find(","));
        string wht = tokens[i].substr(tokens[i].find(",")+1, tokens[i].size());
        stringstream obj(dst);
        stringstream obj1(wht);
        stringstream obj2(tokens[0]);
        int destination=0,weight=0,source=0;
        obj>>destination;
        obj1>>weight;
        obj2>>source;
        //cout<<destination+weight+source<<endl;
        graph[source-1][destination-1]=weight;
    }

    tokens.clear();
    //for(int i=0;i<3;i++)
    //cout<<endl;

}
for(int i=0;i<=199;i++)
    for(int j=0;j<=199;j++)
        cout<<i<<","<<j<<"="<<graph[i][j]<<"   ";
            cout<<endl;
dijkstra(graph, 0);

return 0;
}
