#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

struct TrieNode {
	vector<TrieNode*> children;
	char value;
	TrieNode* failNode;
	int point;

	TrieNode() {
		point = -1;
		failNode = NULL;
		children.resize(26, NULL);
	}
}; // struct TrieNode

void insert(TrieNode* root, const string& s, int num) {
	TrieNode* p = root;
	for(size_t i = 0; i < s.size(); ++i) {
		char w = s[i];
		int idx = w - 'a';
		if (!p->children[idx]) {
			p->children[idx] = new TrieNode();
		}
		p = p->children[idx];
		if (i + 1 == s.size()) {
			p->point = num;

		}
	}
}

void buildFailNodeBFS(TrieNode* root) {
	queue<TrieNode*> q;
	q.push(root);
	while (!q.empty()) {
		TrieNode* cur = q.front(); q.pop();
		for (int i = 0; i < 26; ++i) {
			if (cur->children[i]) {
				if (cur == root) {
					cur->children[i]->failNode = root;
				} else {
					TrieNode* p = cur->failNode;
					while (p) {
						if (p->children[i]) {
							cur->children[i]->failNode = p->children[i];
							break;
						}
						p = p->failNode;
					}
					if (!p) {
						cur->children[i]->failNode = root;
					}
				}
				q.push(cur->children[i]);
			}
		}
	}
}

vector<pair<int, int>>
search(TrieNode* root, const std::string& word) {
	vector<pair<int, int>> ret;

	size_t len = word.size();
	TrieNode* p = root;
	for (int i = 0; i < len; ++i) {
		int index = word[i] - 'a';

		while (!p->children[index] && p != root) {
			p = p->failNode;
		}

		if (!p->children[index]) continue;
		p = p->children[index];
		TrieNode* t = p;
		while (t != root) {
			if (t->point != -1) {
				ret.push_back(make_pair(t->point, i));
			}
			t = t->failNode;
		}
	}
	return ret;
}


int main() {

	vector<string> patterns;

	TrieNode* root = new TrieNode();
	cout << "input words: ";
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		string s;
		cin >> s;
		patterns.push_back(s);
		insert(root, s, i);
	}

	buildFailNodeBFS(root);

	string s;
	cin >> s;
	vector<pair<int, int>> ans = search(root, s);
	for (int i = 0; i < ans.size(); ++i) {
		printf("found : %d %lu\n", ans[i].first, ans[i].second - patterns[ans[i].first].size() + 1);
		printf("%s\n", patterns[ans[i].first].c_str());
		printf("%d\n", ans[i].second);
	}
	return 0;
}
