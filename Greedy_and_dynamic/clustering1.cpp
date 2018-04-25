#include<bits/stdc++.h>
using namespace std;

// structure to store the information of link
typedef struct
{
    int node[2];
    int cost;
} edge;

int clustering(vector<edge>& edg, int nov) ;  // prototype

// sort the edges on the basis of cost
bool Sort_cost(edge e1, edge e2) {return (e1.cost < e2.cost);}


int main() {
int nov;
ifstream infile;
infile.open("clustering1.txt",ios::in);
infile>>nov;

vector<edge> edg;   // vector of edges
edge e;  // to store information corresponding to a node

for(int i=0;i<124750;i++) {
        infile >> e.node[0];
        infile >> e.node[1];
        e.node[0]--;
		e.node[1]--;
        infile >> e.cost;
        edg.push_back(e);

}
infile.close();

int ans=clustering(edg,nov);
cout<<ans<<endl;    // 106
return 0;
}


// Function to find the subset of an element i
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to do union of two subsets
void Union(int parent[], int x, int y)
{
    int X = find(parent, x);
    int Y = find(parent, y);
    if(X == Y) return;
    else parent[X] = Y;
}

int clustering(vector<edge>& edg, int nov)
{
    // sort the edges in increasing order of cost
    sort(edg.begin(), edg.end(), Sort_cost);

    // assign all node as parent of own initially
    int *parent = (int*) malloc( nov * sizeof(int) );
    memset(parent, -1, sizeof(int) * nov);

    //  start number_of_cluster with number_of_vertex
    int ans = 0,noc=nov,i=0;
	while(noc!=3 )   // means 4 cluster are already created
    {
        int root1 = find(parent, edg[i].node[0]);
        int root2 = find(parent, edg[i].node[1]);
        if (root1 != root2)
        {
            ans = edg[i].cost;
            //cout<<ans<<endl;
            noc--;    // decrease cluster count only when having different parent
        }

        Union(parent,root1, root2);
		i++;
    }

    return ans;
}
