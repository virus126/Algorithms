//      ���楢 ����ᥩ
//1.	� ���������� �������� ��ப� ᨬ�����:
//(Solution1) OK  a.	� �������� ᨬ���. ������� �ணࠬ��, ����� ������뢠��, ᪮�쪮 ࠧ ᨬ��� �室�� � ��ப�;
//(Solution2) OK  b.	������� �ணࠬ��, ����� ��।����, ���� �� � ��ப� ����� �㪢�;
//(Solution3) OK  c.	������� ᮡ�⢥���� �㭪�� ������ strlen.
//(Solution4) OK  d.	*������� �ணࠬ��, ����� ��।����, ����� ���᭠� �㪢� ����砥��� �� �ᥣ�;
//                e.	**�।�ᬮ����, �� ������� ����� ����� ��������� ��������� ���.
//                      � �⮬ ��砥 �뢥�� ᮮ�饭��, �� ��� �������� ��� ������饩�� ���᭮�.
//(Solution5) OK  2.    a.  **��� ���� ��ப ������ �㭪��, ��।�������, ���� �� ���� ��ப� ����⠭����� ��㣮�.
//                      b.  **������ �⨫���, ����� �蠥� ������ �ਭ���� ��� ��ப�� ����⢥ ��ࠬ��஢
//                          ��������� ��ப�
//(Solution6) OK  3.    **����������� �㭪��, �����⢫����� ᦠ⨥ ��ப�, �� �᭮�� ����稪� ����������� ᨬ�����.
//                      ���ਬ��, ��ப� aabcccccaaa ������ �ॢ������ � a2b1c5a3. �᫨ ᦠ�� ��ப� ����뢠����
//                      ������� ��室���, �㭪�� ������ ������ ��室��� ��ப�.
//(Solution7) OK  4.	*����������� �㭪�� void shift(char *str), ����� �㤥� 横���᪨ ᤢ����� ��ப� ��ࠢ�.
//                      ���ਬ��: �����, �����, �����
//(Solution8) OK  5.	���� ��� 楫��᫥���� ���ᨢ�, 㯮�冷祭��� �� �����⠭��: �[n] � B[m].
//                      ��ନ��� ���ᨢ C[n+m], ����騩 �� ����⮢ ���ᨢ�� � � �, 㯮�冷祭�� �� �����⠭��.
//                      ���ᨢ� A � B ����� �� 䠩��� A.TXT � B.TXT.

//    �����筮 ���� 3 �����. ��ࠩ��� ࠧ������ �ணࠬ�� �� ����ணࠬ��. ��९��뢠�� � ��砫� �ணࠬ��
//    �᫮��� � ᢮� 䠬����. �� �ணࠬ�� ᤥ���� � ����� �襭��. ��� �襭�� ����� �ᯮ����
//    �������塞� ��ப� (string)

#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>

void inputString        (char* str);
int countSymbol         (char* str, char symbol);
void Solution1          ();
int hasVowel            (char* str);
void Solution2          ();
int myStrLen            (char* str);
void Solution3          ();
void Solution4          ();
void Print              (char *str);
void swap               (char* a, char* b);
void sort               (char *str);
_Bool isMix             (char* str1, char* str2);
void Solution5          (int argc, char *argv[]);
void handleCount        (char* resStr, int* j, int count);
void Solution6          ();
void shift              (char *str);
void Solution7();
void printIntArray      (int* A, int N, int* B, int M, int* C);
void readLengthArray    (char* path, int* length);
void readFromFile       (char* path, int* array, int N);
void mergeArray         (int* A, int N, int* B, int M, int* C);
void Solution8          ();

char str[31];

int main(int argc, char *argv[])
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
        case 5:
            Solution5(argc, argv);
            break;
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

void inputString (char* str) {
    printf("Input string (max length 30): ");
    fflush(stdin);
    scanf("%s", str);
    str[30] = 0;
}

int countSymbol (char* str, char symbol) {
    int i = 0;
    int count = 0;
    while (str[i] != 0)
        if (str[i++] == symbol)
            count++;
    return count;
}

void Solution1() {
    system("cls");
    inputString(str);
    char symbol;
    printf("Input symbol: ");
    fflush(stdin);
    scanf("%c", &symbol);
    printf("Count %c: %d\n", symbol, countSymbol(str, symbol));
}

int hasVowel (char* str) {
    int i = 0;
    while (str[i] != 0) {
        char sym = toupper(str[i]);
        if (sym == 65 || sym == 69 || sym == 73 || sym == 79 || sym == 85 || sym == 89)
            return 1;
        i++;
    }
    return 0;
}

void Solution2() {
    system("cls");
    inputString(str);
    if (hasVowel(str) == 0)
        printf("String doesn't contains vowels\n");
    else
        printf("String contains vowels\n");
}

int myStrLen (char* str) {
    int i = 0;
    while (str[i++] != 0) {}
    return i - 1;
}

void Solution3() {
    system("cls");
    inputString(str);
    printf("String length: %d\n", myStrLen(str));
}

void Solution4() {
    system("cls");
    puts("String isn't case sensitive");
    inputString(str);
    int i = 0;
    while (str[i] != 0) {
        str[i] = toupper(str[i]);
        i++;
    }
    int array[6][2] = {     {65, 0}, {69, 0}, {73, 0}, {79, 0}, {85, 0}, {89, 0}    };
    _Bool single = true;
    int max = 0;
    int index = -1;
    for (i = 0; i < 6; i++) {
        array[i][1] = countSymbol(str, (char)array[i][0]);
        if (array[i][1] > max) {
            max = array[i][1];
            index = i;
            single = true;
        } else if (array[i][1] == max) {
                    single = false;
               }
    }
    if (single)
        printf("The most common symbol in string is %c(%d)\n", array[index][0], array[index][1]);
    else
        printf ("String hasn't the most common symbol\n");
}

void Print(char *str) {
    int i = 0;
    while (str[i] != 0) {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void sort(char *str) {
    int i = 1;
    while (str[i] != 0) {
        if (str[i - 1] > str[i]) {
            swap(str + i, str + i - 1);
            int j = i - 1;
            while (j >= 1) {
                if (str[j] < str[j - 1])
                    swap(str + j, str + j - 1);
                else
                    break;
                j--;
            }
        }
        i++;
    }
}

_Bool isMix (char* str1, char* str2) {
    if (myStrLen(str1) != myStrLen(str2))
        return false;
    else {
        int i = 0;
        while (*(str1 + i) != 0) {
            if (*(str1 + i) != *(str2 + i))
                return false;
            i++;
        }
    }
    return true;
}

void Solution5(int argc, char *argv[]) {
    system("cls");
    char str1[30];
    char str2[30];
    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);
    sort(str1);
    sort(str2);
    printf("One string %s a transposition of another string\n", isMix(str1, str2) ? "is" : "isn't");
}

void handleCount (char* resStr, int* j, int count) {
    char string[4];
    int length = 0;
    while (count > 9)
    {
        *(string + length++) = count % 10 + '0';
        count /= 10;
    }
    *(string + length++) = count % 10 + '0';
    for(int i = length - 1; i >= 0; i--) {
        resStr[(*j)++] = *(string + i);
    }
}

void Solution6() {
    system("cls");
    inputString(str);
    char resStr[60];
    int i = 1;
    int j = 0;
    int count = 1;
    char prevSym = *str;
    while(*(str + i) != 0) {
        if (*(str + i) != prevSym) {
            //
            resStr[j++] = prevSym;
            handleCount(resStr, &j, count);
            //
            count = 1;
            prevSym = *(str + i);
        } else
            count++;
        i++;
    }
    resStr[j++] = prevSym;
    handleCount(resStr, &j, count);
    resStr[j] = 0;
    printf("Result string: ");
    Print((i > j) ? resStr : str);
}

void shift (char *str) {
    for(int i = myStrLen(str) - 1; i > 0; i--)
        swap(&str[i], &str[i - 1]);
}

void Solution7() {
    system("cls");
    inputString(str);
    int length = myStrLen(str);
    for(int i = 0; i < length; i++) {
        shift(str);
        printf("-> %d\t%s\n", i + 1, str);
    }
}

void printIntArray(int* A, int N, int* B, int M, int* C) {
    for (int i = 0; i < N || i < M; i++) {
        if (i < N)
            if (i < M)
                printf("A[%d] = %d\tB[%d] = %d\n", i, *(A + i), i, *(B + i));
            else
                printf("A[%d] = %d\n", i, *(A + i));
        else
            if (i < M)
                printf("\t\tB[%d] = %d\n", i, *(B + i));

    }
    puts("-------------------------------------------");
    for (int i = 0; i < N + M; i++)
        printf("C[%d] = %d\n", i, *(C + i));

}

void readLengthArray(char* path, int* length) {
    FILE *in;
    in = fopen(path,"r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    fscanf(in, "%i", length);
}

void readFromFile(char* path, int* array, int N) {
    FILE *in;
    in = fopen(path,"r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    int X;
    fscanf(in, "%i", &X);
    for(int i = 0; i < N; i++)
        fscanf(in, "%i", &array[i]);
    fclose(in);
}

void mergeArray(int* A, int N, int* B, int M, int* C) {
    int i = 0, j = 0, k = 0;
    while (i < N || j < M) {
//      �᫨ ���ᨢ B �����稫��, ������塞 ���ᨢ �
//      ��⠢訬��� ����⠬� ���ᨢ� A
        if (j == M)
            for(i; i < N; i++, k++)
                C[k] = A[i];
//      �᫨ ���ᨢ A �����稫��, ������塞 ���ᨢ �
//      ��⠢訬��� ����⠬� ���ᨢ� B
        if (i == N)
            for(j; j < M; j++, k++)
                C[k] = B[j];
        if (A[i] < B[j])
            C[k++] = A[i++];
        else if (A[i] > B[j])
                 C[k++] = B[j++];
             else {
                 C[k++] = A[i++];
                 C[k++] = B[j++];
             }
    }
}

void Solution8() {
    system("cls");
//    ���塞 � ���뢠�� ����� ���ᨢ�� �� 䠩���
    int N, M;
    readLengthArray("..\\HomeworkLesson6\\A.txt", &N);
    readLengthArray("..\\HomeworkLesson6\\B.txt", &M);
//    ���塞 ���ᨢ� � ������塞 ��
    int A[N], B[M], C[N+M];
    readFromFile("..\\HomeworkLesson6\\A.txt", A, N);
    readFromFile("..\\HomeworkLesson6\\B.txt", B, M);
//    �믮��塞 ᫨ﭨ� ���ᨢ��
    mergeArray(A, N, B, M, C);
//    ���⠥� ���ᨢ�
    printIntArray(A, N, B, M, C);
}
