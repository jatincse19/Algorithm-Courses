#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,a[100008]={0},j=0,n=1;
	a[0] = INT_MAX;
	a[1] = INT_MAX;
	int median_sum=0;

	ifstream infile;
	infile.open("Median.txt",ios::in);
	string line;
	while(getline(infile,line)) {
	    int item=0,median;
	    infile>>item;
	    int i = n;
     while(item<a[i] && i>=1)
     {
           a[i+1] = a[i];
           i--;
     }
     a[++i] = item;
     if(n%2!=0)
     median = a[(n+1)/2];
     else
     median = a[n/2];
    cout<<median<<endl;
     n++;
     median_sum=(median+median_sum)%10000;
	}
	cout<<median_sum<<endl;   //1213
	infile.close();

	return 0;
}
