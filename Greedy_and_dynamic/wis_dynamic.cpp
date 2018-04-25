#include<bits/stdc++.h>
using namespace std;

int main() {
long v;
ifstream infile;
infile.open("mwis.txt",ios::in);
infile>>v;
cout<<v<<endl;
long long dp[v+1],arr[v+1],index[v+1]={0}, ind[v+1] = {0};
for(long i=0;i<v;i++) infile>>arr[i];
for(long i=0;i<v;i++) cout<<arr[i]<<endl;

dp[0]=arr[0];
dp[1]=arr[1];
//index[0] = 1;
//index[1] = 1;
for(long i=2;i<v;i++) {
    dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
}
for(int i = v;i>0;){
    if(dp[i] > dp[i-1]){
        index[i] = 1;
        i-=2;
    }
    else i--;
}
if(index[1] == 0) index[0] = 1;
cout<<"ans="<<dp[v-1]<<endl;
//for(long i=0;i<v;i++) cout<<index[i]<<endl;

cout<<index[0]<<index[1]<<index[2]<<index[3]<<index[16]<<index[116]<<index[516]<<index[996]<<endl;

return 0;
}
