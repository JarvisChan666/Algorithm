//求距离
//这道题写的是bfs，但是实际在添加节点到栈的时候是一个一个加进去的，而不是一层一层加进去的
/*
#include <bits/stdc++.h>

using namespace std;

int n, m, k, q[20001], dist[20001];

vector<int> edges[20001];

int main() {
	scanf("%d%d%d", &n, &m, &k);//此处并没有判断参数输入的合法性，比如x，y超过了n
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	//计算起点到终点的距离
	for (; k--; ) {
		int s, t;
		scanf("%d%d",&s, &t);
		memset(dist,255, sizeof(dist));//将一开始的距离都设置为-1,表示该点还没被查过
		dist[s] = 0;//起点到起点的位置当然是0
		int front = 1, rear = 1;
		q[1] = s;
		while (front <= rear) {
			int x = q[front];//x 先保存一下队头
			++front;//头出队
			for (auto y : edges[x])
				if (dist[y] == -1) {//
					dist[y] = dist[x] + 1;
					q[++rear] = y;//通过一个个入队，达到下一层入队
				}
		}
		printf("%d\n",dist[t]);
	}	
}
*/

//迷宫
/*
#include <bits/stdc++.h>

using namespace std;

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//2
//dist每个点到起点的距离，q为一个队列，总共1000*1000数据量，有x和y第二维
int n, m, q[1000001][2], dist[1001][1001];
//s用来记录图
//此处是1base图，ij表示第i行第j列，char数组内部会多留一维去记录结束符号，所以要到1002
char s[1001][1002];//思考为什么是1002？

int main() { 
	scanf("%d%d",&n, &m);
	for (int i = 1; i <= n; i++)
		//读图
		scanf("%s", s[i] + 1);
	int sx, sy, ex, ey;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			//start
			if (s[i][j] == 'S')
				sx = i, sy = j;
			else
			//end,此处可能还会有一种情况是X障碍，所以else后面还要连接if
				if (s[i][j] == 'E')
					ex = i, ey = j;
	memset(dist, 255, sizeof(dist));//一开始每个点离起点的位置为-1，我们可以把这些为-1的点当做是没有被处理过得点
	dist[sx][sy] = 0;//起点自己离自己的位置为0
	int front = 1, rear = 1;
	q[1][0] = sx; q[1][1] = sy;
	while (front <= rear) {
		int x = q[front][0], y = q[front][1];
		++front;
		for (int i = 0; i < 4; i++) {//枚举四个方向
			int xx = x + D[i][0], yy = y + D[i][1];
			if (xx < 1 || xx > n || yy < 1 || yy > m)//走出了图
				continue;
			if (s[xx][yy] != 'X' && dist[xx][yy] == -1) {//判断位置是否为障碍且没被访问过
				dist[xx][yy] = dist[x][y] + 1;
				q[++rear][0] = xx;
				q[rear][1] = yy;
			}
		}
	}
	printf("%d\n", dist[ex][ey]);
}
*/

//连通块计数
//连通块是一个“极大状态”的图，也称为极大联通子图，H是G的连通块,是G的一个子图，也可以是G，如果H再多加一块就可能等于G。H逼近了G。
//H不能加完一个点后还是子图，这就不叫极大了
//所有和他联通的点都去访问一下
//b[i] = false代表当前没有连通块把该点包含进去5

/*
	
*/

/*
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> edges[20001];
bool b[20001];

inline void dfs (int x) {
	b[x] = true;//记录该点的被访问情况
	for (auto y : edges[x])
		if (!b[y])
			dfs(y);
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	memset(b, 0, sizeof(b));
	int cnt = 0;//记录连通块数量
	for (int i = 1; i <= n; i++)
		if (!b[i]) {
			dfs(i);//如果i没被访问过，我们就去遍历所有和i号点连通的点，把所有i能够走到的点都走一遍，走完以后的那些点b为true
			//此时i的这个连通块我们算出了，
			//在遍历到b[i] == false时，说明前面的点的连通块没有把他包含进去，所以他可以新启一个炼铜块
			//每次看到一个b[i] == false 我去dfs一次，其实这个dfs就是在dfs一个连通块，所以我每次dfs后把答案+1
			++cnt;
		}
	printf("%d\n",cnt);
}
*/

//汉密尔顿回路
//一条贿赂有且仅有通过每隔顶点一次的路

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> edges[20001];
bool b[20001];
//在遍历的时候往下找的时候b会设置为true
//但是在最后找完后要回溯，重新设置为false
//汉密尔顿回路最后还要回到起点
////dfs(k,c)//找一条从k开始（然后回退到k的路径），k为当前点后面一个参数代表除了起点走过了多少点
//回到起点后c会等于n
//q:为什么一开始不把x先设置为true，因为一开始k进来了我不想设置为被访问过
//因为最后还要回到k，我想最后一次才true，如果一开始就是true我就进不来了，被访问过了

bool dfs(int x, int c) {
	if (c == n && x == k)//已经走了n步(保证走过每一个顶点)并且回到了起点(保证闭合回路)
		return true;
	for (auto y : edges[x])
		if (!b[y]) {
			b[y] = true;//记录访问情况
			if (dfs(y, c + 1))
			//一直往下看，如果期间找到了回路那就true
				return true;
			//回溯之前的点为false
			//因为函数会一直在if里进行往下递归，如果没找到回路的话然后往上将b设置为false；
			b[y] = false;
		}
	return false;//如果没找到，返回false
}		

int main() {//保证了一开始的k是false
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	scanf("%d", &k);
	if (dfs(k, 0))
		printf("Yes\n");
	else
		printf("No\n");
}
