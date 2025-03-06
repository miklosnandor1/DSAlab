#include <stdio.h>
#include "student.h"

int main(void) {



    Student_t student1 = {
        .name = "Miklos Nandor",
        .nepfunCode = "MP2ER7",
        .birthPlace = "karcfalva",
        .dateOfBirth = {2001, 3, 10},
        .gender = MALE,
        .avg = 5.70
    };



    printStudent(student1);

    Student_t student2;
    readStudentDetails(&student2);

    printStudent(student2);

    Student_t *students;
    int numberOfStudents;
    readAllStudentsDetails(&students, &numberOfStudents, "input.txt");

    printAllStudents(students, numberOfStudents, "CON");

    calculatePercentageBoysGirls(&students, numberOfStudents);

    deallocate(&students);

    return 0;
}
