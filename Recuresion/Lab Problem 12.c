#include<stdio.h>
void combination(int arr[],int sizeArr,int sub[],int subsize,int idx)
{
    for(int i=0;i<subsize;i++)
    {
        printf("%d ",sub[i]);
    }
    printf("\n");
    for(int i=idx;i<sizeArr;i++)
    {
        sub[subsize]=arr[i];
        subsize++;
        combination(arr,sizeArr,sub,subsize,i+1);
        subsize--;
    }
    return;
}
int main(){
int arr[]={11,3,21};
int sub[100];
combination(arr,3,sub,0,0);
}
