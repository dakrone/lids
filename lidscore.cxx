#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "lidscore.h"
#include "lidsbuffer.h"

using namespace std;

/*
 * Temporary code, this is the beginning template for  code that will
 * eventually kick off all the pcap captures, threading and packet-hand-
 * offing to the event handlers, which will generate alert messages.
 *
 * This, of course, assumes that everything works like I want it to, but hey,
 * aren't all projects like that?
 */
LIDSCore::LIDSCore()
{
}

LIDSCore::~LIDSCore()
{
}

int LIDSCore::register_event(LIDSEvent *e)
{
      return 0;
}

void LIDSCore::process()
{
}

void LIDSCore::dispatch()
{
}

void LIDSCore::store()
{
}

