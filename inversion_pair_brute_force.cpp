#include <bits/stdc++.h>
using namespace std;
// function to calculate inversion pair
long long int getInvCount(int arr[], int n)
{
  long long int  inv_count = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i+1; j < n; j++)
      if (arr[i] > arr[j])
        inv_count++;

  return inv_count;
}

// main function
int main()
{
    int  arr[100000];
    for(int  i=0;i<100000;i++) cin>>arr[i];
    cout<<getInvCount(arr, 100000)<<endl;
    return 0;
}
