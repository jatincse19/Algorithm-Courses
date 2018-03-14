#include<bits/stdc++.h>
using namespace std;

/* Load from text file */
void store_file(vector<vector<int> >& adj_list, string filename) {
	ifstream infile;
	infile.open(filename, ios::in);
	string line;

	while (getline(infile, line)) {
        cout<<line<<endl;
		vector<int> temp_list;
		istringstream istr(line);
		int temp;
		cout<<temp<<endl;
		while (istr >> temp)
			temp_list.push_back(temp);
		adj_list.push_back(temp_list);
	}
	infile.close();

}

/* print the adjacency list */
void print_adj_list(vector<vector<int> >& adj_list) {
	for(int i = 0; i < adj_list.size(); ++i) {
		for (int j = 0; j < adj_list[i].size(); ++j)
			cout << adj_list[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}



/* random pick edge u-v */
void pick_random_edge(vector<vector<int>>& adj_list, int& start_edge_index, int& end_edge_index) {

	start_edge_index = rand() % adj_list.size();
	int temp_v = (rand() % (adj_list[start_edge_index].size() - 1)) + 1;
	for (int i = 0; i < adj_list.size(); ++i)
		if (adj_list[i][0] == adj_list[start_edge_index][temp_v]) {
			end_edge_index = i;
			break;
		}
}

/* merge the u and v, keep u, delete v */
void fuse_vertex(vector<vector<int>>& adj_list, int& start_edge_index, int& end_edge_index) {
	for (int i = 0; i < adj_list.size(); ++i) {
		if (i != end_edge_index) {
			for (int j = 1; j < adj_list[i].size(); ++j) {
				if (adj_list[i][j] == adj_list[end_edge_index][0])
					adj_list[i][j] = adj_list[start_edge_index][0];
			}
		}
	}
	for (int i = 1; i < adj_list[end_edge_index].size(); ++i)
		adj_list[start_edge_index].push_back(adj_list[end_edge_index][i]);
}

/* remove self-loop */
void remove_self_loop(vector<vector<int>>& adj_list, int& start_edge_index, int& end_edge_index) {
	for (int i = 1; i < adj_list[start_edge_index].size(); ++i)
		if (adj_list[start_edge_index][i] == adj_list[start_edge_index][0]) {
			adj_list[start_edge_index].erase(adj_list[start_edge_index].begin() + i);
			--i;
		}
	adj_list.erase(adj_list.begin() + end_edge_index);
}




/* karger kerger_contraction */
int kerger_contraction(vector<vector<int>>& adj_list) {
	while (adj_list.size() > 2) {
		int start_edge_index = 0;
		int end_edge_index = 0;
		pick_random_edge(adj_list ,start_edge_index, end_edge_index);
		fuse_vertex(adj_list, start_edge_index, end_edge_index);
		remove_self_loop(adj_list, start_edge_index, end_edge_index);
	}
	return adj_list[0].size() - 1;
}


int main() {

	vector<vector<int> > adj_list;
	/* store the elements in txt file into adjacency list */
	 store_file(adj_list, "kargerMinCut.txt");

	vector<vector<int>> temp = adj_list;
    print_adj_list(adj_list);


	/* karger kerger_contraction */
	int min_cut = INT_MAX;
	// running loop 5000 times because it will get succeed in at least vertex-1 times
	for (int i = 0; i < 5000; ++i) {
		adj_list = temp;

		int inter_val = kerger_contraction(adj_list);

		min_cut = min(inter_val, min_cut);

	}
	 //17
	 cout << "min-cut for karger kerger_contraction is equals :" << min_cut << endl;

	return 0;
}







