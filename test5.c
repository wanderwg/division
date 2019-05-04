//以给定值x为基准将链表分为两部分，所有小于x的节点排在所有大于或等于x节点之前
//要注意的地方：
//1.链表遍历完一遍后没有一个小于x的节点，即l1为空
//2.最后要将last2指向NULL
ListNode* partition(ListNode* pHead, int x) {
	ListNode* l1 = NULL;
	ListNode* last1 = NULL;
	ListNode* l2 = NULL;
	ListNode* last2 = NULL;
	ListNode* pCur = pHead;
	while (pCur) {
		if (pCur->val < x) {
			if (l1 == NULL) {
				l1 = pCur;
				last1 = pCur;
			}
			else {
				last1->next = pCur;
				last1 = last1->next;
			}
		}
		else {
			if (l2 == NULL) {
				l2 = pCur;
				last2 = pCur;
			}
			else {
				last2->next = pCur;
				last2 = last2->next;
			}
		}
		pCur = pCur->next;
	}
	if (last1) {
		last1->next = l2;
	}
	if (last2 != NULL) {
		last2->next = NULL;
	}
	if (last1)
		return l1;
	else
		return l2;
}