all:server
server:s_dir.o s_enter.o s_main.o s_network.o
	gcc -o server s_dir.o s_enter.o s_main.o s_network.o
	rm *.o 
	mv server ../bin/
s_dir.o:s_dir.c
	gcc -c s_dir.c -o s_dir.o
s_enter.o:s_enter.c
	gcc -c s_enter.c -o s_enter.o
s_mian.o:s_main.c
	gcc -c s_main.c -o s_main.o
s_network.o:s_network.c
	gcc -c s_network.c -o s_network.o

