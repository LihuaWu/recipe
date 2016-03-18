#include <stdio.h>

#include <queue>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int v) : value(v), left(NULL), right(NULL) {}
};

Node* buildTree(int nodeNumber) {
	int i = 0;
	Node* root = new Node(i++);
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* cur  = q.front(); q.pop();
		if (i > nodeNumber) break;
		Node* left = new Node(i++);
		Node* right = new Node(i++);
		cur->left = left;
		cur->right = right;
		q.push(left);
		q.push(right);
	}
	return root;
}

void traverse(Node* root) {
	queue<Node*> q;
	q.push(root);
	printf("traversing a tree: ");
	while (!q.empty()) {
		Node* cur = q.front(); q.pop();
		printf("%d ", cur->value);
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
	printf("\n");
}

bool search(Node* root, int& m, int& value) {
	bool flag = false;
	if (!root) return flag;

	if (root->right) {
		flag = search(root->right, m, value);
		if (flag) return flag;
	}
	if (m > 0) m--;
	if (m == 0)  {
		value = root->value;
		return true;
	}
	if (root->left) {
		return search(root->left, m, value);
	}
}

int main() {
	Node* root = buildTree(10);
	traverse(root);

	for (int i = 1; i < 13; ++i) {
		int idx = i;
		int value = -1;
		bool flag = search(root, idx, value);
		printf("found : %s with value: %d\n", flag ? "YES" : "NO", value);
	}
	return 0;
}
