#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input(); // Declare input function
void show();  // Declare input function
void cal();   // Declare input function

int main() // Main function
{
    int i, j;
    int choice;

    printf("********** Banker's Algorithm ************\n");

    printf("Choose an option:\n");
    printf("1. Optional\n");
    printf("2. Random\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            input();
            break;
        case 2:
            // Generate random values for matrices and resources
            int thang_sinh = 11;
            int ngay_sinh  = 7;
            int N = thang_sinh + ngay_sinh;

            r = 2 + (N % 3);
            n = 3 + (N % 3);

            int k = 15 + (N % 7);

            srand(time(NULL)); // Seed for random numbers

            for (i = 0; i < n; i++) {
                for (j = 0; j < r; j++) {
                    max[i][j] = rand() % (k + 1);
                    alloc[i][j] = rand() % (max[i][j] + 1);
                }
            }

            for (j = 0; j < r; j++) {
                avail[j] = rand() % (k + 1);
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    show();
    cal();

    return 0;
}

void input() // Implement the input function
{
    int i, j;

    printf("Enter the no of Processes: ");
    scanf("%d", &n);
    printf("Enter the no of resources instances: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the available Resources\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() //show the table of the model

{

     int i,j;

     printf("Process\t Allocation\t Max\t Available\t");

     for(i=0;i<n;i++)

     {

          printf("\nP%d\t ",i+1);

          for(j=0;j<r;j++)

          {

          printf("%d ",alloc[i][j]);

          }

          printf("\t");

          for(j=0;j<r;j++)

          {

          printf("%d ",max[i][j]);

          }

          printf("\t");

          if(i==0)

          {

          for(j=0;j<r;j++)

          printf("%d ",avail[j]);

}}}

void cal() //calculate and output the results

{

     int finish[100],temp,need[100][100],flag=1,k,c1=0;

     int safe[100];

     int i,j;

     for(i=0;i<n;i++)

     {

     finish[i]=0;

     }

     //find need matrix

     for(i=0;i<n;i++)

     {

     for(j=0;j<r;j++)

     {

     need[i][j]=max[i][j]-alloc[i][j];

     }}

     printf("\n");

     while(flag)

     {

     flag=0;

     for(i=0;i<n;i++)

     {

     int c=0;

     for(j=0;j<r;j++)

     {

     if((finish[i]==0)&&(need[i][j]<=avail[j]))

     {

     c++;

     if(c==r)

     {

     for(k=0;k<r;k++)

     {

     avail[k]+=alloc[i][j];

     finish[i]=1;

     flag=1;

     }

     printf("P%d->",i);

     if(finish[i]==1)

     {

     i=n;

     }}}}}}

     for(i=0;i<n;i++)

     {

     if(finish[i]==1)

     {

          c1++;

     }else

     {printf("P%d->",i+1);

     }}

     if(c1==n)

     {printf("\n The system is in safe state");

     }

     else

     {

     printf("\n Process are in deadlock");

     printf("\n System is in unsafe state");

}}