/*!
  \file fileIO.c
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \brief File interaction
  \remarks None

  This file stores all the methods needed in order
  to interact with the filesystem.

*/

#include "fileIO.h"





/*!
  \fn void writeData(student* class, int int_size, FILE** ptr_file)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param class The class
  \param int_size The amount of students
  \param ptr_file The file to write to
  \brief Formats the data and writes it to the file
  \remarks Formatting is firstName,lastName,age;
*/
void writeData(student* class, int int_size, FILE** ptr_file)
{
  /* Variables */
  int i;
  char str_conversion[12];

  for (i = 0; i < int_size; i++) {
    writeTextToFile(class[i].firstName, *ptr_file);
    writeTextToFile(",", *ptr_file);
    writeTextToFile(class[i].lastName, *ptr_file);
    writeTextToFile(",", *ptr_file);
    /* Convert age to string */
    sprintf(str_conversion, "%d", class[i].age);
    writeTextToFile(str_conversion, *ptr_file);
    writeTextToFile(";\n", *ptr_file);
  }
}

void writeToFile(student* class, int int_size, char* str_filename)
{
  /* Variables */
  FILE* ptr_file;

  /* Open file */
  openFile(&ptr_file, str_filename, "w");

  /* Write to file */
  writeData(class, int_size, &ptr_file);

  /* Close file */
  closeFile(&ptr_file);

  /* Message the user */
  printf(GREEN "Data successfully written to " reset "%s\n\n", str_filename);
}

/*!
  \fn int wordLength(char* str_string, int int_strLength, int int_startPoint)
  \author L.Draescher <draescherl@eisti.eu>
  \date 22/12/2020
  \version 0.1 - first draft
  \param str_string The string to search through
  \param int_strLength The length of the string
  \param int_startPoint The position from which to start looking
  \return The length of a word in the file or -1 if an error occured
  \brief This function loops through a line of formatted text and
  and returns the length of the word between two commas
  \remarks Line must respect the correct format : firstName,lastName,age;
*/
int wordLength(char* str_string, int int_strLength, int int_startPoint)
{
  /* Variables */
  int i;
  int int_res;

  /* Loop through line until a comma or a semi colon is found or 
  the loop exceeds the length of the string */
  i = int_startPoint;
  while ( (str_string[i] != ',') && (str_string[i] != ';') && (i < int_strLength) ) {
    i++;
  }

  int_res = (i == int_strLength) ? -1 : i-int_startPoint;
  return(int_res);
}

/*!
  \fn void wordLengthErrorHandling(int int_wordLength)
  \author L.Draescher <draescherl@eisti.eu>
  \date 22/12/2020
  \version 0.1 - first draft
  \param int_wordLength return value of the wordLength function
  \brief Handles the error case of the wordLength function
  \remarks None
*/
void wordLengthErrorHandling(int int_wordLength)
{
  if (int_wordLength == -1) {
    fprintf(stderr, RED "Error while reading file : " reset "content format error.\n");
    exit(FILE_HANDLING_ERROR);
  }
}

/*!
  \fn void readData(char* str_line, student* student_s)
  \author L.Draescher <draescherl@eisti.eu>
  \date 22/12/2020
  \version 0.1 - first draft
  \param str_line Source line from file
  \param student_s Where to store the information
  \brief Read a line from a file
  \remarks Line must respect the correct format : firstName,lastName,age;
*/
void readData(char* str_line, student* student_s)
{
  /* Variables */
  int int_startingPoint;
  int int_endingPoint;
  int int_strLength;
  char* str_age;

  int_strLength = strlen(str_line);
  str_age = malloc(3 * sizeof(char));
  student_s->firstName = malloc(STRING_MAX_SIZE * sizeof(char));
  student_s->lastName  = malloc(STRING_MAX_SIZE * sizeof(char));

  /* Copy first name */
  int_startingPoint = 0;
  int_endingPoint = wordLength(str_line, int_strLength, int_startingPoint);
  wordLengthErrorHandling(int_endingPoint);
  strncpy(student_s->firstName, str_line + int_startingPoint, int_endingPoint);

  /* Copy last name */
  int_startingPoint = int_endingPoint + 1; /* Skip separation char */
  int_endingPoint = wordLength(str_line, int_strLength, int_startingPoint);
  wordLengthErrorHandling(int_endingPoint);
  strncpy(student_s->lastName, str_line + int_startingPoint, int_endingPoint);

  /* Copy age */
  int_startingPoint = int_startingPoint + int_endingPoint + 1;
  int_endingPoint = wordLength(str_line, int_strLength, int_startingPoint);
  wordLengthErrorHandling(int_endingPoint);
  strncpy(str_age, str_line + int_startingPoint, int_endingPoint);
  student_s->age = strtol(str_age, NULL, 10);

  free(str_age);
}

int readFromFile(student** class, char* str_filename)
{
  /* Variables */
  int int_nStudents;
  char* str_line;
  FILE* ptr_file;
  size_t st_len;
  __ssize_t sst_read;

  /* Init values */
  str_line = NULL;
  st_len = 0;
  int_nStudents = 1;

  /* Allocate initial amount of memory */
  *class = malloc(int_nStudents * sizeof(student));
  if (*class == NULL) {
    fprintf(stderr, RED "Error while allocating memory.\n" reset);
    exit(MEMORY_ALLOCATION_ERROR);
  }

  /* Open file */
  openFile(&ptr_file, str_filename, "r");

  /* Copy line by line */
  while ((sst_read = getline(&str_line, &st_len, ptr_file)) != -1) {
    readData(str_line, &(*class)[int_nStudents-1]);
    int_nStudents++;
    /* Make array bigger to fit as many students as necessary */
    *class = realloc(*class, int_nStudents * sizeof(student));
    if (*class == NULL) {
      fprintf(stderr, RED "Error while allocating memory.\n" reset);
      exit(MEMORY_ALLOCATION_ERROR);
    }
  }

  closeFile(&ptr_file);
  free(str_line);
  printf("\n" GREEN "Data successfully read from " reset "%s\n\n", str_filename);

  return(int_nStudents-1);
}