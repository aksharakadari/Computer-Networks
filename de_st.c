#include<stdio.h>
void main(){
  int a[200],b[100];
  int i,j=0,n;
  int count=0;
  
  printf("enter stuffed frame length:");
  scanf("%d",&n);
  
  printf("enter stuffed frame(0's and 1's only)\n");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<n;i++){
    b[j++]=a[i];
    if(a[i]==1){
      count++;
      if (count==5){
       i++;
       count=0;
      }
    }
    else{
     count=0;
    }
  }
  
  printf("\n after bit destuffing,the frame is:\n");
  for(i=0;i<j;i++){
     printf("%d",b[i]);
  }
  printf("\n");
}

