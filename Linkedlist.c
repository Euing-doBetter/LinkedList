#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;      // ���� ����Ʈ�̹Ƿ� NULL�� ����
    return L;
}

void freeLinkedList_h(linkedList_h* L) //���Ḯ��Ʈ �ʱ�ȭ,
{
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

void printList(linkedList_h* L) //�̸� : ���� ������
{
    listNode* p;
    printf("L = (");
    p = L->head;
    while (p != NULL) {
        printf("%s %d", p->name, p->score);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(") \n");
}

void printRangedList(linkedList_h* L, int lowscore, int highscore)
// lowscore �̻� hightscore ������ �л��� �̸��� ��� ���
{
    //lowscore = findLowScore(L);
    listNode* p;

    p = L->head;
    //while (p != NULL) {
    //    highscore = p->score;

    //    if (highscore < p->score) {
    //        highscore = p->score;

    //    }
    //    /*else{
    //       min=min;
    //    }*/
    //    p = p->link;
    //}
    //return highscore;
    while (p != NULL) {
        if (lowscore <= p->score && highscore >= p->score) {
            printf("%s ", p->name);
            //p = p->link;
        }
        p = p->link;
    }
}

void insertNode(linkedList_h* L, int score, char* name)
//- score�� ������� ��ġ�� ã�� �Է�
{

    listNode* newnode;
    listNode* p;
    listNode* q;
    newnode = (listNode*)malloc(sizeof(listNode));
    newnode->score = score;
    strcpy(newnode->name, name);

    p = L->head;
    q = NULL;

    if (L->head == NULL) {
        L->head = newnode;
        newnode->link = NULL;
        return;
    }
    else if (p->link == NULL)
    {
        if (p->score > newnode->score){
            newnode->link = NULL;
            p->link = newnode;
            return;
        }
        else if (p->score < newnode->score) {
            L->head = newnode;
            newnode->link = p;
            return;
        }
        else if (p->score == newnode->score)
        {
            if (strcmp(p->name, newnode->name) > 0)
            {
                L->head = newnode;
                newnode->link = p;
                return;
            }
            else if (strcmp(p->name, newnode->name) < 0)
            {
                newnode->link = NULL;
                p->link = newnode;
                return;
            }
        }
    }
    else {

        while (p != NULL) {
            if (p->score > newnode->score) {
                if (p->link == NULL) {
                    newnode->link = NULL;
                    p->link = newnode;
                    break;
                }
                else
                {
                    q = p;
                    p = p->link;
                }

            }
            else if (p->score < newnode->score) {

                if (q == NULL) {
                    L->head = newnode;
                    newnode->link = p;
                    break;
                }
                else {
                    q->link = newnode;
                    newnode->link = p;
                    break;
                }

            }
            else if (p->score == newnode->score)
            {
                if (strcmp(p->name, newnode->name) > 0)
                {
                    if (q == NULL) 
                    {
                        L->head = newnode;
                        newnode->link = p;
                        break;
                    }
                    else
                    {
                        q->link = newnode;
                        newnode->link = p;
                        break;
                    }
                }
                else if (strcmp(p->name, newnode->name) < 0)
                {
                    if (p->link == NULL)
                    {
                        newnode->link = NULL;
                        p->link = newnode;
                        break;
                    }
                    else
                    {
                        newnode->link = p->link;
                        p->link = newnode;
                        break;
                    }
                }
            }
        }

    }

}

void deleteNode(linkedList_h* L, char* name)
{
    listNode* p = L->head;
    listNode* q = NULL;

    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {
            if (q != NULL) {
                q->link = p->link;
            }
            else {
                L->head = p->link;
            }
            free(p);
            return;
        }
        q = p;
        p = p->link;
    }
}


int searchbyName(linkedList_h* L, char* name)
// �̸��� ������� ã�Ƽ� ���° ����Ʈ���� ����
{
    listNode* p;
    int count = 1;
    p = L->head;
    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {
            return count;
        }
        else {
            p = p->link;
            count++;
        }
    }
}

int searchbyScore(linkedList_h* L, int score)
//������ ������� ã�Ƽ� ���° ����Ʈ���� ����
{
    listNode* p;
    int count = 1;
    p = L->head;
    while (p != NULL) {
        if (score == p->score) {
            return count;
        }
        else {
            p = p->link;
            count++;
        }
    }
}

int findLowScore(linkedList_h* L)
{
    listNode* p;
    int min = 0;
    p = L->head;
    while (p != NULL) {
        min = p->score;

        if (min > p->score) {
            min = p->score;

        }
        /*else{
           min=min;
        }*/
        p = p->link;
    }
    return min;

}


int findMidScore(linkedList_h* L)
{
    listNode* p;
    int count = 0;
    int ph = 1;
    p = L->head;
    while (p != NULL) {
        if (p == NULL) {
            break;
        }
        else {
            count++;
            p = p->link;
        }
    }
    if (count % 2 == 1) {//Ȧ��
        count = count / 2 + 1;

    }
    else if (count % 2 == 0) { //¦��
        count = count / 2;

    }
    p = L->head;
    while (p != NULL) {

        if (ph == count) {
            return p->score;
        }
        else {
            p = p->link;
            ph++;
        }

    }
}


double calAve(linkedList_h* L) //��ü �л� ���
{
    listNode* p;
    int p_num = 0;
    double sum = 0;
    double calave;
    p = L->head;
    while (p != NULL) {
        if (p == NULL) {
            return p_num;
        }
        else {
            sum = sum + p->score;
            p = p->link;
            p_num++;
        }
    }
    calave = sum / p_num;
    return calave;
}

void changeScorebyName(linkedList_h* L, int score, char* name)
{
    listNode* p;
    p = L->head;
    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            deleteNode(L, name);
            insertNode(L, score, name);
            break;
        }
        p = p->link;
    }
    
}//�̸��� ������� ã��(searchname) �� �л���
//������ �����ϰ�, (������ ������� ��ġ ������=insertnode)
