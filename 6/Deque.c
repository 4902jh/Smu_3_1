#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 이중 연결 리스트 노드 구조체
typedef struct DQNode {
    element data;
    struct DQNode* llink; // 왼쪽 링크
    struct DQNode* rlink; // 오른쪽 링크
} DQNode;

// 데크의 front와 rear를 관리하는 구조체
typedef struct {
    DQNode *front, *rear;
} DequeType;

// 공백 데크 생성
DequeType* createDeque() {
    DequeType* DQ = (DequeType*)malloc(sizeof(DequeType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

// 데크가 비어있는지 검사
int isDQEmpty(DequeType* DQ) {
    if (DQ->front == NULL) return 1;
    else return 0;
}

// front 방향으로 삽입
void insertFront(DequeType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->llink = NULL;
    newNode->rlink = DQ->front;

    if (isDQEmpty(DQ)) {
        DQ->front = newNode;
        DQ->rear = newNode;
    } else {
        DQ->front->llink = newNode;
        DQ->front = newNode;
    }
}

// rear 방향으로 삽입
void insertRear(DequeType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->rlink = NULL;
    newNode->llink = DQ->rear;

    if (isDQEmpty(DQ)) {
        DQ->front = newNode;
        DQ->rear = newNode;
    } else {
        DQ->rear->rlink = newNode;
        DQ->rear = newNode;
    }
}

// front 방향에서 삭제
element deleteFront(DequeType* DQ) {
    DQNode* old = DQ->front;
    element item;
    if (isDQEmpty(DQ)) return 0;
    else {
        item = old->data;
        DQ->front = DQ->front->rlink;
        if (DQ->front == NULL) DQ->rear = NULL;
        else DQ->front->llink = NULL;
        free(old);
        return item;
    }
}

// rear 방향에서 삭제
element deleteRear(DequeType* DQ) {
    DQNode* old = DQ->rear;
    element item;
    if (isDQEmpty(DQ)) return 0;
    else {
        item = old->data;
        DQ->rear = DQ->rear->llink;
        if (DQ->rear == NULL) DQ->front = NULL;
        else DQ->rear->rlink = NULL;
        free(old);
        return item;
    }
}

// front 원소 검색
element peekFront(DequeType* DQ) {
    if (isDQEmpty(DQ)) return 0;
    else return DQ->front->data;
}

// rear 원소 검색
element peekRear(DequeType* DQ) {
    if (isDQEmpty(DQ)) return 0;
    else return DQ->rear->data;
}

// 데크 출력
void printDQ(DequeType* DQ) {
    DQNode* temp = DQ->front;
    printf(" DeQue : [ ");
    while (temp) {
        printf("%c ", temp->data);
        temp = temp->rlink;
    }
    printf("] ");
}

int main(void) {
    DequeType* DQ1 = createDeque();
    element data;

    printf("***** 데크 연산 *****\n\n");

    printf("front 삽입 A>>"); insertFront(DQ1, 'A'); printDQ(DQ1); printf("\n");
    printf("front 삽입 B>>"); insertFront(DQ1, 'B'); printDQ(DQ1); printf("\n");
    printf("rear  삽입 C>>"); insertRear(DQ1, 'C'); printDQ(DQ1); printf("\n");

    printf("front 삭제 >>"); data = deleteFront(DQ1); printDQ(DQ1); printf("   삭제 데이터 : %c\n", data);
    printf("rear  삭제 >>"); data = deleteRear(DQ1); printDQ(DQ1); printf("   삭제 데이터 : %c\n", data);

    printf("rear  삽입 D>>"); insertRear(DQ1, 'D'); printDQ(DQ1); printf("\n");
    printf("front 삽입 E>>"); insertFront(DQ1, 'E'); printDQ(DQ1); printf("\n");
    printf("front 삽입 F>>"); insertFront(DQ1, 'F'); printDQ(DQ1); printf("\n");

    printf("peek Front item : %c\n", peekFront(DQ1));
    printf("peek Rear item : %c\n", peekRear(DQ1));

    getchar(); return 0;
}