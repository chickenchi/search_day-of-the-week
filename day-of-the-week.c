#include <stdio.h>

int is_LeapYear(int y);

int main()
{
    int a = 0, b = 5, s = 0;
    int month[13] = {0, 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    char week[7][4] = {"��", "��", "ȭ", "��", "��", "��", "��"};
    int sy, sm, sd;
    int result;

    printf("���� �˻����Դϴ�.\nã�� ���� ��¥�� ��������\n[oooo. oo. oo.] ������ �Է��� �ּ���.\n");
    scanf("%d. %d. %d.", &sy, &sm, &sd);

    do
    {
        a++;
        if(is_LeapYear(a)) b++; // ���� ���� ������ �ڵ�
        b++;
        b %= 7;

    } while(a != sy);

    result = (b + month[sm] + sd) % 7;

    if(is_LeapYear(a)) result--;
    if(result == -1) result = 6;

    printf("�̳��� %s�����Դϴ�.", week[result]);
    return 0;
}

int is_LeapYear(int y)
{
    return y%4==0 && y%100!=0 ? 1 : y%400==0 ? 1 : 0;
}
