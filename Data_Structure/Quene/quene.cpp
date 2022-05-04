//1.队列结构的基本实现  push  ,pop, query k
/*
队列是一种数据结构。现在你要支持几种操作：

push x，将x这个元素放到队尾。

pop，表示将队头的元素删除。

query k，询问从队头往后数第k个元素是多少。

输入格式
第一行一个整数m，表示操作个数。

接下来m行，每行一个上面所述的操作。

输出格式
输出若干行，对于每个查询操作，输出答案。

数据规模
对于100%的数据，保证m≤10^5。

对于push操作，保证1≤x≤10^9。

对于pop操作，保证队列非空。

对于query操作，保证k≥1且k不超过队列里面的元素个数。

10
push 1
push 2
query 1
query 2
push 3
query 1
pop
query 1
push 4
query 1
*/
/*
#include <bits/stdc++.h>
using namespace std;
int m,q[100001],k,front = 1,rear = 0;
char str[1001];//???????????

int main(){
	scanf("%d",&m);
	for(int i = 1;i<=m;i++){
		scanf("%s",str);
		if(str[2]=='s'){//push
			int x;
			scanf("%d",&x);
			q[++rear] = x;
		}else{
			if(str[0]=='p'){//pop
				++front;
			}else{
				int k;
				scanf("%d",&k);
				printf("%d\n",q[front+k-1]);
			}
		}
	}
	return 0;
}
*/

/*2.
你有一个数字x，并且把x放到队列里，你要执行如下操作k次。

每次记队首的元素为y，首先把这个元素从队列中弹出，然后将2y和2y+1依次放到队列的末尾。

对于每次操作，输出队首的元素y。

输入格式
第一行两个整数x,k。

输出格式
共k行，每行一个元素，表示每次操作队首的元素。

样例输入1
10 5
样例输出1
10
20
21
40
41

数据规模
对于100%的数据，保证1≤x≤104,1≤k≤105。

#include <bits/stdc++.h>
using namespace std;
int x,k,q[200002],front = 1,rear = 0;
int main(){
	scanf("%d%d",&x,&k);
	if(!(x&&k))
		return -1;
	q[++rear] = x;
	for(int i = 1;i<=k;i++){
		int p;
		p = q[front];
		q[++rear] = 2*p;
		q[++rear] = 2*p+1;
		printf("%d\n",q[front]);
		++front;
	}

	return 0;
}
*/
/*3
给你一个长度为n的数组，数组里的每一个数字都大于等于它之前的那个数字。(dizeng)

现在要你统计对于每个位置的数字a[i]，在它之前的所有数字有几个大于等于 a[i]–5。

输入格式
第一行一个整数 n。

接下来一行是n个正整数。

输出格式
输出n个数，第i个数表示在a[1],a[2],...,a[i−1]中，有多少个数字大于等于 a[i]–5。

样例输入
10
1 2 3 3 6 8 8 9 9 10
样例输出
0 1 2 3 4 3 4 3 4 5
数据规模
对于所有数据，保证 n≤100000, 1≤a[i]≤1000000。

#include <bits/stdc++.h>
using namespace std;

int n,q[1000001],front = 1,rear = 0;
//队列重要的数组长度求法：rear-front +1
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		int x;
		scanf("%d",&x);
		//rear>=front保证队列正确
		for(;rear>=front && q[front] < x-5;++front);//这个循环利用front来记录位置，最后front左边数字是
		printf("%d ",rear-front+1);//末减初+1
		q[++rear] = x;
	}

	return 0;
}
？？？？？？？？？？？？？？？？？？？？？？？？？？
*/

/*
有n个人在排队买票，队伍的位置为1到n。

给你一个数组a[i]， 其中第i个人想要买a[i]张票。

每一秒，位于队列头的人一次可以买一张票。如果他这次买完了所有他需要的票，他就会离开；否则，它会来到队伍末尾继续排队。

现在给出所有人需要的票数，需要你求出每个人买完票的时间。（第一个人买完第一张票算作第一秒）。

输入格式
第一行一个整数n。

接下来一行一个长度为n的字符串s。

输出格式
输出n个数，第i个数表示第i个人买完票的时间。

样例输入
4
3 4 2 1

样例输出
8 10 7 4

数据规模
对于所有数据，保证n≤1000, 1≤a[i]≤1000。


#include <bits/stdc++.h>
using namespace std;
int n,a[1001],b[1001],q[1000001],front = 1,rear = 0;
//q保存时间，最坏情况一百万
int main(){
	scanf("%d",&n);
	if(n<=1)
		return -1;
	for(int i = 1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i = 1;i<=n;i++)
		q[++rear] = i;
	int cnt = n;
	for(int i = 1;cnt;i++){
		--a[q[front]];//减少一次时间
		if(!a[q[front]])
			b[q[front]] = i,--cnt;
		else
			q[++rear] = q[front];
		++front;
	}
	for(int i = 1;i<= n;i++)
		printf("%d ",b[i]);
	return 0;
}
?????????
*/
/*
有n个人排成一圈，从1到n标号。从第一个人开始报数，每次数到m的人出列，下一个继续从1开始数，依次类推，直到所有人都出列。

输出每次出列的人的编号。

输入格式
第一行，两个整数n,m。

输出格式
输出一行，包含n个数，表示每次出列的人的标号。

样例输入
10 3
样例输出
3 6 9 2 7 1 8 5 10 4
数据规模
对于100%的数据，保证1≤m≤n≤100。

#include <bits/stdc++.h>
using namespace std;
int n,m,q[10001],front = 1,rear = 0;
//大致思路：轮不到他就把他塞到后面
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		q[++rear] = i;
	}
	int c = 0;
	for(;front<=rear;){
		++c;//如果是0base就不用
		if(c==m){
			printf("%d ",q[front]);
			++front;
			c = 0;
		}else{
			q[++rear] = q[front];//把当前的排头塞到末尾，还轮不到他
			++front;//更新排头
		}
	}

}
*/

/*
队列是一种数据结构。现在你要支持几种操作：

push x，将x这个元素放到队尾。

pop，表示将队头的元素删除。

query k，询问从队头往后数第k个元素是多少。

输入格式
第一行一个整数m，表示操作个数。

接下来m行，每行一个上面所述的操作。

输出格式
输出若干行，对于每个查询操作，输出答案。

样例输入
10
push 1
push 2
query 1
query 2
push 3
query 1
pop
query 1
push 4
query 1
样例输出
1
2
1
2
2
数据规模
对于100%的数据，保证m≤106。

对于push操作，保证1≤x≤106。

对于pop操作，保证队列非空。

对于query操作，保证k≥1且k不超过队列里面的元素个数。

保证所有时刻，队列长度len≤1000。
*/
#include <bits/stdc++.h>
using namespace std;
const int size=1000;
int m,q[1000001],front = 1,rear=size;
char str[1001];//??开多大

int main(){
	scanf("%d",&m);
	for(int i = 1;i<=m;i++){
		scanf("%s",str);
		if(str[2]=='e'){
			int x;
			scanf("%d",&x);
			if(front + x -1<=size)
				printf("%d\n",q[front+x-1]);//正向，rear behind front
			else
				printf("%d\n",q[front+x-1-size]);
		}else{
			if(str[1]=='u'){
				int x;
				scanf("%d",&x);
				rear = rear%size+1;
				q[rear] = x;
			}else{
				front = front % size +1;
			}
		}
	}
	return 0;
}