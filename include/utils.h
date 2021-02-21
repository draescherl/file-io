/*!
  \file utils.h
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \brief Header file for utils.c
  \remarks None
*/

#ifndef _UTILS_H_
#define _UTILS_H_

/* Additional librairies */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errno.h"

/* Global variables */
/*! Error code for input */
#define INPUT_ERROR -1
/*! Error code for memory allocation */
#define MEMORY_ALLOCATION_ERROR -2
/*! Error code for file handling */
#define FILE_HANDLING_ERROR -3

/*! ANSI reset colour */
#define reset "\e[0m"
/*! ANSI red colour */
#define RED "\e[0;31m"
/*! ANSI green colour */
#define GREEN "\e[0;32m"

/*! First and last name size */
#define STRING_MAX_SIZE 256

/* Custom types */
/*! Custom type to store a student */
typedef struct {
  char* lastName;    /*!< Last name must be less than STRING_MAX_SIZE characters long */
  char* firstName;   /*!< First name must be less than STRING_MAX_SIZE characters long */
  int age;           /*!< Age of the student must be >0 */
} student;


/* Function prototypes */
/*!
  \fn int intInput(void)
  \author L.Draescher <draescherl@eisti.eu>
  \date 13/10/2020
  \version 0.1 - first draft
  \return The user's input
  \brief This function makes sure the user inputs an int
  \remarks None
*/
int intInput(void);

/*!
  \fn char charInput(void)
  \author L.Draescher <draescherl@eisti.eu>
  \date 23/12/2020
  \version 0.1 - first draft
  \return Clean char
  \brief Clean char input
  \remarks None
*/
char charInput(void);

/*!
  \fn void stringInput(char** str_string)
  \author L.Draescher <draescherl@eisti.eu>
  \date 04/12/2020
  \version 0.1 - first draft
  \param str_string The string of characters
  \brief Makes sure the user inputs a clean string
  \remarks None
*/
void stringInput(char** str_string);

/*!
  \fn void writeTextToFile(char* str_toWrite, FILE* ptr_file)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param str_toWrite Text to write
  \param ptr_file File to write to
  \brief Write text to an open file and handle errors
  \remarks None
*/
void writeTextToFile(char* str_toWrite, FILE* ptr_file);

/*!
  \fn void closeFile(FILE** ptr_file)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param ptr_file The file
  \brief Properly close a file
  \remarks None
*/
void closeFile(FILE** ptr_file);

/*!
  \fn void openFile(FILE** ptr_file, char* str_filename, char* str_mode)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param ptr_file Stream with the file
  \param str_filename Filename of the file to open
  \param str_mode The mode in which to open the file
  \brief Properly open a file
  \remarks None
*/
void openFile(FILE** ptr_file, char* str_filename, char* str_mode);


#endif