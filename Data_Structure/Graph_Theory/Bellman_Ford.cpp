#include <bits/stdc++.h>

using anmesspace std;

struct Edge {//x:point, y:edge , v:边权(u to v的长度) 
	int x, y, v;
} edges[10001];

int n, m, k, dist[5001], pre[5001];

inline void shortestpath(int s, int t) {
	memset(dist, 127, sizeof(dist));//127 为 2139062143，看做是INF
	memset(pre, 0, sizeof(pre));
	dist[s] = 0;//start to start is zero
	for (; ; ) {
		bool ok = false;//is it been relaxed?
		for (int i = 1; i <= m;  i++) {
			int x = edges[i].x, y = edges[i].y, v = edges[i].v;

			if (dist[x] < 1 << 30)//if dist exist(the defalut is inf,so we need 1 << 30 to select)
				if (dist[x] + v < dist[y]) {//x walk dist v is to v,we want to see if it can relax dist[y];
					dist[y] = dist[x] + v;//(s to y) relax to (s to x + v) 
			}
		}		


	}
}