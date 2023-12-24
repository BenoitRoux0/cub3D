# <p align="center">42_CUB3D</p>

## 📑 Introduction
CUB3D is a project that involves creating a basic raycasting game engine inspired by the classic game Wolfenstein 3D. <br>
It's a visual exploration of raycasting techniques to render a 3D-like environment.

## 🎮️ Description
The CUB3D project challenges you to build a simple game engine that can render a textured maze-like environment in a 2D window. <br>
The core of the project revolves around raycasting, a technique that simulates a 3D perspective by casting rays from the player's viewpoint <br>
and calculating the intersections with walls and other objects.
The project requirement asked us to parse a map file that defines the layout of the maze, handle player movement, <br>
and render the scene using textures. <br>
Other features, such as wall collision, mouse mouvement, controller handling and such were optional.

## 🛠️ Implementation
Creating the CUB3D game engine asked us to work on the following components:

- Map parsing: Read and interpret the map file that defines the maze layout, textures, and other properties.
- Raycasting: Cast rays to calculate distances to walls and objects in the player's view, creating the 3D-like effect.
- Texturing: Apply textures to walls and other surfaces based on the raycasting results.
- Player movement: Implement controls for player movement, rotation.
- Graphic rendering: Set up a window and render the scene using the MinilibX graphical library
- Game controller handling: Handle game controller inputs by reading the controller input file on a separate thread.

## 💽 Usage
To compile the program, run the following command:
```shell
make
```
It will compile the program and create an executable called "cub3D".<br>


To run the program, simply execute the created executable:
```shell
./cub3D path_to_map.cub
```

This will only give you access to the mandatory part of the project. <br>
To compile the bonus part, run the following command:
```shell
make bonus
```
Then, launch the bonus executable with the following command:
```shell
./cub3D_bonus path_to_map.cub
```



## 🎮 Controller handling
In the bonus part, we implemented a game controller handling feature. <br>
Press "M" on the keyboard to swap beetwen four controller modes: <br>
- Keyboard only
- Keyboard + Mouse
- Controller only (tested with an xbox 360 controller, but should work with any controller)
- Guitar Hero controller (tested with a Guitar Hero 3 controller, but should work with any guitar hero controller)

##  ⚠️ Warning
This project is a part of the 42-Cursus curriculum and is intended for educational purposes. <br>
If you are currently a student in any 42-affiliated campus, we strongly advise you not to copy this project or submit it as your own work, as it goes against the school's academic integrity policy. <br>
We will not be responsible for any misuse of the project or academic penalties that may arise from it. However, you are welcome to use this project as a reference or for learning purposes.

## 🕒 Project Duration
The mandatory part was made in roughly one month. <br>
Every other Bonus features were added in the span of another month.

## 🙇 Author
#### Guillaume d'harcourt
- Github: [@gd-harco](https://github.com/gd-harco)<br>

#### Benoit Roux
- Github: [@BenoitRoux0](https://github.com/BenoitRoux0)<br>
