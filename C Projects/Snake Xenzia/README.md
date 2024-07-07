# Snake Xenzia

Snake Xenzia is a classic snake game implemented in C. The objective is to navigate the snake to eat food, grow longer, and avoid crashing into walls or itself.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Game Rules](#game-rules)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [Contact](#contact)

## Description

This project is a recreation of the classic Snake Xenzia game. The game is played on a console, where the player controls a snake to eat food and avoid obstacles. The game tracks the player's score and records the high score.

## Features

- Classic snake gameplay.
- High score tracking.
- Simple and intuitive controls.
- Console-based game interface.

## Installation

To run this game, you need to have a C compiler installed on your machine. Follow these steps to set up and run the game:

1. Clone the repository:
    ```sh
    git clone https://github.com/hasan-nazmul/Projects.git
    cd '.\Projects\C Projects\Snake Xenzia\'
    ```

2. Compile the game:
    ```sh
    gcc snake_xenzia.c -o snake_xenzia -lconio -lwindows -lstdlib -ltime
    ```

3. Run the game:
    ```sh
    ./snake_xenzia
    ```

## Usage

After following the installation steps, run the game executable. The game will start with instructions on how to play and control the snake.

## Controls

- `i` or `w`: Move up
- `k` or `s`: Move right
- `m` or `z`: Move down
- `j` or `a`: Move left

## Game Rules

1. The snake moves continuously in the direction of the last input.
2. The objective is to eat the food represented by `@`.
3. Each time the snake eats food, it grows longer.
4. The game ends if the snake collides with the walls or its own body.
5. The score increases by 10 points for each food item eaten.
6. The high score is recorded and displayed at the start of each game.

## Future Enhancements

- Add levels with increasing difficulty.
- Implement different types of food with varying points.
- Add sound effects and music.
- Improve the graphical interface.

## Contributing

Contributions are welcome! If you have any ideas or improvements, feel free to fork the repository and create a pull request. Please follow the [code of conduct](https://github.com/hasan-nazmul/Projects/blob/main/CODE_OF_CONDUCT.md) when contributing.

## Contact

If you have any questions or suggestions, feel free to reach out:

- Email: [Nazmul Hasan](mailto:nh2826239@gmail.com)
- GitHub: [Nazmul Hasan](https://github.com/hasan-nazmul)

Thank you for checking out my Snake Xenzia project. Have fun playing!

Video Demo: [Snake Xenzia with C](https://youtu.be/33qJ-mIBJFU?si=y6xGYaHobFPZT5d1)