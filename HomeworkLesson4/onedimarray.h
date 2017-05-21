#ifndef ONEDIMARRAY_H
#define ONEDIMARRAY_H

void MenuOneDim();
void printOneDimArray (int *array, int N);
void Solution1_1(int *array, int N);
void Solution2_1(int *array, int N);
int sumOneDimArray (int *array, int N);
void Solution3_1(int *array, int N);
double averageOneDimArray (int *array, int N);
void Solution4_1(int *array, int N);
void Solution5_1(int *array, int N);
void Solution6_1(int *array, int N);
void Solution7_1(int *array, int N);
void Solution8_1(int *array, int N);

void MenuOneDim() {
    int N = 100;
    int array[N];
    int choice = 0;
    do {
        system("cls");
        puts("1. Task 1");
        puts("2. Task 2");
        puts("3. Task 3");
        puts("4. Task 4");
        puts("5. Task 5");
        puts("6. Task 6");
        puts("7. Task 7");
        puts("8. Task 8");
        puts("0. Back");
        printf("Select: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Solution1_1(array, N);
            break;
        case 2:
            Solution2_1(array, N);
            break;
        case 3:
            Solution3_1(array, N);
            break;
        case 4:
            Solution4_1(array, N);
            break;
        case 5:
            Solution5_1(array, N);
            break;
        case 6:
            Solution6_1(array, N);
            break;
        case 7:
            Solution7_1(array, N);
            break;
        case 8:
            Solution8_1(array, N);
            break;
        case 0:
            return;
        default:
            puts("Invalid choice");
            break;
        }
        system("PAUSE");
    }
    while (choice != 0);
}

void printOneDimArray (int *array, int N) {
    for (int i = 0; i < N; i++)
        printf("array[%d] = %d\n", i, array[i]);
}

void Solution1_1(int *array, int N) {
    system("cls");
    for (int i = 0; i < N; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
}

void Solution2_1(int *array, int N) {
    system("cls");
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        array[i] = rand() % 100 + 1;
    printOneDimArray(array, N);
}

int sumOneDimArray (int *array, int N) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += *(array + i);
    return sum;
}

void Solution3_1(int *array, int N) {
    system("cls");
    printf("Sum = %d\n", sumOneDimArray(array, N));
}

double averageOneDimArray (int *array, int N) {
    return (double)sumOneDimArray(array, N) / N;
}

void Solution4_1(int *array, int N) {
    system("cls");
    printf("Average of array = %g\n", averageOneDimArray(array, N));
}

void Solution5_1(int *array, int N) {
    system("cls");
    double average = averageOneDimArray(array, N);
    double currentMaxDiv = fabs((double)*array - average);
    int numElement = 0;
    double div;
    for (int i = 1; i < N; i++) {
        div = fabs((double)*(array + i) - average);
        if (div > currentMaxDiv) {
            numElement = i;
            currentMaxDiv = div;
        }
    }
    printf("Number of Element = %d\n", numElement);
}

void Solution6_1(int *array, int N) {
    system("cls");
    int* max = array;
    for (int i = 1; i < N; i++)
        if (*(array + i) > *max)
            max = array + i;
    printf("Max Element = %d\n", *max);
}

void Solution7_1(int *array, int N) {
    system("cls");
    FILE *in;
    in = fopen("..\\HomeworkLesson4\\file_one_dim.txt","r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    fscanf(in, "%d", &N);
    for (int i = 0; i < N; i++)
        fscanf(in, "%d", &array[i]);
    fclose(in);
    printOneDimArray(array, N);
}

void Solution8_1(int *array, int N) {
    typedef struct Node {
        int i;
        struct Node *next;
    } Node;

    Node* head = (Node*) malloc(sizeof(Node));
        head->i = 0;
        head->next = NULL;
    Node* current = head;
    double average = averageOneDimArray(array, N);
    double currentMaxDiv = fabs((double)*array - average);
    double div;
    for (int i = 1; i < N; i++) {
        div = fabs((double)*(array + i) - average);
        if (div > currentMaxDiv) {
            head->i = i;
            head->next = NULL;
            currentMaxDiv = div;
            current = head;
        } else if (div == currentMaxDiv) {
                    current->next = (Node*) malloc(sizeof(Node));
                    current = current->next;
                    current->i = i;
                    current->next = NULL;
               }
    }
    current = head;
    while (current != NULL) {
        printf("[%d]\n", current->i);
        current = current->next;
    }
}

#endif // ONEDIMARRAY_H
