This C++ project aims to develop a remote-controlled robot system for performing surveillance missions in two specified areas. The robot can move in four directions (north, south, east, west), with each movement having a fixed distance. The objective is to implement a C++ program that enables control of the robot's movements on a coordinate map.

Project Files and Descriptions:

Robot.h: This header file defines the Robot class, which represents individual robots with unique sequential identifiers. It also includes function declarations related to the Robot class.

Robot.cpp: This C++ file provides the implementation for the Robot class. It includes member functions for the Robot class, allowing for the creation and management of robot instances.

Map.h: In this header file, the Map class is defined, which represents two-dimensional maps containing '0's (passable) and '1's (impassable). The X-coordinate designates columns, while the Y-coordinate represents rows.

Map.cpp: This C++ file contains the implementation of the Map class. It includes functions for creating, accessing, and manipulating maps. The maps are expected to remain constant during runtime.

Game.h: The Game header file includes declarations for the Game class, which acts as the central orchestrator of the robot missions. It manages the robots and maps.

Game.cpp: This C++ file provides the implementation of the Game class. The Game class handles the creation of new robots and their placement on maps, as well as controlling their movements based on user input.

main.cpp: The main program file is where the program execution begins. It sets up the environment, interacts with users, and manages robot missions using the defined classes.
