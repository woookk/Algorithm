//
//  5639 - 이진 검색 트리.cpp
//  cpp
//
//  Created by 민병욱 on 2024/01/09.
//

#include <iostream>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MAX_NUMBER_OF_NODES = 1e4 + 5;

vector<int> pre(MAX_NUMBER_OF_NODES);

void preToPost(int start, int end) {
    if (start >= end) return;
    int root = pre[start];
    int delim = start;
    for (int i = start; i < end; i++, delim++) {
        if (root < pre[i]) break;
    }
    preToPost(start + 1, delim);
    preToPost(delim, end);
    cout << root << "\n";
}

int main() {
    FASTIO
    int idx = 0;
    int value;
    while (cin >> value) {
        pre[idx++] = value;
    }
    preToPost(0, idx);
    return 0;
}

/*
 이진 검색 트리는 다음과 같은 세 조건을 만족하는 이진 트리
 - 노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
 - 노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
 - 왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.
 전위 순회 (루트-왼쪽-오른쪽)은 루트를 방문하고, 왼쪽 서브트리, 오른쪽 서브 트리를 순서대로 방문하면서 노드의 키를 출력한다. 후위 순회 (왼쪽-오른쪽-루트)는 왼쪽 서브트리, 오른쪽 서브트리, 루트 노드 순서대로 키를 출력
 이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램을 작성
 
 전위 순회라면 처음에 들어온 노드가 Root Node이고 이후에 Root Node의 값보다 값이 작은 Node들은 모두 Left Sub Tree, Root Node의 값보다 값이 큰 Node들은 Right Sub Tree이다.
 각각 Left, Right Sub Tree에 대해서 재귀를 활용해서 위와 같은 방식으로 접근하면 이진 검색 트리를 복구할 수 있다.
 이후 복구된 이진 검색 트리를 후위 순회로 출력
 
 위 방식에서 전위 순회에서 Left Sub Tree, Right Sub Tree를 각각 구할 수 있으므로 Left, Right Sub Tree를 먼저 출력하고 이후에 Root를 출력하는 방식으로 출력 순서를 조정하여 후위 순회 방식으로 출력
 
 Left Sub Tree와 Right Sub Tree를 나누는 구분자(delim) 찾는 과정에서 root보다 큰 값이 있을 경우 delim으로 지정하는 방식으로 하게되면 root보다 큰 값이 없게되면 반복해서 함수를 호출하는 오류가 발생해 메모리 초과 발생
 root보다 큰 값이 나오기 전까지 delim을 계속해서 증가시키는 방식으로 풀이 변경
 */
