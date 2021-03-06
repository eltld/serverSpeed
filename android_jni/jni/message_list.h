#ifndef __MSG_H__
#define __MSG_H__


#define ACTION_DETAIL 1
#define ACTION_RESULT 2
#define ACTION_RESULT_AVG 3
#define ACTION_RESULT_DROP 4
#define ACTION_STOP 5

typedef struct {
    int id;
    int what;
    int type;
    int tm;
    int tag;
    int value;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
}jni_message_t;

typedef struct {
    jni_message_t list[M_64KB];
    int total;
    int rpos;
    int wpos;
    int size;

    pthread_mutex_t mtx;
}message_list_t;


void message_list_init();

void push_action(int id, int what, int type, int tag);

void push_message(int id, int what, int type, int tag, int value, int arg1);

void push_detail(int id, int type, int tag, int val, int arg1);

void push_result(int id, int what, int type, int tag, int value, int arg1, int arg2, int arg3, int arg4);

int pop_message(jni_message_t *j);

#endif
