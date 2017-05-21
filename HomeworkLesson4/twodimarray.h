#ifndef TWODIMARRAY_H
#define TWODIMARRAY_H

void MenuTwoDim();
void printTwoDimArray (int *array, int N);
void Solution1_2(int *array, int N);
void Solution2_2(int *array, int N);
int sumTwoDimArray (int *array, int N);
void Solution3_2(int *array, int N);
double averageTwoDimArray (int *array, int N);
void Solution4_2(int *array, int N);
void Solution5_2(int *array, int N);
void Solution6_2(int *array, int N);
void Solution7_2(int *array, int N);
void Solution8_2(int *array, int N);

void MenuTwoDim() {
    int N = 10;
    int array[N][N];
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
            Solution1_2(array, N);
            break;
        case 2:
            Solution2_2(array, N);
            break;
        case 3:
            Solution3_2(array, N);
            break;
        case 4:
            Solution4_2(array, N);
            break;
        case 5:
            Solution5_2(array, N);
            break;
        case 6:
            Solution6_2(array, N);
            break;
        case 7:
            Solution7_2(array, N);
            break;
        case 8:
            Solution8_2(array, N);
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

void printTwoDimArray (int *array, int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            printf("array[%d][%d] = %d\n", i, j, *(array + i * N + j));
}

void Solution1_2(int *array, int N) {
    system("cls");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("array[%d][%d] = ", i, j);
            scanf("%d", array + i * N + j);
        }
    }
}

void Solution2_2(int *array, int N) {
    system("cls");
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            *(array + i * N + j) = rand() % 100 + 1;
    printTwoDimArray(array, N);
}

int sumTwoDimArray (int *array, int N) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += *(array + i * N + j);
    return sum;
}

void Solution3_2(int *array, int N) {
    system("cls");
    printf("Sum = %d\n", sumTwoDimArray(array, N));
}

double averageTwoDimArray (int *array, int N) {
    return (double)sumTwoDimArray(array, N) / (N * N);
}

void Solution4_2(int *array, int N) {
    system("cls");
    printf("Average of array = %g\n", averageTwoDimArray(array, N));
}

void Solution5_2(int *array, int N) {
    system("cls");
    double average = averageTwoDimArray(array, N);
    double currentMaxDiv = fabs((double)*array - average);
    double div;
    int numI = 0;
    int numJ = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            div = fabs((double)*(array + i * N + j) - average);
            if (div > currentMaxDiv) {
                numI = i;
                numJ = j;
                currentMaxDiv = div;
            }
        }
    printf("Number of Element = [%d][%d]\n", numI, numJ);
}

void Solution6_2(int *array, int N) {
    system("cls");
    int* max = array;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (*(array + i * N + j) > *max)
                max = array + i * N + j;
    printf("Max Element = %d\n", *max);
}

void Solution7_2(int *array, int N) {
    system("cls");
    FILE *in;
    in = fopen("..\\HomeworkLesson4\\file_two_dim.txt","r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    fscanf(in, "%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fscanf(in, "%d", array + i * N + j);
    fclose(in);
    printTwoDimArray(array, N);
}

void Solution8_2(int *array, int N) {
    typedef struct Node {
        int i;
        int j;
        struct Node *next;
    } Node;

    Node* head = (Node*) malloc(sizeof(Node));
        head->i = 0;
        head->j = 0;
        head->next = NULL;
    Node* current = head;
    double average = averageTwoDimArray(array, N);
    double currentMaxDiv = fabs((double)*array - average);
    double div;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (i == 0 && j == 0)
                continue;
            div = fabs((double)*(array + i * N + j) - average);
            if (div > currentMaxDiv) {
                head->i = i;
                head->j = j;
                head->next = NULL;
                currentMaxDiv = div;
                current = head;
            } else if (div == currentMaxDiv) {
                        current->next = (Node*) malloc(sizeof(Node));
                        current = current->next;
                        current->i = i;
                        current->j = j;
                        current->next = NULL;
                   }
        }
    current = head;
    while (current != NULL) {
        printf("[%d][%d]\n", current->i, current->j);
        current = current->next;
    }
}

#endif // TWODIMARRAY_H
