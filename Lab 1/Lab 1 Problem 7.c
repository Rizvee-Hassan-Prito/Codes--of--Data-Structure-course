#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
     int n, n1 = 2, i, c = 0;
        scanf("%d",  & n);
        clock_t start = clock();
        int *arr;
    arr=(int*)malloc((n+1)*sizeof(int));
        //took n+1 for taking zero
    for (i = 2; i < n + 1; i++) {
            arr[i] = n1;
            n1++;
        }
        for (i = 2; i*i<=n; i++) {
            if (arr[i] == 0) {
                continue;
            } else {
                for(int j=i+1; j<=n; j++){
                    if(arr[j]%i==0){
                        arr[j]=0;
                    }
                }
            }
        }
        for (i = 2; i<=n; i++){if (arr[i] != 0){c++;}}
        printf("Prime Numbers: %d\n", c);
        clock_t end = clock();
        float seconds = (float) (end - start) / CLOCKS_PER_SEC;
        printf("Time taken: %.5f", seconds);
        int number,i1,j;
    printf("\nEnter the number\n");
    scanf("%d",&number);
  start = clock();
/////////////////////////////////////////////////////////////
    int *primes;
    primes=(int*)malloc((number+1)*sizeof(int));
    for(i1 = 2; i1<=number; i1++)
        primes[i1] = i1;

    i1 = 2;
    while ((i1*i1) <= number)
    {
        if (primes[i1] != 0)
        {
            for(j=2; j<=number; j++)
            {
                if (primes[i1]*j > number)
                    break;
                else
                    // Instead of deleteing , making elemnets 0
                    primes[primes[i1]*j]=0;
            }
        }
        i1++;
    }
       int c1=0;
        for(i = 2; i<=number; i++)
    {
        //If number is not 0 then it is prime
        if (primes[i]!=0)
            c1++;
    }
printf("%d\n",c1);
   end = clock();
       seconds = (float) (end - start) / CLOCKS_PER_SEC;
        printf("Time taken: %.5f", seconds);
    return 0;
}
