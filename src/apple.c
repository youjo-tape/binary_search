#include <stdio.h>

int n;
int k;
int A[100000];

// x 個のりんごが入るバッグ k 個で足りるかどうかを返す
int p(int x){
    int nBag = 0, i;
    for(i = 0; i < n; i ++) nBag += (A[i]-1)/x + 1;
    return nBag <= k;
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
