#include <stdio.h>

int is_LeapYear(int y);

int main()
{
    int a = 0, b = 5, s = 0;
    int month[13] = {0, 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    char week[7][4] = {"일", "월", "화", "수", "목", "금", "토"};
    int sy, sm, sd;
    int result;

    printf("요일 검색기입니다.\n찾고 싶은 날짜의 연월일을\n[oooo. oo. oo.] 식으로 입력해 주세요.\n");
    scanf("%d. %d. %d.", &sy, &sm, &sd);

    do
    {
        a++;
        if(is_LeapYear(a)) b++; // 윤년 변수 방지용 코드
        b++;
        b %= 7;

    } while(a != sy);

    result = (b + month[sm] + sd) % 7;

    if(is_LeapYear(a)) result--;
    if(result == -1) result = 6;

    printf("이날은 %s요일입니다.", week[result]);
    return 0;
}

int is_LeapYear(int y)
{
    return y%4==0 && y%100!=0 ? 1 : y%400==0 ? 1 : 0;
}
