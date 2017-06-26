//count pair(a,b) for (a^2+b^2+m)/ab is an integer and 0<a<b<n given n,m
//just all search pair(a,b) satisfiy (a^2+b^2+m)/ab is an integer // O(n^2) <- n<=100
#include <iostream>
using namespace std;
int main(){   int n;   int a, b;   int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)   {
        cin >> a >> b;
        for (float x = 1; x < a; x++)    for (float y = x + 1; y < a; y++)    (float)((x*x + y*y + b) / (x*y)) == (int)((x*x + y*y + b) / (x*y)) ? cnt++ : 0;
        cout << cnt << endl;      cnt = 0;
    }
}
//BOJ 9094
