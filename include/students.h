/*!
  \file students.h
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \brief Header file for students.c
  \remarks None
*/

#ifndef _STUDENTS_H_
#define _STUDENTS_H_

/* Additional librairies */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

/* Global variables */


/* Function prototypes */
/*!
  \fn void printStudent(student student_s)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param student_s The student
  \brief Print student details
  \remarks None
*/
void printStudent(student student_s);

/*!
  \fn void studentInput(student* student_s);
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param student_s A student
  \brief Prompts the user for information regarding a student and stores it
  \remarks None
*/
void studentInput(student* student_s);

/*!
  \fn int inputClass(student** class)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param class The class of students
  \return The size of the class
  \brief Allows the user to input the size of the class and 
  the details of each student
  \remarks None
*/
int inputClass(student** class);

/*!
  \fn void printClass(student* class, int int_size)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param class The class to display
  \param int_size The size of the class
  \brief Print class to the terminal
  \remarks None
*/
void printClass(student* class, int int_size);


#endif