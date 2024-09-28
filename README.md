# Gyroscopic_motion
This motion solved is created by modifying "rotatingMotion" solidBodyMotionSolver of OpenFOAM v12 to define local as well as global axis of rotation instead of single axis of rotation. It is tested only in OpenFOAM v12.
A sample of usage of this solver in dynamicMeshDict is given in the simple tutorial which can be executed using Allrun script. Pretty much everything in dynamicMeshDict is self explainatory.
It is recommended to move the motionSolvers folder to src folder in working user directory.
Navigate to motionSolvers directory in bash and run wmake libso to compile the code and your new motion solver is ready!
Any suggestion on improving the code/adding new functionality/more generalization is highly appreciated.
