#include <stdio.h>
#include <string.h>
#include "include/History.h"

void AddNewCommandToHistory(int* count, char commandList[maxcharsize][maxcommandstorage], char* currentCommand){
    strcpy(commandList[*count], currentCommand);
    *count = *count + 1;
}

void GetHistory(int size, char commandList[maxcharsize][maxcommandstorage]){
    printf("ID | Command name\n");
    for (int i = 0; i < size; i++){
        printf("%d | %s\n", i, commandList[i]);
    }
}

void EraseAllHistory(int* size, char commmandList[maxcharsize][maxcommandstorage]){
  int size_value = *size;

  for (int i = 0; i < size_value; i++){
    strcpy(commmandList[i], "");
  }

  *size = 0;
}

int EraseHistoryItem(int size, char commmandList[maxcharsize][maxcommandstorage]){
  int cmdIndex = 0;
  printf("\nProvide an index to delete: ");
  scanf("%d", &cmdIndex);

  if (cmdIndex > size){
    printf("\nOutOfBoundIndex: The provided index '%d' is greater than the number of commands present '%d'\n", cmdIndex, size);
    return -1;
  }

  strcpy(commmandList[cmdIndex], "");

  return 0;
}
