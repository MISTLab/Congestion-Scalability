# Congestion and Scalability in Robot Swarms: a Study on Collective Decision Making 


## Setting up the simlations for Line and Star in Argos3 and Buzz.

ARGoS3 Simulator ARGoS3 simulator can also be installed from binaries please refer to the official website for more information: https://www.argos-sim.info/
The instructions below are for installing ARGoS3 from its source.
Official code repository: https://github.com/ilpincy/argos3
Dependencies for ARGoS3 can be installed using the following command:

```
sudo apt-get install cmake libfreeimage-dev libfreeimageplus-dev \
qt5-default freeglut3-dev libxi-dev libxmu-dev liblua5.3-dev \
lua5.3 doxygen graphviz graphviz-dev asciidoc
```
Installations for Argos3 

```
$ git clone https://github.com/ilpincy/argos3.git argos3
$ cd argos3
$ mkdir build_simulator
$ cd build_simulator
$ cmake ../src
$ make
$ sudo make install
```

Installations for Buzz

```
$ cd Buzz
$ mkdir build
$ cd build
$ cmake ../src
$ sudo make install
$ sudo ldconfig
```

Installations for Khepera V

```
$ git clone https://github.com/ilpincyargos3-kheperaiv.git
$ mkdir build_sim
$ cd build_sim
$ cmake -DCMAKE_BUILD_TYPE=Release ../src
$ make
$ sudo make install
```

Building the loop function for ARGoS:

```
$ cd loop_fun_src/
$ mkdir build
$ cd build/
$ cmake ..
$ make
```
