# 🎮 Tic-Tac-Toe AI (Raylib)  
*By Addy897*  
[![GitHub](https://img.shields.io/badge/GitHub-Repository-blue)](https://github.com/Addy897/TicTacToe)

A classic Tic-Tac-Toe game with a smart AI opponent, built with **Raylib** for seamless graphics and gameplay.

---

## 🚀 Features  
- 🆚 **Player vs AI Gameplay**: Battle against an unbeatable AI  
- 🧠 **Minimax Algorithm**: AI uses decision-making optimization  
- 🎨 **Raylib GUI**: Smooth and intuitive graphical interface  
- 🏆 **Win/Draw Detection**: Instant game state checks  

---

## 📥 Installation  
**Prerequisites**: Raylib installed ([Installation Guide](https://www.raylib.com/)).  

Clone the repository:  
```bash
git clone https://github.com/Addy897/TicTacToe
cd TicTacToe
```

**Installation**
----------------

To install the game, follow these steps:

```makefile
make
```

This will compile the game and generate an executable file. You can run the game by executing the following command:

```makefile
./main
```



**Game Controls**
-----------------

| Key | Action |
| --- | --- |
| Left-click a cell | Place X/O |
| Esc key | Quit  |

**Configuration Options**
-------------------------

You can customize the computer turn settings by modifying the `src/main.c` file by changing the following line:
```C
// src/main.c (line 8)
Gamestate.computer = X;  // Change to O for AI to play second
 ```
