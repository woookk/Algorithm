#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {

	string s;
	cin >> s;
	int A[26] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		A[(int)s[i] - 97]++; // A[s[i] - 'a']로 표현 가능.
	}
	for (int e : A){
		cout << e << " ";
	}
	return 0;
}

/* 
for (char a = 'a'; a <= 'z'; a++) {
	int cnt = 0;
	for(auto c : s)
		if(a == c) cnt++;
		cout << cnt << ' '
	이런 풀이도 가능.
*/
