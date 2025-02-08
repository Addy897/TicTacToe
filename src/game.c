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
void reset_game(void) {
    for (int i = 0; i < 9; i++) {
        
        Board[i] = EMPTY;
        
    }
    Gamestate.gameover = false;
    Gamestate.turn = X;  
}
void read_input(void) {
    if (Gamestate.gameover) {
        Vector2 mousePos = GetMousePosition();
        startOver.isSelected = CheckCollisionPointRec(mousePos, startOver.rec);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && startOver.isSelected) {
            reset_game();
        }
        return;
    }
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
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
