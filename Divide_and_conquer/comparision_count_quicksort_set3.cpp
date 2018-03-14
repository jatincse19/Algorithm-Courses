#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int ,int );
int quickSort(int arr[], int ,int );

long int count_comp;

// for sorting the partition and counting the number of comparison
int partition(int arr[],int left,int right) {
    int med = -1;
    int mid = (left + right)/2;
    int maxi = max(max(arr[left],arr[right]),arr[mid]);
    int mini = min(min(arr[left],arr[right]),arr[mid]);
    if(arr[left] != maxi && arr[left]!= mini) med = left;
    if(arr[right] != maxi && arr[right]!= mini) med = right;
    if(arr[mid] != maxi && arr[mid]!= mini) med = mid;
    if(med == -1) med = mid;
   // cout << arr[left] << " "<<arr[right] <<" "<<arr[mid] <<" "<< " "<<arr[med] << endl;
    int temp;
    temp = arr[left];
    arr[left] = arr[med];
    arr[med] = temp;

    int pivot=arr[left],p1=left+1,i;
        count_comp += right - left;
        for(i=left+1;i<=right;i++) {
            if(arr[i]<pivot) {
                if(i!=p1) {
                swap(arr[p1],arr[i]);
                }    p1++;
            }
        }

        arr[left]=arr[p1-1];
        arr[p1-1]=pivot;

    return p1-1;
}

// recursive calling for quick sort
int quickSort(int arr[], int left, int right) {

    if(left<right) {

        int pivot = partition(arr,left,right);
        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot+1,right);
    }
}

int main() {


    int  arr[100000];
    for(int  i=0;i<10000;i++) cin>>arr[i];

    quickSort(arr, 0,9999 );

    //to check if array is sorted
   for(int i = 0; i < 10000;i++) {
    cout<<arr[i]<<endl;
   }
    // 138382
    cout<<"number of comparison :"<<count_comp<<endl;
    return 0;
}
