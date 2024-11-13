#pragma once
// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	int score;
	char name[10];
	struct ListNode* link;
} listNode;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h* L);
void printRangedList(linkedList_h* L, int lowscore, int highscore);
void insertNode(linkedList_h* L, int score, char* name);
void deleteNode(linkedList_h* L, char* name);
int searchbyName(linkedList_h* L, char* name);
int searchbyScore(linkedList_h* L, int score);
int findLowScore(linkedList_h* L);
int findMidScore(linkedList_h* L);
double calAve(linkedList_h* L);
void changeScorebyName(linkedList_h* L, int score, char* name);