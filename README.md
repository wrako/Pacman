# Pacman Clone

This is a simple Pacman clone written in C using the `ncurses` library. The game features Pacman navigating through a maze, avoiding ghosts, and collecting points. It includes a menu system and multiple levels.

## Features
- Classic Pacman gameplay
- Multiple levels
- Simple ghost AI
- Menu navigation
- `ncurses` based rendering

## Installation
### Prerequisites
Ensure you have `gcc` and `ncurses` installed.

#### Ubuntu / Debian:
```sh
sudo apt update
sudo apt install gcc libncurses5-dev libncursesw5-dev
```

#### macOS:
```sh
brew install ncurses
```

### Compilation
```sh
gcc main.c render.c game.c ghost.c level.c -o pacman -lncurses
```

## Usage
Run the compiled program:
```sh
./pacman
```
Use arrow keys to move Pacman and `e` to select menu options.

## Project Structure
```
📂 Pacman-Clone
├── main.c       # Entry point and menu handling
├── render.c     # Drawing functions
├── render.h     # Render function headers
├── game.c       # Game mechanics
├── game.h       # Game function headers
├── ghost.c      # Ghost AI
├── ghost.h      # Ghost function headers
├── level.c      # Level management
├── level.h      # Level headers
└── README.md    # Project description
```

## Controls
- **Arrow keys**: Move Pacman
- **E key**: Select menu options
- **Esc**: Exit the game

## License
This project is released under the MIT License.

## Contributing
Feel free to contribute by submitting pull requests!

## Author
Created by [Your Name]

