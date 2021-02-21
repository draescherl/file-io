/*!
  \file students.c
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \brief Student interaction
  \remarks None

  This file stores all the methods needed to interact with students

*/

#include "students.h"



void printStudent(student student_s)
{
  // printf("--- Student info --- \n");
  printf("First name : %s\n", student_s.firstName);
  printf("Last name  : %s \n", student_s.lastName);
  printf("Age        : %d\n", student_s.age);
}

void studentInput(student* student_s)
{
  printf("Enter the student's first name : ");
  stringInput(&student_s->firstName);

  printf("Enter the student's last name  : ");
  stringInput(&student_s->lastName);

  do {
    printf("Enter the student's age (>0)   : ");
    student_s->age = intInput();
  } while (student_s->age <= 0);
}

int inputClass(student** class)
{
  /* Variables */
  int int_nStudents;
  char char_continue;

  /* Initial memory allocation */
  *class = malloc(1 * sizeof(student));
  if (*class == NULL) {
    fprintf(stderr, RED "Error while allocating memory.\n" reset);
    exit(MEMORY_ALLOCATION_ERROR);
  }

  int_nStudents = 0;
  printf("\n");
  do {
    /* Make array bigger to fit as many students as necessary */
    int_nStudents++;
    *class = realloc(*class, int_nStudents * sizeof(student));
    if (*class == NULL) {
      fprintf(stderr, RED "Error while allocating memory.\n" reset);
      exit(MEMORY_ALLOCATION_ERROR);
    }

    /* User input */
    printf("--- Student number %d ---\n", int_nStudents);
    studentInput(&(*class)[int_nStudents - 1]);
    printf("Continue (y/n) ? ");
    char_continue = charInput();
    printf("\n");
  } while (char_continue == 'y');
  
  return(int_nStudents);
}

void printClass(student* class, int int_size)
{
  /* Variables */
  int i;

  for (i = 0; i < int_size; i++) {
    printf("--- Details of student number %d ---\n", i+1);
    printStudent(class[i]);
    printf("\n");
  }
}