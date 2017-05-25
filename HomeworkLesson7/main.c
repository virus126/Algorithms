//(Solution 1)  OK  1.	����������� �㭪�� ��ॢ��� �� 10 ��⥬� � �������, �ᯮ���� ४����.
//                  2.	����������� �㭪�� ���������� �᫠ a � �⥯��� b:
//(Solution 2)  OK      a.	��� ४��ᨨ;
//(Solution 3)  OK      b.	४��ᨢ��;
//(Solution 4)  OK      c.	*४��ᨢ��, �ᯮ���� ᢮��⢮ ��⭮�� �⥯���.
//                  3.	�ᯮ���⥫� �������� �८�ࠧ�� 楫�� �᫮, ����ᠭ��� �� �࠭�. � �ᯮ���⥫� ��� �������,
//                      ������ ������� ��᢮�� �����:
//                      1. �ਡ��� 1
//                      2. ������ �� 2
//                      ��ࢠ� ������� 㢥��稢��� �᫮ �� �࠭� �� 1, ���� 㢥��稢��� �� �᫮ � 2 ࠧ�.
//                      ����쪮 ������� �ணࠬ�, ����� �᫮ 3 �८�ࠧ��� � �᫮ 20.
//(Solution 5)          �) � �ᯮ�짮������ ���ᨢ�;
//(Solution 6)  OK      �) � �ᯮ�짮������ ४��ᨨ.
//(Solution 7)  OK  4.	*������⢮ ������⮢ � �९���⢨ﬨ. ����������� �⥭�� ���ᨢ� � �९���⢨�� � ��宦����� ������⢠ ������⮢.
//(Solution 8)  OK  5.	**�ॡ���� ����� ���� �嬠��� ���� ࠧ��஬ NxM, �ன�� �१ �� ���� ��᪨ �� ������ ࠧ�.
//                      ����� ������ �襭�� ⠪�� �� ��� � � ����� � 8 ����. ������ ⮫쪮 � �஢�થ ��������� ����.

#include <stdio.h>
#include <stdbool.h>
#define N 7
#define VECT_N 8
#define VECT_M 2
#define SIZE 8
#define HORSES 64

char str[33];
int j;
int count;
int map[N][N];
int board[SIZE][SIZE];
int vect[VECT_N][VECT_M] = {    {-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}  };

void DecToBin       (unsigned int n);
void Solution1      ();
int MyPow           (int a, int b);
void Solution2      ();
int RecPow          (int a, int b);
void Solution3      ();
int RecPow2         (int a, int b);
void Solution4      ();
void Solution5      ();
int FromTo          (int n);
void Solution6      ();
void readMap        (int* a);
void PrintMap       ();
void AnalyzeMap     ();
int W               (int a, int b);
void Solution7      ();
void showBoard      ();
bool tryHorse       (int a, int b);
int countWays       (int lastX, int lastY);
int setHorse        (int lastX, int lastY, int a);
void Zero           ();
void Solution8      ();

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
        puts("6. Task 6");
        puts("7. Task 7");
        puts("8. Task 8");
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
//        case 5:
//            Solution5();
//            break;
        case 6:
            Solution6();
            break;
        case 7:
            Solution7();
            break;
        case 8:
            Solution8();
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
// ----------------------------------------------------------------
void DecToBin(unsigned int n) {
    if (n < 1)
        return;
    DecToBin(n / 2);
    str[j++] = n % 2 + '0';
}

void Solution1() {
    system("cls");
    unsigned int n;
    printf("Input N = ");
    fflush(stdin);
    scanf("%u", &n);
    j = 0;
    DecToBin(n);
    str[j] = 0;
    printf("Bin: %s\n", str);
}
// ----------------------------------------------------------------
int MyPow(int a, int b) {
    int result = 1;
    for (int i = 1; i <= b; i++)
        result *= a;
    return result;
}

void Solution2() {
    count = 0;
    system("cls");
    int a, b;
    printf("Input a = ");
    fflush(stdin);
    scanf("%d", &a);
    printf("Input b = ");
    fflush(stdin);
    scanf("%d", &b);
    printf("%d^%d = %d\n", a, b, MyPow(a, b));
}
// ----------------------------------------------------------------
int RecPow(int a, int b) {
    count++;
    if (b < 1)
        return 1;
    return a * RecPow(a, --b);
}

void Solution3() {
    count = 0;
    system("cls");
    int a, b;
    printf("Input a = ");
    fflush(stdin);
    scanf("%d", &a);
    printf("Input b = ");
    fflush(stdin);
    scanf("%d", &b);
    printf("%d^%d = %d\n", a, b, RecPow(a, b));
    printf("Entry in RecPow: %d\n", count);
}
// ----------------------------------------------------------------
int RecPow2(int a, int b) {
    count++;
//  �᫨ ������⥫� �⥯��� ����� 1, �����頥� 1
    if (b < 1)
        return 1;
//  �᫨ ������⥫� �⥯��� ࠢ�� 1, �����頥� a
    if (b == 1)
        return a;
//  �᫨ ������⥫� �⥯��� �����,
    else if (b % 2 != 0) {
            int result = RecPow2(a, b / 2);
            result *= a * result;
            return result;
         }
         else {
//          �᫨ ������⥫� �⥯��� ���
            int result = RecPow2(a, b / 2);
            result *= result;
            return result;
         }
}

void Solution4() {
    system("cls");
    int a, b;
    printf("Input a = ");
    fflush(stdin);
    scanf("%d", &a);
    printf("Input b = ");
    fflush(stdin);
    scanf("%d", &b);
    count = 0;
    if (b % 2 == 0) {
        printf("%d^%d = %d\n", a, b, RecPow2(a, b));
        printf("Entry in RecPow2: = %d\n", count);
    }
    else
        puts("Exponent isn't even");
}
// ----------------------------------------------------------------
void Solution5() {
    system("cls");
}
// ----------------------------------------------------------------
int FromTo (int n) {
    if (n < 3)
        return 0;
    if (n == 3)
        return 1;
    else if (n % 2 == 0)
             return FromTo(n - 1) + FromTo(n / 2);
         else
             return FromTo(n - 1);
}

void Solution6() {
    system("cls");
    printf("3 ->> 20\n");
    printf("There are %d paths\n", FromTo(20));
}
// ----------------------------------------------------------------
void readMap(int* a) {
    FILE *in;
    in = fopen("..\\HomeworkLesson7\\Map.txt","r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            fscanf(in, "%i", a + i * N + j);
    fclose(in);
}

void PrintMap() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

void AnalyzeMap () {
//  �஡����� �� ����
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
//          �᫨ ����� ����祭 ��� ����饭��, �.�. ࠢ�� 0
            if (map[i][j] == 0) {
//              � ��室���� � �㫥��� ��ப�
                if (i == 0)
//                  ����頥� �� ������ �ࠢ�� ����
                    for (int k = j + 1; k < N; k++)
                        map[i][k] = 0;
//              ��� �㫥��� �⮫��
                if (j == 0)
//                  ����頥� �� ������ ���� ����
                    for (int k = i + 1; k < N; k++)
                        map[k][j] = 0;
            }
}

int W(int a, int b) {
    if (map[a][b] != 0)
        if (a < 1 || b < 1)
            return 1;
        else
            return W(a, b - 1) + W(a - 1, b);
    else
        return 0;
}

void Solution7() {
    system("cls");
//  ��⠥� ����� �� 䠩��
    readMap(map);
//  ��������㥬 �����
    AnalyzeMap();
//  PrintMap();
    printf("Count = %d\n", W(N - 1, N - 1));
}
// ----------------------------------------------------------------
// �㭪�� showBoard() �⮡ࠦ��� ���� c ����ࠬ� 室�� ����
void showBoard() {
    for(int a = 0; a < SIZE; ++a) {
        for(int b = 0; b < SIZE; ++b)
            printf("%3d |", board[a][b]);
        printf("\n");
        for(int i = 0; i < SIZE; i++)
            printf("-----");
        printf("\n");
    }
}

// �㭪�� tryHorse() - �஢���� �������� �� ��⠭���� � ����� [a][b]
bool tryHorse(int a, int b) {
    if (a >= 0 && a < SIZE && b >= 0 && b < SIZE)
        if (board[a][b] == 0)
            return true;
    return false;
}

// �㭪�� ������뢠�� ������⢮ ���쭥��� ��⥩
int countWays (int lastX, int lastY) {
    int ways = 0;
    for(int i = 0; i < VECT_N; i++) {
        int x = vect[i][0];
        int y = vect[i][1];
        if (tryHorse(lastX + x, lastY + y))
            ++ways;
    }
    return ways;
}

// �㭪�� setHorse() - �஡�� ���� १����� �襭��.
int setHorse(int lastX, int lastY, int a) { // a - ����� ��।��� ����
    if (a == HORSES + 1)
        return 1;
    int minways = 8;
    int memX, memY;

    for(int i = 0; i < VECT_N; i++) {
        int x = vect[i][0];
        int y = vect[i][1];
        if (tryHorse(lastX + x, lastY + y)) {
            int ways = countWays(lastX + x, lastY + y);
            if (ways < minways) {
                memX = lastX + x;
                memY = lastY + y;
                minways = ways;
            }
        }
    }

    board[memX][memY] = a;
    if (setHorse(memX, memY, a + 1))
        return 1;
    board[memX][memY] = 0;
    return 0;
}

// ��頥� ����
void Zero() {
    for (int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            board[i][j] = 0;
}

void Solution8() {
    system("cls");
//  �����뢠�� 室� ���� ��� ���⮪ �� [0][0] �� [SIZE][SIZE]
    for (int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++) {
            Zero();
            board[i][j] = 1;
            if (setHorse(i, j, 2) == 0)
                printf("[%d][%d] fail\n", i, j);
            else {
                printf("[%d][%d] success\n", i, j);
                showBoard();
                printf("\n");
            }
    }
}
