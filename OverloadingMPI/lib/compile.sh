rm *.o *.so *.so.1 *.so.1.0
 
gcc -w -fPIC -c mpi_overrice.c 

gcc -shared -Wl,-soname,libtariqmpi.so.1 -o libtariqmpi.so.1.0 *.o

ln -sf libtariqmpi.so.1.0 libtariqmpi.so.1
ln -sf libtariqmpi.so.1.0 libtariqmpi.so

