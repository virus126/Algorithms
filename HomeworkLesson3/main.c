//1.OK  Написать функцию возведения целого числа a в степень b.
//2.OK  Написать функцию определения, является ли число простым.
//3.OK  * Написать функцию перевода из 2 системы счисления в 10 систему счисления.
//4.OK  * Написать программу подсчёта количества хороших чисел в диапазоне от 1 до 1 000 000.
//      Хорошим называется число, которое делится на сумму своих цифр.
//      Реализовать подсчёт времени выполнения программы.
//5.OK  а) Описать структуру простая дробь. Реализовать функции сложения, вычитания, умножения и деления простых дробей;
//      б)*Добавить упрощение дробей.

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <math.h>
#include "mylib.h"

typedef struct Fraction {
    int numerator;
    int denumerator;
} Fraction;

void Solution1();
_Bool isSimple(int a);
void Solution2();
int from2To10 (char* str);
void Solution3();
void Solution4();
int gcd (int a, int b);
Fraction plusminusFraction (Fraction f1, Fraction f2, _Bool minus);
Fraction mulFraction (Fraction f1, Fraction f2);
Fraction divFraction (Fraction f1, Fraction f2);
Fraction simFraction (Fraction f1);
void Solution5();

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
        case 0:
            break;
        default:
            puts("Invalid choice");
            break;
        }
    }
    while (choice != 0);
    return 0;
}

void Solution1() {
    system("cls");
    int x, y, result;
    printf("Input x: ");
    scanf("%d",&x);
    printf("Input y: ");
    scanf("%d",&y);
    result = x;
    for (int i = 2; i <= abs(y); i++) {
        result *= x;
    }
    y ? : (result = 1);
    (y >= 0) ? printf("%d^%d = %d\n", x, y, result) : printf("%d^%d = %lf\n", x, y, 1.0 / result);
    system("PAUSE");
}

_Bool isSimple(int a) {
    int count = 1;
    for (int i = 2; i <= a; i++)
        if (a % i == 0)
            count++;
    if (count == 2)
        return true;
    return false;
}

void Solution2() {
    system("cls");
    int a;
    do {
        printf("Input a: ");
        scanf("%d",&a);
        if (a < 0)
            puts("Input a > 0");
    } while (a < 0);
    if (isSimple(a))
        printf("Number %d is simple\n", a);
    else
        printf("Number %d is not simple\n", a);
    system("PAUSE");
}

int from2To10(char* str) {
    int length = 0;
    while (str[length] != 0)
        length++;
    int result = 0;
    int exp = 0;
    for(int i = length - 1; i >= 0; i--) {
        if (str[i] == 49)
            result += pow(2, exp);
        exp++;
    }
    return result;
}

void Solution3() {
    system("cls");
    char str[31];
    printf("Input binary string (max length 31): ");
    scanf("%s", str);
    printf("Decimal: %d\n", from2To10(str));
    system("PAUSE");
}

void Solution4() {
    system("cls");
    int a = 1;
    int count = 0;
    time_start();
    while (a <= 1000000) {
        int sum = 0;
        int x = a;
        while (!((x / 10 == 0) && (x % 10 == 0))) {
            sum += x % 10;
            x /= 10;
        }
        if (a % sum == 0)
            count++;
        a++;
    }
    printf("Time: %ld millisecond\n", time_stop());
    printf("Good numbers: %d\n", count);
    system("PAUSE");
}

int gcd (int a, int b) {
    if (a == 0 || b == 0)
        return 1;
    while(a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}

Fraction plusminusFraction (Fraction f1, Fraction f2, _Bool minus) {
    Fraction result;
    if (minus)
        f2.numerator = -f2.numerator;
    if (f1.denumerator == f2.denumerator) {
        result.denumerator = f1.denumerator;
        result.numerator = f1.numerator + f2.numerator;
        return result;
    } else {
        int GCD = gcd(f1.denumerator, f2.denumerator);
        if (GCD == 1)
        {
            result.denumerator = f1.denumerator * f2.denumerator;
            result.numerator = f1.numerator * f2.denumerator + f2.numerator * f1.denumerator;
            return result;
        } else {
            result.denumerator = GCD * (f1.denumerator / GCD) * (f2.denumerator / GCD);
            result.numerator = f1.numerator * (result.denumerator/f1.denumerator) + f2.numerator * (result.denumerator/f2.denumerator);
            return result;
            }
    }
    return result;
}

Fraction mulFraction (Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denumerator = f1.denumerator * f2.denumerator;
    return result;
}

Fraction divFraction (Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denumerator;
    result.denumerator = f1.denumerator * f2.numerator;
    return result;
}

Fraction simFraction (Fraction f1) {
    int GCD = gcd(abs(f1.numerator), abs(f1.denumerator));
    if (GCD != 1) {
        f1.numerator = f1.numerator / GCD;
        f1.denumerator = f1.denumerator / GCD;
    }
    return f1;
}

void Solution5() {
    Fraction f1, f2;
    _Bool flag;
    do {
        system("cls");
        flag = false;
        printf("Numerator of first fraction: ");
        scanf("%d", &f1.numerator);
        printf("Denumerator of first fraction: ");
        scanf("%d", &f1.denumerator);
        printf("Numerator of second fraction: ");
        scanf("%d", &f2.numerator);
        printf("Denumerator of second fraction: ");
        scanf("%d", &f2.denumerator);
        flag = f1.denumerator == 0 || f2.denumerator == 0;
        if (flag) {
            printf("Denumerator < 0, input correct values\n");
            system("PAUSE");
        }
    } while (flag);
    int choice = 0;
    do {
        system("cls");
        Fraction fres;
        printf("First fraction: %d/%d\n", f1.numerator, f1.denumerator);
        printf("Second fraction: %d/%d\n", f2.numerator, f2.denumerator);
        puts("1. +");
        puts("2. -");
        puts("3. *");
        puts("4. /");
        puts("5. Simplify first fraction");
        puts("6. <- Back");
        printf("Select: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            fres = simFraction(plusminusFraction(f1, f2, false));
            break;
        case 2:
            fres = simFraction(plusminusFraction(f1, f2, true));
            break;
        case 3:
            fres = simFraction(mulFraction(f1, f2));
            break;
        case 4:
            fres = simFraction(divFraction(f1, f2));
            break;
        case 5:
            fres = simFraction(f1);
            break;
        case 6:
            return;
        default:
            puts("Invalid choice");
            break;
        }
        if (fres.numerator == 0)
            printf("%d\n", 0);
        else if (fres.numerator == fres.denumerator)
                printf("%d\n", 1);
             else
                printf("%d / %d\n", fres.numerator, fres.denumerator);
        system("PAUSE");
    }
    while (choice != 6);
}

