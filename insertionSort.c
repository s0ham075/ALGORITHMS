#include <stdio.h>
#include <math.h>
#include <time.h>
void insertionSort(long  array[],long n){
   if(n==1 || n==0) return ;
   for(long i=1;i<n;i++){
      long correctPos = -1;
      for(long j=0;j<=i-1;j++){
        if(array[i]<array[j]){
            correctPos=j;
            break;
        }
     }
     if(correctPos != -1){
        long temp = array[i];
        for(long j= i;j>=correctPos;j--){
           array[j]=array[j-1];
        }
        array[correctPos] = temp;
     }
   }
}


long main (){
    long  n = pow(2,10);
    long bestCase[n];
    long worstCase[n];
    clock_t start ,end, s, e;
    for(long i=0;i<n;i++){
        bestCase[i]=i;
        worstCase[i]=n-i;
    }
    start = clock();
    insertionSort(bestCase,n);
    end = clock();
    double timeTakenBestCase =(double)( end - start )/CLOCKS_PER_SEC;
    s = clock();
    insertionSort(worstCase,n);
    e = clock();
    double timeTakenWorstCase = (double)(e-s)/CLOCKS_PER_SEC;
    printf("Time taken by best case  - %f",timeTakenBestCase);
    printf("Time taken by worst case - %f",timeTakenWorstCase);

    return 0;
}