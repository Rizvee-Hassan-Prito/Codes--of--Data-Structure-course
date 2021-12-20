#include<stdio.h>
#include<time.h>
#include<math.h>
int isPrimeCount(int n){
    int i,count=0;
    for(i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    int n,m,i,c=0;
    scanf("%d",&n);
    scanf("%d",&m);
    int c1=pow(n,m);
    clock_t start = clock();
    for(i=1;i<=c1;i++){
        if(isPrimeCount(i)==0){
            c++;
        }
    }
    printf("%d\n",c);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);
}
