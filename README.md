# Industrial Software Development for Engineers / C++

This repo contains the code of my practical course **"Industrial Software Development for Engineers / C++"**. The code were edited with the IDE **Eclipse C/C++** on the **Ubuntu** OS. The project consists of the following three parts:<br>
<br>
## 01: Fundamentals of C++ programming

**Tag1:** Data type, string, pointer, reference, static/dynamic storage reservation.<br>
**Tag2:** OOP: class, overload, override, inheritance.<br>
**Tag3:** Recursion, data read and write from the file, try-catch block, list.<br>
<br>
## 02: Keyboard control of a simulated robot
Due to the COVID-19 pandemic, this project was organized online. Instead of the hardware things, the robot was simulated using **Unity** engine. Anyway, having a glance at the robot's hardware structure helps to understand our following works:<br>
<br>
<img src="https://user-images.githubusercontent.com/83095045/162617975-0fa988e1-b323-481f-8dad-53976ae8b847.png" width="700"><br>
<br>
*To whom wants to replicate this project:<br>
All the required libraries (ncurses, jsoncpp, rt ...) and the "MoonRover" simulation program were already provided by the tutor in the virtual machine **Ubuntu_IDE_SEFI_Online**. If you are interested in this project and want to replicate it, it is recommended to edit and run the codes on this virtual machine using **VMware Player**.*<br>
(*download “Ubuntu_IDE_SEFI_Online”*).<br>
<br>
**Tag4:**<br>
The task of this part is to control the robot with the keyboard input. We have to create a class **<*KeyboardControl*>** to establish the data stream between the user and the robot. It contains two methods: **Communicate()** and **Step()**. The structure of <KeyboardControl> seeing below:<br>
<br>
  ![image](https://user-images.githubusercontent.com/83095045/162619854-ecc6c23d-d7ea-4646-ac79-c057a62cbe6a.png)<br>
<br>
In the method **Communicate()** we use the library ***ncurses*** to get the keyboard input from the user. The class **<*InterfaceSIM*>** was provided by the tutor, which is used to transmit data between the method **Step()** and the robot. Finally, we created a controller class **<*PIDCtrl*>** to make the robot follow the command smoothly.<br>
<br>
**Demo Tag4:**<br>
  <br>
 ![demo_tag4](./Demo/demo_tag4.gif)<br>
<br>
  commands:  
  | input | action |
  | :----: | :----: |
  | 'w', 'a', 's', 'd' | directions |
  | 'b' | brake |
  | 'q' | quit the control panel |
  
  
<br>
## 03: Maneuver control of a simulated robot
**Tag5:**<br>
The task of this part is to control the robot with two generated maneuvers: a circle trajectory and an 8-shaped trajectory. Besides the given class **<*InterfaceSIM*>** there are four more classes to write:<br>
<br>
**<*PosEstimation*>:**<br>
calculate the current actual value of the position array x = (x, y, w) using the current speed and the position values stored by the previous timestep.<br>
<br>
**<*Maneuver*>:**<br>
serves both the calculation of the coordinates of the maneuver, as well as the calculation of the target speeds to reach the next point of the coordinate list. There are two kinds of maneuvers: circle track and '8'-shape track.<br>
<br>
**<*PIDCtrl*>:**<br>
provides a PID controller that adjusts the actual value to the target value smoothly.<br>
<br>
**<*RobotControl*>:**<br>
the **"master class"**. It manages the call of the functions of each class at the right time and is similar to the **<*KeyboardControl*>** class of the previous part. It initializes objects of the respective classes, has an interface for communication with the user (**Communicate()**) and provides the interface with a function for iterative calculation of the calculated maneuver (**Step()**).<br>
  <br>
Here is an overview of the entire architecture:<br>
![image](https://user-images.githubusercontent.com/83095045/162617954-79e56018-e1f9-4385-89cc-f04eeee86cc4.png)<br>
 <br>

**Demo Tag5:**<br>
| circle | 8-shaped |
| :---- | :---- |
| <img src="./Demo/demo_tag5_circle.gif" width="600"> | <img src="./Demo/demo_tag5_8.gif" width="600"> |
| Radius = 0.5m | Radius = 0.3m |
|Speed = 0.3m/s | Speed = 0.3m/s|
  
  
  commands:  
  [1]: start;  
  [2]: stop;  
  [3]: proceed.  
  <br>
For detailed tutorials, please check the script **[2022-03-27_SEPR_Skript.pdf]** (in German language).<br>
© Copyright AIS, TUM 2022
