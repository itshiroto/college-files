#include<stdio.h>
 int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,totalwt=0,totaltat=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Masukkan berapa banyak proses yang ingin dibuat:");
    scanf("%d",&n);
  
    // Memasukkan Burst Time dari proses proses yang sudah di inisialisasi
    printf("\nMasukkan Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;         
    }
  
    // Proses Shortest Job First
    for(i=0;i<n;i++)
    {
        // Membuat temporary data yaitu pos
        pos=i;
        // Disini kita membandingkan burst time pos atau disini adalah i dan burst time j (i+1) 
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        
        // Ini untuk melakukan sorting SJF JOB mana yang memiliki burst time tercepat akan ditaruh paling depan
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
   
    wt[0]=0;            
  
   // Mendapatkan total waiting time dengan cara melakukan kalkulasi waiting time pada burst time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        totalwt+=wt[i];
    }
  
  
    printf("\nJOB\tBT\tWT\tTaT");
    for(i=0;i<n;i++)
    {
        // tat adalah gabungan dari burst time dan waiting time
        tat[i]=bt[i]+wt[i];   
        // mendapatkan total turn around time
        totaltat+=tat[i];
    }
    
    for(i=0;i<n;i++){
        printf("\np%d\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
    }
  
    printf("\n");
  
    // mendapatkan gambaran job mana yang disolve pertama..
    // hal ini dapat dibentuk sedemikian rupa karena pada soal
    // saya menganggap bahwa soal merupakan SJF non-preemtive
    for(i=0;i<n;i++){
        if(i<n-1){
        printf("p%d > ",p[i]);
        }else{
        printf("p%d",p[i]);
        }
    }
  
    printf("\n");
    
    avg_wt=(float)totalwt/n;      
    avg_tat=(float)totaltat/n;    
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}