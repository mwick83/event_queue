#ifndef EVENT_QUEUE_H_
#define EVENT_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#ifndef EVENT_QUEUE_LENGTH
#define EVENT_QUEUE_LENGTH 32
#endif


typedef struct
{
	bool		event_valid;
	uint32_t	event_type;
	void		(*event_handler)(void*);
	void		*event_data;
} event_t;


void event_queue_init(void);
int event_queue_push(event_t event);
event_t event_queue_pop(void);
int event_queue_has_elements(void);

#ifdef __cplusplus
}
#endif

#endif /*EVENT_QUEUE_H_*/
