//Solution1     1.	Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
//              2.	Переписать программу, реализующее двоичное дерево поиска.
//              а)  Добавить в него обход дерева различными способами.
//Solution2     б)  *Добавить в программу обработку командной строки с помощью которой можно указывать из какого файла
//                  считывать данные, каким образом обходить дерево.
//Solution3     3.  Разработать базу данных студентов из трех полей "Имя", "Фамилия", "Возраст", в которой использовать
//                  все знания, полученные на уроках. Считайте данные в двоичное дерево поиска.
//                  Реализуйте поиск по какому-нибудь полю базы данных (фамилия, имя).

#include <stdio.h>
#include <windows.h>
#include <math.h>

// For Task2
typedef struct TNode {
    int value;
    struct TNode* left;
    struct TNode* right;
} Node;
// For Task3
typedef struct Student {
    char fname[15];
    char sname[15];
    int age;
    struct Student* left;
    struct Student* right;
} Student;

typedef struct NodeSearch {
    Student* student;
    struct NodeSearch* next;
} NodeSearch;

// Task1
int hash                            (char* str);
void Solution1                      ();
// Task2
Node* createNode                    (int value);
void addNode                        (Node* head, int value);
void printTree                      (Node* root);
int findRoot                        (int* a, int N);
void preOrderTravers                (Node* root);
void inOrderTravers                 (Node* root);
void postOrderTravers               (Node* root);
int AnalyzeTravers                  (char* str);
void Solution2                      ();
// Task3
Student* createStudent              (Student student);
void addStudentToTree               (Student student);
int findRootStudent                 (Student* a, int N);
void cutOff                         (Student* student);
void createTree                     ();
NodeSearch* createNodeSearch        (Student* student);
void addToSearchList                (Student* student);
void recSearchSurname               (Student* root, char* str);
void recSearchName                  (Student* root, char* str);
void printSearch                    ();
void findStudent                    ();
void addNewStudent                  ();
void Solution3                      ();

int main(int argc, char *argv[])
{
    int choice = 0;
    do {
        system("cls");
        puts("1. Task 1");
        puts("2. Task 2");
        puts("3. Task 3");
        puts("0. Exit");
        printf("Select: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Solution1();
            break;
        case 2:
            Solution2(argc, argv);
            break;
        case 3:
            Solution3();
            break;
        case 0:
            return 0;
        default:
            puts("Invalid choice");
            break;
        }
        system("pause");
    }
    while (choice != 0);
    return 0;
}
// ---------------- TASK1 ----------------
int hash(char* str) {
    int i = 0;
    int sum = 0;
    while(str[i])
        sum += str[i++];
    return sum;
}

void Solution1() {
    system("cls");
    char str[31];
    printf("Input string (max length 30): ");
    fflush(stdin);
    scanf("%s", str);
    str[30] = 0;
    printf("Hash: %d\n", hash(str));
}
// ---------------- TASK2 ----------------
Node* createNode(int value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void addNode(Node* head, int value) {
    if (head == NULL) {
        head = createNode(value);
        return;
    }
    Node* tmp = head;
    while (tmp) {
        if (value > tmp->value) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = createNode(value);
                return;
            }
        } else if (value < tmp->value) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = createNode(value);
                return;
            }
        } else
            exit(2);//value == tmp->value
    }
}

void printTree(Node* root) {
    if (root) {
        printf("%d",root->value);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

int findRoot(int* a, int N) {
//  Вычисляем среднее арифметическое массива
    double average = 0;
    for(int i = 0; i < N; i++)
        average += *(a + i);
    average /= N;
//  Находим индекс элемента, минимальное отличающегося от среднего арифметического
    double div = fabs((double)*a - average);
    double minDiv = div;
    int index = 0;
    for (int i = 1; i < N; i++) {
        div = fabs((double)*(a + i) - average);
        if (div < minDiv) {
            index = i;
            minDiv = div;
        }
    }
    return index;
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->value);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node* root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->value);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(Node* root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->value);
    }
}

int AnalyzeTravers(char* str) {
    if (strcmp(str, "preOrder") == 0)
        return 1;
    if (strcmp(str, "inOrder") == 0)
        return 2;
    if (strcmp(str, "postOrder") == 0)
        return 3;
    return 0;
}

void Solution2(int argc, char *argv[]) {
    system("cls");
//  Если количество параметров меньше двух, выходим
    if (argc < 2) {
         printf("Incorrect command line\n");
         return;
    }
//  Заполняем массив из файла
    FILE *in;
    // path "..\\HomeworkLesson9\\tree.txt"
    in = fopen(argv[1],"r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    int N;
    fscanf(in, "%i", &N);
    int a[N];
    for (int i = 0; i < N; i++)
        fscanf(in, "%i", a + i);
    fclose(in);
//  Находим оптимальный элемент для корня дерева и заполняем дерево
    int index = findRoot(a, N);
    Node* head = createNode(*(a + index));
    for (int i = 0; i < N; i++) {
        if (i == index)
            continue;
        addNode(head, *(a + i));
    }
//  Выбираем способ обхода и печатаем
    switch (AnalyzeTravers(argv[2])) {
        case 1:
            preOrderTravers(head);
            break;
        case 2:
            inOrderTravers(head);
            break;
        case 3:
            postOrderTravers(head);
            break;
        default:
            printf("Incorrect travers");
            break;
    }
    printf("\n");
}
// ---------------- TASK3 ----------------
Student* head;
NodeSearch* headSearch;
int count;
// ---------- Добавление студентов из файла ----------
Student* createStudent(Student student) {
    Student* tmp = (Student*)malloc(sizeof(Student));
    strcpy(tmp->sname, student.sname);
    strcpy(tmp->fname, student.fname);
    tmp->age = student.age;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void addStudentToTree(Student student) {
    if (head == NULL) {
        head = createStudent(student);
        return;
    }
    Student* tmp = head;
    while (tmp) {
        if (strcmp(student.sname, tmp->sname) > 0) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = createStudent(student);
                return;
            }
        } else if (strcmp(student.sname, tmp->sname) < 0) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = createStudent(student);
                return;
            }
        } else
            exit(2);
    }
}

int findRootStudent(Student* a, int N) {
//  Вычисляем среднее арифметическое кодов первых символов фамилий
    double average = 0;
    for(int i = 0; i < N; i++)
        average += a[i].sname[0];
    average /= N;
//  Находим индекс элемента, минимальное отличающегося от среднего арифметического
    double div = fabs((double)a[0].sname[0] - average);
    double minDiv = div;
    int index = 0;
    for (int i = 1; i < N; i++) {
        div = fabs((double)a[i].sname[0] - average);
        if (div < minDiv) {
            index = i;
            minDiv = div;
        }
    }
    return index;
}

// Обрезать лишние символы
void cutOff (Student* student) {
    int j = 0;
    while (student->sname[j] != '\n')
        j++;
    student->sname[j] = '\0';
    j = 0;
    while (student->fname[j] != '\n')
        j++;
    student->fname[j] = '\0';
}

void createTree() {
//  Загружаем студентов из файла в массив
    FILE *in;
    in = fopen("..\\HomeworkLesson9\\students.txt","r");
    if (in == NULL) {
        puts("File not found");
        return;
    }
    int N;
    char c;
    fscanf(in, "%i", &N);
    fscanf(in, "%c", &c);
    Student students[N];
    for (int i = 0; i < N; i++) {
        fgets(students[i].sname, 15, in);
        fgets(students[i].fname, 15, in);
        cutOff(&students[i]);
        fscanf(in, "%i", &students[i].age);
//      "Дочитываем" символ переноса строки
        fscanf(in, "%c", &c);
    }
//  Подбираем корень дерева
    int index = findRootStudent(students, N);
    head = createStudent(students[index]);
//  Заполняем дерево студентами
    for (int i = 0; i < N; i++) {
        if (i == index)
            continue;
        addStudentToTree(students[i]);
    }
    free(students);
}
// ---------- Поиск студентов ----------
NodeSearch* createNodeSearch(Student* student) {
    NodeSearch* tmp = (NodeSearch*)malloc(sizeof(NodeSearch));
    tmp->student = student;
    tmp->next = NULL;
    return tmp;
}

void addToSearchList(Student* student) {
    if (headSearch == NULL) {
        headSearch = createNodeSearch(student);
        return;
    }
    NodeSearch* tmp = headSearch;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = createNodeSearch(student);
}

void recSearchSurname(Student* root, char* str) {
    if (root) {
        recSearchSurname(root->left, str);
        if (strcmp(root->sname, str) == 0) {
            count++;
            addToSearchList(root);
        }
        recSearchSurname(root->right, str);
    }
}

void recSearchName(Student* root, char* str) {
    if (root) {
        recSearchName(root->left, str);
        if (strcmp(root->fname, str) == 0) {
            count++;
            addToSearchList(root);
        }
        recSearchName(root->right, str);
    }
}

void printSearch() {
    NodeSearch* current = headSearch;
    int i = 1;
    while(current) {
        printf("%d. %s %s\n", i++, current->student->sname, current->student->fname);
        current = current->next;
    }
}

void findStudent() {
    Student student;
    int choice = 0;
    do {
        system("cls");
        printf("Search by:\n");
        printf("    1. Surname\n");
        printf("    2. Name\n");
        printf("    0. Back\n");
        printf("Select: ");
        scanf("%i", &choice);
        count = 0;
        headSearch = NULL;
        switch (choice) {
        case 1:
            system("cls");
            printf("Input second name of student: ");
            scanf("%s", student.sname);
            recSearchSurname(head, student.sname);
            break;
        case 2:
            system("cls");
            printf("Input first name of student: ");
            scanf("%s", student.fname);
            recSearchName(head, student.fname);
            break;
        case 0:
            return;
        default:
            printf("Invalid choice\n");
            break;
        }
        if (choice == 1 || choice == 2) {
            printf("We found %d student(s)\n", count);
            printSearch();
        }
        system("pause");
    } while (choice != 0);
}

// ---------- Добавление нового студента ----------
void addNewStudent () {
    system("cls");
    Student student;
    printf("Input first name of student: ");
    scanf("%s", student.fname);
    printf("Input second name of student: ");
    scanf("%s", student.sname);
    printf("Input age of student: ");
    scanf("%i", &student.age);
    addStudentToTree(student);
}

void Solution3() {
    int choice = 0;
    do {
        system("cls");
        puts("1. Load students from file to tree");
        puts("2. Add new student");
        puts("3. Find student");
        puts("0. Back");
        printf("Select: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            createTree();
            break;
        case 2:
            addNewStudent();
            break;
        case 3:
            findStudent();
            break;
        case 0:
            return;
        default:
            puts("Invalid choice");
            break;
        }
        system("pause");
    }
    while (choice != 0);
}
