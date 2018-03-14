#include <bits/stdc++.h>
using namespace std;
int  temp[100003]; // to store sorted sub array

int  merge( int arr[], int left,  int mid,  int right);


// for counting the inversion pair
 long long int  inversion_count(int arr[],int left,int right) {
 long long int  mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    inv_count += inversion_count(arr,  left, mid);  // for left sub array inversion
    inv_count += inversion_count(arr, mid+1, right); // for right sub array inversion
    inv_count += merge(arr,  left, mid+1, right);  // for split inversion
  }
  return inv_count;
}

//for merging two unsorted sub array
 int merge( int arr[],  int left,  int mid,  int right)
{
   int  i, j, k;
   long long int   inv_count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

      inv_count = inv_count + (mid - i);
    }
  }

  while (i <= mid - 1)
    temp[k++] = arr[i++];


  while (j <= right)
    temp[k++] = arr[j++];


  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}


// main function
 int  main()
{
    int  arr[100000];
    for(int  i=0;i<100000;i++) cin>>arr[i];
    cout<<inversion_count(arr,0, 99999)<<endl;
    return 0;
}
