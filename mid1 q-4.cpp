#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
int main(){
    int X;
    printf("Enter last 3 digit Of your student id:");
    scanf("%d",&X);
    int a[11];
    a[0] = (X % 5) + 12;
    a[1] = (X % 3) + 8;
    a[2] = (X % 7) -15;
    a[3] = (X % 11) - 7;
    a[4] = (X % 9) * 4;
    a[5] = (X % 6) - 9;
    a[6] = 0;
    a[7] = (X % 5) + 5;
    a[8] = (X % 3) + 12;
    a[9] = 0;
    a[10] = (X % 5) - 8;
    printf("\n\nData: ");
    for(int i=0;i<=10;i++) printf("%d ",a[i]);
    printf("\n");
    stack<int> S1;
    queue<int> Q1;
    for(int i=0;i<11;i++)
    {
        if(a[i]>=0)
        {
            S1.push(a[i]);
        }
        else{
            if(!S1.empty()) S1.pop();
            while(!S1.empty()){
                int x = S1.top();
                Q1.push(x);
                S1.pop();
            }
        }
    }

    while(!Q1.empty()){
        int y = Q1.front();
        Q1.pop();
        if(y==0) break;
        S1.push(y);
    }
    printf("S:");
    while(!S1.empty())
    {
        printf("%d ",S1.top());
        S1.pop();
    }

    printf("\nQ:");
    while(!Q1.empty())
    {
        printf("%d ",Q1.front());
        Q1.pop();
    }
}
