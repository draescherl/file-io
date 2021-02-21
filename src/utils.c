/*!
  \file utils.c
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \brief Utilities
  \remarks None

  This file stores general utility methods.

*/

#include "utils.h"



int intInput(void)
{
  /* Variables */
  int int_input;
  int int_correct;
  int int_c;

  int_correct = scanf("%d", &int_input);
  if (int_correct == 0) {
    fprintf(stderr, RED "Error: " reset "Something went wrong while entering int.\n");
    exit(INPUT_ERROR);
  }

  /* Empty buffer */
  while ( ((int_c = getchar()) != '\n') && (int_c != EOF) ) { }

  return (int_input);
}

char charInput(void)
{
  /* Variables */
  char char_input;
  int int_correct;
  int int_c;

  int_correct = scanf("%c", &char_input);
  if (int_correct == 0) {
    fprintf(stderr, RED "Error: " reset "Something went wrong while entering char.\n");
    exit(INPUT_ERROR);
  }

  /* Empty buffer */
  while ( ((int_c = getchar()) != '\n') && (int_c != EOF) ) { }

  return (char_input);
}

void stringInput(char** str_string)
{
  *str_string = malloc(STRING_MAX_SIZE * sizeof(char));
  if (*str_string == NULL) {
    fprintf(stderr, RED "Error while allocating memory.\n" reset);
    exit(MEMORY_ALLOCATION_ERROR);
  }

  fgets(*str_string, STRING_MAX_SIZE, stdin);

  /* Remove trailing newline */
  if ( (strlen(*str_string) > 0) && ((*str_string)[strlen(*str_string) - 1] == '\n') ) {
    (*str_string)[strlen(*str_string) - 1] = '\0';
  }
}

void writeTextToFile(char* str_toWrite, FILE* ptr_file)
{
  /* Variables */
  int int_isCorrect;
  int int_strLength;

  int_strLength = strlen(str_toWrite);
  int_isCorrect = fwrite(str_toWrite, sizeof(char), int_strLength, ptr_file);

  if (int_isCorrect != int_strLength) {
    fprintf(stderr, RED "Write error : " reset "%s\n", strerror(errno));
    exit(FILE_HANDLING_ERROR);
  }
}

void closeFile(FILE** ptr_file)
{
  /* Variables */
  int int_fileClosed;

  int_fileClosed = fclose(*ptr_file);
  if (int_fileClosed == EOF) {
    fprintf(stderr, RED "Error closing file : " reset "%s\n", strerror(errno));
    exit(FILE_HANDLING_ERROR);
  }
}

void openFile(FILE** ptr_file, char* str_filename, char* str_mode)
{
  *ptr_file = fopen(str_filename, str_mode);
  if (*ptr_file == NULL) {
    fprintf(stderr, RED "Error while opening file : " reset "%s\n", strerror(errno));
    /* Give the address pointed by ptr_file */
    closeFile(*&ptr_file);
    exit(FILE_HANDLING_ERROR);
  }
}