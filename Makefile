compile: 
	g++ -fPIC main.cpp template.cpp utils.cpp -ldl 


run: 
	./a.out


clean:
	rm *.so
	rm *.gch
	rm *.out
