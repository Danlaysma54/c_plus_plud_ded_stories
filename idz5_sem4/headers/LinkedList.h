#ifndef IDZ5_SEM4_LINKEDLIST_H
#define IDZ5_SEM4_LINKEDLIST_H
struct LinkedList
{
    LinkedList *next;
    int key;
    std::string data;
    LinkedList *nextlink;
    LinkedList *prevlink;
    LinkedList() : next(nullptr), nextlink(nullptr), prevlink(nullptr), key(-1), data(""){};
    LinkedList(LinkedList *smth, LinkedList *input_nextlink, LinkedList *input_prevlink, int input_key, std::string input_data) : next(smth), nextlink(input_nextlink), prevlink(input_prevlink), data(input_data), key(input_key){};
};
#endif // IDZ5_SEM4_LINKEDLIST_H