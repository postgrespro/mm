#ifndef DMQ_H
#define DMQ_H

#include "libpq-fe.h"
#include "lib/stringinfo.h"

typedef int8 DmqDestinationId;
typedef int8 DmqSenderId;

extern void dmq_init(void);

extern DmqDestinationId dmq_destination_add(char *connstr, char *sender_name, int ping_period);

extern void dmq_push(DmqDestinationId dest_id, char *stream_name, char *msg);
extern void dmq_stream_subscribe(char *sender_name, char *stream_name);
extern void dmq_pop(DmqSenderId *sender_id, StringInfo msg);
extern void dmq_push_buffer(DmqDestinationId dest_id, char *stream_name, const void *buffer, size_t len);

typedef void (*dmq_receiver_start_hook_type) (char *);
extern dmq_receiver_start_hook_type dmq_receiver_start_hook;

#endif