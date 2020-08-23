#include <stdio.h>

int main()
{
    int marks[5],i,sum=0;
    float avg;
    char grade;
    printf("Enter your marks in 5 Subjects (Math,Physics,Chemistry,Programming,English)\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&marks[i]);
        sum = sum + marks[i];
    }
    avg = sum / 5 ;

   if(avg >= 90)
    {
        grade = 'A';
    }
    else if(avg >= 80 && avg < 90)
    {
        grade = 'B';
    }
    else if(avg >= 70 && avg < 80)
    {
        grade = 'C';
    }
    else if(avg >= 60 && avg < 70)
    {
        grade = 'D';
    }
    else if(avg >= 50 && avg < 60)
    {
        grade = 'E';
    }
    else 
    {
        grade = 'F';
    }
    
    printf("You scored %f percentage\n",avg);                
    printf("Your grade is %c \n", grade);   
}
