all:client
client:c_dir.o c_enter.o c_main.o c_network.o
	gcc -o client c_dir.o c_enter.o c_main.o c_network.o
	rm *.o 
	mv client ../bin/
c_dir.o:c_dir.c
	gcc -c c_dir.c -o c_dir.o
c_enter.o:c_enter.c
	gcc -c c_enter.c -o c_enter.o
c_mian.o:c_main.c
	gcc -c c_main.c -o c_main.o
c_network.o:c_network.c
	gcc -c c_network.c -o c_network.o

