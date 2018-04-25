#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned weight;
    MinHeapNode *left, *right;

    // initializing a new node or call it as a constructor
    MinHeapNode(char data, unsigned weight){
        left = right = NULL;
        this->data = data;
        this->weight = weight;
    }
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {
  bool operator()(MinHeapNode* l, MinHeapNode* r){
      return (l->weight > r->weight);
      }
};


//19
int findMax(struct MinHeapNode* root){
    if(root->left == NULL && root->right == NULL)
    return 0;
    int left  = findMax(root->left);
    int right = findMax(root->right);
    if(left > right)
        return 1 + left;
    else
        return 1 + right;
}


//9
int findMin(struct MinHeapNode* root){
    if(root->left == NULL && root->right == NULL)
    return 0;
    int left  = findMax(root->left);
    int right = findMax(root->right);
    if(left < right)
        return 1 + left;
    else
        return 1 + right;
}

// for printing the desired output
void printCodes(struct MinHeapNode* root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int weight[], int size)
{
    // for storing the two minimum and a new internal node
    struct MinHeapNode *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], weight[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum
        // weight items from min heap
        left = minHeap.top();  minHeap.pop();
        right = minHeap.top(); minHeap.pop();

        // new internal node having data '$' and weight=left+right
        top = new MinHeapNode('$', left->weight + right->weight);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    // for printing the desired output
    printCodes(minHeap.top(), "");
    cout<<endl;
    cout<<"max :"<<findMax(minHeap.top())<<endl;
    cout<<"min :"<<findMin(minHeap.top())<<endl;
}

int main()
{
    int noe;
    ifstream infile;
    infile.open("huffman.txt",ios::in);
    infile>>noe;

    char arr[noe+1];      // dummy array to give a character a name
    memset(arr,'a',sizeof(arr));
    int weight[noe+1];    // to store the weight of the nodes
    for(int i=0;i<noe;i++) infile>>weight[i];
    HuffmanCodes(arr, weight, noe);

    return 0;
}


