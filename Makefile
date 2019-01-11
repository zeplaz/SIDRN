output: test_main_SIDRN.o
	g++ test_main_SIDRN.o -o output_01

test_main_SIDRN.o: test_main_SIDRN.cpp
	g++ -c test_main_SIDRN.cpp

clean:
	rm *.o output_01
