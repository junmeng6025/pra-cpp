# pra-cpp
This repo contains C++ code of my practical course "Industrial Software Development for Engineers / C++"<br>
Using Eclipse IDE on Ubuntu.<br>
There are three parts:<br>
**01: Fundamentals of C++ programming**<br>
  Datatype, string, pointer, reference, static/dynamic storage reservation <br>
  OOP: class, overload, override, inheritance<br>
  recursion, data read and write from file, try-catch block, list<br>
  <br>
**02: Keyboard control of a simulated robot**<br>
  due to COVID-19 we could only do this project online. The robot was simulated in a computergame-like program, which was built with Unity, instaed of the hardware things. Anyway, a glance at hardware construction of this robot is still helpful to the understanding of the following work.<br>
  (figure 19)
  <br>
  In this part, the task is to control the robot using keyboard input. We have to create a class *KeyboardCtrl*, and there are two methods "Communicate" and "Step" in it, which are enssential for the command transmission and sensor data collecting between the user and the robot.<br>
  The structure of *KeyboardCtrl* is like this:<br>
  ![image](https://user-images.githubusercontent.com/83095045/162403796-019f02f0-e987-4af9-bc3e-345ab9112ad1.png)<br>
In the method Communicate we use ***ncurses*** library to get the keyboard input from the user.<br>
<br>
**03: Maneuver control of a simulated robot**<br>
  
