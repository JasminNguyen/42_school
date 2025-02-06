#include <stdio.h>
#include <ctype.h>

#include <stdlib.h>
#include <stddef.h>


typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;
node *parse_expr(char **s);

node * new_node(node n)
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void unexpected_char(char c)
{
    if (c)
        printf("Unexpexted token '%c'\n", c);
    else
        printf("Unexpexted end of input \n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s,c))
        return (1);
    unexpected_char(**s);
    return (0);
}

node *parse_number(char **s)
{
    if(isdigit(**s))
    {
        node n = {.type = VAL, .val = **s - '0', .l = NULL, .r = NULL};
        (*s)++;
        return new_node(n);
    }
    unexpected_char(**s);
    return NULL;
}

node *parse_factor(char **s)
{
    if(accept(s, '('))
    {
        node *expr = parse_expr(s);
        if(!expr)
        {
            destroy_tree(expr);
            return NULL;
        }
        if(expect(s, ')') == 0)
        {
            destroy_tree(expr);
            return NULL;
        }
        return expr;
    }
    return parse_number(s);
}
node *parse_term(char **s)
{
    node *left = parse_factor(s);
    while(accept(s, '*'))
    {
        node *right = parse_factor(s);
        if(!right)
        {
            destroy_tree(left);
            return NULL;
        }
        node n = {.type = MULTI, .l = left, .r = right};
        left = new_node(n);
    }
    return left;
}
node *parse_expr(char **s)
{
    // Your code is here
    node *left = parse_term(s);
    while(accept(s, '+'))
    {
        node *right = parse_term(s);
        if(!right)
        {
            destroy_tree(left);
            return (NULL); 
        }
        node n = {.type = ADD, .l = left, .r = right};
        left = new_node(n);
    }
    return (left);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main (int argc, char** argv)
{
    if (argc!= 2)
        return 1;
    char *input = argv[1];
    node *tree = parse_expr(&input); //passing a pointer to input
    if (!tree) //destroy tree if the node creation does not work
    {
        destroy_tree(tree);
        return 1;
    }
    else if(*input) //check if there are extra characters after parsing
    { 
        unexpected_char(*input);
        destroy_tree(tree);
        return 1;
    }
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}

