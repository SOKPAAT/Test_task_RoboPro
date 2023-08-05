# Test_task_RoboPro
"RoboPro Test Task: DH Kinematics for 6-Axis Collaborative Robot"

# Forward Kinematics for a 6-Axis Collaborative Robot

This repository contains a C program that implements the forward kinematics algorithm for a 6-axis collaborative robot based on the Denavit-Hartenberg (DH) parameters. The forward kinematics algorithm allows calculating the position and orientation of the robot's end effector based on the joint angles.

## How it Works

The program utilizes the DH parameters provided in the task description to create the DH transformation matrices for each robot joint. It then performs matrix multiplication to obtain the final transformation matrix representing the robot's position and orientation in its base coordinate system.

## Key Features

- Modular functions for matrix multiplication and DH matrix creation for organized and maintainable code.
- Cross-platform compatibility, can be compiled and executed on Linux operating systems.

## Usage

1. Clone the repository.
2. Go to the /Test directory:
```bash
cd Test
```
3. Compile the C program using the following command in the terminal:
```bash
gcc -o kinematics kinematics.c -lm
```
4. Run the executable to calculate the position and orientation of the robot's end effector:
```bash
./kinematics
```

## Code Highlights

The code demonstrates proficiency in C programming, kinematics, and matrix operations, showcasing an efficient and well-documented solution to the test task provided by RoboPro.

**Note:** This project is part of a test task and serves for demonstration purposes only. It may not cover all real-world scenarios and edge cases.

**Feel free to explore the code, and please reach out if you have any questions or suggestions!**
