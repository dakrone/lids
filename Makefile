# regular compile
CC = g++ -Wall
# semi-debug (no crazy call trees)
#CC = g++ -g -O0 -Wall
# For debug (uncomment)
#CC = g++ -g -O0 -Wall -DDEBUG


lids: lids.o lidscore.o testevent.o lidsevent.o lidsbuffer.o lidsrunner.o lidsalarm.o portevent.o
	${CC} -lpcap -o lids lidsrunner.o lidsalarm.o lidsbuffer.o lidsevent.o testevent.o portevent.o lidscore.o lids.o

lidsalarm.o: lidsalarm.cxx
	${CC} -c lidsalarm.cxx

lidsrunner.o: lidsrunner.cxx
	${CC} -c lidsrunner.cxx

lidsevent.o: lidsevent.cxx
	${CC} -c lidsevent.cxx

lidsbuffer.o: lidsbuffer.cxx
	${CC} -c lidsbuffer.cxx

testevent.o: testevent.cxx
	${CC} -c testevent.cxx

portevent.o: portevent.cxx
	${CC} -c portevent.cxx

lidscore.o: lidscore.cxx
	${CC} -c lidscore.cxx

lids.o: lids.cxx
	$(CC) -c lids.cxx

remake: clean lids

run: lids
	sudo ./lids

clean:
	rm -f *.o
	rm -f lids
