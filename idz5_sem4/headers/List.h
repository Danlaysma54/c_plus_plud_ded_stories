#ifndef IDZ5_SEM4_LIST_H
#define  IDZ5_SEM4_LIST_H
struct list
{
    list *next;
    int key;
    std::string data;
    list() : next(nullptr), key(-1), data(""){};
    list(list *smth,int input_key,std::string input_data): next(smth),key(input_key),data(input_data){};
};
#endif // IDZ5_SEM4_LIST_H