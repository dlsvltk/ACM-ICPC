	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<set>
	#include<queue>
	#include<iostream>
	using namespace std;

	const int N = 15;
	const int jump[15][6] = { { 0,0,0,0,2,3 },{ 0,1,0,3,4,5 },{ 1,0,2,0,5,6 },
	{ 0,2,0,5,7,8 },{ 2,3,4,6,8,9 },{ 3,0,5,0,9,10 },
	{ 0,4,0,8,11,12 },{ 4,5,7,9,12,13 },{ 5,6,8,10,13,14 },
	{ 6,0,9,0,14,15 },{ 0,7,0,12,0,0 },{ 7,8,11,13,0,0 },
	{ 8,9,12,14,0,0 },{ 9,10,13,15,0,0 },{ 10,0,14,0,0,0 }
		//(upleft, upright, left, right, downleft, downright)의 노드, 만약에 없다면 0
	};

	int n;
	struct point {
		int s;
		int num;
		int time;
		int path[2][15];
	};
	//전체 아이디어 = BFS + 비트연산을 이용해서 뛰어넘을수 있는 값 체크
	// 110 - > 001 이렇게....

	queue<point> tree;

	set<int> sugae;

	void bfs() {
		sugae.clear();
		while (!tree.empty())
			tree.pop();
		point tmp;
		tmp.s = ((1 << 16) - 1) ^ (1 << (n - 1));  // 비어있는 칸을 받아서 비트 연산
	
		tmp.time = 0;
		tmp.num = 14;
		tree.push(tmp);
		while (!tree.empty()) {
			point a = tree.front();
			tree.pop();

			for (int i = 0; i < 15; i++) {
				if (a.s & (1 << i)) {
					for (int j = 0; j < 6; j++) {
						int cur = i;
						point c = a;
						if (jump[i][j] != 0 && c.s & (1 << (jump[i][j] - 1))) {
							while (cur >= 0 && (c.s & (1 << cur))) {
								c.s ^= (1 << cur);
								c.num--;
								cur = jump[cur][j] - 1;
							}
							if (cur < 0)
								continue;
							c.s |= (1 << cur);
							c.path[0][c.time] = i + 1;
							c.path[1][c.time] = cur + 1;
							c.time++; // 총 시행 횟수 계산
							c.num++;
							
							if (!sugae.count(c.s)) {
								if (c.num == 1 && c.s & (1 << (n - 1))) {
									cout << c.time << endl << c.path[0][0] << " " << c.path[1][0];
									for (int k = 1; k < c.time; k++) {
										cout <<" " << c.path[0][k] << " " << c.path[1][k];	
									}
									cout << endl;
									return;
								}
								sugae.insert(c.s);
								tree.push(c);
							}
						}
					}
				}
			}
		}
		cout << "IMPOSSIBLE";
	}
	int main() {
		int t;
		cin >> t;
		while (t--) {
			cin >> n;
			bfs();
		}
	}
