//
// Created by PC on 2018/1/3.
//

#include <stdio.h>
void main3()
{
    int arr[2][3] = {1 , 2 , 3 , 4 , 5 , 6};
    int *p = &arr[0][0];
    // 下标方式访问
    for (int i = 0; i < 6; i++)
    {
        printf("arr[%d] = %d\n" , i , i[p]);
    }
}