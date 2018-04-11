#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int noe = 1000000;
int range_start = -10000;
int range_end = 10000;

int64 arr[noe];

int main()
{
    ifstream fin;
    fin.open("algo1-programming_prob-2sum.txt",ios::in);

    for (int i = 0; i < noe; i++) fin >> arr[i];

    sort(arr, arr + noe);

    int start = 0;
    int end = noe - 1;
    bool found[range_end - range_start + 1];
    for (int i = range_start; i <= range_end; i++)
    {
        found[i - range_start] = false;
    }
    while (start < end)
    {
        int64 req_sum = arr[start] + arr[end];
        if (req_sum < range_start) start++;

        else if (req_sum > range_end) end--;

        else
        {
            if (arr[start] != arr[end])
            {
                found[req_sum - range_start] = true;
            }
            int current_start = start;
            int current_end = end;
            while (true){
                start++;
                int64 req_sum = arr[start] + arr[end];
                if (req_sum < range_start || req_sum > range_end)
                break;
                else
                {
                    if (arr[start] != arr[end])
                    {
                        found[req_sum - range_start] = true;
                    }
                }
            }
            start = current_start;

            while (true){
                end--;
                int64 req_sum = arr[start] + arr[end];
                if (req_sum < range_start || req_sum > range_end)
                break;
                else
                {
                    if (arr[start] != arr[end])
                    {
                        found[req_sum - range_start] = true;
                    }
                }
            }
            end = current_end;
            start++;
            end--;
        }
    }

    int count = 0;
    for (int i = range_start; i <= range_end; i++){
        if (found[i - range_start])  count++;
    }
    cout << count << endl;   //427

    fin.close();
    return 0;
}
