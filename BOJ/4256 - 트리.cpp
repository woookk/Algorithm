//
//  4256 - 트리.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/27.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC;

void getPostOrder(vector<int>& preOrder, vector<int>& inOrder, vector<int>& indexOfInOrder, int startOfPreOrder, int endOfPreOrder, int startOfInOrder, int endOfInOrder) {
    if (startOfInOrder > endOfInOrder || startOfPreOrder > endOfPreOrder) return;
    
    int root = indexOfInOrder[preOrder[startOfPreOrder]];
    int left = root - startOfInOrder;
    getPostOrder(preOrder, inOrder, indexOfInOrder, startOfPreOrder + 1, startOfPreOrder + left, startOfInOrder, root - 1);
    getPostOrder(preOrder, inOrder, indexOfInOrder, startOfPreOrder + 1 + left, endOfPreOrder, root + 1, endOfInOrder);
    cout << preOrder[startOfPreOrder] << " ";
}

int main() {
    FASTIO
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<int> preOrder(n + 1), inOrder(n + 1);
        vector<int> indexOfInOrder(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> preOrder[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> inOrder[i];
            indexOfInOrder[inOrder[i]] = i;
        }
        getPostOrder(preOrder, inOrder, indexOfInOrder, 1, n, 1, n);
        cout << "\n";
    }
    return 0;
}

/*
 이진 트리를 전위, 중위 순회한 결과가 주어졌을 때, 후위 순회했을 때의 결과를 구하는 프로그램을 작성하시오.
 
 전위 순회: 루트 -> 왼쪽 -> 오른쪽
 중위 순회: 왼쪽 -> 루트 -> 오른쪽
 후위 순회: 왼쪽 -> 오른쪽 -> 루트
 */
