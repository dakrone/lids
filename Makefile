lids: 
	g++ -Wall -c -o lidscore.o lidscore.cxx
	g++ -Wall -c -o lids.o lids.cxx
	g++ -Wall -lpcap -o lids lidscore.o lids.o

run: lids
	./lids

clean:
	rm *.o
	rm lids
