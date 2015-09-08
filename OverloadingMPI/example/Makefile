# Tariq Alturkestani
# Sept - 8 - 2015

hello: helloWorld.c
	mpicc helloWorld.c -o hello

overrided: helloWorld.c
	mpicc -L/home/alturktl/Research/HOW_TO/OverloadingMPI/lib helloWorld.c -ltariqmpi -lmpi -o helloWithOverRides
clean:
	rm  hello helloWithOverRides
