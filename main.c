#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char* str;
    struct node *next;
    struct node *prev;
};
struct list{
    struct node *start;
    struct node *end;
};
int init_list(struct list *list);
int push_back(struct list *list,struct node *node);
int push_front(struct list *list,struct node *node);
int print(struct list *list);
int print_backwards(struct list *list);
struct node* create_element(char *);
void clear(struct list *);
int main()
{
    struct list l;
    init_list(&l);
    const char *txts[] = {"arbuz", "winogrono", "banan", "agrest"};
    int txts_len = 4;
    for(int i=0; i<txts_len; i++)
    {
        struct node *n = create_element(txts[i]);
        push_front(&l, n);
    }
    print(&l);
    print_backwards(&l);
    clear(&l);
    return 0;
}
int init_list(struct list *list)
{
    if(list==NULL)
        return 1;
    list->start=NULL;
    list->end=NULL;
    return 0;
}
int push_back(struct list *list,struct node *node)
{
    if(list==NULL||node==NULL)
        return 1;
    if(list->end==NULL&&list->start==NULL)
    {
        node->prev=NULL;
        node->next=NULL;
        list->start=node;
        list->end=node;
        return 0;
    }
    node->prev=list->end;
    node->next=NULL;
    list->end->next=node;
    list->end=node;
    return 0;
}
int push_front(struct list *list,struct node *node)
{
    if(list==NULL||node==NULL)
        return 1;
    if(list->end==NULL&&list->start==NULL)
        return push_back(list,node);

    node->next=list->start;
    node->prev=NULL;
    list->start->prev=node;
    list->start=node;
    return 0;
}
int print(struct list *list)
{
    if(list==NULL)
        return 1;
    for (struct node *i = list->start;i;i=i->next ) {
        printf("%s\n",i->str);
    }
    return 0;
}
int print_backwards(struct list *list)
{
    if(list==NULL)
        return 1;
    for (struct node *i = list->end;i;i=i->prev ) {
        printf("%s\n",i->str);
    }
    return 0;
}
struct node* create_element(char *word)
{
    if(word==NULL)
        return NULL;
    struct node *n=malloc(sizeof(struct node));
    if(n==NULL)
        return NULL;
    n->str=strdup(word);
    if(n->str==NULL)
    {
        free(n);
        return NULL;
    }

    return n;
}
void clear(struct list *list)
{
    if(list==NULL)
        return;
    for (struct node *i = list->start;i;) {
        free(i->str);
        struct node *temp=i->next;
        free(i);
        i=temp;
    }
}