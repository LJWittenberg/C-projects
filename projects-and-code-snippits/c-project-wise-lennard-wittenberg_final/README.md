Conway's Game of Life implementation by Lennard Wittenberg in the language C
============================================================================
In this project contains my attempt at the project Game of Life by John Conway. written in C and complied with make.

## What is the Game of Life short explenation 
This is the describtion by the Cornell University  
The Game of Life (an example of a cellular automaton ) is played on an infinite two-dimensional rectangular grid of cells. Each cell can be either alive or dead. The status of each cell changes each turn of the game (also called a generation) depending on the statuses of that cell's 8 neighbors.

## current project state
date 25.03.2024  
The core functionality of the Game of Life is in working order. The simulation is behaving as expected. All files compile without any errors, and the code coverage is 100 percent. The simulation is currently being visualized through console printing. Therefore, a possible improvement could be to use SDL2 instead. However, as of this moment, there are no plans on making those changes.

## How access and use the project.
After downloading the project. Open a new terminal and  
1.) Enter the project folder with the cd command.  
2.) Input the make command into the terminal  
3.) Enter the new release folder with the cd command. cd build/release/  
4.) Enter ./game_of_life and than a series of number pairs like 0 0 0 1 1 1 two numbers form a pair and it is important to leave spaces between each number.  
note: The rules and specialties of this project are detailed in the file placerholder.
[![pipeline status](https://gitlab.rz.htw-berlin.de/Lennard.Wittenberg/c-wise-lennard-wittenberg/badges/main/pipeline.svg)](https://gitlab.rz.htw-berlin.de/Lennard.Wittenberg/c-wise-lennard-wittenberg/-/commits/main)







