/*
���ѹα� �ر��� ���� �ؾ��ȣ�� ���� 24�ð� 356�� �츮�� �ٴٸ� ��Ű�� �ִ�. �ѱ��� ���� �������� ����������� ���� 28���� ���� �� ������ ����� 3�븦 �߰��ߴ�.
��� ������ġ�� �Ϸ��� ����������� ���������� �̻��� �߻縦 ���� SonarDetector()�Լ��� �����Ͽ� �ҳ� Ž�������� �����ϰ� A,B,C�� ǥ�õ� ��������� ��Ȯ�� ��ǥ�� �Է��ϰ����Ѵ�.
�����Ҵ��� �̿��� �� ������� �ѷ��� X�� �ѷ� �ε��� �����ϰ�
������ ������ Oǥ�ø� �ؼ� �Ʊ��� ��� ��ȣ�϶�
���:
������� A �ı�!
������� B �ı�!
������� C �ı�!
������ġ ����, �� ����� ħ�� Ȯ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************�� �Լ����� �ǵ帮�� ������***********************************************************/
void SonarDetector()
{
    printf("����! �ѿ� ������ġ! ����!\n\n");
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
        printf("������� A �ı�!\n");
        count++;
    }
    if (Submarine_pos[9][2] == 'X' && Submarine_pos[9][3] == 'B' && Submarine_pos[9][4] == 'X' && Submarine_pos[8][2] == 'X' && Submarine_pos[8][3] == 'X' && Submarine_pos[8][4] == 'X' && Submarine_pos[10][2] == 'X' && Submarine_pos[10][3] == 'X' && Submarine_pos[10][4] == 'X')
    {
        printf("������� B �ı�!\n");
        count++;
    }
    if (Submarine_pos[14][16] == 'X' && Submarine_pos[14][17] == 'C' && Submarine_pos[14][18] == 'X' && Submarine_pos[13][16] == 'X' && Submarine_pos[13][17] == 'X' && Submarine_pos[13][18] == 'X' && Submarine_pos[15][16] == 'X' && Submarine_pos[15][17] == 'X' && Submarine_pos[15][18] == 'X')
    {
        printf("������� C �ı�!\n");
        count++;
    }
    if (count == 3)
    {
        printf("������ġ ����, �� ����� ħ�� Ȯ��\n");
    }
    else
    {
        printf("���� Ÿ��� ��ڷ� ���� �İ��߻�! �� �¹��� ������� �϶�.. �Ǥ���..\n");
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

/*****************************************************�� �Լ����� �ǵ帮�� ������***********************************************************/

int main()
{
    SonarDetector();
    printf("\n-------------------------------------------\n");
    /*���� �޴���*/
    //1. char�� 16 X 20 ũ�� ���� �迭�� ���� �Ҵ��ϰ� �� ������� ��ġ�� ã�� �� A,B,C�� �Է��Ͻÿ�.
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

    printf("----�迭 �ʱ�ȭ �Ϸ�----\n\n");

    //2. �� ����� �ֺ��� X ���ڷ� �ٲٴ� �Լ� MarxX�� ����ÿ�.

    //[����]�� ����� ��ǥ
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

    printf("----�� ����� Ž�� �Ϸ�----\n");

    //3. ����� �ı� ���θ� Ȯ���϶�

    printWarResult(Submarine_pos);

    free(Submarine_pos);
    return 0;

}
