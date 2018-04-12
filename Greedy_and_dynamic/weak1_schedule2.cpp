#include<bits/stdc++.h>
#define n 10000
using namespace std;

int main() {

	vector<float> weight;
	vector<float> length;
	//vector<int> score;
	ifstream infile;
	infile.open("jobs.txt", ios::in);
	string line;
    float w,l;
    //int n;
    //infile>>n;
	while (getline(infile, line)) {

		infile>>w>>l;
		//cout<<w<<" +++"<<l<<endl;
		weight.push_back(w);
		length.push_back(l);
	}
	infile.close();
	/*for(int i=0;i<n;i++) {
       score.push_back(weight[i]-length[i]);
       //score.push_back(weight[i]/length[i]);
	}
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(weight[j]<weight[j+1]) {
                swap(weight[j],weight[j+1]);
                swap(length[j],length[j+1]);
                swap(score[j],score[j+1]);
            }
        }
    }
*/
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(weight[j]/length[j]<weight[j+1]/length[j+1]) {
                //swap(score[j],score[j+1]);
                swap(weight[j],weight[j+1]);
                swap(length[j],length[j+1]);

            }
        }
    }
    long long int completion_time=length[0];
    long long  int ans=0;
    for(int i=0;i<n;i++) {
        cout<<weight[i]/length[i]<<" "<<completion_time<<" ";
        ans+=completion_time*weight[i];
        completion_time+=length[i+1];
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
     //67311454237
	return 0;
}







