#include "raylib.h"
#include "resource_dir.h"
#include "manager.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(800, 600, "Hello Raylib");

	SearchAndSetResourceDir("resources");

  bool btnex = false;
	
	while (!WindowShouldClose())		
	{	
		BeginDrawing();
		
		ClearBackground(BLACK);

    if (btnex == true){
      OpenFileExplorer();
      btnex = false;
    }

    btnex = GuiButton((Rectangle){100, 100, 30, 30}, "Open File");
		
		DrawText("FmanagerUi", 400, 600, 20, WHITE);
		
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}
