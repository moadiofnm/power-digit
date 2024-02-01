all:
	g++ -o dow power-digit-sum.cpp 
run: 
	./dow

try: all run 