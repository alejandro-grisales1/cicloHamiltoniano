ce:
	g++ controller/main.cpp -o program.exe
	./program.exe

gdb:
	g++ -g controller/main.cpp -o program.exe
	gdb ./program.exe

valgrind:
	g++ controller/main.cpp -o program.exe
	valgrind --leak-check=full ./program.exe

clean:
	rm *.exe
