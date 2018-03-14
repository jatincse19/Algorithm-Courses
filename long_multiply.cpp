#include<bits/stdc++.h>
using namespace std;

string mul(string arr1, string arr2)
{

    int index1,index2,n1,n2;
    n1 = arr1.size();
    n2 = arr2.size();
    vector<int> arr3(n1 + n2, 0);

    for (int i=n1-1; i>=0; i--)
    {
        int c = 0;
        int n1 = arr1[i] - '0';

        index2 = 0;
        for (int j=n2-1; j>=0; j--)
        {
            int n2 = arr2[j] - '0';

            int sum = n1*n2 + arr3[index1 + index2] + c;

            c = sum/10;

            arr3[index1 + index2] = sum % 10;

            index2++;
        }

        if (c > 0)
            arr3[index1 + index2] += c;

        index1++;
    }

    int i = arr3.size() - 1;
    while (i>=0 && arr3[i] == 0)
       i--;

    string s = "";
    while (i >= 0)
        s +=to_string(arr3[i--]);

    return s;
}
int main()
{
    string str1 = "3141592653589793238462643383279502884197169399375105820974944592";
    string str2 = "2718281828459045235360287471352662497757247093699959574966967627";
    cout << mul(str1, str2);
    return 0;
}
