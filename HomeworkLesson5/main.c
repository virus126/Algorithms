//1.	Попробовать оптимизировать пузырьковую сортировку. Описать в комментариях к программе что дают эти улучшения.
//      Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
//2.	Реализовать шейкерную сортировку.
//3.	Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
//      Функция возвращает индекс найденного элемента или -1, если элемент не найден.
//4.	*Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
//      Реализовать меню с выбором способа заполнения массива: из файла, случайными числами, с клавиатуры

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b);
void Print(int *array, int N);
void Solution1(int *array, int N);
void Solution2(int *array, int N);
void Solution3(int *array, int N);
int bubbleSort(int* array, int N);
void Solution4(int *array, int N);
int combSort(int* array, int N);
void Solution5(int *array, int N);
int shakerSort (int* array, int N);
void Solution6(int *array, int N);
int binarySearch (int *array, int N, int value);
void Solution7(int *array, int N);

_Bool isInitialized = false;

int main()
{
    int N = 1000;
    int array[N];
    int choice = 0;
    do {
        system("cls");
        puts("1. Input array (from keyboard)");
        puts("2. Input array (from file)");
        puts("3. Input array (random)");
        puts("4. Task 1 Bubble sort");
        puts("5. Task 1 Comb sort");
        puts("6. Task 2 Shaker sort");
        puts("7. Task 3 Binary Search");
        puts("0. Exit");
        printf("Select: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Solution1(array, N);
            break;
        case 2:
            Solution2(array, N);
            break;
        case 3:
            Solution3(array, N);
            break;
        case 4:
            Solution4(array, N);
            break;
        case 5:
            Solution5(array, N);
            break;
        case 6:
            Solution6(array, N);
            break;
        case 7:
            Solution7(array, N);
            break;
        case 0:
            break;
        default:
            puts("Invalid choice");
            break;
        }
        system("pause");
    }
    while (choice != 0);
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void Print(int *array, int N) {
    for(int i = 0; i < N; i++)
        printf("%6i", array[i]);
    printf("\n");
}

void Solution1(int *array, int N) {
    system("cls");
    for (int i = 0; i < N; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    Print(array, N);
    isInitialized = true;
}

void Solution2(int *array, int N) {
    system("cls");
    FILE *in;
    in = fopen("..\\HomeworkLesson5\\data.txt","r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    for(int i = 0; i < N; i++)
        fscanf(in, "%i", &array[i]);
    fclose(in);
    Print(array, N);
    isInitialized = true;
}

void Solution3(int *array, int N) {
    system("cls");
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        array[i] = rand() % 100 + 1;
    Print(array, N);
    isInitialized = true;
}

int bubbleSort(int* array, int N) {
    int count = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N - 1; j++) {
            count++;
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
        }
    return count;
}

void Solution4(int *array, int N) {
    system("cls");
    if (!isInitialized) {
        puts("Array is not initialized");
        return;
    }
    puts("Array before sort");
    Print(array, N);
    int count = bubbleSort(array, N);
    puts("Array after sort");
    Print(array, N);
    printf("Count: %d\n", count);
}

int combSort(int* array, int N) {
    int count = 0;
    for(int factor = N / 1.247; factor > 1; factor /= 1.247)
        for(int i = 0; i + factor < N; i++) {
            count++;
            if (array[i + factor] < array[i])
                swap(&array[i], &array[i + factor]);
        }
    for(int i = 0; i < N - 1; i++) {
        count++;
        if (array[i + 1 ] < array[i])
            swap(&array[i], &array[i+1]);
    }
    return count;
}

void Solution5(int *array, int N) {
    system("cls");
    if (!isInitialized) {
        puts("Array is not initialized");
        return;
    }
    puts("Array before sort");
    Print(array, N);
    int count = combSort(array, N);
    puts("Array after sort");
    Print(array, N);
    printf("Count: %d\n", count);
}

int shakerSort (int* array, int N) {
    int left = 0;
    int right = N - 1;
    int count = 0;
    do {
        for (int i = left; i < right; i++) {
            count++;
            if (array[i] > array[i+1]) {
                swap(&array[i], &array[i+1]);
            }
        }
        right--;
        for (int i = right; i > left ; i--) {
            count++;
            if(array[i] < array[i-1]) {
                swap(&array[i], &array[i-1]);
            }
        }
        left++;
    } while (left <= right);
    return count;
}

void Solution6(int *array, int N) {
    system("cls");
    if (!isInitialized) {
        puts("Array is not initialized");
        return;
    }
    puts("Array before sort");
    Print(array, N);
    int count = shakerSort(array, N);
    puts("Array after sort");
    Print(array, N);
    printf("Count: %d\n", count);
}

int binarySearch (int *array, int N, int value) {
    int L = 0;
    int R = N - 1;
    int m = L + (R - L) / 2;
    while(L <= R && array[m] != value) {
        if (array[m] < value)
            L = m + 1;
        else
            R = m - 1;
        m = L + (R - L) / 2;
    }
    if (array[m] == value)
        return m;
    else
        return -1;
}

void Solution7(int *array, int N) {
    system("cls");
    if (!isInitialized) {
        puts("Array is not initialized");
        return;
    }
    int value;
    printf("Input value for search: ");
    scanf("%d", &value);
    combSort(array, N);
    int result = binarySearch(array, N, value);
    if (result == -1)
        printf("Value not found\n");
    else
        printf("Index: %d Value: %d\n", result, array[result]);
}
