#ifndef HISTORY_H
#define HISTORY_H

#define maxcharsize 100
#define maxcommandstorage 255

void AddNewCommandToHistory(int* count, char commandList[maxcharsize][maxcommandstorage], char* currentCommand);
void GetHistory(int size, char commandList[maxcharsize][maxcommandstorage]);
void EraseAllHistory(int* size, char commmandList[maxcharsize][maxcommandstorage]);
int EraseHistoryItem(int size, char commandList[maxcharsize][maxcommandstorage]);

#endif