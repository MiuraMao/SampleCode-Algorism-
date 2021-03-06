#include <stdio.h>
/*再帰版クイックソート*/
//安定な整列アルゴリズムでない

/*配列a[l]~a[r]を分割する。枢軸の添え字を返す*/
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

/*実際にクイックソートを行う関数*/
void quick_sort_1(int a[], int l, int r)
{
    int v;

    //printf("%d...%d", l, r);

    /*整列する要素が１つなら、何もしないでリターンする*/
    if (l > r)
        return;
    
    /*枢軸vを基準に分割する*/
    v = partition(a, l, r);

    /*左の部分配列a[l]~a[v-1]を整列する*/
    quick_sort_1(a, l, v-1);

    /*右の部分配列a[v+1]~a[r]を整列する*/
    quick_sort_1(a, v+1, r);
}

/*クイックソート*/
void main(int a[], int n)
{
    quick_sort_1(a, 0, n - 1);
}
