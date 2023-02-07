#include <stdio.h>
#include <stdlib.h>

typedef struct Student
    {
        int sNum;
        char sName[20];
        float gpa;
    }Student;

void test(Student *s) {
    s->gpa -= 0.5;
}


int main() {
    Student s1;
    scanf("%d %s %f", &s1.sNum, s1.sName, &s1.gpa);
    printf("%d : %s - %.2f\n", s1.sNum, s1.sName, s1.gpa);

    test(&s1);
    printf("%d : %s - %.2f\n", s1.sNum, s1.sName, s1.gpa);
    
    
return 0;

    
}