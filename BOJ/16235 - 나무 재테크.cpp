//
//  16235 - 나무 재테크.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/31.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

int N, M, K, ans;
int map[11][11];
int A[11][11];

deque<int> trees[11][11];

void input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = 5;
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }
}

int getNumberOfTrees() {
    int result = 0;
    while(K--) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int treeIdx;
                int numberOfTrees = (int) trees[i][j].size();
                for (treeIdx = 0; treeIdx < numberOfTrees; treeIdx++) {
                    if (map[i][j] < trees[i][j][treeIdx]) break;
                    map[i][j] -= trees[i][j][treeIdx]++;
                }
                for (int deadTreeIdx = numberOfTrees - 1; deadTreeIdx >= treeIdx; deadTreeIdx--) {
                    map[i][j] += (trees[i][j][deadTreeIdx] / 2);
                    trees[i][j].pop_back();
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (auto tree: trees[i][j]) {
                    if (tree % 5 != 0) continue;
                    for (int dir = 0; dir < 8; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        
                        if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
                        trees[nx][ny].push_front(1);
                    }
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j] += A[i][j];
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            result += trees[i][j].size();
        }
    }
    return result;
}

int main() {
    FASTIO
    input();
    ans = getNumberOfTrees();
    cout << ans << "\n";
    return 0;
}

/*
 나무 재테크란 작은 묘목을 구매해 어느정도 키운 후 팔아서 수익을 얻는 재테크이다. 상도는 나무 재테크로 더 큰 돈을 벌기 위해 M개의 나무를 구매해 땅에 심었다.
 1 * 1 크기의 칸에 여러 개의 나무가 심어져 있을 수도 있다.
 
 이 나무는 사계절을 보내며, 아래와 같은 과정을 반복
 
 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 각각의 나무는 나무가 있는 1 * 1 크기의 칸에 있는 양분만 먹을 수 있다.
 하나의 칸 여러개 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
 만약, 땅에 양분이 부족하다면 나무는 즉시 죽는다.
 
 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. (소수점 아래 버림)
 
 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수, 인접한 8개 칸에 나이가 1인 나무가 생긴다.
 
 겨울에는 땅에 양분을 추가. 각 칸에 추가되는 양분의 양은 A[r][c]
 
 K년이 지난 후 상도의 땅에 살아있는 나무의 개수를 구하는 프로그램을 작성하시오.
 
 */
