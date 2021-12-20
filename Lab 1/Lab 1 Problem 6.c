#include<stdio.h>
#include<time.h>
#include<math.h>
int isPrimeCount(int n){
    int i,count=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==0){
        return 0;
    }
    else{
        return 1;
    }
}
int isPrimeFlag(int n){
    int i,flag=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
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
    for(i=2;i<=c1;i++){
        if(isPrimeFlag(i)==0){
            c++;
        }
    }
    printf("%d\n",c);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);
}
