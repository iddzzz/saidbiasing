# saidbiasing
Geant4 application implementing cell importance biasing with very simple geometrical/detector construction

## How to compile and run the simulation
You can use the normal way to compile and run a Geant4 simulation. Here is what I usually did.
1. Open your terminal
2. Do `source` your Geant4 variables
3. Go to the directory containing these files
4. To run with visualization: `mkdir build && cd build && cmake .. && make && ./saidbiasing`
5. To run with custom macro command: `mkdir build && cd build && cmake .. && make && ./saidbiasing <yourmacrofile.mac>`
