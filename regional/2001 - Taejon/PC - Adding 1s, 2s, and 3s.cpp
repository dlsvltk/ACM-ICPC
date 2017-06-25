#include <iostream>
#include <math.h>
using namespace std;
#define MAX 11
int name(int n){   
	if (n == 1 || n == 2 || n == 3)		return pow(2, n - 1);   
	else      return name(n - 1) + name(n - 2) + name(n - 3);
}
int main(){   
	int number[MAX];   
	int n;   
	cin >> n;   
	for (int i = 0; i < n; i++) {      
		cin >> number[i];   
	}   
	for(int i = 0;i<n;i++)      
		cout << name(number[i]) << endl;   
	return 0;
}
