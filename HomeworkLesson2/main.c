//1.	����� a � b � �뢥�� ������� � ��� �ᥫ �� a �� b.
//2.	���� 楫� ������⥫�� �᫠ N � K. �ᯮ���� ⮫쪮 ����樨 ᫮����� � ���⠭��,
//      ���� ��⭮� �� ������� ��楫� N �� K, � ⠪�� ���⮪ �� �⮣� �������.
//3.	���� 楫�� �᫮ N (> 0). � ������� ����権 ������� ��楫� � ����� ���⪠ �� ������� ��।�����,
//      ������� �� � ����� �᫠ N ����� ����. �᫨ �������, � �뢥�� True, �᫨ ��� ? �뢥�� False.
//4.	� ���������� �������� �᫠, ���� �� �㤥� ������ 0. �������� �।��� ��䬥��᪮� ���
//      ������⥫��� ���� �ᥫ, ����稢������ �� 8.
//5.	������� �㭪�� ��宦����� ���ᨬ��쭮�� �� ��� �ᥫ.
//6.	* ������� �㭪��, ����������� ��砩��� �᫮ �� 1 �� 100.
//      �) � �ᯮ�짮������ �⠭���⭮� �㭪樨 rand()
//      �) ��� �ᯮ�짮����� �⠭���⭮� �㭪樨 rand()
//
// Encoding: IBM866/CP866/csIBM866

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>

void Solution1();
void Solution2();
void Solution3();
void Solution4();
void Solution5();
void Solution6a();
void Solution6b();

int main()
{
    int choice = 0;
    do {
        system("cls");
        puts("1. Task 1");
        puts("2. Task 2");
        puts("3. Task 3");
        puts("4. Task 4");
        puts("5. Task 5");
        puts("6. Task 6a");
        puts("7. Task 6b");
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
        case 3:
            Solution3();
            break;
        case 4:
            Solution4();
            break;
        case 5:
            Solution5();
            break;
        case 6:
            Solution6a();
            break;
        case 7:
            Solution6b();
            break;
        case 0:
            break;
        default:
            puts("Invalid choice");
            break;
        }
        system("PAUSE");
    }
    while (choice != 0);
    return 0;
}

void Solution1() {
    system("cls");
    int a, b;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    int i;
    for (i = a; i <= b; i++) {
        printf("%d^2 = %g\n", i, pow(i, 2));
        printf("%d^3 = %g\n", i, pow(i, 3));
    }
}

void Solution2() {
    system("cls");
    int N, K;
    printf("Input N: ");
    scanf("%d", &N);
    printf("Input K: ");
    scanf("%d", &K);
    int i = 0;
    while ((N - K * (i + 1)) >= 0) {
        i++;
    }
    printf("%d / %d = %d (%d)\n", N, K, i, N - K * i);
}

void Solution3() {
    system("cls");
    int N;
    printf("Input N: ");
    scanf("%d", &N);
    if (N == 0) { puts("True"); return; }
    do {
        if ((N % 10) % 2 != 0) {
            puts("True");
            return;
        }
        N /= 10;
    }
    while (N != 0);
    puts("False");
}

void Solution4() {
    system("cls");
    int N = -1;
    int count = 0;
    int sum = 0;
    _Bool flag = false;
    while (N != 0) {
        printf("Input N: ");
        scanf("%d", &N);
        if (N > 0 && N % 10 == 8) {
            count++;
            sum += N;
            flag = true;
        }
    }
    if (flag)
        printf("Average: %g\n", (double)sum / count);
    else
        printf("Numbers ending in 8 is not found\n");
}

void Solution5() {
    system("cls");
    int max, a, b, c;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    printf("Input c: ");
    scanf("%d", &c);
    max = a;
    if (b > c) {
        if (b > a)
            max = b;
    }
    else
        if (c > a)
            max = c;
    printf("Maximum: %d\n", max);
}

void Solution6a() {
    system("cls");
    srand(time(NULL));
    printf("Random: %d\n", rand() % 100 + 1);
}

void Solution6b() {
    system("cls");
    int X, A, B, M;
    int i, N;
    printf("Input N (amount of numbers): ");
    scanf("%d", &N);
    M = 100;
    B = 3;
    A = 2;
    X = 1;
    for(i = 0; i < N; i++) {
        X = (A * X + B) % M;
        printf("%d\t", X);
    }
    printf("\n");
}
