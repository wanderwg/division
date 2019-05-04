//�Ը���ֵxΪ��׼�������Ϊ�����֣�����С��x�Ľڵ��������д��ڻ����x�ڵ�֮ǰ
//Ҫע��ĵط���
//1.���������һ���û��һ��С��x�Ľڵ㣬��l1Ϊ��
//2.���Ҫ��last2ָ��NULL
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