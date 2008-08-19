CC = g++ -Wall

lids: lids.o lidscore.o testevent.o lidsevent.o lidsbuffer.o
	${CC} -lpcap -o lids lidsbuffer.o lidsevent.o testevent.o lidscore.o lids.o

lidsevent.o:
	${CC} -c lidsevent.cxx

lidsbuffer.o:
	${CC} -c lidsbuffer.cxx

testevent.o:
	${CC} -c testevent.cxx

lidscore.o:
	${CC} -c lidscore.cxx

lids.o:
	$(CC) -c lids.cxx

run: lids
	./lids

clean:
	rm -f *.o
	rm -f lids
