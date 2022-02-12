#include <czmq.h>
#include <stdio.h>

int main(void)
{
    zsock_t* requester = zsock_new(ZMQ_REQ);
    zsock_connect(requester, "tcp://localhost:5555");
    char msg[20];

    for (int n = 0; n != 10; n++) {
        snprintf(msg, 19, "Hello %d", n);
        zstr_send(requester, msg);
        char* str = zstr_recv(requester);
        printf("Received %s\n", str);
        zstr_free(&str);
    }
    zsock_destroy(&requester);
}
