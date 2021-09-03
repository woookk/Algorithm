#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	while (getline(cin, str)) {
		int a = 0, b = 0, c = 0, d = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == ' ') d++;
			else if (str[j] >= 97) a++;
			else if (str[j] >= 65) b++;
			else c++;
		}	cout << a << " " << b << " " << c << " " << d << endl;
	}

	return 0;
}