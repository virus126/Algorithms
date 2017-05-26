//Solution1()   OK   1.  *Создать стек на основе закольцованного списка.
//Solution2()   OK   2.  Добавить в программу "реализация стека на основе односвязного списка" проверку на выделение памяти
//                      (посмотрите в Интернете, как это сделать). Если память не выделяется, то выводится соответствующее сообщение.
//                      Постарайтесь создать ситуацию, когда память не будет выделятся.
//Solution3()        3.	Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//                      Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
//                      неправильных - )(, ())({), (, ])}), ([(]) для скобок [,(,{. Например: (2+(2*2)) или [2/{5*(4+7)}]
//Solution4()        4. **Предположим, что для реализации односвязного списка мы определили узел следующим образом
//                      typedef struct TNode* Node; Переписать программу с учётом этих изменений;
//Solution5()   OK   5.	*Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного списка,
//                      без удаления первого списка).
//Solution6()   OK   6.	***Создать функцию SortPush, которая вставляет узел в односвязный список таким образом, чтобы список был отсортирован.
//                      Продемонстрировать работу программы.
//Solution7()   OK   7.	****Создать стек на основе двусвязного списка.


#include <stdio.h>
#include <malloc.h>
#define T char

typedef struct TNode1 {
    T value;
    struct TNode1 *next;
} Node1;

typedef struct TNode2 {
    int value;
    struct TNode2* next;
} Node2;
//-----------------------------------------------
void push1              (T value);
T pop1                  ();
void printStack1        ();
void Solution1          ();
//-----------------------------------------------
void push2              (int value);
int pop2                ();
void printStack2        ();
void Solution2          ();
//-----------------------------------------------
Node1* createCharList   ();
Node1* copyList         (Node1* headSrc);
void printCharList      (Node1* current);
void Solution5          ();
//-----------------------------------------------
Node2* createIntList    ();
void printIntList       (Node2* current);
void sortPush           (Node2* head, int N);
void Solution6          ();
//-----------------------------------------------
void push7              (T value);
T pop7                  ();
void printStackHead     ();
void printStackTail     ();
void Solution7          ();

int main()
{
    int choice = 0;
    do {
        system("cls");
        puts("1. Task 1");
        puts("2. Task 2");
        puts("5. Task 5");
        puts("6. Task 6");
        puts("7. Task 7");
        puts("0. Exit");
        printf("Select: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Solution1();
            break;
        case 2:
            Solution2();
            break;
        case 5:
            Solution5();
            break;
        case 6:
            Solution6();
            break;
        case 7:
            Solution7();
            break;
        case 0:
            return 0;
        default:
            puts("Invalid choice");
            break;
        }
        system("PAUSE");
    }
    while (choice != 0);
    return 0;
}
//  TASK 1
struct Stack1 {
    Node1* head;
    Node1* tail;
    int size;
    int maxSize;
};

struct Stack1 stack1;

void push1(T value)
{
   if (stack1.size >= stack1.maxSize) {
       printf("Error stack size\n");
       return;
   }
   Node1* tmp = (Node1*) malloc(sizeof(Node1));
   tmp->value = value;
   tmp->next = stack1.head;
   stack1.head = tmp;
   if (stack1.size == 0)
       stack1.tail = stack1.head;
   stack1.tail->next = stack1.head;
   stack1.size++;
}

T pop1() {
   if (stack1.size==0) {
       printf("Stack is empty\n");
       return;
   }
   Node1* next = NULL;

   T value = stack1.head->value;
   next = stack1.head;
   stack1.head = stack1.head->next;
   stack1.tail->next = stack1.head;

   free(next);

   stack1.size--;
   return value;
}

void printStack1() {
    Node1 *current = stack1.head;
    while(current) {
        printf("%c", current->value);
        current = current->next;
        if (current == stack1.head) {
            printf("\n");
            return;
        } else
            printf(" -> ");
    }
}

void Solution1() {
    system("cls");
    stack1.maxSize = 100;
    stack1.head = NULL;
    stack1.tail = stack1.head;
    push1('a');
    push1('b');
    push1('c');
    push1('d');
    push1('e');
    push1('f');
    printStack1();
}

//  TASK 2
struct Stack2 {
    Node2 *head;
    int size;
    int maxSize;
};

struct Stack2 stack2;

void push2(int value) {
    if (stack2.size >= stack2.maxSize) {
        printf("Error stack size");
        return;
    }
//  Запрашиваем у ОС 500 Мб
    Node2* tmp = (Node2*) malloc(50000000*sizeof(Node2));
    if (tmp == NULL) {
        puts("Error");
        return;
    }
    tmp->value = value;
    tmp->next = stack2.head;
    stack2.head = tmp;
    stack2.size++;
}

int pop2() {
    if (stack2.size == 0) {
        printf("Stack is empty\n");
        return;
    }
    Node2* next = NULL;

    int value;
    value = stack2.head->value;
    next = stack2.head;
    stack2.head = stack2.head->next;

    free(next);

    stack2.size--;
    return value;
}

void printStack2() {
    Node2 *current = stack2.head;
    while(current) {
        printf(current->next ? " %d ->" : " %d", current->value);
        current = current->next;
    }
    printf("\n");
}

void Solution2() {
    system("cls");
    stack2.maxSize = 10;
    stack2.head = NULL;
    for(int i = 0; i < stack2.maxSize; i++)
        push2(i);
    printStack2();
}
//  TASK 5
Node1* createCharList() {
    Node1* head = (Node1*)malloc(sizeof(Node1));
    head->value = 'a';
    head->next = NULL;
    for(char c = 'b'; c < 'j'; c++) {
        Node1* tmp = (Node1*)malloc(sizeof(Node1));
        tmp->value = c;
        tmp->next = head;
        head = tmp;
    }
    return head;
}

Node1* copyList(Node1* headSrc) {
    Node1* headDst = (Node1*)malloc(sizeof(Node1));
    Node1* last = headDst;
    if (headSrc) {
        last->value = headSrc->value;
        headSrc = headSrc->next;
    }
    while (headSrc) {
        last->next = (Node1*)malloc(sizeof(Node1));
        last = last->next;
        last->value = headSrc->value;

        headSrc = headSrc->next;
    }
    return headDst;
}

void printCharList(Node1* current) {
    while(current) {
        printf(current->next ? " %c ->" : " %c", current->value);
        current = current->next;
    }
    printf("\n");
}

void Solution5() {
    system("cls");
    Node1* headSrc = createCharList();
    Node1* headDst = copyList(headSrc);
    printf("Sourse list: ");
    printCharList(headSrc);
    printf("Result list: ");
    printCharList(headDst);
}
//  TASK 6
Node2* createIntList() {
    Node2* head = (Node2*)malloc(sizeof(Node2));
    head->value = 100;
    head->next = NULL;
    for(int i = 90; i >= 0; i -= 10) {
        Node2* tmp = (Node2*)malloc(sizeof(Node2));
        tmp->value = i;
        tmp->next = head;
        head = tmp;
    }
    return head;
}

void printIntList(Node2* current) {
    while(current) {
        printf(current->next ? " %d ->" : " %d", current->value);
        current = current->next;
    }
    printf("\n");
}

void sortPush(Node2* head, int N) {
    Node2* prev = head;
    Node2* next = head->next;
//  Если элемент меньше самого первого
    if (N <= head->value) {
        Node2* tmp = (Node2*)malloc(sizeof(Node2));
        tmp->value = N;
        tmp->next = head;
        head = tmp;
        return;
    } else {
//      Иначе ищем ему место
        while (N > next->value && next->next) {
            prev = next;
            next = next->next;
        }
        Node2* tmp = (Node2*)malloc(sizeof(Node2));
        tmp->value = N;
//      Если элемент больше последнего
        if (N > next->value) {
            next->next = tmp;
            tmp->next = NULL;
//      Если элемент больше предыдущего и меньше следующего
        } else {
            prev->next = tmp;
            tmp->next = next;
        }
    }
}

void Solution6() {
    system("cls");
    Node2* head = createIntList();
    int N;
    printf("Sourse list: ");
    printIntList(head);
    printf("Input number: ");
    fflush(stdin);
    scanf("%d", &N);
    sortPush(head, N);
    printf("Result list: ");
    printIntList(head);
}
//  TASK 7
typedef struct TNode7 {
    T value;
    struct TNode7 *prev;
    struct TNode7 *next;
} Node7;

struct Stack7 {
    Node7* head;
    Node7* tail;
    int size;
    int maxSize;
};

struct Stack7 stack7;

void push7(T value) {
   if (stack7.size >= stack7.maxSize) {
       printf("Error stack size\n");
       return;
   }
   Node7* tmp = (Node7*) malloc(sizeof(Node7));
   tmp->value = value;
   tmp->prev = NULL;
   if (stack7.size == 0) {
       tmp->next = NULL;
       stack7.tail = tmp;
   } else {
       tmp->prev = NULL;
       tmp->next = stack7.head;
       stack7.head->prev = tmp;
   }
   stack7.head = tmp;
   stack7.size++;
}

T pop7() {
    if (stack7.size==0) {
        printf("Stack is empty\n");
        return;
    }
    Node7* next = stack7.head;
    T value = stack7.head->value;
    stack7.head = stack7.head->next;
    if (stack7.head != NULL)
        stack7.head->prev = NULL;
    else
        stack7.tail = NULL;

    free(next);

    stack7.size--;
    return value;
}

void printStackHead() {
    Node7 *current = stack7.head;
    while(current) {
        printf(current->next ? " %c ->" : " %c", current->value);
        current = current->next;
    }
    printf("\n");
}

void printStackTail() {
    Node7 *current = stack7.tail;
    while(current) {
        printf(current->prev ? " %c ->" : " %c", current->value);
        current = current->prev;
    }
    printf("\n");
}

void Solution7()
{
    system("cls");
    stack7.maxSize = 100;
    stack7.head = NULL;
    push7('a');
    push7('b');
    push7('c');
    push7('d');
    push7('e');
    push7('f');

    printf("Print stack from head:");
    printStackHead();
    printf("Print stack from tail:");
    printStackTail();

    return 0;
}

