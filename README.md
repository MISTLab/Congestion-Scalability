# Congestion and Scalability in Robot Swarms: a Study on Collective Decision Making 


To cite us:
```
@misc{soma2023congestion,
      title={Congestion and Scalability in Robot Swarms: a Study on Collective Decision Making}, 
      author={Karthik Soma and Vivek Shankar Vardharajan and Heiko Hamann and Giovanni Beltrame},
      year={2023},
      eprint={2307.08568},
      archivePrefix={arXiv},
      primaryClass={cs.RO}
}
```








## Setting up the simulations for Honey Bee, Stigmergy and Divison of Labor approaches in Argos3 and Buzz.

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

Building the Buzz scripts:

```
cd buzz_scripts
bzzc -I includes/ HoneyBee_pm.bzz
bzzc -I includes/ HoneyBee_wpm.bzz
bzzc -I includes/ StigmergyDatabase.bzz
bzzc -I includes/ StigmergyConsensus.bzz
bzzc -I includes/ DivsionOfLabor.bzz
```

##Data Processing files:

Refer to `data_processing/HoneyBee.ipynb` for the Honey Bee approach, `data_processing/Stigmergy.ipynb` for the Stigmergy approach and `data_processing/DivisionOfLabor.ipynb` for the Divison of labor approach. 



##Parameters to change:

For examples check the files `DDMkhepera_HoneyBee.argos`, `DDMkhepera_stigmergy_divisonoflabor.argos` and `DDMkhepera_stigmergy.argos`.

```
<loop_functions library="BINARY_FILE_OF_BUILD_FILE_LOOPFUNCTION"
                  label="LABEL NAME" 
                  robots = "NUMBER OF ROBOTS"
                  dir = "DATA FILE OUTPUT DIRECTORY"
                  seed = "SEED NUMBER"
                  rab_range = "RANGE OF ROBOTS"
                  rab_range_beacon = "RANGE OF BEACONS"
                  rab_data_size = "MESSAGE SIZE IN BYTES"
                  fill_ratio_white = "ZONE A FILL RATIO"
                  fill_ratio_black = "ZONE B FILL RATIO"
                  out_file = "OUTPUT FILE CLASS NAME"/>
```