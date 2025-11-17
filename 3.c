#include<stdio.h>
#include<stdlib.h>
void towerOfHanoi(int n,char fromtower,char totower,char auxtower){
if(n==1){
    printf("\nMove disc 1 from tower %c to tower %c ",fromtower,totower);
    return;
}
towerOfHanoi(n-1,fromtower,auxtower,totower);
printf("\nmove disc %d from tower %c to tower %c",n,fromtower,totower);
towerOfHanoi(n-1,auxtower,fromtower,totower);
}
int main(){
    int n;
    printf("\nenter the no. of disks\n");
    scanf("%d",&n);
    printf("\nthe steps to be performed\n");
    towerOfHanoi(n,'a','b','c');
}
