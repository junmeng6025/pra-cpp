# pra-cpp
This repo contains C++ code of my practical course "Industrial Software Development for Engineers / C++", using ***Eclipse C/C++*** as the IDE on Ubuntu.<br>
There are three parts:<br>
**01: Fundamentals of C++ programming**<br>
  Datatype, string, pointer, reference, static/dynamic storage reservation <br>
  OOP: class, overload, override, inheritance<br>
  recursion, data read and write from file, try-catch block, list<br>
  <br>
**02: Keyboard control of a simulated robot**<br>
  due to COVID-19 we could only do this project online. The robot was simulated in a computergame-like program, which was built with Unity (which was contained in a by tutor provided virtual machine), instead of the hardware things. Anyway, a glance at hardware construction of this robot is still helpful to the understanding of the following work.<br>
  (figure 19)
  <br>
  In this part, the task is to control the robot using keyboard input. We have to create a class *KeyboardCtrl*, and there are two methods Communicate() and Step() in it, which are enssential for the command transmission and sensor data collecting between the user and the robot.<br>
  The structure of *KeyboardCtrl* is like this:<br>
  (figure 22)<br>
  ![image](https://user-images.githubusercontent.com/83095045/162405406-44c33c7c-c8fd-4f83-9266-2fa610b8b898.png)<br>

In the method Communicate() we use ***ncurses*** library to get the keyboard input from the user. The class *InterfaceSIM* was provided by tutor, which was used to transmit data between the method Step() and the robot. Finally, we created a controller class *PIDCtrl* to make the robot follow the command smoothly.<br>
  (figure 25)
<br>
**03: Maneuver control of a simulated robot**<br>
  In this part, the task is to control the robot with generated maneuvers. There are five classes including the given *InterfaceSIM*. The other four classes to write are:
  <br>*PosEstimation*:
  <br>*Maneuver*:
  <br>*PIDCtrl*:
  <br>*RobotControl*:
  
