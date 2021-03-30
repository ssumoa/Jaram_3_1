#include <stdio.h>

/*
배열을 선언하고 배열의 순서대로 값을 출력해주는 프로그램을 만드세요
알고리즘 정의: 배열을 사용하세요
입력: 4 5 2 5 3 8 2 5 3 7
출력: 4->5->2->5->3->8->2->5->3->7
*/

int main()
{
    int a[10];
    scanf("%d %d %d %d %d %d %d %d %d %d", a, a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);
    for(int i=0; i < sizeof(a)/sizeof(int);i++){
       printf("%d->", a[i]);
   }

}
