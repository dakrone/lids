lids: 
	g++ -Wall -c -o lidsevent.o lidsevent.cxx
	g++ -Wall -c -o lidscore.o lidscore.cxx
	g++ -Wall -c -o lids.o lids.cxx
	g++ -Wall -lpcap -o lids lidsevent.o lidscore.o lids.o

run: lids
	./lids

clean:
	rm *.o
	rm lids
