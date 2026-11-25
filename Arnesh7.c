#include <stdio.h>

#define MAX 100

struct Student
{
    int roll_no;
    char name[50];
    float marks[3];
    float total;
    float percentage;
};

int main()
{
    struct Student s[MAX];
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of students.");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter roll number: ");
        scanf("%d", &s[i].roll_no);

        printf("Enter name: ");
        scanf(" %49[^\n]", s[i].name);

        s[i].total = 0;

        printf("Enter marks of 3 subjects: ");
        for (j = 0; j < 3; j++)
        {
            scanf("%f", &s[i].marks[j]);
            s[i].total = s[i].total + s[i].marks[j];
        }

        s[i].percentage = (s[i].total / 300.0) * 100;
    }

    printf("\n--- Student Result ---\n");

    printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s\n",
           "Roll No", "Name", "Sub1", "Sub2", "Sub3", "Total", "Percent");

    for (i = 0; i < n; i++)
    {
        printf("%-10d %-20s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n",
               s[i].roll_no,
               s[i].name,
               s[i].marks[0],
               s[i].marks[1],
               s[i].marks[2],
               s[i].total,
               s[i].percentage);
    }

    return 0;
}
