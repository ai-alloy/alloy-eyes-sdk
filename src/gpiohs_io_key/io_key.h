#ifndef _IO_KEY_H_
#define _IO_KEY_H_

typedef struct _key_event{
	uint8_t key_num;
	uint8_t press;
}key_event_t;

void key_init(void);
int key_detect(key_event_t *keyEvent);

#endif /* _IO_KEY_H_ */
