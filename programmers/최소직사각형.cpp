//
//  최소직사각형.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0;
    int height = 0;
    for (int i = 0; i < sizes.size(); ++i) {
        width = max(width, max(sizes[i][0], sizes[i][1]));
        height = max(height, min(sizes[i][0], sizes[i][1]));
    }
    return width * height;
}
