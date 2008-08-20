CC = g++ -Wall

lids: lids.o lidscore.o testevent.o lidsevent.o lidsbuffer.o
	${CC} -lpcap -o lids lidsbuffer.o lidsevent.o testevent.o lidscore.o lids.o

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

run: lids
	./lids

clean:
	rm -f *.o
	rm -f lids
