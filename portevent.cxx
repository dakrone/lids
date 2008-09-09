#include <iostream>

#include "portevent.h"
#include "lidsdebug.h"

using namespace std;

PortEvent::PortEvent()
{
	/* if a port occurs in less than X percent of all these packets... */
	low_port_threshold = 5; /* 5% */
}

PortEvent::~PortEvent()
{
}

bool PortEvent::process_packet(LIDSBuffer* buff)
{
	IN();
	bool threw_alarm = false;

	int** plist = buff->get_port_list();
	if (plist == NULL) {
		return false;
	}
	for (u_int i = 0; i < buff->get_packet_count(); i++) {
		/*
		 * grab port, add to a list, tell if the list has x% or less of
		 * those ports in the packets
		 */
		/* do something with the packet */
		cout << "port: " << plist[0][0] << endl;
	}

	OUTd(threw_alarm);
	return threw_alarm;
}

char* PortEvent::get_event_name()
{
	IN();
	OUT();
	return (char*)"Port Event";
}
