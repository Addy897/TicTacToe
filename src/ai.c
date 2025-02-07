
#include <main.h>


int minimax(int depth, bool isMaximizingPlayer) {
    int score = evaluate_board();
    
    if (score == 10 || score == -10) {
        return score;
    }
    
    if (!are_moves_left()) {
        return 0;
    }
    
    if (isMaximizingPlayer) {
        int best = -1000;
        for (int i = 0; i < 9; i++) {
            if (Board[i] == EMPTY) {
                Board[i] = X;
                best = (best > minimax(depth + 1, false)) ? best : minimax(depth + 1, false);
                Board[i] = EMPTY;
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 9; i++) {
            if (Board[i] == EMPTY) {
                Board[i] = O;
                best = (best < minimax(depth + 1, true)) ? best : minimax(depth + 1, true);
                Board[i] = EMPTY;
            }
        }
        return best;
    }
}


int find_best_move(void) {
    int bestVal = (Gamestate.computer == X) ? -1000 : 1000;
    int bestMove = -1;
    
    for (int i = 0; i < 9; i++) {
        if (Board[i] == EMPTY) {
            Board[i] = Gamestate.computer;
            int moveVal = minimax(0, Gamestate.computer != X);
            Board[i] = EMPTY;
            
            if (Gamestate.computer == X) {
                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    bestMove = i;
                }
            } else {
                if (moveVal < bestVal) {
                    bestVal = moveVal;
                    bestMove = i;
                }
            }
        }
    }
    
    return bestMove;
}
