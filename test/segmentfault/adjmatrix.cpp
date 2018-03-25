//
// Created by PC on 2018/1/3.
//

#include<stdio.h>       //
#include<stdlib.h>      // for rand()
#include<time.h>
#define MAX 0x3f3f3f3f
#define vexnum 10000
#define sup 11111

typedef struct n{
    int Adjmatrix[sup][sup];
} MG;

int flag[sup] = {0},n,m;
MG x;

int random_num(int p)
{
    int ran;
    ran = rand() % p + 1;
    return ran;
}

void Dij(int t[],int lw[])
{
    int i,j,k,min;

    for(i = 1; i <= vexnum; i++){
        lw[i] = x.Adjmatrix[1][i];
        t[i] = 1;
    }

    t[0] = -1;
    flag[1]=1;

    for( i=2 ; i <= vexnum ; i++){
        min = MAX;
        for( j=1 ; j<=vexnum ; j++ ){
            if( !flag[j] && lw[j]<min ){
                min = lw[j];
                k = j;
            }
        }
        flag[k] = 1;
        for( j=2; j<=vexnum ; j++){
            if( !flag[j] && min+x.Adjmatrix[k][j] < lw[j] ){
                lw[j] = min + x.Adjmatrix[k][j];
                t[j] = k;
            }
        }
    }
}

int main2()
{
    int i,j,sum=0;
    int path[sup],lowcost[sup];
    int u,v,w,pre;

    srand( (unsigned)time( NULL ) );
    //建立矩阵
    for(i=1;i<=vexnum;i++) {
        for (j = 1; j <= vexnum; j++) {
            x.Adjmatrix[i][j] = MAX;
        }
    }

    // 从第一行开始, 每行取随机次不在对角线上的值, 并随机将其变小
    for(i = 1; i <= vexnum; i++){
        m = random_num(vexnum);
        for(j = 1;j <= m; j++){
            v = random_num(vexnum);
            w = random_num(vexnum);
            if(x.Adjmatrix[i][v] > w && i != v){
                x.Adjmatrix[i][v] = w;
            }
        }
    }

    Dij(path,lowcost);
    for(i = 2; i <= vexnum; i++){
        sum = sum + lowcost[i];
    }
    std::cout<<sum<<std::endl;
    freopen( "lowcost.txt", "w", stdout );
    for(i = 1; i <= vexnum; i++){
        std::cout<<"lowcost["<<i<<"]: "<<lowcost[i]<<std::endl;
    }
    freopen( "path.txt", "w", stdout );
    for(i = 1; i <= vexnum; i++){
        pre = i;
        std::cout<<"v1--v"<<pre<<": "<<lowcost[i]<<std::endl;
        if(lowcost[i] == MAX){
            std::cout<<"v1 to v"<<i<<" has no shortest path"<<std::endl;
        }
        else{
            do {
                std::cout<<"v"<<pre<<"<--";
                pre = path[pre];
            } while(pre != 1);
            std::cout<<"v1"<<std::endl;
        }
    }
    return 0;
}
