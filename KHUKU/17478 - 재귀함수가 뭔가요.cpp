#include<iostream>
#include<string>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, cnt=0;
void recursive(int num) {
	string ul = "";
	for (int i = 0; i < cnt; i++) ul += "____";
	cout << ul << "\"재귀함수가 뭔가요?\"\n";
	if (num == 0) {
		cout << ul <<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		cout << ul << "라고 답변하였지.\n";
		return;
	}
	else {
		cout << ul << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		cout << ul << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		cout << ul << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		cnt++;
		}
	recursive(num - 1);
	cout << ul << "라고 답변하였지.\n";
}
int main() {
	FASTIO;
	cin >> N;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	recursive(N);
	return 0;
}