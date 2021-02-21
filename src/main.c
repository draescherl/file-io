/*!
  \file main.c
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \brief Main project file
  \remarks None

  This project allows the storage of students in files.

*/

/* Additional librairies */
#include "fileIO.h"
#include "students.h"
#include "utils.h"




/*!
  \fn void argW(student* class, char* str_filename)
  \author L.Draescher <draescherl@eisti.eu>
  \date 22/12/2020
  \version 0.1 - first draft
  \param class The class of students
  \param str_filename The filename
  \brief Calls all the necessary functions for writing out to a file
  \remarks None
*/
void argW(student* class, char* str_filename)
{
  /* Variables */
  int int_size;

  int_size = inputClass(&class);
  writeToFile(class, int_size, "data.txt");
}



/*!
  \fn void argR(student* class, char* str_filename)
  \author L.Draescher <draescherl@eisti.eu>
  \date 22/12/2020
  \version 0.1 - first draft
  \param class The class of students
  \param str_filename The filename to read from
  \brief Calls all the necessary function for reading from a file
  \remarks None
*/
void argR(student* class, char* str_filename)
{
  /* Variables */
  int int_size;

  int_size = readFromFile(&class, "data.txt");
  printClass(class, int_size);
}



/*!
  \fn void argH(void)
  \author L.Draescher <draescherl@eisti.eu>
  \date 23/12/2020
  \version 0.1 - first draft
  \brief Print help to the terminal
  \remarks None
*/
void argH(void)
{
  printf("NAME\n");
  printf("\tstudents - file read/write exercise.\n");
  
  printf("\nSYNOPSIS\n");
  printf("\t./students [ARG] [FILENAME]\n");
  
  printf("\nARGUMENTS\n");
  printf("\t-h\tshow this help screen\n");
  printf("\n");
  printf("\t-r\tread data from [FILENAME]\n");
  printf("\n");
  printf("\t-w\twrite data to [FILENAME]\n");

  printf("\nAUTHOR\n");
  printf("\tWritten by Lucas Draescher.\n");
}



/*!
  \fn int main(int argc, char** argv)
  \author L.Draescher <draescherl@eisti.eu>
  \date 21/12/2020
  \version 0.1 - first draft
  \param argc Number of console arguments
  \param argv Console parameters
  \return 0 on success
  \brief Main program
  \remarks None
*/
int main(int argc, char** argv) {
  /* Variables */
  student* class;
  class = NULL;


  /* Call the correct functions depending on the args given */
  if (argc == 1) {
    printf("Too few arguments. See -h for help.\n");
  } else if (argc == 2) {
    if (strcmp(argv[1], "-h") == 0) {
      argH();
    } else if ( (strcmp(argv[1], "-r") == 0) || (strcmp(argv[1], "-w") == 0) ) {
      printf("Missing file name.\n");
    } else {
      printf("Unknown argument : %s\n", argv[1]);
    }
  } else if (argc == 3) {
    if (strcmp(argv[1], "-h") == 0) {
      argH();
    } else if (strcmp(argv[1], "-r") == 0) {
      argR(class, argv[2]);
    } else if (strcmp(argv[1], "-w") == 0) {
      argW(class, argv[2]);
    } else {
      printf("Unknown argument : %s\n", argv[1]);
    }
  } else {
    printf("Too many arguments. See -h for help.\n");
  }
 
  
  free(class);
  return(0);
}