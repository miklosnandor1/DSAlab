//
// Created by Nandor on 2025. 03. 06
//

#include <stdio.h>
#include <stdlib.h>

#include "student.h"



void readStudentDetails(Student_t *pStudent) {

    printf("Enter student name: ");
    scanf(" %[^\n]", pStudent->name);
    printf("Enter Nepfun code: ");
    scanf(" %s", pStudent->nepfunCode);
    printf("Enter birth place: ");
    scanf(" %[^\n]", pStudent->birthPlace);
    printf("Enter date of birth (YYYY MM DD): ");
    scanf("%d %d %d", &pStudent->dateOfBirth.year, &pStudent->dateOfBirth.month, &pStudent->dateOfBirth.day);
    printf("Enter gender (0 for MALE, 1 for FEMALE): ");
    int gender;
    scanf("%d", &gender);
    pStudent->gender = (gender == 0) ? MALE : FEMALE;
    printf("Enter exam result: ");
    scanf("%lf", &pStudent->avg);

}

void printStudent(Student_t student) {
    printf("Name: %s\n", student.name);
    printf("Nepfun Code: %s\n", student.nepfunCode);
    printf("Birth Place: %s\n", student.birthPlace);
    printf("Date of Birth: %04d-%02d-%02d\n", student.dateOfBirth.year, student.dateOfBirth.month, student.dateOfBirth.day);
    printf("Gender: %s\n", student.gender == MALE ? "MALE" : "FEMALE");
    printf("Exam Result: %.2f\n", student.avg);
}

void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents) {
    *dpStudents = (Student_t *)malloc(numberOfStudents * sizeof(Student_t));
    if (*dpStudents == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input) {
    FILE *file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(file, "%d", numberOfStudents);
    allocateMemoryForStudents(dpStudents, *numberOfStudents);

    for (int i = 0; i < *numberOfStudents; i++) {
        fscanf(file, " %[^\n]", (*dpStudents)[i].name);
        fscanf(file, " %s", (*dpStudents)[i].nepfunCode);
        fscanf(file, " %[^\n]", (*dpStudents)[i].birthPlace);
        fscanf(file, "%d %d %d", &(*dpStudents)[i].dateOfBirth.year, &(*dpStudents)[i].dateOfBirth.month, &(*dpStudents)[i].dateOfBirth.day);
        int gender;
        fscanf(file, "%d", &gender);
        (*dpStudents)[i].gender = (gender == 0) ? MALE : FEMALE;
        fscanf(file, "%lf", &(*dpStudents)[i].avg);
    }

    fclose(file);
}

void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination) {
    FILE *file = fopen(destination, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < numberOfStudents; i++) {
        fprintf(file, "Name: %s\n", pStudents[i].name);
        fprintf(file, "Nepfun Code: %s\n", pStudents[i].nepfunCode);
        fprintf(file, "Birth Place: %s\n", pStudents[i].birthPlace);
        fprintf(file, "Date of Birth: %04d-%02d-%02d\n", pStudents[i].dateOfBirth.year, pStudents[i].dateOfBirth.month, pStudents[i].dateOfBirth.day);
        fprintf(file, "Gender: %s\n", pStudents[i].gender == MALE ? "MALE" : "FEMALE");
        fprintf(file, "Exam Result: %.2f\n", pStudents[i].avg);
        fprintf(file, "\n");
    }

    fclose(file);
}

void calculatePercentageBoysGirls(Student_t **dpStudents, int numberOfStudents) {
    int boys = 0, girls = 0;
    for (int i = 0; i < numberOfStudents; i++) {
        if ((*dpStudents)[i].gender == MALE) {
            boys++;
        } else {
            girls++;
        }
    }
    printf("Percentage of boys: %.2f%%\n", (boys * 100.0) / numberOfStudents);
    printf("Percentage of girls: %.2f%%\n", (girls * 100.0) / numberOfStudents);
}

void deallocate(Student_t **pStudent) {
    free(*pStudent);
    *pStudent = NULL;
}