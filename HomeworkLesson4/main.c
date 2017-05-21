//	������� ���ᨢ �� 100 ����⮢. ������� �ணࠬ��, ����� ᮤ�ন� �㭪樨 ���
//  1.OK	����� ���ᨢ� � ����������;
//  2.OK	�������� ���ᨢ ��砩�묨 �᫠��;
//  3.OK	������ �㬬� ����⮢;
//  4.OK	������ �।���� ��䬥��᪮� ����⮢;
//  5.OK	��宦����� ����� ��ࢮ�� �����, ����� ���ᨬ��쭮 �⫨砥��� �� �।���� ��䬥��᪮��;
//  6.OK	��室�� ���ᨬ��쭮� �᫮ � ���ᨢ�;
//  7.OK	*���뢠�� ���ᨢ �� 䠩��. � 䠩�� ���� �᫮� ���� ���-�� ����⮢ ���ᨢ�;
//  8.OK	**��室�� �� ����� ����⮢, ����� ���ᨬ��쭮 �⫨����� �� �।���� ��䬥��᪮�� ���ᨢ�;
//    OK    C������ ������ ������� � ���� �㭪樨, � ������ ��।����� ���ᨢ.
//    OK    **��९���� �㭪樨 (�� ��� �������) � �ᯮ�짮������ ��䬥⨪� 㪠��⥫��.
//          !!! ��� ��������� ���ᨢ�� ��।����� �㭪�� 3, 6, 8
//          !!! ��� ��㬥��� ���ᨢ�� �� �蠥��� �१ ��䬥⨪� 㪠��⥫��
//2.  OK    *�믮����� ��ࢮ� ������� ��� ���嬥୮�� ���ᨢ�

#include <stdio.h>
#include "onedimarray.h"
#include "twodimarray.h"

int main()
{
    int choice = 0;
    do {
        system("cls");
        puts("1. One-dimensional");
        puts("2. Two-dimensional");
        puts("0. Exit");
        printf("Select: ");
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            MenuOneDim();
            break;
        case 2:
            MenuTwoDim();
            break;
        case 0:
            break;
        default:
            puts("Invalid choice");
            break;
        }
        system("pause");
    } while (choice != 0);
    return 0;
}
