#include <bits/stdc++.h>
using namespace std;
/*1.
栈是一种数据结构。现在你要支持几种操作：

push x，将x这个元素放到栈顶。

pop，将栈顶元素删除。

top，询问栈顶元素是多少。

输入格式
第一行一个整数m，表示操作个数。

接下来m行，每行一个上面所述的操作。

输出格式
输出若干行，对于每个查询操作，输出答案。
数据规模
对于100%的数据，保证m≤10^5。

对于push操作，保证1≤x≤10^9。

对于pop和top操作，保证栈非空。
*/
#if 0
int m,top,s[100001];
char str[11];//to store 操作类型
int main(){
	top = 0;
	scanf("%d",&m);
	if(!m)
		return -1;
	for(int i = 1;i<=m;i++){
		scanf("%s",str);
		if(str[1]=='u'){//压栈
			int n;
			scanf("%d",&n);
			s[++top]=n;
		}else{//弹出栈
			if (str[0]=='p')
				--top;
			else//查看顶部
				printf("%d\n",s[top]);
		}
	}
}
#endif

/*2 push pop query top
上题新增query k
query k，询问从栈顶往下数第k个元素是多少。

int top,m,s[100001];//m是操作的步数
char str[11];

int main(){
	top = 0;
	scanf("%d",&m);
	if(!m)
		return -1;
	for(int i = 1;i<=m;i++){
		scanf("%s",str);
		if(str[2]=='e'){//query
			int k;
			scanf("%d",&k);
			printf("%d\n",s[top+1-k]);
		}else if(str[0]=='p'){
			int n;
			if(str[1]=='u'){//push
				scanf("%d",&n);
				s[++top]=n;
			}else{//pop,注意pop无
				--top;
			}
		}else//top
			printf("%d\n",s[top]);
	}
}
*/

/*3.
现在有一个栈，有n个元素，分别为1,2,…,n。我们可以通过push和pop操作，将这n个元素依次放入栈中，然后从栈中弹出，依次把栈里面的元素写下来得到的序列就是出栈序列。

比如n=3，如果执行push 1, push 2, pop, push 3, pop, pop，那么我们pop操作得到的元素依次是2,3,1。也就是出栈序列就是2,3,1。

现在给定一个合法的出栈序列，请输出一个合法的由push和pop操作构成的出栈序列。这里要求push操作一定是按1,2,…,n的顺序。

输入格式
第一行一个整数n，接下来一行n个整数，表示出栈序列。

输出格式
输出2n行，每行一个push x或pop的操作，可以发现一个出现序列对应的操作序列是唯一的。

数据规模
对于100%的数据，保证1≤n≤100000，出栈序列一定是个合法的出栈序列。

样例输入
5
1 3 5 4 2  数组目标数
*/
/*
思路：输入5为目标数，本题：push1，pop1，push 2，push 3，pop 3，push4，push 5，pop5，pop4，pop2；
也就是说，到了数组目标数，pop出来，没到，继续push，到了总目标数，全pop


#include <bits/stdc++.h>
using namespace std;

int top,s1[100001],n;
int l = 0;
int main(){
	top = 0;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){//总循环
		int x;
		scanf("%d",&x);//数组目标数
		if(s1[top]!=x){//i不是数组目标数时，一直push进去，这步也可以过空数组
			for(int j = l+1;j<=x;j++){//这步进行push操作，没到数组目标数就一直push
				s1[++top]=j;//
				printf("push %d\n",j);
			}
			//l会一直沉默着，直到x=n，也就是连续输入的数字串中某个数到了n，l变大，结束上面循环
			l=x;//一旦有了这步，就是数组目标数到了总目标数，随后就是--top
		}
		//来到了这步，就不再进行push了，依次弹出剩余数字
		printf("pop\n");
		--top;//这步就是数组目标数x到了总目标数n了
	}
}
*/

/*4
给定一个长度为 n 的字符串 s，字符串由 (, ), [, ]组成，问 s 是不是一个合法的括号序列。

合法的括号序列的定义是：

空串是一个合法的括号序列。

若 A 是一个合法的括号序列，则 (A), [A] 也是合法的括号序列。

若 A, B 都是合法的括号序列，则 AB 也是合法的括号序列。

输入格式
第一行一个整数 n。

接下来一行一个长度为 n 的字符串 s 。

输出格式
如果 s 是合法的括号序列，输出 Yes，否则输出 No。


#include <bits/stdc++.h>
using namespace std;
int top,n,s[100001];
char str[100001];
int main(){
	//思路：没遇到匹配度就一直压栈，遇到匹配的就弹出，然后匹配的右边的那个就不用压进去了
	//遍历字符串
	top = 0;
	bool ok = true;
	scanf("%d%s",&n,str);
	for(int i = 0;i<n && ok;i++){//这里因为传进来的默认0开头，因此不用1base
		if(str[i]=='[' || str[i] == '('){//左半部分疯狂压入
			s[++top] = str[i];
		}else{//右半边就开始判断
			if(!top)
				ok = false;//仍然有剩余
			else
				if(str[i]==']'){
					if(s[top] == '[')
						--top;
					else
						ok = false;//剩下的不用看了必错
				}else{
					if(s[top] == '(')
						--top;
					else
						ok = false;
				}
			}
		}
	if(top)//还有剩的
		ok = false;
	if(ok)
		printf("Yes\n");
	else
		printf("No\n");
}
*/

/*5.
给定一个长度为n的字符串s，字符串由小写字母a..z组成。

小明来对这个字符串进行操作，他会从头到尾检查这个字符串，如果发现有两个相同的字母并排在一起，就会把这两个字符都删掉。小明会重复这个操作，直到没有相邻的相同字母。

你需要给出处理完成的字符串。

输入格式
第一行一个整数n。

接下来一行一个长度为n的字符串s。

输出格式
输出最后处理完成的字符串，有可能是空串。

9
acccabddb

aca
*/
/*
#include <bits/stdc++.h>
using namespace std;

int n;
char s[100001];//接受
char str[100001];//被压
int top = 0;
int main(){
	scanf("%d%s",&n,s);
	if((sizeof(s)/8)<=1)
		return -1;
	for(int i = 0;i<n;i++){
		if(str[top]==s[i]){
			--top;
		}else{
			str[++top]=s[i];
		}
	}
	for(int j = 1;j<=top;j++)
		printf("%c",str[j]);
	return 0;
}
*/

/*6
给定一个长度为n的字符串s，字符串由小写字母a..z和大写字母A..Z组成。

小明来对这个字符串进行操作，他会从头到尾检查这个字符串，如果发现：

s[i]是小写字母，s[i+1]是s[i]对应的大写字母(1≤i<n);

s[i]是大写字母，s[i+1]是s[i]对应的小写字母(1≤i<n);

就会把s[i], s[i+1]这两个字符都删掉。

小明会重复这个操作，直到字符串不再改变。

你需要给出处理完成的字符串。

输入格式
第一行一个整数n。

接下来一行一个长度为n的字符串s。

输出格式
输出最后处理完成的字符串，有可能是空串。

样例输入1
5
aAcCa
样例输出1
a


#include <bits/stdc++.h>
using namespace std;
int n;
char s[100001];
char str[100001];

int main(){
	scanf("%d%s",&n,s);
	if(n<=1){
		if(n==0)
			return -1;
		else
			printf("%c",s[0]);
	}
	int top = 0;
	for(int i = 0;i<n;i++){
		if(str[top]-32==s[i]||str[top]+32==s[i]){
			--top;
		}else{//1base str
			str[++top]=s[i];
		}
	}
	for(int j = 1;j<=top;j++){
		printf("%c",str[j]);
	}
	return 0;
}
*/

/*7
现在有一个栈，有n个元素，分别为1,2,…,n。我们可以通过push和pop操作，将这n个元素依次放入栈中，然后从栈中弹出，依次把栈里面的元素写下来得到的序列就是出栈序列。

比如n=3，如果执行push 1, push 2, pop, push 3, pop, pop，那么我们pop操作得到的元素依次是2,3,1。也就是出栈序列就是2,3,1。

请按字典序，输出所有n个元素的可行的出栈序列。

输入格式
第一行，一个整数n。

输出格式
若干行，每行n个整数，表示出栈序列。

样例输入
3
样例输出
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1

4

1234
1324
1432
....
数据规模
对于100%的数据，保证n≤12。
*/
//注意，只能按顺序push
//观察pop，其实是个循环
//push 1,pop1,push2,pop2,push3,pop3    大小各一次
//push1,pop1,push2,push3,pop3,pop2      大循环一次，小循环一次   大循环两次，小循环两次
//push1,push2,pop2,pop1,push3,pop3		大循环两次，小循环两次，大小各一次
//push1,push2,pop2,push3,pop3,pop1        大两次，小一次  大一次，小两次
//push1,push2,push3,pop3,pop2,pop1        大三次，小三次
//卡特兰数：
/*
  我们可以这样想，假设k是最后一个出栈的数。比k早进栈且早出栈的有k-1个数，一共有h(k-1)种方案。
  比k晚进栈且早出栈的有n-k个数，一共有h(n-k)种方案。所以一共有h(k-1)*h(n-k)种方案。
  显而易见，k取不同值时，产生的出栈序列是相互独立的，所以结果可以累加。
  k的取值范围为1至n，所以结果就为h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0)。
	h(2) = h(0)*h(1)+h(1)*h(0)=2   h(4)= 04 +13+22+31+40 = 18
  本题：h(3) = h(0)*h(2) + h(1)*h(1) + h(2)*h(0)=5
*/
// #include <bits/stdc++.h>
// using namespace std;
// int n,top;
// int s[13];
// int str[13];

// int main(){
// 	scanf("%d",&n);
// 	if(n<=1)
// 		return -1;
// 	for(int i = 1;i<=n;i++){
// 		s[i] = i;	
// 	}
// 	top = 0;
// 	//push ,pop ,top

	//方案数
// 	int sum = 0;
// 当j = 1，k = 3，乘完后k要变2，要让他跳出循环，每次外内循环只会执行一次
// 	for(int j = 1;j<=n;j++){
// 		for(int k = n;k<=;){
// 			sum += j*k;
// 		}
// 	}
// 	printf("%d",sum);
// 	return 0;
// }