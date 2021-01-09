#include <stdio.h>

/*
*線形探索法（linear search）
*/

struct 
{
    int key;
    int data;
}table[100];

int n;      /*tableに登録されているデータの個数*/
int main(int key)
{
    int i;
    
    i = 0;
    while(i < n){
        if (table[i].key == key)
            return (table[i].data);     /*見つかった*/
        i++;
    }
    return -1;                          /*見つからなかった*/
}

