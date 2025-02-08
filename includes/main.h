#ifndef MAIN_H
#define MAIN_H
    #include <stdio.h>
    #include <raylib.h>
    #include <stdbool.h>

    #define SCREEN_WIDTH 300
    #define SCREEN_HEIGHT 300
    #define COL_WIDTH 100
    #define COL_HEIGHT 100

    enum SYMBOLS {
        EMPTY = 0,
        X = 1,
        O = 2
    };
    typedef struct Button{
        Rectangle rec;
        bool isSelected;
        char *text;
        Color color;
        Color hoverColor;

    }Button;
    typedef struct {
        enum SYMBOLS turn;
        enum SYMBOLS won;
        bool gameover;
        enum SYMBOLS computer;
        Vector2 winnerLineStart;
        Vector2 winnerLineEnd;
    } GameState;
    extern char Board[9];
    extern GameState Gamestate;
    extern Button startOver;
    extern void init_window(void);
    extern void init_gui(void);
    extern void exit_window(void);
    extern void draw_board(void);
    extern void draw_line(void);
    extern bool check_winner(void);
    extern bool is_board_full(void);
    extern void read_gamestate(void);
    extern int evaluate_line(int a, int b, int c);
    extern int evaluate_board(void);
    extern bool are_moves_left(void);
    extern int minimax(int depth, bool isMaximizingPlayer);
    extern int find_best_move(void);
    extern void play_computer(void);
    extern void read_input(void);
extern void reset_game(void);

#endif