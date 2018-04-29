///Run the code on two input files
/// for more clarification plot the points on the graph
/// final ans will be equal to ans(first file) + ans(second file) - common
/// common length is equal to 2*distance between node 11 and 12 (start with 0)
/// complexity of this code is O(n*2^n)
/// work fine for 14 to 15 cities
/// 26442 is final answer
#include<bits/stdc++.h>
using namespace std;


/// n=14 for tsp2.txt and n=13 for tsp1.txt
/// visited all will take care of cities which are visited or not
int n=13,VISITED_ALL = (1<<n) -1;
double dist[25][25],dp[1000000][20];   /// for storing the input and output

/* dynamic version of tsp*/
double  tsp(int mask,int pos){

	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
	   return dp[mask][pos];
	}

    double ans = INT_MAX;

	///Visit all the unvisited cities and take the best route
	for(int city=0;city<n;city++){

        /// will check if current city is not visited
		if((mask&(1<<city))==0){

			double newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = min(ans, newAns);  /// store the result
		}

	}

	return dp[mask][pos] = ans;
}

int main(){
    /// initialize dp with -1
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    /// to store the co-ordinates
    double corx[25],cory[25];
    int n;  /// for storing the number of cities
    ifstream infile;
    /// comment and uncomment to run on two different files
    infile.open("tsp1.txt",ios::in);   ///14662
 ///infile.open("tsp2.txt",ios::in);   ///14409.2
    infile>>n;
    for(int i=0;i<n;i++){
        infile>>corx[i]>>cory[i];
    }
    /// creating cost matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           float a = corx[i]-corx[j];
           float b = cory[i]-cory[j];
           float ans = pow(a,2)+pow(b,2);
           dist[i][j]=sqrt(ans);
            }
    }
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cout<<dist[i][j]<<"   ";
            }
            cout<<endl;
    }
    */
    cout<<"Travelling Saleman Distance is "<<tsp(1,0);  ///14662 +  14409.2 - 1314.24*2
     /// 26442 is the final answer
return 0;
}
