#ifndef APA_NODE_H
#define APA_NODE_H

enum node_tag {
    N_IDENTIFIER,
    N_LITERAL_S,
    N_LITERAL_N,
    N_KEYWORD,
    N_PAREN_L,
    N_PAREN_R,
    N_BRACE_R,
    N_BRACE_L,
};

union node_payload {
    char *literal_s;
    int literal_n;
};

typedef struct Node Node;

struct Node {
    enum node_tag tag;
    union node_payload payload;
};

#endif /* APA_NODE_H */
