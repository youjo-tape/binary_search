#include <stdio.h>

int n;
int k;
int A[100000];

// n 時間の仕事 a を k 人に割り振ったとき、最大の1人の仕事量を x 以下にできるか判定する
int p(int x){
    int kNeed = 1, aSum = 0, i;
    for(i = 0; i < n; i ++){
        if(A[i] > x) return 0;
        
        aSum += A[i];
        if(aSum > x){
            aSum = A[i];
            kNeed ++;
        }
    }
    return kNeed <= k;
}

int main(){
    int i, lb, ub;
  
    // 入力
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    // 二分探索
    lb = 0, ub = 1000000000;
    while(ub - lb > 1){
        int m = (lb+ub)/2;
        if(p(m)) ub = m;
        else lb = m;
    }
    
    // 出力
    printf("%d", ub);
    return 0;
}
