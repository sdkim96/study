#include <stdio.h>

struct node
{
    int data;
    struct node* next_node_or_null;
};

const struct node* get_next_or_null(const struct node* n);
int get_data(const struct node* n);
const int* search_deep_data_from(const struct node* n);

const struct node* push(const int data, const struct node* n_or_null);
void pop(void);

int main(void)
{   
    const struct node* start = push(1, (struct node*)NULL);
    const struct node* n1 = push(2, start);
    const struct node* n2 = push(3, n1);
    const struct node* end = push(4, n2);

    return 0;
}

const struct node* push(const int data, const struct node* n_or_null)
{
    static struct node* this_node;
    this_node = (struct node*)malloc(sizeof(struct node));

    if (n_or_null == (struct node*)NULL) 
    {   
        this_node->data = data;
        this_node->next_node_or_null = NULL;
    }
    else
    {
        this_node->data = data;
        this_node->next_node_or_null = n_or_null;
    }
    return this_node;
}

const struct node* get_next_or_null(const struct node* n)
{   
    return n->next_node_or_null;
}

int get_data(const struct node* n)
{
    return n->data;
}

const int* search_deep_data_from(const struct node* n)
{
    return &n->data;
}

void pop(void)
{
    return;
}

