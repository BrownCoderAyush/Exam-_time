#include <stdio.h>
#include <stdlib.h>

/*
    Goal is to 
    1. sort the array in decending order 
    2. for each job try to find index maxI in the slot as greater and nearer to deadline as possible 
    
*/
typedef struct Job{
    char id; 
    int deadline;
    int profit;
} job ;


int compare(const void* a, const void* b)
{
    job* temp1 = (job*)a;
    job* temp2 = (job*)b;
    return (temp2->profit - temp1->profit);
}

int main(){

    int slots[2] = {0};
    int total = 0;
     job arr[] = { { 'a', 2, 50 },
                  { 'b', 1, 15 },
                  { 'c', 2, 10 },
                  { 'd', 1, 25 } };
    
    qsort(arr,4,sizeof(job),compare);

    for(int i = 0 ; i < 4 ; i++){
        int deadl = arr[i].deadline;
        int profit = arr[i].profit;
        int maxI = -1;
      
        for(int j = 0 ; j < deadl ; j++){
            if(slots[j] == 0){
                maxI = j;
                
            }
       

        }
        if(maxI != -1){
            slots[maxI] = 1;
            total = total + profit ;
        

        }
      
        
    }

    printf("Total profit is %d",total);
    
    return 0;
    
}