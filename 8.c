/*
대한민국 해군은 조국 해양수호를 위해 24시간 356일 우리의 바다를 지키고 있다. 한국의 대형 이지스함 세종대왕함은 서해 28구역 순찰 중 북한의 잠수함 3대를 발견했다.
즉시 전투배치를 완료한 세종대왕함의 승조원들은 미사일 발사를 위해 SonarDetector()함수를 실행하여 소나 탐지정보를 열람하고 A,B,C로 표시된 적잠수함의 정확한 좌표를 입력하고자한다.
동적할당을 이용해 적 잠수함의 둘레를 X로 둘러 싸도록 설정하고
나머지 구역은 O표시를 해서 아군과 어선을 보호하라
출력:
적잠수함 A 파괴!
적잠수함 B 파괴!
적잠수함 C 파괴!
전투배치 해제, 적 잠수함 침몰 확인
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************이 함수들은 건드리지 마세요***********************************************************/
void SonarDetector()
{
    printf("실전! 총원 전투배치! 실전!\n\n");
    printf("   01234567890123456789\n");
    printf("0  0OOOOOOOOOOOOOOOOOOO\n");
    printf("1  0OOOOOOOOOOOOOOOOOOO\n");
    printf("2  0OOOOOOAOOOOOOOOOOOO\n");
    printf("3  0OOOOOOOOOOOOOOOOOOO\n");
    printf("4  0OOOOOOOOOOOOOOOOOOO\n");
    printf("5  0OOOOOOOOOOOOOOOOOOO\n");
    printf("6  0OOOOOOOOOOOOOOOOOOO\n");
    printf("7  0OOOOOOOOOOOOOOOOOOO\n");
    printf("8  0OOOOOOOOOOOOOOOOOOO\n");
    printf("9  0OOOBOOOOOOOOOOOOOOO\n");
    printf("10 0OOOOOOOOOOOOOOOOOOO\n");
    printf("11 0OOOOOOOOOOOOOOOOOOO\n");
    printf("12 0OOOOOOOOOOOOOOOOOOO\n");
    printf("13 0OOOOOOOOOOOOOOOOOOO\n");
    printf("14 0OOOOOOOOOOOOOOOOCOO\n");
    printf("15 0OOOOOOOOOOOOOOOOOOO\n");

}

void printWarResult(char **Submarine_pos)
{
    int count = 0;
    if (Submarine_pos[2][6] == 'X' && Submarine_pos[2][7] == 'A' && Submarine_pos[2][8] == 'X' && Submarine_pos[1][6] == 'X' && Submarine_pos[1][7] == 'X' && Submarine_pos[1][8] == 'X' && Submarine_pos[3][6] == 'X' && Submarine_pos[3][7] == 'X' && Submarine_pos[3][8] == 'X')
    {
        printf("적잠수함 A 파괴!\n");
        count++;
    }
    if (Submarine_pos[9][2] == 'X' && Submarine_pos[9][3] == 'B' && Submarine_pos[9][4] == 'X' && Submarine_pos[8][2] == 'X' && Submarine_pos[8][3] == 'X' && Submarine_pos[8][4] == 'X' && Submarine_pos[10][2] == 'X' && Submarine_pos[10][3] == 'X' && Submarine_pos[10][4] == 'X')
    {
        printf("적잠수함 B 파괴!\n");
        count++;
    }
    if (Submarine_pos[14][16] == 'X' && Submarine_pos[14][17] == 'C' && Submarine_pos[14][18] == 'X' && Submarine_pos[13][16] == 'X' && Submarine_pos[13][17] == 'X' && Submarine_pos[13][18] == 'X' && Submarine_pos[15][16] == 'X' && Submarine_pos[15][17] == 'X' && Submarine_pos[15][18] == 'X')
    {
        printf("적잠수함 C 파괴!\n");
        count++;
    }
    if (count == 3)
    {
        printf("전투배치 해제, 적 잠수함 침몰 확인\n");
    }
    else
    {
        printf("선저 타기실 어뢰로 인한 파공발생! 전 승무원 비상이함 하라.. 실ㅈㅓ..\n");
    }
}


void MarkX(char **ch, int i, int j){
    for( int m=0; m<3; m++){
        for(int n=0; n<3; n++){
            if(!(m==1 && n==1)) *(*(ch+m+i-1)+n+j-1) = 'X';
        }
    }
}

void printarray(char **ch){
    printf("   01234567890123456789\n");
    char** Submarine_pos = ch;
    for(int i=0; i<16; i++){
        if(i>=10) printf("%d ",i);
        else printf("%d  ",i);
        for(int j=0; j<20; j++){
            if(j!=19) {  printf("%c", *(*(Submarine_pos+i)+j));}
            else{printf("%c\n", *(*(Submarine_pos+i)+j));}
        }
    }
}

/*****************************************************이 함수들은 건드리지 마세요***********************************************************/

int main()
{
    SonarDetector();
    printf("\n-------------------------------------------\n");
    /*전투 메뉴얼*/
    //1. char형 16 X 20 크기 이중 배열을 동적 할당하고 적 잠수함의 위치를 찾아 각 A,B,C를 입력하시오.
    char **Submarine_pos;
    Submarine_pos = (char **)malloc(sizeof(char*)*16);


    // for(int i =0; i<16; i++){
    //     *(Submarine_pos +i) = (char *)calloc(20,sizeof(char));
    // }

    for(int i =0; i<16; i++){
        *(Submarine_pos +i) = (char*)malloc(sizeof(char)*20);
        memset(*(Submarine_pos+i), 'O',(sizeof(char)*20));
    }


    printarray(Submarine_pos);

    printf("----배열 초기화 완료----\n\n");

    //2. 적 잠수함 주변을 X 문자로 바꾸는 함수 MarxX를 만드시오.

    //[참고]적 잠수함 좌표
    //Submarine_pos[2][7] == 'A'
    //Submarine_pos[9][3] == 'B'
    //Submarine_pos[14][17] == 'C'


    *(*(Submarine_pos+2)+7) = 'A';
    *(*(Submarine_pos+9)+3) = 'B';
    *(*(Submarine_pos+14)+17) = 'C';


    int ax = 2, ay = 7;
    int bx = 9, by = 3;
    int cx = 14, cy = 17;


    MarkX(Submarine_pos, ax, ay);
    MarkX(Submarine_pos, bx, by);
    MarkX(Submarine_pos, cx, cy);

    printarray(Submarine_pos);

    printf("----적 잠수함 탐지 완료----\n");

    //3. 잠수함 파괴 여부를 확인하라

    printWarResult(Submarine_pos);

    free(Submarine_pos);
    return 0;

}
