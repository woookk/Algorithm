//
//  11718 - 그대로 출력하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/11.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    FASTIO;
    string str;
    
    while(1){
        getline(cin, str);
        if(str == "")
            break;
        
        cout << str << "\n";
    }
    return 0;
}
