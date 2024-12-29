#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
	char data;
	unsigned freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, unsigned freq) : data(data), freq(freq), left(NULL), right(NULL) {}
};

struct compare
{
	bool operator()(MinHeapNode *l, MinHeapNode *r) { return l->freq > r->freq; }
};

void printCodes(MinHeapNode *root, string str, vector<string> &v)
{
	if (!root)
		return;
	if (root->data != '$')
		v.push_back(str);
	printCodes(root->left, str + "0", v);
	printCodes(root->right, str + "1", v);
}

vector<string> HuffmanCodes(char data[], int freq[], int size)
{
	vector<string> v;
	priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	while (minHeap.size() != 1)
	{
		MinHeapNode *left = minHeap.top();
		minHeap.pop();
		MinHeapNode *right = minHeap.top();
		minHeap.pop();
		MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left, top->right = right, minHeap.push(top);
	}
	printCodes(minHeap.top(), "", v);
	return v;
}

int main()
{
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	HuffmanCodes(arr, freq, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
