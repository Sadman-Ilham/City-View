# City View
View the City in 3D Mode

#### Features

- Press 1 to rotate the view from right to left
- Keep Pressing 1 to increase the speed of rotation
- Press 2 to rotate the view from left to right
- Keep Pressing 2 to increase the speed of rotation
- Press 3 to stop the rotation

#### Run
###### Ubuntu
- Make sure the GL/glut.h file is installed in your system. 
  If not then install it from <strong>freeglut3-dev</strong> package by the following command line -
  - sudo apt-get install freeglut3-dev
- g++ CityView.cpp -o out -lGL -lGLU -lglut (This command line will produce an executable file called 'out')
- ./out (This will produce the output)

*`Compile process for Windows is Comming soon ... ... ...`*

#### Output
![city_view_1](https://github.com/Sadman-Ilham/City-View/blob/master/img/view_1.png)
![city_view_2](https://github.com/Sadman-Ilham/City-View/blob/master/img/view_2.png)
![city_view_3](https://github.com/Sadman-Ilham/City-View/blob/master/img/view_3.png)
