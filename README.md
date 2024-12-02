# so_long | 42 Project

**so_long** is a graphical project that uses the MLX42 graphics library as part of the 42 curriculum. The game is a 2D puzzle where the player collects items and exits the map after meeting certain conditions.

Have a look to `level_1.ber`:
<p align="center"><img width="768px" alt="448px" src="https://github.com/jogarman/so_long/blob/main/level_1.gif"></p>

Here is level_2.ber
<p align="center"><img width="896px" alt="512px" src="https://github.com/jogarman/so_long/blob/main/level_2.png"></p>

You can create and add as many levels as you wish 😁 !!

## Instruction set

To meet the objectives of the mandatory part of the project, I had to follow these rules:

| **#** | **Instruction**                                                                                 |
| ----- | ----------------------------------------------------------------------------------------------- |
|  `1`  | Collect all objects on the map and choose the shortest route                                    |
|  `2`  | Use arrows or W, A, S, and D keys to move the main character                                              |
|  `3`  | Move the character in four directions: up, down, left, or right                                 |
|  `4`  | Avoid entering walls                                                                            |
|  `5`  | Display the real number of movements after each move in a terminal.                             |
|  `6`  | Utilize a 2D perspective.                                        |
|  `7`  | The game does not need to be real-time.                                                         |
|  `8`  | Ensure clean window management, including switching windows and minimizing.                     |
|  `9`  | Pressing ESC should close the window and end the program cleanly.                               |
|  `10` | Clicking the red cross on the window should close the window and terminate the program cleanly. |

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/username/so_long.git
    ```

2. Build the project:

    ```bash
    make
    ```

3. Run the game with a valid `.ber` map file:

    ```bash
    ./so_long maps/level_1.ber
    ```

## Requirements

- Just **MLX42** library is required for the graphical interface.


