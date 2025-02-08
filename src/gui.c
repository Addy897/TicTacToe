#include <main.h>
void init_gui(){
    int width=150;
    int height=50;
    Rectangle rec= (Rectangle){.height=height,.width=width,.x=SCREEN_WIDTH/2-width/2,.y=SCREEN_WIDTH/2-height/2};
    startOver = (Button){.rec=rec,.text="Play Again",.color=GRAY, .hoverColor=DARKGRAY,.isSelected=false};
}
void draw_board(void) {
    float thickness = 2.0f;
    
    for (int i = 1; i < 3; i++) {
        DrawLineEx(
            (Vector2){i * COL_WIDTH, 0},
            (Vector2){i * COL_WIDTH, SCREEN_HEIGHT},
            thickness, DARKGRAY
        );
        DrawLineEx(
            (Vector2){0, i * COL_HEIGHT},
            (Vector2){SCREEN_WIDTH, i * COL_HEIGHT},
            thickness, DARKGRAY
        );
    }
    
    for (int i = 0; i < 9; i++) {
        float x = (i % 3 + 0.5f) * COL_WIDTH;
        float y = (i / 3 + 0.5f) * COL_HEIGHT;
        
        if (Board[i] == O) {
            DrawCircleLines(x, y, COL_WIDTH/4, WHITE);
        }
        if (Board[i] == X) {
            float offset = COL_WIDTH/4;
            DrawLine(x - offset, y - offset, x + offset, y + offset, WHITE);
            DrawLine(x + offset, y - offset, x - offset, y + offset, WHITE);
        }
    }
}


void draw_line(void) {
    if (Gamestate.gameover && Gamestate.won) {
        DrawLineEx(Gamestate.winnerLineStart, Gamestate.winnerLineEnd, 2.0f, RED);
    }
}