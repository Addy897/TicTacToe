#include <main.h>
void init_gui(){
    int width=150;
    int height=50;
    screen.screen_draw[screen.totalScreens++]=&draw_menu;
    screen.screen_draw[screen.totalScreens++]=&draw_game;
    Color color=GRAY;
    Color hoverColor=DARKGRAY;
    Rectangle startRec= (Rectangle){.height=40,.width=180,.x=60,.y=40};

    char *texts[3]= {"Play as X","Play as O","Quit"};
    char *gameOvertexts[2]= {"Play Again","Back To Menu"};
    void (*funcptr[3])(void)={&play_as_x,&play_as_o,&CloseWindow};
    for (int i = 0; i < 3; i++)
    {

        startMenuButton[i].rec=startRec;
        startMenuButton[i].isSelected=false;
        startMenuButton[i].color=color;
        startMenuButton[i].hoverColor=hoverColor;
        startMenuButton[i].text=texts[i];
        startMenuButton[i].onClick=funcptr[i];
        startRec.y+=90;
    }
    funcptr[1]=&back_to_menu;
    funcptr[0]=&reset_game;
    startRec= (Rectangle){.height=40,.width=180,.x=60,.y=80};
    for (int i = 0; i < 2; i++)
    {

        gameMenuButton[i].rec=startRec;
        gameMenuButton[i].isSelected=false;
        gameMenuButton[i].color=color;
        gameMenuButton[i].hoverColor=hoverColor;
        gameMenuButton[i].text=gameOvertexts[i];
        gameMenuButton[i].onClick=funcptr[i];
        startRec.y+=80;
    }
    

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

void draw_menu(void){
   for (int  i = 0; i < 3; i++)
   {
    draw_button(startMenuButton[i]);
   }
   

}

void draw_game(void){
    draw_board();
    draw_line();
    if(Gamestate.gameover){
        for (int i = 0; i < 2; i++)
        {
            draw_button(gameMenuButton[i]);
        }
        
        
    }
}
void draw_screen(void){
    screen.screen_draw[screen.currentScreenNo]();

}

void draw_line(void) {
    if (Gamestate.gameover && Gamestate.won!=EMPTY) {
        DrawLineEx(Gamestate.winnerLineStart, Gamestate.winnerLineEnd, 2.0f, RED);
    }
}