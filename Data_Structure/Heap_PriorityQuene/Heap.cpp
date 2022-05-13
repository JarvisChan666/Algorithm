/*1.基础堆

#include <bits/stdc++.h>
using namespace std;
int len,heap[100001];
//往上调整
inline void up(int k) {
	while (k > 1 && heap[k] < heap[k / 2]) {
		swap(heap[k],heap[k / 2]);
		k /= 2;
	}
}

inline void down(int k) {
	//至少该节点左孩子还在，要不然就下不了
	while (k + k <= len) {
		int j = k + k;
		//看看和左孩子换还是右孩子换，首先右节点要存在才能考虑这一步
		if (j + 1 <= len && heap[j + 1] < heap[j])
			j++;//那就换右节点
		//
		if (heap[k] <= heap[j])//换到已经小于左节点了或右节点了
			break;
		swap(heap[k],heap[j]);
		k = j;
	}
}
int n;
int main(){
	scanf("%d",&n);
	len = 0;
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d",&x);
		heap[++len] = x;
		up(len);
	}
	for(int i = 1; i <= n; i++){
		printf("%d ",heap[1]);
		swap(heap[1],heap[len]);
		--len;//头出堆
		down(1);//换上来的数换回去
	}
}
*/
/*STL
#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		q.push(x);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ",q.top());
		q.pop();
	}
}
*/
/*合并序列
#include <bits/stdc++.h>
using namespace std;

struct Info {//要处理两个值，一个是值，一个是队列的下一个元素比前一个元素大几
	int v,delta;
} heap[20001];//heap里面存着结构体
int n,m,len;

inline void up(int k) {
	while (k > 1 && heap[k].v < heap[k / 2].v) {
		swap(heap[k],heap[k / 2]);
		k /= 2;
	}
}
inline void down(int k) {
	while(k + k <= len) {
		int j = k + k;
		if (j + 1 <= len && heap[j].v > heap[j + 1].v)
			j++;
		if (heap[k].v <= heap[j].v)
			break;
		swap(heap[k],heap[j]);
		k = j;
	}
}

int main() {
	scanf("%d",&n);
	len = 0;
	for (int i = 1; i<= n; i++){
		int k, b;
		scanf("%d%d",&k,&b);
		heap[++len].v = b;
		heap[len].delta = k;
		up(len);
	}
	scanf("%d",&m);
	for (int i = 1; i <= m; i++){
		printf("%d ",heap[1].v);
		heap[1].v += heap[1].delta;
		down(1);
	}
}
*/
/*大富翁
*/
#include <bits/stdc++.h>
using namespace std;
//因为要求出某个人的最大值和最小值，因此要维护一个大根堆和小根堆
//s记录堆
//s[i]表示第i个人在这个堆里，他的下标为几的点
//比如我要改第p个人，首先要看s[p]，他在堆里哪一个位置，把他资金改了x以后，要向上向下调整
//s1[pos]表示名为pos的人对应了小根堆里下标为s1[i]的点，也就是说小根堆里下标为s1[i]的点记录了第i个人的信息
//其实游戏中一开始就是在数组中s举行，只不过为了求出最大最小值，我们需要用堆求出。因此要建立两者的联系
//联系就是我在s中，能够查到
//在堆中第k个点的名字pos能在s数组中找到在堆中的位置为k
struct Info {
	int v, pos;//pos是你这个人是哪个人，表示当前堆里面下标，某一个下标，某一个节点他上面是原来编号为几点睡人
} heap1[100001],heap2[100001];
int n,m,len1,len2,s1[100001],s2[100001];
//这里的k是堆中的位置
inline void up1(int k) {
	while (k > 1 && heap1[k].v < heap1[k / 2].v) {
		swap(heap1[k],heap1[k / 2]);
		s1[heap1[k].pos] = k;//记录名字为pos的堆点在堆中的位置k于数组中
		s1[heap1[k / 2].pos] = k / 2;
		k /= 2;
	}
}

inline void down1(int k) {
	while (k + k <= len1) {
		int j = k + k;
		if (j + 1 <= len1 && heap1[j].v > heap1[j + 1].v)
			j++;
		if (heap1[k].v <= heap1[j].v)
			break;
		swap(heap1[k],heap1[j]);
		//s数组始终都在记录着成员的位置
		s1[heap1[k].pos] = k;//k是堆中的位置
		s1[heap1[j].pos] = j;
		k = j;
	}
}

inline void up2(int k) {
	while (k > 1 && heap2[k].v > heap2[k / 2].v) {
		swap(heap2[k],heap2[k / 2]);
		s2[heap2[k].pos] = k;//s2记住名字为pos的人在堆中哪个位置k
		s2[heap2[k / 2].pos] = k / 2;
		k /= 2; 
	}
}

inline void down2(int k) {
	while (k + k <= len2) {
		int j = k + k;
		if (j + 1 <= len2 && heap2[j].v < heap2[j + 1].v)
			j++;
		if (heap2[k].v >= heap2[j].v)
			break;
		swap(heap2[k],heap2[j]);
		s2[heap2[k].pos] = k;
		s2[heap2[j].pos] = j;
		k = j;//更新k
	}
}


int main() {
	scanf("%d",&n);
	len1 = len2 = 0;
	//小根堆和大根堆的维护
	//之所以要用s数组，是方便我们跟踪每个人的位置，假设这个人是第i个人，s[i]就是他在堆里的位置
	//一开始大家都是100
	for (int i = 1; i <= n; i++) {
		heap1[++len1].v = 100;//每人初始100元钱
		heap1[len1].pos = i;//pos其实就能理解成名字，不要理解成position
		s1[i] = len1;//名字为i的人在堆中的位置
		up1(len1);
		heap2[++len2].v = 100;
		heap2[len2].pos = i;
		s2[i] = len2;
		up2(len2);
	}
	//
	scanf("%d",&m);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d",&x);//读取1操作还是2操作，1操作就是资金变动，2操作查询最大资金者
		if (1 == x) {
			int y, z;//读取队伍中第y个人，资金变动z
			scanf("%d%d",&y,&z);
			heap1[s1[y]].v += z;//
			up1(s1[y]);//在up，down函数内部也会调该人在s中位置
			down1(s1[y]);
			heap2[s2[y]].v += z;//
			up2(s2[y]);
			down2(s2[y]);
		}else {
			printf("%d %d\n",heap2[1].v,heap1[1].v);
		}
	}
}

/*动态中位数
//前i+1/2 放在大根堆，后半数放在小根堆

#include <bits/stdc++.h>
using namespace std;
//a是前一半，b是后一半
priority_queue<int> a,b;//b这里定义成一个大根堆，但其实是要小根堆，所以要加负号，
//负的一个大根堆就是正的一个小根堆
int n;

int main() {
	scanf("%d",&n);
	int x;
	scanf("%d",&x);
	a.push(x);
	printf("%d ",a.top());
	for (int i = 1; i <= n/2; i++) {
		int x, y, z = a.top();//z是之前的中位数
		scanf("%d%d",&x,&y);//两个两个读进去
		if (x < z)//比之前中位数小
			a.push(x);
		else
			b.push(-x);//比中位数大
		if (y < z)
			a.push(y);
		else
			b.push(-y);
		if (a.size() - b.size() == 3) {
			b.push(-a.top());
			a.pop();
		}else
		if (b.size() - a.size() == 1) {
			a.push(-b.top());
			b.pop();
		}
		printf("%d ",a.top());
	}
}
*/