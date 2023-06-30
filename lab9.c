//This lab incorporates linked lists in order to keep track of CSV files
//The program should allow the user to search, alter, add, delete, etc the files/ entries

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STRING_MAX 1024
typedef struct node {
  char *name;
  int lines;
  int runtime;
  int memory_usage;
  struct node *next;
} Node;

typedef struct linked_list {
  Node *head;
} LinkedList;

void readInputString(char *, int);

void readInputNumber(int *);

void readInputChar(char *);

LinkedList *newList();

char getCommand();

void handleInsert(LinkedList *);

void handleDelete(LinkedList *);

void handleSearch(LinkedList *);

void handlePrint(LinkedList *);

void handleQuit(LinkedList *);

int main() {
  LinkedList *list = newList();
  char command = '\0';
  printf("Experimental database entry\n");
  while (command != 'Q') {
    command = getCommand();
    switch (command) {
      case 'I':
        handleInsert(list);
        break;
      case 'D':
        handleDelete(list);
        break;
      case 'S':
        handleSearch(list);
        break;
      case 'P':
        handlePrint(list);
        break;
      case 'Q':
        handleQuit(list);
        break;
    }
  }
  free(list);
  return 0;
}

void handleInsert(LinkedList *list) {
  // get all the iser input
  int numOfCharInFileName, numOfLinesInFile, expRunTime, expMemUsage;
  printf("\nNumber of characters in file name: ");
  readInputNumber(&numOfCharInFileName);
  char *fileName;
  fileName = (char *)malloc(
      (numOfCharInFileName + 1) *
      sizeof(char));  // dynamically allocating space for file name
  printf("File name: ");
  readInputString(fileName, numOfCharInFileName + 1);
  printf("Number of lines in CSV file: ");
  readInputNumber(&numOfLinesInFile);
  printf("Experiment runtime (ms): ");
  readInputNumber(&expRunTime);
  printf("Experiment memory usage (B): ");
  readInputNumber(&expMemUsage);

  // check if a node with the user given name already exists or not
  Node *tempPtr = list->head;
  bool proceed = true;
  while (tempPtr != NULL) {
    if (strcmp(fileName, tempPtr->name) == 0) {
      printf("\nAn entry with that file name already exists.\n");
      proceed = false;
    }
    tempPtr = tempPtr->next;
  }

  if (proceed == true) {
    // now create a new node which will contain user entered info
    Node *newNode = (Node *)malloc(sizeof(Node));

    // add info
    newNode->name = fileName;
    newNode->lines = numOfLinesInFile;
    newNode->runtime = expRunTime;
    newNode->memory_usage = expMemUsage;
    newNode->next = NULL;

    // if the linked list has no nodes, this new node must be the first, else,
    // we insert alphabetically
    if (list->head == NULL) {
      list->head = newNode;
    } else if (strcmp(fileName, list->head->name) < 0) {
      // ^^ need to have a condition for the case when the new file name is not
      // alphabetically greater than any other one, and thus, we have to insert
      // it at the beginning of the linked list
      newNode->next = list->head;
      list->head = newNode;
    } else {
      Node *ptr = list->head, *ptr2;
      while (ptr != NULL) {
        if (strcmp(fileName, ptr->name) > 0) {
          ptr2 = ptr->next;
          ptr->next = newNode;
          newNode->next = ptr2;
          break;
        }
        // update ptr
        ptr = ptr->next;
      }
    }
  }
}

void handleDelete(LinkedList *list) {
  char fileName[100];
  printf("\nEnter file name to delete: ");
  readInputString(fileName, 100);
  Node *ptr = list->head, *ptr2;
  bool proceed = true;
  // loop through list to find the file name and then delete
  while (ptr != NULL) {
    if (strcmp(fileName, list->head->name) == 0) {
      printf("Deleting entry for CSV file <%s>\n", list->head->name);
      list->head = list->head->next;
      free(ptr->name);
      free(ptr);
      proceed = false;
    } else if (strcmp(fileName, ptr->name) == 0) {
      printf("Deleting entry for CSV file <%s>\n", ptr->name);
      // unlink node from the linked list
      ptr2->next = ptr->next;
      // and then delete the node from heap memory
      free(ptr->name);
      free(ptr);
      proceed = false;
    }
    ptr2 = ptr;
    ptr = ptr->next;
  }
  // if the name does not exist, then print so
  if (proceed == true) {
  printf("An entry for file <%s> does not exist.\n", fileName);
  }
}

void handleSearch(LinkedList *list) {
  char fileName[100];
  printf("\nEnter file name to find: ");
  readInputString(fileName, 100);
  // now loop through linked list, see if the file is present, and print its
  // contents
  Node *ptr = list->head;
  bool proceed = true;
  while (ptr != NULL) {
    if (strcmp(fileName, ptr->name) == 0) {
      double throughPut =
          ((double)(ptr->lines) / (double)(ptr->runtime));  // num of lines / runtime (s)
      printf(
          "File <%s>\nLines: %d\nRuntime (ms): %d\nMemory usage (B): "
          "%d\nThroughput: %.2lf\n",
          ptr->name, ptr->lines, ptr->runtime, ptr->memory_usage, throughPut);
      proceed = false;
    }
    // update ptr
    ptr = ptr->next;
  }
  // if didn't find file, print so
  if (proceed == true) {
    printf("An entry for file <%s> does not exist.\n", fileName);
  }
}

void handlePrint(LinkedList *list) {
  printf("\nData entries:\n");
  if (list->head == NULL) {
    printf("There are no data entries.\n");
  } else {
    Node *ptr = list->head;

    while (ptr != NULL) {
      double throughPut =
          ((double)(ptr->lines) / (double)(ptr->runtime));  // num of lines / runtime (s)
      printf(
          "\nFile <%s>\nLines: %d\nRuntime (ms): %d\nMemory usage (B): "
          "%d\nThroughput: %.2lf\n",
          ptr->name, ptr->lines, ptr->runtime, ptr->memory_usage, throughPut);

      // update ptr
      ptr = ptr->next;
    }
  }
}

void handleQuit(LinkedList *list) {
  // similar to handleDelete, just this time for the whole linked list
  Node *ptr = list->head, *ptr2;
  while (ptr != NULL) {
    printf("Deleting entry for CSV file <%s>\n", ptr->name);
    ptr2 = ptr;
    ptr = ptr->next;
    free(ptr2->name);
    free(ptr2);
  }
}

void readInputString(char *str, int length) {
  int i = 0;
  char c;
  while (i < length && (c = getchar()) != '\n') {
    str[i++] = c;
  }
  str[i] = '\0';
}

void readInputNumber(int *number) {
  char buf[STRING_MAX];
  readInputString(buf, STRING_MAX);
  *number = (int)strtol(buf, (char **)NULL, 10);
}

void readInputChar(char *character) {
  char buf[2];
  readInputString(buf, 3);
  *character = buf[0];
}

LinkedList *newList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->head = NULL;
  return list;
}

char getCommand() {
  char command;
  printf("\nSupported commands are:\n");
  printf(" I - Insert\n");
  printf(" D - Delete\n");
  printf(" S - Search\n");
  printf(" P - Print\n");
  printf(" Q - Quit\n");
  printf("\nPlease select a command: ");
  readInputChar(&command);
  while (command != 'I' && command != 'D' && command != 'S' && command != 'P' &&
         command != 'Q') {
    printf("Invalid command <%c>, please select a command: ", command);
    readInputChar(&command);
  }
  return command;
}
