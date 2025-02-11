#include <main.h>

void read_gamestate(void) {
    if (check_winner() || is_board_full()) {
        Gamestate.gameover = true;
        
    }
}
void play_computer(void) {
    if (Gamestate.turn == Gamestate.computer && !Gamestate.gameover) {
        int bestMove = find_best_move();
        if (bestMove != -1) {
            Board[bestMove] = Gamestate.computer;
            Gamestate.turn = (Gamestate.turn == X) ? O : X;
        }
    }
}
void back_to_menu(void){
    reset_game();
    screen.currentScreenNo=0;
}
void reset_game(void) {
    for (int i = 0; i < 9; i++) {
        
        Board[i] = EMPTY;
        
    }
    Gamestate.gameover = false;
    Gamestate.won=EMPTY;
    Gamestate.turn = X;  
}
void play_as_x(){
    Gamestate.computer=O;
    screen.currentScreenNo=1;
}

void play_as_o(){
    Gamestate.computer=X;
    screen.currentScreenNo=1;
}
void read_input(void) {
    if(!screen.currentScreenNo){
        for (int i = 0; i < 3; i++)
        {
            Vector2 mousePos = GetMousePosition();
            startMenuButton[i].isSelected = CheckCollisionPointRec(mousePos, startMenuButton[i].rec);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && startMenuButton[i].isSelected) {
                startMenuButton[i].onClick();
            }
        }
        return;
        
    }
    if (screen.currentScreenNo && Gamestate.gameover) {
        for(int i=0;i<2;i++){
            Vector2 mousePos = GetMousePosition();
            gameMenuButton[i].isSelected = CheckCollisionPointRec(mousePos, gameMenuButton[i].rec);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && gameMenuButton[i].isSelected) {
                gameMenuButton[i].onClick();
                return;

            }
        }
        return;
    }
    if(Gamestate.computer==Gamestate.turn){
        return;
    }
    if (screen.currentScreenNo&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        int col = mousePos.x / COL_WIDTH;
        int row = mousePos.y / COL_HEIGHT;
        int index = col + row * 3;
        
        if (col >= 0 && col < 3 && row >= 0 && row < 3 && Board[index] == EMPTY) {
            Board[index] = Gamestate.turn;
            Gamestate.turn = (Gamestate.turn == X) ? O : X;
        }
    }
}
