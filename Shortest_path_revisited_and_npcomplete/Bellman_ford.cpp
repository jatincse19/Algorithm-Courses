#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int src, dst, weight;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};

// bellman ford function
void bellmanford(Graph * graph, int src) {
    int min_distance=INT_MAX;
    int V,E;
    V=graph->V;
    E=graph->E;
    int dist[V];
    for(int i=0;i<=V-1;i++) dist[i]=INT_MAX;
    dist[src]=0;
    //min_distance=-19;

//will construct the all pair shortest distance
//looping V-1 means any pair have atmost V-1 edges
    for(int i=0;i<=V-1;i++) {
        for(int j=0;j<E;j++) {
            int src,dst,weight;
            src=graph->edge[j].src;
            dst=graph->edge[j].dst;
            weight=graph->edge[j].weight;
                if (dist[src] != INT_MAX && dist[src] + weight < dist[dst])
                dist[dst] = dist[src] + weight;
        }
        //min_distance=min(min_distance,dist[i]);
    }



    for (int i = 0; i < V; ++i){
        cout<<i<<"--->"<<dist[i]<<endl;
        min_distance=min(min_distance,dist[i]);
    }
//detect the negative edge cycle
    for(int j=0;j<E;j++){
        int src,dst,weight;
        src=graph->edge[j].src;
        dst=graph->edge[j].dst;
        weight=graph->edge[j].weight;
            if (dist[src] != INT_MAX && dist[src] + weight < dist[dst]){
            cout<<"Graph contains negative weight cycle"<<endl;
            }
            //else
            //cout<<"graph contain no negative cycle"<<endl;
    }
    cout<<min_distance<<endl;      //-19 FOR 3RD ONE
    return ;

}

int main() {

    int V,E,src,dst,weight;
    ifstream infile;
    //infile.open("g1.txt",ios::in);   // negative cycle
   // infile.open("g2.txt",ios::in);     // negative cycle
    infile.open("g3.txt",ios::in);   // length=-19
    infile>>V>>E;
    cout<<V<<"  "<<E<<endl;
     struct Graph* graph = new Graph ;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    for(int i=0;i<E;i++) {
        infile>>src>>dst>>weight;
        cout<<src<<" "<<dst<<" "<<weight<<endl;;
            graph->edge[i].src = src-1;
            graph->edge[i].dst = dst-1;
            graph->edge[i].weight = weight;
    }
    bellmanford(graph,0);
    return 0;

}
