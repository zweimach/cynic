#include <czmq.h>
#include <stdio.h>

int main(void)
{
    zsock_t* responder = zsock_new(ZMQ_REP);
    int rc = zsock_bind(responder, "tcp://*:5555");
    assert(rc == 5555);
    char msg[20];
    int n;

    while (1) {
        char* str = zstr_recv(responder);
        printf("Received %s\n", str);
        sscanf(str, "Hello %d", &n);
        snprintf(msg, 19, "World %d", n * n);
        sleep(3);
        zstr_send(responder, msg);
        zstr_free(&str);
        if (n == 9)
            break;
    }
    zsock_destroy(&responder);
}
