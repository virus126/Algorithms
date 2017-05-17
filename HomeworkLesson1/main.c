//1.      Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h),
//        где m-масса тела в килограммах, h - рост в метрах.
//2.      Написать программу обмена значениями двух переменных:
//        a. с использованием третьей переменной;
//        b. *без использования третьей переменной.
//3.      Написать программу нахождения всех корней заданного квадратного уравнения.
//4.      Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
//5.      *С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
//        Требуется определить, относятся ли к поля к одному цвету или нет.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Solution1();
void Solution2a();
void Solution2b();
void Solution3();
void Solution4();
void Solution5();

int main()
{
    int choice = 0;
    do {
        system("cls");
        puts("1. Task 1");
        puts("2. Task 2a");
        puts("3. Task 2b");
        puts("4. Task 3");
        puts("5. Task 4");
        puts("6. Task 5");
        puts("0. Exit");
        printf("Select: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Solution1();
            break;
        case 2:
            Solution2a();
            break;
        case 3:
            Solution2b();
            break;
        case 4:
            Solution3();
            break;
        case 5:
            Solution4();
            break;
        case 6:
            Solution5();
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
    double m, h;
    printf("Input m = ");
    scanf("%lf", &m);
    printf("Input h = ");
    scanf("%lf", &h);
    printf ("Index = %lf\n", m / (h * h));
}

void Solution2a() {
    system("cls");
    int a, b, tmp;
    printf("Input a = ");
    scanf("%d", &a);
    printf("Input b = ");
    scanf("%d", &b);
    tmp = a;
    a = b;
    b = tmp;
    printf("Values after changing:\na = %d\nb = %d\n", a, b);
}

void Solution2b() {
    system("cls");
    int a, b;
    printf("Input a = ");
    scanf("%d", &a);
    printf("Input b = ");
    scanf("%d", &b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("Values after changing:\na = %d\nb = %d\n", a, b);
}

void Solution3() {
    system("cls");
    int a, b, c;
    puts("ax^2 + bx + c = 0");
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    printf("Input c: ");
    scanf("%d", &c);
    double D = pow(b, 2) - (4 * a * c);
    if (D > 0) {
        printf ("x1 = %.1lf\n", (-b + sqrt(D)) / (2 * a));
        printf ("x2 = %.1lf\n", (-b - sqrt(D)) / (2 * a));
    } else  if (D == 0)
                printf ("x = %.1lf\n", (double)-b / (2 * a));
            else
                printf("%s\n", "D < 0, quadratic equation hasn't real roots");
}

void Solution4() {
    system("cls");
    int year;
    printf("Input year: ");
    scanf("%d", &year);
    if ((year >= 5 && year <= 20) || (year >= 105 && year <= 120)) {
        printf("%d %s\n", year, "let"); // лет
    } else {
        int div = year % 10;
        switch (div) {
            case 0:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                printf("%d %s\n", year, "let"); //"лет"
                break;
            case 2:
            case 3:
            case 4:
                printf("%d %s\n", year, "goda"); //года
                break;
            case 1:
                printf("%d %s\n", year, "god"); //"год"
                break;
            default:
                printf("%d %s\n", year, "ololo");
                break;
        }
    }
}

void Solution5() {
    system("cls");
    int x1, x2, y1, y2;
    printf("%s\n", "Input x1:");
    scanf("%d", &x1);
    printf("%s\n", "Input y1:");
    scanf("%d", &y1);
    printf("%s\n", "Input x2:");
    scanf("%d", &x2);
    printf("%s\n", "Input y2:");
    scanf("%d", &y2);
    if (x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7 && x2 >= 0 && x2 <= 7 && y1 >= 0 && y2 <= 7)
        if (((x1 + y1) % 2) == ((x2 + y2) % 2))
            printf("Color is same\n");
        else
            printf("Color is not same\n");
    else
        printf ("Invalid coordinates\n");
}

