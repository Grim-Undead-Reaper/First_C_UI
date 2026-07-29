#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/Commands.h"
#include "include/History.h"
#include "include/User.h"

static const char version[] = "v0.0.11";

Command commands[] = {
    {"help", "Show all commands.", HELP},
    {"setuser", "Set a new user name.", SETUSER},
    {"getuser", "Get Current User.", GETUSER},
    {"cls", "Clear console.", CLEARCONSOLE},
    {"cmdh", "Get all commands used.", GETHISTORY},
    {"killh", "Clear the command history", CLEARTERMINAL},
    {"killhi", "Erase a specific item from command history", CLEARTERMINALITEM},
    {"fmanager", "File the files", FILEMANAGER},
    {"--version", "Get current terminal version", VERSION},
    {"exit", "Close the terminal.", EXIT}
};

const int COMMANDSIZE = (sizeof(commands) / sizeof(commands[0]));

enum Functions InputHandler(char* InputArray, int* count, char commandList[100][255]){
    printf(">>> ");
    scanf("%254s", InputArray);
    printf("\n");
    AddNewCommandToHistory(count, commandList, InputArray);
    for (int i = 0; i < COMMANDSIZE; i++){
        if (strcmp(InputArray, commands[i].name) == 0){
            return commands[i].func;
        }
    }

    return COMMANDNOTFOUND;
}

int help(){
    for (int i = 0; i < COMMANDSIZE; i++){
        printf("%s: %s\n", commands[i].name, commands[i].description);
    }
    return 0;
}

void ClearConsole(void){
    system("cls");
}

void CurrentVersion(void){
    printf("\n[Author]: {Grim-Undead-Reaper}\n[Software]: {First_C_UI}\n[Version]: {%s}\n\n", version);
}
