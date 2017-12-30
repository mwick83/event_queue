#include "event_queue.h"

event_t event_queue[EVENT_QUEUE_LENGTH];
unsigned int event_queue_read_pointer;
unsigned int event_queue_write_pointer;

void event_queue_init(void)
{
	int i;
	for(i = 0; i < EVENT_QUEUE_LENGTH; i++) {
		event_queue[i].event_valid = false;
	}
	
	event_queue_read_pointer = 0;
	event_queue_write_pointer = 0;
}

int event_queue_push(event_t event)
{
	if(event_queue[event_queue_write_pointer].event_valid) {
		// overflow
		return -1;
	} else {
		event_queue[event_queue_write_pointer] = event;
		event_queue[event_queue_write_pointer].event_valid = true;
		event_queue_write_pointer++;
		if(event_queue_write_pointer >= EVENT_QUEUE_LENGTH) event_queue_write_pointer = 0;
		return 0;
	}
}

event_t event_queue_pop(void)
{
	event_t ev;
	
	if(!event_queue[event_queue_read_pointer].event_valid) {
		// no event there...
		ev = event_queue[event_queue_read_pointer];
	} else {
		ev = event_queue[event_queue_read_pointer];
		event_queue[event_queue_read_pointer].event_valid = false;
		event_queue_read_pointer++;
		if(event_queue_read_pointer >= EVENT_QUEUE_LENGTH) event_queue_read_pointer = 0;
	}
	
	return ev;
}

int event_queue_has_elements(void)
{
	if(event_queue[event_queue_read_pointer].event_valid) {
		return 1;
	} else {
		return 0;
	}
}
