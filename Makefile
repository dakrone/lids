# regular compile
CC = g++ -Wall
# For debug (uncomment)
CC = g++ -g -Wall -DDEBUG


lids: lids.o lidscore.o testevent.o lidsevent.o lidsbuffer.o lidsrunner.o
	${CC} -lpcap -o lids lidsrunner.o lidsbuffer.o lidsevent.o testevent.o lidscore.o lids.o

lidsrunner.o: lidsrunner.cxx
	${CC} -c lidsrunner.cxx

lidsevent.o: lidsevent.cxx
	${CC} -c lidsevent.cxx

lidsbuffer.o: lidsbuffer.cxx
	${CC} -c lidsbuffer.cxx

testevent.o: testevent.cxx
	${CC} -c testevent.cxx

lidscore.o: lidscore.cxx
	${CC} -c lidscore.cxx

lids.o: lids.cxx
	$(CC) -c lids.cxx

remake: clean lids

run: lids
	./lids

clean:
	rm -f *.o
	rm -f lids
