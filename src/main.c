#include <main.h>
char Board[9] = {0};
GameState Gamestate = {0};
void init_window(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TicTacToe");
    SetTargetFPS(60);
    Gamestate.turn = X;
    Gamestate.computer = O;
}

void exit_window(void) {
    CloseWindow();
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
        EndDrawing();
        
        read_input();
    }
    
    exit_window();
    return 0;
}