#include <main.h>

void init_window(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TicTacToe");
    init_gui();
    SetTargetFPS(60);
    Gamestate.turn = X;
    Gamestate.computer = EMPTY;
    Gamestate.won=EMPTY;
    
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
            draw_screen();
        EndDrawing();
        
        read_input();
    }
    
    exit_window();
    return 0;
}