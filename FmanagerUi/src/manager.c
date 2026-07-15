#include <stdio.h>
#include <windows.h>
#include "manager.h"

int OpenFileExplorer(){
  OPENFILENAME ofn;
  char file_size[260];
  HWND hwnd;
  HANDLE hf;

  ZeroMemory(&ofn, sizeof(ofn));
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = file_size;
  ofn.lpstrFile[0] = '\0';
  ofn.nMaxFile = sizeof(file_size);
  ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = NULL;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = NULL;
  ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

  if (GetOpenFileName(&ofn)==TRUE)
    hf = CreateFile(ofn.lpstrFile,
                    GENERIC_READ,
                    0,
                    (LPSECURITY_ATTRIBUTES) NULL,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    (HANDLE) NULL);

  return 0;
}
