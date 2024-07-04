#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    int rollno;
    char name[MAX_NAME_LENGTH];
    float marks;
} Student;

int main() {

    int iterations, comparisons;
    Student students[MAX_STUDENTS] = {
        {1, "Meenal", 85.5},
        {2, "Akash", 78.0},
        {3, "Pranjal", 92.3},
        {4, "Pranshi", 67.4},
        {5, "chinu", 88.9},
        {6, "pooja", 90.0},
        {7, "sanskruti", 75.6},
        {8, "vartika", 80.2},
        {9, "sonam", 95.1},
        {10, "emily", 70.5}
    };

    int n = MAX_STUDENTS;                      //read

    
    sortStudentsByRollNo(students, n, &iterations, &comparisons);
    printStudents(students, n);
    printf("\nIterations = %d, Comparisons = %d\n", iterations, comparisons);


    sortStudentsByMarks(students, n);
printStudents(students, n);
    




    return 0;
}


void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}


void sortStudentsByMarks(Student students[], int n) {
 for (int i = 0; i < n - 1; i++) {
   for (int j = 0; j < n - i - 1; j++) {
         if (students[j].marks > students[j + 1].marks) {
              swap(&students[j], &students[j + 1]);
              }
        }
    }
}

void sortStudentsByRollNo(Student students[], int n, int *iterations, int *comparisons) {
    *iterations = 0;
    *comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        (*iterations)++;
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (students[j].rollno > students[j + 1].rollno) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("RollNo: %d, Name: %s, marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

