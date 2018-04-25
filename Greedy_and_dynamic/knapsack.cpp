#include <bits/stdc++.h>
using namespace std;

int dp[10001][101];

int knapSack(int bud, int weight[], int value[], int n)
{
   int i, j;

   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= bud; j++)
       {
           if (i==0 || j==0)
               dp[i][j] = 0;
           else if (weight[i-1] <= j)
               dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]],  dp[i-1][j]);
           else
               dp[i][j] = dp[i-1][j];
       }
   }

   return dp[n][bud];
}

int main() {
    int bud,n;
    ifstream infile;
    infile.open("knapsack1.txt",ios::in);
    infile>>bud>>n;
    int value[n+1],weight[n+1];
    cout<<bud<<" "<<n<<endl;
    for(int j=0;j<n;j++) infile>>value[j]>>weight[j];
    for(int j=0;j<n;j++) cout<<value[j]<<" "<<weight[j]<<endl;
    infile.close();
    //cout<<"hello"<<endl;
    int ans = knapSack(bud,weight,value,n);
    cout<<ans<<endl;

	return 0;
}
