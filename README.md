Freyja
======

2015 Recycle Rush robot

Freyja is structured based on 4 tiers, Freyja, Controllers, Robot, and Subsystems.

At the top, there is Freyja, the representation of the FRC IterativeRobot. It contains the Init, Periodic, and Disable methods so that our robot can cycle through the different phases of the game (Autonomous and Teleop). These methods delegate control of the robot to Autonomous Controller and Human Controller based on the state the robot is in.

Autonomous Controller and Human Controller are the next part. These contain the logic for what our robot should do during each phase. Autonomous Controller contains the strings of commands that our robot needs to execute for its path during autonomous, while Human Controller translates joystick input into commands for our robot. These commands are calls to Robot to perform actions or specific series of actions.

Robot is the representation of the physical robot. It contains the subsystems that our robot has, Drivetrain, Lifter, and Arm. It contains the commands the robot can perform by delegating methods to the subystems, or in some cases, chaining commands to subsystems in order to execute a common series of tasks.

Finally each subsystem is one of the main parts of our robot's functionality. They each contain private and public methods in order to perform or encapsulate specific functions

More detail is in the Freyja wiki (found in the sidebar to the right).
