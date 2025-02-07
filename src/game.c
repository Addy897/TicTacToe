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

void read_input(void) {
    if (Gamestate.gameover) {
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
