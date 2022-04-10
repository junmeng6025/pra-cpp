# pra-cpp
<br>
This repo contains the C++ code of my practical course "Industrial Software Development for Engineers / C++", edited with the IDE Eclipse C/C++ on Ubuntu. The project was divided into the following three parts:<br>
## 01: Fundamentals of C++ programming<br>
**Tag1:** Data type, string, pointer, reference, static/dynamic storage reservation.<br>
**Tag2:** OOP: class, overload, override, inheritance.<br>
**Tag3:** Recursion, data read and write from the file, try-catch block, list.<br>
<br>
## 02: Keyboard control of a simulated robot<br>
Due to the COVID-19 pandemic, this project was organized online. Instead of the hardware things, the robot was simulated virtually in a program, which was launched by **Unity.** Anyway, a glance at the hardware structure of this robot helps to understand the following works:

Fig 1. The hardware structure and the rendered simulation of the “MoonRover” Robot.

To whom wants to replicate this project:<br>

All the required libraries (ncurses, jsoncpp, rt ...) and the **"MoonRover"** simulation program were already provided by the tutor in the virtual machine **Ubuntu\_IDE\_SEFI\_Online**. If you are interested in this project and want to replicate it, it is recommended to edit and run the codes on this virtual machine using **VMware Player**. (*download “Ubuntu\_IDE\_SEFI\_Online”*).

**Tag4:**
The task of this part is to control the robot with the keyboard input. We have to create a class **<*KeyboardControl*>** to establish the data stream between the user and the robot. It contains two methods: **Communicate()** and **Step()**. The structure of **<*KeyboardControl*>** seeing below:

Fig 2. The concept of the class <KeyboardControl>.


In the method **Communicate()** we use the library ***ncurses*** to get the keyboard input from the user. The class **<*InterfaceSIM*>** was provided by the tutor, which is used to transmit data between the method **Step()** and the robot. Finally, we created a controller class **<*PIDCtrl*>** to make the robot follow the command smoothly.

## 03: Maneuver control of a simulated robot
Tag5:
The task of this part is to control the robot with two generated maneuvers: a circle trajectory and an 8-shaped trajectory. Besides the given class **<*InterfaceSIM*>** there are four more classes to write:
**<*PosEstimation*>:**
calculate the current actual value of the position array x = (x, y, w) using the current speed and the position values stored by the previous timestep.
**<*Maneuver*>:**
serves both the calculation of the coordinates of the maneuver, as well as the calculation of the target speeds to reach the next point of the coordinate list. There are two kinds of maneuvers: circle track and '8'-shape track.
**<*PIDCtrl*>:**
provides a PID controller that adjusts the actual value to the target value smoothly.
**<*RobotControl*>:**
the **"master class"**. It manages the call of the functions of each class at the right time and is similar to the ***<KeyboardControl>*** class of the previous part. It initializes objects of the respective classes, has an interface for communication with the user (**Communicate()**) and provides the interface with a function for iterative calculation of the calculated maneuver (**Step()**).
Here is an overview of the entire architecture:

![](Aspose.Words.c3a8efe9-1afd-4505-b4c1-aa4a3278a362.003.png)

Fig 3. The concept of the
