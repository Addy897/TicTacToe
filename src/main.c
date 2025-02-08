#include <main.h>

void init_window(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TicTacToe");
    init_gui();
    SetTargetFPS(60);
    Gamestate.turn = X;
    Gamestate.computer = X;
    
}

void exit_window(void) {
    CloseWindow();
}

void draw_button(Button b) {
    int fontSize = 24;
    int textWidth = MeasureText(b.text, fontSize);
    
    Vector2 textPosition = {
        b.rec.x + (b.rec.width - textWidth) / 2,
        b.rec.y + (b.rec.height - fontSize) / 2
    };
    
    DrawRectangleRec(b.rec,b.isSelected?b.hoverColor:b.color);
    DrawText(b.text, textPosition.x, textPosition.y, fontSize, WHITE);
}

int main(void) {
    init_window();
    
    while (!WindowShouldClose()) {
        play_computer();
        read_gamestate();
        
        BeginDrawing();
            ClearBackground(BLACK);
            draw_board();
            draw_line();
            if(Gamestate.gameover){
                draw_button(startOver);
            }
        EndDrawing();
        
        read_input();
    }
    
    exit_window();
    return 0;
}