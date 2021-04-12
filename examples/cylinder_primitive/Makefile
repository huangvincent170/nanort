all:
	# g++ -O2 -g -o cylinder_render -I../../ -I. main.cc
	# verilator -Wall --cc our.v --exe --build sim_main.cpp
	# verilator -Wall --cc our.v --exe --build main.cc -O2 -o cylinder_render -I~/cs3220/nanort/ -I~/cs3220/nanort/examples/cylinder_primitive/ main.cc
	verilator -Wall --cc ../../intersector.v --exe --build main.cc -O2 -o cylinder_render -I~/cs3220/nanort/ -I~/cs3220/nanort/examples/cylinder_primitive/ main.cc
