/*!
  \file fileIO.h
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \brief Header file for fileIO.c
  \remarks None
*/

#ifndef _FILEIO_H_
#define _FILEIO_H_

/* Additional librairies */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

/* Global variables */


/* Function prototypes */
/*!
  \fn void writeToFile(student* class, int int_size, char* str_filename)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param class The class
  \param int_size The amount of students
  \param str_filename The file to write to
  \brief Write the data out to a given file
  \remarks One line in the file corresponds to one student
*/
void writeToFile(student* class, int int_size, char* str_filename);

/*!
  \fn void readFromFile(student** class, char* str_filename)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param class The array to store the data
  \param str_filename The source file
  \return The number of students in the class
  \brief Read formatted data from a file
  \remarks Data MUST be formatted correctly in the file : 
  firstName,lastName,age;
*/
int readFromFile(student** class, char* str_filename);


#endif