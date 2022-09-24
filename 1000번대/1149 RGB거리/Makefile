CXXFLAGS -Wall -std=c++17 -g -pedantic -fsanitize=address

main:	main.o
	$(CXX) -o $@ $^ -fsanitize=address

.phony:	clean
clean:
	$(RM)	main *.o