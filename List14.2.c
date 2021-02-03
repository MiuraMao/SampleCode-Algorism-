#include <stdio.h>
/*非再帰版クイックソート*/

int partition(int a[], int l, int r)
{
    int i, j, pivot, t;

    /*ポインタiとjを初期化する*/
    i = l -1;
    j = r;
    /*いちばん右端の要素を枢軸にする*/
    pivot = a[r];
    /*ポインタiとjがぶつかるまで繰り返す*/
    for (;;){
        /*ポインタiを右へ進める*/
        while (a[++i] < pivot)  //条件αを成立させる要素βをあらかじめ配列の要素の最後に入れる技法を「番兵」という
            ;
        /*ポインタjを左へ進める*/
        while (i < j-- && pivot < a[j])     //jが左端まで到達した時に、左端から突き出ないようにする
            ;
        /*ポインタiとjがぶつかったらループを抜ける*/
        if (i >= j)
            break;
        /*iの指す要素とjの指す要素を交換する*/
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    /*a[i]と枢軸を交換する*/
    t = a[i]; a[i] = a[r]; a[r] = t;
    return i;
}

/*配列aをクイックソートする*/
void quick_sort_2(int a[], int n)
{
    int l, r, v;
    int low[30], high[30];
    int sp;

    /*スタックを初期化する*/
    low[0] = 0;
    high[0]= n - 1;
    sp = 1;

    /*スタックが空になるまで繰り返す*/
    while (sp > 0){

        /*スタックから、整列する範囲を取り出す*/
        sp--;
        l = low[sp];
        r = high[sp];

        //printf("%d...%d", l, r);

        /*整列要素が１つなら、何もしない（再びwhile文を実行する）*/
        if (l >= r)
            ;
        else{
            /*枢軸vを基準に分割する*/
            v = partition(a, l, r);

            /*左、右の順番で部分配列を整列する（スタックなので、「右左」の順に積むことに注意）*/
            low[sp] = v + 1;
            high[sp++] = r;
            low[sp] = l;
            high[sp++] = v - 1;     
        }
    }
}

void main(int a[], int n)
{
    quick_sort_2(a, n);
}
