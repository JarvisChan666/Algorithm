/*
图论必会内容：
1. G = <V,E>,点集v，边集E
2. 有向图和无向图
3. 度数
4. 完全图（任意一个点）都与其他点有相连 和 竞赛图
5. 补图
6. 同构  从图上理解就是一种伸缩变换
7. 道路，贿赂，路径和距离
8. 连通  
*/

//简单图判断,不能自连，重边
/*
#include <bits/stdc++.h>

using namespace std;

int n, m, a[1001][1001];

int main() {
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));//如果是全局变量其实可以不用memset？？
	for (int i = 1; i <= m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (x == y || a[x][y]) {
			printf("No\n");
			return 0;
		}
		a[x][y] = a[y][x] = 1;
	}
	printf("Yes\n");
}
*/
//顶点度数统计
/*
#include <bits/stdc++.h>

using namespace std;

int n, m, d[1001];

int main() {
	scanf("%d%d",&n,&m);
	memset(d,0,sizeof(d));
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		++d[x], ++d[y];
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n",d[i]);
	printf("\n");
}
*/
//度数合法性
//结论：度数之和为偶存在，奇不存在

//偶数部分自己和自己连消掉，最后剩下每个点的度数不是1就是0
//那么1会有偶数个，两两匹配就行
/*
#include <bits/stdc++.h>

using namespace std;

int n, m = 0;

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		m += x;
	}
	if (m & 1)
		printf("No\n");																																																									
	else
		printf("Yes\n");
}
*/

//竞赛图数量
//来自n阶无向完全图，每条边定义一个方向，就变成了n阶竞赛图
//那么每条边都有两种可以选择的方向，一共有a = n（n-1）/2条边（Cn2），那么本题答案2^a

//输出技巧，比如输出2的四次方，那就是1左移4位
//LL ,会有2的55次方，所以要longlong，由于右边写ll麻烦，我们左边写
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
	scanf("%d",&n);
	printf("lld\n",1LL << (n * (n - 1) / 2));
}
*/





//判断图是否同构，
//映射关系判断
//c[i]表示第一幅图的第i个点是第二幅图的第j个点
//r[i]点是否被映射过																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																						
//!!!!!!!!!!!
//{本题本质就是两幅图的点之间的排列组合}

//本题
#include <bits/stdc++.h>

using namespace std;

int n, m, ans, a[9][9], b[9][9], c[9];
bool r[9];
//同构是不是原先相连的同构映射后相同位置上还是连着的

/*它的同构方案是这样的
本题需要画图理解，假设有图Y型和——型，四个点三条边，这两个图是非同构的
*/
//dfs决定第一张图的x映射到第二张图的哪个点
//return true表示后面已经存在同构了，就不用继续下去，如果是false就要继续
bool dfs(int x) {
	if (x == n + 1) {//如果前n个点已经决定了，那么就要判断方案是否满足条件
		bool ok = true;//一开始的映射都是合理的
		//for一下第一幅图的任意两个点对，也就是所有点对枚举一下，ok表示目前为止看起来还正常
		for (int i = 1; i <= n && ok; i++)
			for (int j = i + 1; j <= n &&ok; j++)
				if (a[i][j] != b[c[i]][c[j]])//第一幅图的ij之间有边，第二幅图的c[i]c[j]之间没边，或者反过来
					ok = false;
		if (ok)//如果前面每组点对都是true，表示真的同构了，return true
			return true;
		else
			return false;
	}
	//枚举一下第一张图的x号点会映射到第二张图的哪个点
	for (int i = 1; i <= n; i++) 
		if (!r[i]) {
			c[x] = i;
			r[i] = true;

			if(dfs(x + 1))//下一个点去做映射，直到最后一个点，然后进行上面的for循环，看该方案是否有效
				return true;
			r[i]  = false;//当前方案已经看完了，这个点又可以用了
		}
	return false;
}

int main() {
	scanf("%d%d",&n, &m);
	//把第一个图和第二个图读完后放到邻阶矩阵
	for (int i = 1; i<= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		//画个图可以知道，矩阵中这个点被标记为1
		a[x][y] = a[y][x] = 1;//无向图建立
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		b[x][y] = b[y][x] = 1;
	}

	if (dfs(1))//如果最后dfs1 return true我找到了方案，yes
		printf("Yes\n");
	else
		printf("No\n");
}


