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
