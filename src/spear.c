#include <stdio.h>

int n;
int k;
int A[100000];

// 長さ x の槍を k 本作れ"ない"かどうかを返す
int p(int x){
    int nSpear = 0, i;
    for(i = 0; i < n; i ++) nSpear += A[i]/x;
    return nSpear < k;
}

int main(){
    int i, lb, ub;
  
    // 入力
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
  
    // 二分探索
    lb = 0, ub = 1000000001;
    while(ub - lb > 1){
        int m = (lb+ub)/2;
        if(p(m)) ub = m;
        else lb = m;
    }
    
    // 出力
    printf("%d", lb);
    return 0;
}
