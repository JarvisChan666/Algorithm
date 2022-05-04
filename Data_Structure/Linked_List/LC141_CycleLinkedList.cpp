#include <bits/stdc++.h>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
bool isCycle(ListNode *head){
	if(head==nullptr || head->next==nullptr)
		return false;
	ListNode *slow = head;
	ListNode *fast = head->next;
	while(slow!=fast){
		if(fast==nullptr || fast->next==nullptr)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}

int main()
{
	isCycle()
	return 0;
}