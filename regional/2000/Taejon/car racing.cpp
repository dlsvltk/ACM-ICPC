#include<iostream>
#include<queue>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		queue<int> bypass;

		int num;
		cin >> num;


		int counter = 1;

		for (int i = 0; i < num; i++) {
			int input;
			cin >> input;
			if (counter == input) {
				counter++;
				while (!bypass.empty() && bypass.front() == counter) {
					bypass.pop();
					counter++;
				}
				continue;
			}
			else {
				while (!bypass.empty() && bypass.front() == counter) {
					bypass.pop();
					counter++;
				}
				if (counter == input) {
					counter++;
					continue;
				}
				else {
					bypass.push(input);
				}
			}
		}

		if (counter == (num + 1)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}