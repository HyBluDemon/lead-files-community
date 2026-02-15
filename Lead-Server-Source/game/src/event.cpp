/*
 *    Filename: event.c
 * Description: Event related (timed event)
 *
 *      Author: Hanjoo Kim (aka. Rain leaves , Cronan), Youngjin Song (aka. myevan, broomstick )
 */
#include "stdafx.h"

#include "event_queue.h"

extern void ContinueOnFatalError();
extern void ShutdownOnFatalError();

static CEventQueue cxx_q;

/* Creates and returns an event */
LPEVENT event_create_ex(TEVENTFUNC func, event_info_data* info, long when)
{
	LPEVENT new_event = NULL;

	/* Must next pulse Please call after more time has passed. . */
	if (when < 1)
		when = 1;

	new_event = M2_NEW event;

	assert(NULL != new_event);

	new_event->func = func;
	new_event->info	= info;
	new_event->q_el	= cxx_q.Enqueue(new_event, when, thecore_heart->pulse);
	new_event->is_processing = FALSE;
	new_event->is_force_to_end = FALSE;

	return (new_event);
}

/* Remove events from the system */
void event_cancel(LPEVENT * ppevent)
{
	LPEVENT event;

	if (!ppevent)
	{
		sys_err("null pointer");
		return;
	}

	if (!(event = *ppevent))
		return;

	if (event->is_processing)
	{
		event->is_force_to_end = TRUE;

		if (event->q_el)
			event->q_el->bCancel = TRUE;

		*ppevent = NULL;
		return;
	}

	// Has it already been canceled? ?
	if (!event->q_el)
	{
		*ppevent = NULL;
		return;
	}

	if (event->q_el->bCancel)
	{
		*ppevent = NULL;
		return;
	}

	event->q_el->bCancel = TRUE;

	*ppevent = NULL;
}

void event_reset_time(LPEVENT event, long when)
{
	if (!event->is_processing)
	{
		if (event->q_el)
			event->q_el->bCancel = TRUE;

		event->q_el = cxx_q.Enqueue(event, when, thecore_heart->pulse);
	}
}

/* Execute events when the time to execute the event arrives. */
int event_process(int pulse)
{
	long	new_time;
	int		num_events = 0;

	// event_q That is, the current time is greater than the time of the head of the event queue. pulse If there is less, the loop statement 
	// It won't turn .
	while (pulse >= cxx_q.GetTopKey())
	{
		TQueueElement * pElem = cxx_q.Dequeue();

		if (pElem->bCancel)
		{
			cxx_q.Delete(pElem);
			continue;
		}

		new_time = pElem->iKey;

		LPEVENT the_event = pElem->pvData;
		long processing_time = event_processing_time(the_event);
		cxx_q.Delete(pElem);

		/*
		 * The return value is the new time and the return value is 0 If it is larger than that, add the event again. . 
		 * return value 0 If you do more than this event To avoid deleting memory information allocated to
		 * Be careful .
		 */
		the_event->q_el = NULL;
		the_event->is_processing = TRUE;

		if (!the_event->info)
		{
			the_event->q_el = NULL;
			ContinueOnFatalError();
		}
		else
		{
			//sys_log(0, "EVENT: %s %d event %p info %p", the_event->file, the_event->line, the_event, the_event->info);
			new_time = (the_event->func) (get_pointer(the_event), processing_time);
			
			if (new_time <= 0 || the_event->is_force_to_end)
			{
				the_event->q_el = NULL;
			}
			else
			{
				the_event->q_el = cxx_q.Enqueue(the_event, new_time, pulse);
				the_event->is_processing = FALSE;
			}
		}

		++num_events;
	}

	return num_events;
}

/* Event execution time pulse Returns in units */
long event_processing_time(LPEVENT event)
{
	long start_time;

	if (!event->q_el)
		return 0;

	start_time = event->q_el->iStartTime;
	return (thecore_heart->pulse - start_time);
}

/* The remaining time for the event pulse Returns in units */
long event_time(LPEVENT event)
{
	long when;

	if (!event->q_el)
		return 0;

	when = event->q_el->iKey;
	return (when - thecore_heart->pulse);
}

/* remove all events */
void event_destroy(void)
{
	TQueueElement * pElem;

	while ((pElem = cxx_q.Dequeue()))
	{
		LPEVENT the_event = (LPEVENT) pElem->pvData;

		if (!pElem->bCancel)
		{
			// no op here
		}

		cxx_q.Delete(pElem);
		the_event->q_el = NULL;
	}
}

int event_count()
{
	return cxx_q.Size();
}

void intrusive_ptr_add_ref(EVENT* p) {
	++(p->ref_count);
}

void intrusive_ptr_release(EVENT* p) {
	if ( --(p->ref_count) == 0 ) {
		M2_DELETE(p);
	}
}
