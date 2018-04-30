#include <bits/stdc++.h>
using namespace std;

vector <int> reverse_count(3000001);

vector <int> forward_count(3000001);

vector <long> fintime(3000001);


int finish_time =1;
bool satisfiable = true;

void GraphForward(long vars,long track, vector < vector<int> > &graph, long index){
	if (forward_count[track] != 0)
		return ;
	if (forward_count[track] == 0){

		forward_count[track] = index;

		if(track > vars){
			if(forward_count[track -vars] == index)
				satisfiable= false;
		}

		if(track <= vars){
			if(forward_count[track + vars] == index)
				satisfiable = false;
		}

		for (int y=0; y < graph[track].size(); y++)
			GraphForward(vars,graph[track][y], graph,index);

		forward_count[track] = index;

		return;
	}
}


void GraphRev(long r, vector < vector<int> > &graph_rev){
	if (reverse_count[r] == 1)
		return;

	if (reverse_count[r] != 1){
		reverse_count[r] = 1;

		for (int z=0; z < graph_rev[r].size(); z++)
	    	GraphRev(graph_rev[r][z] , graph_rev);


		fintime[finish_time] = r;

		finish_time++;

		return;
	}
}

void readclauses(long vars,vector < vector<int> > &graph,vector < vector<int> > &graph_rev){
	int var1,var2,firstedge,secondedge;
    //Read the clauses
	for(int i = 1;i <= vars;i++){
      infile>>var1>>var2;
        if(var1 < 0)
			var1 = vars + abs(var1);

		if(var2 < 0)
			var2 = vars + abs(var2);

		if(var1 > vars)
			firstedge = var1 -vars;
		else
			firstedge = vars + var1;


		if(var2 > vars)
			secondedge = var2 -vars;
		else
			secondedge = vars + var2;

		graph[firstedge].push_back(var2);

		graph[secondedge].push_back(var1);

		graph_rev[var2].push_back(firstedge);

		graph_rev[var1].push_back(secondedge);

	}
}

int main (){
	// Read the File

	FILE *fp = freopen("2sat1.txt","r",stdin);
	ifstream infile;
	infile.open("2sat1.txt",ios::in);
	// vars
	long vars;

	// Graph and Graph Rev
	vector < vector<int> > graph,graph_rev;  // holds the edges based on index of the original graph

	infile>>vars;

	// Initialize the vectors
	for(int i = 0; i <= 2 * vars; i++){
	  	vector <int> row;
	  	graph.push_back(row);
	  	graph_rev.push_back(row);
	}


	readclauses(vars,graph,graph_rev);

	// Rev
	for(long i = 1; i < graph_rev.size(); i++)
		GraphRev(i, graph_rev);


	// Forward
	for(long i = finish_time-1; i > 0; i--){
		long track = fintime[i];
		GraphForward(vars,track, graph,i);
	}

	if(satisfiable == false)
		cout << "Not satisfiable" << endl;
	else
		cout << "Satisfiable" << endl;

	infile.close();

	return 0;
}
