#include <main.h>
bool check_winner(void) {
    
    for (int i = 0; i < 3; i++) {
        if (Board[i*3] && Board[i*3] == Board[i*3 + 1] && Board[i*3 + 1] == Board[i*3 + 2]) {
            Gamestate.won = Board[i*3];
            float y = (i * COL_HEIGHT) + COL_HEIGHT / 2;
            Gamestate.winnerLineStart = (Vector2){0, y};
            Gamestate.winnerLineEnd = (Vector2){SCREEN_WIDTH, y};
            return true;
        }
    }
    
    
    for (int i = 0; i < 3; i++) {
        if (Board[i] && Board[i] == Board[i + 3] && Board[i + 3] == Board[i + 6]) {
            Gamestate.won = Board[i];
            float x = (i * COL_WIDTH) + COL_WIDTH / 2;
            Gamestate.winnerLineStart = (Vector2){x, 0};
            Gamestate.winnerLineEnd = (Vector2){x, SCREEN_HEIGHT};
            return true;
        }
    }
    
    
    if (Board[0] && Board[0] == Board[4] && Board[4] == Board[8]) {
        Gamestate.won = Board[0];
        Gamestate.winnerLineStart = (Vector2){0, 0};
        Gamestate.winnerLineEnd = (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
        return true;
    }
    
    if (Board[2] && Board[2] == Board[4] && Board[4] == Board[6]) {
        Gamestate.won = Board[2];
        Gamestate.winnerLineStart = (Vector2){SCREEN_WIDTH, 0};
        Gamestate.winnerLineEnd = (Vector2){0, SCREEN_HEIGHT};
        return true;
    }
    
    return false;
}

bool is_board_full(void) {
    for (int i = 0; i < 9; i++) {
        if (Board[i] == EMPTY) {
            return false;
        }
    }
    Gamestate.won=EMPTY;
    return true;
}


int evaluate_line(int a, int b, int c) {
    if (a == b && b == c) {
        if (a == X) return 10;
        if (a == O) return -10;
    }
    return 0;
}


int evaluate_board(void) {
    for (int i = 0; i < 3; i++) {
        int score = evaluate_line(Board[i*3], Board[i*3 + 1], Board[i*3 + 2]);
        if (score != 0) return score;
    }
    
    for (int i = 0; i < 3; i++) {
        int score = evaluate_line(Board[i], Board[i + 3], Board[i + 6]);
        if (score != 0) return score;
    }
    
    int score = evaluate_line(Board[0], Board[4], Board[8]);
    if (score != 0) return score;
    
    score = evaluate_line(Board[2], Board[4], Board[6]);
    if (score != 0) return score;
    
    return 0;
}

bool are_moves_left(void) {
    for (int i = 0; i < 9; i++) {
        if (Board[i] == EMPTY) {
            return true;
        }
    }
    return false;
}
