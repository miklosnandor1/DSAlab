//
// Created by Nandor on 2025. 03. 06
//

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MALE,
    FEMALE
} Gender;

typedef struct {
    int year;
    int month;
    int day;
} Date_t;

typedef struct {
    char name[50];
    char nepfunCode[10];
    char birthPlace[50];
    Date_t dateOfBirth;
    Gender gender;
    double avg;
} Student_t;












///-----------------------------------------------
void readStudentDetails(Student_t *pStudent);
void printStudent(Student_t student);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
void calculatePercentageBoysGirls(Student_t **dpStudents, int numberOfStudents);
void deallocate(Student_t **pStudent);



#endif //STUDENT_H
