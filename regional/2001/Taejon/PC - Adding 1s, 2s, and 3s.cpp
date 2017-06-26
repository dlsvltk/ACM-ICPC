//number of n consits of 1,2, and 3 (add)
//base case 1,2,3 and step by step f(n) = f(n-1) + f(n-2) + f(n-3)
//becasue f(n) is n-1 + 1 or n-2 + 2 or n-3 + 3  
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
//BOJ 9095
