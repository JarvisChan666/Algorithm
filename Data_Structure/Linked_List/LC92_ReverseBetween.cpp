#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left == right)return head;
    ListNode* dummyNode = new ListNode();
    dummyNode->next = head;
    ListNode *pre = dummyNode,*hnext = head->next;
    int index = 1;
    for(;index < right;index++){
        if(index<left){
            pre = pre->next;//left节点的前节点
            head = pre->next;//left节点  
        }else{
            //初始链表为 1->2->3->4->5  left = 2 right = 4 即要反转2->3->4这三个节点 
            //思路为：把3放到2的前面--- 1->3->2->4->5 ，再把4放到3的前面 --- 1->4->3->2->5
            // 先以反转两个节点，以反转2->3为例   2->3---3->2
            //pre->1   head->2  hnext->3
            //2->4 --- 3->2 --- 1->3 --- 1->3->2->4  
            hnext = head->next;//hnext->3
            head->next = hnext->next;//2->4
            hnext->next = pre->next;//3->2
            pre->next = hnext;//1->3 ---此时已将3放到2的前面 --- 1->3->2->4->5 再循环一次将4放到3的前面 --- 1->4->3->2->5
        }
    }
    return dummyNode->next;
}

  int main()
  {
      ListNode *list = [1,3,4,5,6];
      reverseBetween(list,1,3);
      return 0;
  }