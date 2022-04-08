# pra-cpp
This repo contains C++ code of my practical course "Industrial Software Development for Engineers / C++", using ***Eclipse C/C++*** as the IDE on Ubuntu. The project was divided into three parts:<br>
<br>
## 01: Fundamentals of C++ programming<br>
  Datatype, string, pointer, reference, static/dynamic storage reservation <br>
  OOP: class, overload, override, inheritance<br>
  Recursion, data read and write from file, try-catch block, list<br>
  <br>
## 02: Keyboard control of a simulated robot<br>
  Due to COVID-19 we could only do this project online. The robot was simulated in a computergame-like program, which was built with **Unity** (which was contained in a by tutor provided virtual machine), instead of the hardware things. Anyway, a glance at the hardware structure of this robot is still helpful for the understanding of the following works.<br>
  <br>
  ![image](https://user-images.githubusercontent.com/83095045/162421539-3cc86576-c34f-471c-9716-44b2f6b3e84a.png) =800x
  <br>
  In this part, the task is to control the robot using keyboard input. We have to create a class **<*KeyboardCtrl*>**. There are two methods Communicate() and Step() in it, which are enssential for the command transmission and sensor data collecting between the user and the robot.<br>
  The structure of **<*KeyboardCtrl*>** is like this:<br>
  (figure 22)<br>
  ![image](https://user-images.githubusercontent.com/83095045/162405406-44c33c7c-c8fd-4f83-9266-2fa610b8b898.png)<br>

In the method Communicate() we use ***ncurses*** library to get the keyboard input from the user. The class **<*InterfaceSIM*>** was provided by tutor, which was used to transmit data between the method Step() and the robot. Finally, we created a controller class **<*PIDCtrl*>** to make the robot follow the command smoothly.<br>
  (figure 25)
<br>
## 03: Maneuver control of a simulated robot<br>
  In this part, the task is to control the robot with generated maneuvers. There are five classes including the given **<*InterfaceSIM*>**. The other four classes to write are:
  <br>**<*PosEstimation*>**:<br>
  calculate the current actual value of the position array x = (x, y, w) using the current speed and the position values stored by the previous timestep.
  <br>**<*Maneuver*>**:<br>
  serves both the calculation of the coordinates of the maneuver, as well as the calculation of the target speeds to reach the next point of the coordinate list. There are two kinds of maneuvers: circle track and '8'-shape track.
  <br>**<*PIDCtrl*>**:<br>
  provides a PID-controller that adjusts the actual value to the target value smoothly.
  <br>**<*RobotControl*>**:<br>
  the **"master class"**. It manages the call of the functions of each class at the right time and is similar to the <*KeyboardCtrl*> class of the previous part. It initializes objects of the respective classes, has an interface for communication with the user (Communicate()) and provides the interface with a function for iterative calculation of the calculated maneuver (Step()).
  <br>Here is an overview of the architecture.<br>
  ![image](https://user-images.githubusercontent.com/83095045/162412064-659f132d-6b20-48e9-9c94-84003229d2ec.png)

  
  
