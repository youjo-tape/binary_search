#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i, lb, ub;

  // 入力
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
    
  // 二分探索
  lb = -1, ub = n;
  while(ub - lb > 1){
      int m = (lb+ub)/2;
      if(A[m] >= k) ub = m;
      else lb = m;
  }
    
  // 出力
  printf("%d", ub);
  return 0;
}
