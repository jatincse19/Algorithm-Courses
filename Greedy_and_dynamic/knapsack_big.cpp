#include <bits/stdc++.h>
#include <climits>
using namespace std;

//unordered_map<string,long> dp;
int dp[3][2000001];
int knapSack(int bud, int wt[], int val[], int n)
{
    for(int i=0;i<=bud;i++) dp[0][i]=0;

    for (int i = 0; i <= n; i++){
       for (int j = 0; j <= bud; j++){
           if (wt[i-1] <= j)
                 dp[1][j] = max(val[i-1] + dp[0][j-wt[i-1]],  dp[0][j]);
           else
                 dp[1][j] = dp[0][j];
       }
       for(int i=0;i<=bud;i++) dp[0][i]=dp[1][i];
   }
   return dp[1][bud];
}

int main() {
    int bud,n;
    ifstream infile;
    //infile.open("knapsack1.txt",ios::in);     //2493893
    infile.open("knapsack_big.txt",ios::in);  //4243395
    infile>>bud>>n;
    int value[n+1],weight[n+1];
    //cout<<bud<<" "<<n<<endl;
//    dp = new map<long,long>();
    for(int j=0;j<n;j++) infile>>value[j]>>weight[j];
    for(int j=0;j<n;j++) cout<<value[j]<<" "<<weight[j]<<endl;
    infile.close();
    int ans = knapSack(bud,weight,value,n);
    cout<<ans<<endl;

	return 0;
}
