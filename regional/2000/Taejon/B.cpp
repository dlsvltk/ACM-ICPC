//sorting minimum swap counting
#include<bits/stdc++.h>
using namespace std;
int A[1001];
int main() {
	int t,n,c;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		c = 0;
		for (int i = 0; i < n; i++) {
			//swap i,j
			int t = i;

			for (int j = i+1; j < n; j++) {
				if (A[t] > A[j]) t = j;
			}
			if (A[i] != A[t]) {
				swap(A[i], A[t]);
				c++;
			}
		}

		cout << c << " ";
	}
	return 0;
}
