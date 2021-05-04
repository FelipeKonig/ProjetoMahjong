#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    srand(time(NULL));
    int i,j,z;
    char m[12][12];
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            m[i][j] = '0';
            if(i == 0){
                m[i][j] = '-';
            }else if(i == 11){
                m[i][j] = '-';
            }else if(j == 0){
                m[i][j] = '-';
            }else if(j == 11){
                m[i][j] = '-';
            }else{
                m[i][j] = 0;
            }
        }
    }
    int x;
    int v1[18]={10,10,8,8,8,8,6,6,6,6,4,4,4,4,2,2,2,2};
    char v2[18]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'};
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            x=rand()%18;
            while(v1[x] == 0){
                x=rand()%18;
            }
            m[i][j] = v2[x];
            v1[x] -= 1;
        }
    }
    printf("MAHJONG 2D\n");
    printf("\n");
    for(i=0;i<11;i++){
        for(j=1;j<11;j++){
            if(j == 1)
                printf("%2.d ",i);
            if(i == 0)
                printf("%2.d ",j);
            else
                printf("%2.c ",m[i][j]);
        }
            printf("\n");
    }
    int l1,c1,l2,c2,cont =0;
    while(100 > cont){
            printf("Digite a linha do elemento: ");
            scanf("%d",&l1);
            printf("Digite a coluna do elemento: ");
            scanf("%d",&c1);
            printf("Digite a linha do outro elemento: ");
            scanf("%d",&l2);
            printf("Digite a coluna do outro elemento: ");
            scanf("%d",&c2);

            if(m[l1][c1] == m[l2][c2]){
                    if( m[l1][c1] != '-' || m[l2][c2] != '-'){
                        if(l1 == l2 && c1 != c2 || c1 == c2 && l1 != l2 || l1 != l2 && c1 != c2 || c1 == c2 && l1 != l2){
                            if(m[l1 - 1][c1] == '-' || m[l1 + 1][c1] == '-' || m[l1][c1 - 1] == '-' || m[l1][c1 + 1] == '-'){
                                if(m[l2 - 1][c2] == '-' || m[l2 + 1][c2] == '-' || m[l2][c2 - 1] == '-' || m[l2][c2 + 1] == '-'){
                                    m[l1][c1] = '-';
                                    m[l2][c2] = '-';
                                    cont += 2;
                                    printf("%d elementos removidos\n",cont);
                                    printf("\n");
                                }else{
                                    printf("Sua jogada foi invalida, selecione valores que estao na borda\n");
                                    printf("\n");
                                }
                            }else{
                                printf("Sua jogada foi invalida, selecione valores que estao na borda\n");
                                printf("\n");
                        }
                    }else{
                        printf("Escolha elementos em casas diferentes\n");
                        printf("\n");
                    }
                }else{
                    printf("Selecione elementos validos\n");
                    printf("\n");
                }
            }else{
                printf("Sua jogada foi invalida, selecione valores que sao iguais\n");
                printf("\n");
            }
            for(i=0;i<11;i++){
                for(j=1;j<11;j++){
                    if(j == 1)
                        printf("%2.d ",i);
                    if(i == 0)
                        printf("%2.d ",j);
                    else
                        printf("%2.c ",m[i][j]);
                }
                printf("\n");
            }
    }
    printf("Parabens, voce encerrou o jogo\n");
    return 0;
    }
