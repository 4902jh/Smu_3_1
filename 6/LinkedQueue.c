#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 노드 구조체 정의
typedef struct QNode {
    element data;
    struct QNode* link;
} QNode;

// 큐의 front와 rear를 관리하는 구조체
typedef struct {
    QNode *front, *rear;
} LQueueType;

// 공백 연결 큐를 생성하는 연산
LQueueType* createLinkedQueue() {
    LQueueType* LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isLQEmpty(LQueueType* LQ) {
    if (LQ->front == NULL) return 1;
    else return 0;
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enQueue(LQueueType* LQ, element item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if (LQ->front == NULL) { // 큐가 비어있는 경우
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {                  // 큐가 비어있지 않은 경우
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

// 연결 큐의 front에서 원소를 삭제하고 반환하는 연산
element deQueue(LQueueType* LQ) {
    QNode* old = LQ->front;
    element item;
    if (isLQEmpty(LQ)) return 0;
    else {
        item = old->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL) // 삭제 후 공백 큐가 된 경우
            LQ->rear = NULL;
        free(old);
        return item;
    }
}

// 연결 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(LQueueType* LQ) {
    if (isLQEmpty(LQ)) return 0;
    else return LQ->front->data;
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType* LQ) {
    QNode* temp = LQ->front;
    printf(" Linked Queue : [ ");
    while (temp) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("] ");
}

int main(void) {
    LQueueType* LQ1 = createLinkedQueue();
    element data;

    printf("***** 연결 큐 연산 *****\n\n");

    printf("삽입 A>>"); enQueue(LQ1, 'A'); printLQ(LQ1); printf("\n");
    printf("삽입 B>>"); enQueue(LQ1, 'B'); printLQ(LQ1); printf("\n");
    printf("삽입 C>>"); enQueue(LQ1, 'C'); printLQ(LQ1); 
    data = peek(LQ1); printf("    peek item : %c\n\n", data);

    printf("삭제 >>"); data = deQueue(LQ1); printLQ(LQ1); 
    printf("    삭제 데이터 : %c\n", data);
    printf("삭제 >>"); data = deQueue(LQ1); printLQ(LQ1); 
    printf("    삭제 데이터 : %c\n", data);
    printf("삭제 >>"); data = deQueue(LQ1); printLQ(LQ1); 
    printf("    삭제 데이터 : %c\n", data);

    printf("삽입 D>>"); enQueue(LQ1, 'D'); printLQ(LQ1); printf("\n");
    printf("삽입 E>>"); enQueue(LQ1, 'E'); printLQ(LQ1); printf("\n");

    getchar(); return 0;
}