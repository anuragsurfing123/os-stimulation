#include <stdio.h>
int main() 
{
 int i,j,a[10],b[10],temp[10],tat[10],wat[10],temp1,avg=0,tt=0,n;
  
 printf("enter the number of Processes:\n");
 scanf("%d",&n); 
 printf("enter arrival time\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]); 
 printf("enter burst time\n");
 for(i=0;i<n;i++)
 scanf("%d",&b[i]); 
 for(i=1;i<n;i++)
  for(j=1;j<n;j++)
   if(b[j]>b[j+1])
   {
    temp1=b[j];
    b[j]=b[j+1];
    b[j+1]=temp1;
   } 
 temp[0]=0;
 for(i=0;i<n;i++)
  temp[i+1]=temp[i]+b[i];
 printf("\ncompletion time\n");
 for(i=1;i<n+1;i++)
  printf("\n%d",temp[i]);
  
  tat[0]=0;
  printf("\nTurnarround time\n");//completion-arrival
 for(i=1;i<n+1;i++){

 tat[i]=(temp[i]-a[i]);
  printf("\n%d",tat[i]); }
 
 wat[0]=0;
 printf("\nwating time\n");//tat-burst
 for(i=1;i<n+1;i++){

 wat[i]=(tat[i]-b[i]);
  printf("\n%d",wat[i]); }
 
 
 for(i=1;i<n;i++)
  avg=avg+temp[i]-a[i];
 avg=avg/n;
 printf("\nThe Average WT is %d ms",avg);
  
 for(i=2;i<n+1;i++)
 tt=tt+temp[i]-a[i-1];
 tt+=temp[1];
 tt=tt/n;
 printf("\nThe Average TT is %d ms",tt);
return 0; 
}
