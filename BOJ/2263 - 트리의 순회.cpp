//
//  2263 - 트리의 순회.cpp
//  cpp
//
//  Created by 민병욱 on 2024/02/27.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e5 + 1;

int n;

vector<int> postOrder(MAX), inOrder(MAX), indexOfInOrder(MAX);

void getPreOrder(int startOfInOrder, int endOfInOrder, int startOfPostOrder, int endOfPostOrder) {
    if (startOfInOrder > endOfInOrder || startOfPostOrder > endOfPostOrder) {
        return;
    }
    
    int root = indexOfInOrder[postOrder[endOfPostOrder]];
    int left = root - startOfInOrder;
    int right = endOfInOrder - root;
    cout << inOrder[root] << " ";
    
    getPreOrder(startOfInOrder, root - 1, startOfPostOrder, startOfPostOrder + left - 1);
    getPreOrder(root + 1, endOfInOrder, startOfPostOrder + left, endOfPostOrder - 1);
}

int main() {
    FASTIO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inOrder[i];
        indexOfInOrder[inOrder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> postOrder[i];
    }
    getPreOrder(1, n, 1, n);
    return 0;
}

/*
 n개의 정점을 갖는 이진 트리에 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성
 
 프리오더: root - left - right
 인오더: left - root - right
 포스트오더: left - right - root
 
 postOrder의 마지막 원소가 루트 노드이고, inOrder에서 root 노드의 인덱스를 통해서 left 트리와 right 트리를 알아내서 재귀적으로 풀이를 진행할 수 있다.
 시간복잡도 O(N)
 */
