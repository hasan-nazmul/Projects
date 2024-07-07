# Racing Game

Welcome to the Racing Game, an exciting game built with C. This game features both single-player and multiplayer modes, allowing you to compete against friends or enjoy solo challenges. The game includes functionalities like sign-up, sign-in, high scores, car selection, and in-game purchases, all handled through file operations.

## Table of Contents
- [Features](#features)
- [How to Run](#how-to-Run)
- [Controls](#controls)
- [Video Demo](#video-demo)
- [File Handling](#file-handling)
- [Requirements](#requirements)
- [Contact](#contact)

## Features

- **Single Player Mode**: Navigate your car using arrow keys (left-right) to dodge obstacles and race to the finish line.
- **Multiplayer Mode**: 
  - Player 1 controls the car using 'a' (left) and 's' (right) keys.
  - Player 2 controls the car using 'j' (left) and 'k' (right) keys.
- **User Authentication**: Sign up and sign in to save your progress and high scores.
- **High Scores**: Track and display high scores for both single and multiplayer modes.
- **Car Selection**: Choose your favorite car to race with.
- **Purchases**: Buy upgrades and new cars to enhance your racing experience.
- **Menu Navigation**: 
  - Use the arrow keys (up-down) to navigate through the menu options.
  - Press the spacebar to select an option.
  - Press the escape key (Esc) to move back to the previous page.

## How to Run

1. **Color Selection**: First, run the `Color.cpp` file to select your desired colors. The selected colors will be used in the game interface.
   ```sh
   gcc Color.cpp -o Color
   ./Color

2. **Modify Colors**: Change the macros in RacingGame.c as per your color selection.

3. **Compile and Run the Game**: 
    ```sh
    gcc RacingGame.c -o RacingGame ./RacingGame
    ```
## Controls

### Menu Navigation
- Arrow Keys (Up-Down): Navigate through the options
- Spacebar: Select an option
- Escape (Esc): Go back to the previous page

### In-Game Controls
- Single Player Mode: Use arrow keys (left-right) to move the car.
- Multiplayer Mode:
  - Player 1: Use 'a' (left) and 's' (right) to move the car.
  - Player 2: Use 'j' (left) and 'k' (right) to move the car.

## Video Demo
Check out the video demo of the game on YouTube: [Racing Game Demo](https://youtu.be/i1mDcowCwpk?si=MvaCfRPrsR4nUf5q)

## File Handling
The game uses file handling to manage user data, high scores, car selections, and purchases. Make sure the program has the necessary read/write permissions to access the files.

## Requirements
C Compiler (GCC recommended)
Standard C Libraries

## Contact

If you have any questions or suggestions, feel free to reach out:

- Email: [Nazmul Hasan](mailto:nh2826239@gmail.com)
- GitHub: [Nazmul Hasan](https://github.com/hasan-nazmul)

Thank you for checking out my Snake Xenzia project. Have fun playing!