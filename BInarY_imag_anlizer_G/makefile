output: test_main_binaryimg.o
	g++ test_main_binaryimg.o image_Byte8.o -o output_01

test_main_binaryimg.o: main.v2.cpp image_byte8.h
	g++ -c main.v2.cpp

image_Byte8.o: image_Byte8.cpp image_byte8.h
  g++ -c image_Byte8.cpp

clean:
	rm *.o output_01
