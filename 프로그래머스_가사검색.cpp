#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

/*
	https://programmers.co.kr/learn/courses/30/lessons/60060
	2020 Kakao Blind Recruitment	
*/

struct Trie {
	bool isEnd;
	Trie *child[26];
	// map<남은 자리수, 총 개수>
	map<int, int> cnt;

	Trie() : isEnd(false) {
		memset(child, 0, sizeof(child));
	}

	~Trie() {
		for(int i=0;i<26;i++) {
			if(child[i]) delete child[i];
		}
	}

	void insert(string& str, int idx) {
		cnt[str.size()-idx]++;
		if(idx == str.size()) {
			isEnd = true;
		} else {
			int index = str[idx] - 'a';

			if(child[index] == 0) {
				child[index] = new Trie();
			}
			child[index]->insert(str, idx+1);
		}
	}

	int find(string& str, int idx) {
		if(str[idx] == '?') {
			return cnt[str.size()-idx];
		}

		if(idx == str.size() && isEnd) {
			return 1;
		} else if(idx == str.size()) {
			return 0;
		}

		int index = str[idx] - 'a';
		if(child[index] == 0) {
			return 0;
		}
		return child[index]->find(str, idx+1);
	}
};



vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> ans;

	Trie *root = new Trie;
	Trie *reverseRoot = new Trie;
	for(string word : words) {
		root->insert(word, 0);
		reverse(word.begin(), word.end());		
		reverseRoot->insert(word, 0);
	}

	for(string query : queries) {

		if(query[0] == '?' && query[query.size()-1] == '?') {
			ans.push_back(root -> find(query, 0));
		} else if(query[0] == '?') {
			reverse(query.begin(), query.end());		
			ans.push_back(reverseRoot->find(query, 0));
		} else {
			ans.push_back(root -> find(query, 0));
		}
	}

	return ans;
}