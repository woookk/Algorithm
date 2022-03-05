//
//  14956 - Philosopher's Walk.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/05.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

pair<int, int> func(int side , int walk){
    if(side == 2){
        if(walk == 1)
            return {1, 1};
        else if(walk == 2)
            return {1, 2};
        else if(walk == 3)
            return {2, 2};
        else
            return {2, 1};
    }
    int half = side / 2, section = half * half;
    
    if(walk <= section){
        pair<int, int> rv = func(half, walk);
        return { rv.Y, rv.X};
    }
    else if(walk <= 2 * section){
        pair<int, int> rv = func(half, walk - section);
        return {rv.X, half + rv.Y};
    }
    else if(walk <= 3 * section){
        pair<int, int> rv = func(half, walk - 2 * section);
        return {half + rv.X, half + rv.Y};
    }
    else {
        pair<int, int> rv = func(half, walk - 3 * section);
        return {2 * half - rv.Y + 1, half - rv.X + 1};
    }
}

int main(){
    FASTIO;
    int n, m;
    cin >> n >> m;
    pair<int, int> ans = func(n, m);
    cout << ans.X << " " << ans.Y;
    return 0;
}
