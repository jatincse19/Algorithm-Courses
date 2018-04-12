#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int v,e,w,u;
    cin>>v>>e;
    vector<vector< pair<long int,int> >> graph(v);
    vector<long int> d(v);
    vector<bool> seen(v);
    set< pair<long int,int> > queue;
    while(e--)
    {
        int u,v;
        cin>>u>>v>>w;
        graph[u-1].push_back({v-1,w});
        graph[v-1].push_back({u-1,w});

    }
    for(int i=0;i<v;i++)
    {
         d[i]=1000000;seen[i]=false;
    }
    d[0]=0;
    int mstw=0;
    queue.insert({0,0});       //Inserting initial vertex 0
    while(!queue.empty())
    {
        u = queue.begin()->second;
        mstw = mstw + queue.begin()->first;
        seen[u] = true;
        queue.erase(queue.begin());
        for(int i=0;i<graph[u].size();i++)
        {

            if( seen[graph[u].at(i).first] == false && d[graph[u].at(i).first]>graph[u].at(i).second)
            {
                queue.erase({d[graph[u].at(i).first],graph[u].at(i).first});            //ereasing vertex from set
                d[graph[u].at(i).first] = graph[u].at(i).second;                        //Updating the cost
                queue.insert({graph[u].at(i).second,graph[u].at(i).first});             //re inserting in set
            }
        }
    }
    cout<<mstw;
    return 0;
}
