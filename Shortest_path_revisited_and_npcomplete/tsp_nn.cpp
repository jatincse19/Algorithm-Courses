#include<bits/stdc++.h>
using namespace std;
/// for storing the distance given source and remaining cities
double dist[33709];
/// TO check weather the current city is visited or not
int visited[33708];
/// for storing the co-ordinates
double corx[33709],cory[33709];
/// for base condition
int i=0;
/// store the index of recently visited city
int index;


/// function to check whether
double tsp(int source, int n) {
    /// base case
    if (i++==n-1) return 0;

    ///mark city 1 as visited
    visited[source]=1;
    double ans = INT_MAX;

    /// stored the distance of current city from all cities
    for(int i=0;i<n;i++)
    dist[i]=distance(i,source);

    /// check for unvisited minimum distance
    for(int i=0;i<n;i++) {
       if(dist[i]<ans && !visited[i]){
         ans = dist[i];
         index=i;
       }
    }

    /// mark selected city visited
    visited[index]=1;

    /// similar as we done in dfs
    return sqrt(ans) + tsp(index,n);

}


/// for calculating distance between two points without square root
double distance(int src,int dst) {
           double a = corx[src]-corx[dst];
           double b = cory[src]-cory[dst];
           double ans = pow(a,2)+pow(b,2);
           return ans;
}

int main(){
    int n,j;  /// for storing the number of cities
    ifstream infile;
    /// opening input file
    infile.open("try.txt",ios::in);
    infile>>n;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        infile>>j>>corx[i]>>cory[i];
        cout<<corx[i]<<" "<<cory[i]<<endl;
    }

    ///132604
    /// distance between source and destination added explicitly
    cout<<"Travelling Saleman Distance is "<<tsp(0,n)+sqrt(distance(index,0))<<endl;
return 0;
}
