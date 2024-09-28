
# Gyroscopic Motion Solver for OpenFOAM

## Introduction
A custom solidBodyMotionSolver for OpenFOAM, extending the rotatingMotion solver to support local and global axes of rotation.


## Features

* Supports local and global axes of rotation
* Compatible with OpenFOAM v12
* Tested with tutorial of water in a tank performing gyroscopic motion


## Usage

### Installation

1. Move motionSolvers folder to src directory.
2. Navigate to motionSolvers and run `wmake libso`.

### Integration

1. Update dynamicMeshDict with provided sample.
2. Run Allrun script for tutorial.


## Requirements
OpenFOAM v12


## License
This project is licensed under the MIT License. See LICENSE file for details.


## Contributing
Pull requests welcome! Contact VAIBHAV V B for feedback.


## Authors
VAIBHAV V B


## Acknowledgments
Dynamics and Control of Mechanical Systems - NPTEL course - Prof. Ashitava Ghosal
OpenFOAM v12 documentation, Coding Style Guide



