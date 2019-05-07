#include <iostream>
#include <vector>

using namespace std;

class Node {
	public:
		Node *left;
		int value;
		Node *right;

		Node() {
			left = nullptr;
			right = nullptr;
		}

		Node(int value): Node() {
			this->value = value;
		}

};

void getPath(Node* tree, vector<int> &path, int value, bool &found) {
	
	if(tree == nullptr) {
		return;
	}

	if(found) {
		return;
	}

	path.push_back(tree->value);

	if(tree->value == value) {
		found = true;
		return;
	}

	getPath(tree->left, path, value, found);
	getPath(tree->right, path, value, found);
	if(!found)
		path.pop_back();
}

int getLCA(vector<int> pathToA, vector<int> pathToB) {
	int minSize = pathToA.size() <= pathToB.size() ? pathToA.size() : pathToB.size();

	if(minSize == 1) {
		return pathToA[0];
	}

	for(int i = 0; i < minSize; i++) {
		if(pathToA[i] ==  pathToB[i]) {
			continue;
		}
		else {
			return pathToA[i - 1];
		}
	}
	
	return pathToA[(minSize - 2)];

}

int lca(Node *root, int a, int b) {
	vector<int> pathToA;
	vector<int> pathToB;
	bool foundA = false;
	bool foundB = false;

	getPath(root, pathToA, a, foundA);
	getPath(root, pathToB, b, foundB);


	if(foundA and foundB) {
		return getLCA(pathToA, pathToB);
	}
	else {
		return 0;
	}

}

int main() {

	Node *root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right = new Node(3);
	root->right->left = new Node(6);
	root->right->right = new Node(7);



	cout << 4 << ", " << 5 << ": " << lca(root, 4, 5) << endl;
	cout << 1 << ", " << 5 << ": " << lca(root, 1, 5) << endl;
	cout << 4 << ", " << 7 << ": " << lca(root, 4, 7) << endl;
	cout << 3 << ", " << 6 << ": " << lca(root, 3, 6) << endl;
	cout << 6 << ", " << 7 << ": " << lca(root, 6, 7) << endl;
	cout << 2 << ", " << 4 << ": " << lca(root, 2, 4) << endl;


	return 0;
}

