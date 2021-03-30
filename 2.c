#include <stdio.h>
#define MAX_NUM 100

/*
1번 미션의 코드를 그대로 가져와서 insert_value 함수를 제작하세요
알고리즘 정의: 배열은 배열 자체의 크기를 확장하기 힘듭니다. 값을 일일히 밀어내야합니다.
입력1: 4 5 2 5 3 8 2 5 3 7
출력1: 4->5->2->5->3->8->2->5->3->7
      몇번째에 값을 넣으시겠어요?
입력2: 5
출력2: 5번째에 어떤 값을 넣으시겠어요?
입력3: 200
출력3: 4->5->2->5->200->3->8->2->5->3->7
*/

int main()
{
    int a[MAX_NUM]={0,};
    scanf("%d %d %d %d %d %d %d %d %d %d", a, a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);
    for(int i=0; i < sizeof(a)/sizeof(int)-1;i++){
       printf("%d", a[i]);
       if(a[i+1]!=0) printf("->");
       else break;
   }
   int n;
   printf("\nwhich index do you want to put value?\n");
   scanf("%d", &n);
   printf("what do you want to put into index #%d?\n", n);
   int value;
   scanf("%d", &value);
   for(int i = sizeof(a)/sizeof(int); i>=n; i--){
       a[i-1]=a[i-2];
   }
   a[n-1] = value;
   for(int i=0; i < sizeof(a)/sizeof(int);i++){
      printf("%d", a[i]);
      if(a[i+1]!=0) printf("->");
      else break;
  }
}
