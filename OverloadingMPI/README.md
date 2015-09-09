A small "how to" note could be found here:
http://www.alturkestani.com/#!Overriding-MPI-calls/c1mbt/55dd084b0cf2083e080fb57c

cd to lib and do:
chmod +x ./compile.sh

add the path to lib into LD_LUBRARY_PATH

cd to example and 
make hello
make overrided

run with:

mpirun -np 2 ./hello 
and 
mpirun -np 2 ./helloWithOverRides 

