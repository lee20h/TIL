#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5;

bool check[MAX];
int before[MAX];
int hang[MAX];
vector<int> v[MAX];

void visit(int n) {
	if(check[n])
		return;
	if(!check[before[n]]) {
		hang[before[n]] = n;
		return;
	}
	check[n] = true;
	sol(hang[n]);
	for(int i : v[n])
		sol(i);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	for(auto &it: path) {
		v[it[0]].push_back(it[1]);
		v[it[1]].push_back(it[0]);
	}
	for(auto &it: order)
		before[it[1]] = it[0];
	if(before[0])
		return false;
		
	check[0] = true;
	for(int i: v[0])
		dfs(i);
	for(int i=0; i<n; i++) {
		if(!check[i])
			return false;
	}
	return true;
}
