cd to lib and do:
chmod +x ./compile.sh

cd to example and 
make hello
make overrided

run with:

mpirun -np 2 ./hello 
and 
mpirun -np 2 ./helloWithOverRides 

