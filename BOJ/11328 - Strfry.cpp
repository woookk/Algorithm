#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main() {
    FASTIO;

    int N;
    cin >> N;
    while (N--) {
        int a[26] = {}; // N�� �ݺ��ϹǷ� �ʱ�ȭ ���ִ� �� �߿�.
        string s1, s2;
        cin >> s1 >> s2;

        for (auto c : s1) a[c - 'a']++; 
        for (auto c : s2) a[c - 'a']--; 

        bool isPossible = true;
        for (int i : a) {
            if (i != 0) isPossible = false;
        }

        if (isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}