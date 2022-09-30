# Minesweeper

A basic minesweeper game played in the console that reads its config from a text file

Currently being rewritten to include the following changes:
-enter game parameters on program start start instead of using a config file
-Dynamic board 2d array allocation (originally used an preallocated array of 100x100 that was filled with the appropriate number of Spaces)
-Functions to allow for a GUI interface in the future
-Mine generation that will always generate solvable games (using algorithms detailed in [this project paper](https://dspace.cvut.cz/bitstream/handle/10467/68632/F3-BP-2017-Cicvarek-Jan-Algorithms%20for%20Minesweeper%20Game%20Grid%20Generation.pdf?sequence=-1&isAllowed=y) by Jan Cicvárek on Minesweeper Game Grid Generation)

Future plans:
-Create a GUI for playing instead of the command line
-Create save files that can be loaded to resume a game at a later date (something nobody will ever use)
-Timer and/or scoring system
-Ability to share scores on social media (again, will never be used)
-Port to an android app (tbd if I'll actually end up doing this)

Currently just using the stndard C and C++ libraries because I enjoy pain, lets see how long that lasts. Who knows, maybe I'll even try to write my own simple graphics library for the gui
