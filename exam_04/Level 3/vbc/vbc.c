/*
Allowed functions: malloc, calloc, realloc, free, printf, isdigit, write
- program needs to print the result of a math expression.
- handle * and + and parenthesis.
- does not handle whitespace.
- values are between 0 and 9.
- if unexpected symbol OR unexpected '(' ')' -> print error and exit(1)
- if symbol is at the end of input print error
- if syscall failure exit(1) 

./vbc '1'
$1
./vbc '(3+4)*5'
$35
./vbc '1+'
$ unexpected end of input
./vbc '1+2)'
$ unexpected token ')'
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum { ADD, MULT, VAL } type;
    int val;
    struct node *l;
    struct node *r;
} node;

node *parse_expr(char **s);

node* new_node(node n) {
    node* ret = calloc(1, sizeof(node));
    if (!ret) return NULL;
    *ret = n;
    return ret;
}

void unexpected(char c) {
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c) {
    if (**s == c) {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char **s, char c) {
    if (accept(s, c)) {
        return 1;
    }
    unexpected(**s);
    return 0;
}

int eval_tree(node* tree) {
    if (tree->type == ADD)
        return eval_tree(tree->l) + eval_tree(tree->r);
    else if (tree->type == MULT)
        return eval_tree(tree->l) * eval_tree(tree->r);
    else
        return tree->val;
}

void destroy_tree(node* tree) {
    if (tree) {
        if (tree->type != VAL) {
            destroy_tree(tree->l);
            destroy_tree(tree->r);
        }
        free(tree);
    }
}

// solution below

// node *parse_nbr(char **s) {
//     if(isdigit(**s)) {
//         node n = { .type = VAL, .val = **s - '0', .r = NULL, .l = NULL };
//         (*s)++;
//         return new_node(n);
//     }
//     unexpected(**s);
//     return NULL;
// }

// node *parse_fact(char **s)
// {
//     if (accept(s, '('))
//     {
//         node *expr = parse_expr(s);
//         if (!expect(s, ')'))
//         {
//             destroy_tree(expr);
//             return NULL;
//         }
//         return expr;
//     }
//     return parse_nbr(s);
// }


// node *parse_term(char **s) {
//     node *left = parse_fact(s);
//     while (accept(s, '*')) {
//         node *right = parse_fact(s);
//         if (!right) {
//             destroy_tree(left);
//             return NULL;
//         }
//         node n = { .type = MULT , .l = left, .r = right };
//         left = new_node(n);
//     }
//     return left;
// }

// node *parse_expr(char **s) {
//     node *left = parse_term(s);
//     while (accept(s, '+')) {
//         node *right = parse_term(s);
//         if (!right) {
//             destroy_tree(left);
//             return NULL;
//         }
//         node n = { .type = ADD, .l = left, .r = right };
//         left = new_node(n);
//     }
//     return left;
// }



node* parse_number(char **s)
{
    if(isdigit(**s)) //dereference to get to the actual value and check if it's a digit
    {
        node n = {.type = VAL, .val = **s - '0', .l = NULL, .r = NULL}; //initialize node n
        (*s)++; //move forward in string
        return new_node(n); //create and return new node with node n (allocates memory for it)
    }
    else
    {
        unexpected(**s); //not a digit -> prints error message
    }
    return NULL; //in case nothing is true -> signals error
}

node* parse_factor(char **s)
{
    if(accept(s, '('))//check for (
    {
        node *expr = parse_expr(s); //parse the expression inside the ()
        if(expect(s, ')') == 0)//we expect a )
        {
            destroy_tree(expr); //destroy expression and return NULL if there is no )
            return NULL;
        }
        return expr; //return parsed expression
    }
    return parse_number(s); //if no (), return parsed number
}

node *parse_term(char **s)
{
    node *left = parse_factor(s);//parses left
    while(accept(s, '*')) //while loop to get every *
    {
        node *right = parse_factor(s); //parses right
        if(!right) //if !right we destroy what has already been allocated -> left
        {
            destroy_tree(left);
            return NULL;
        }
        node n = {.type = MULT, .l = left, .r = right}; //tie left and right together with MULT
        left = new_node(n); //left now points to the "*" (root of the (sub)tree)
    }
    return left; //return left (*)
}


node *parse_expr(char **s)
{
    node *left = parse_term(s);
    while(accept(s, '+'))
    {
        node *right = parse_term(s);
        if(!right)
        {
            destroy_tree(left);
            return NULL;
        }
        node n = {.type = ADD, .l = left, .r = right};
        left = new_node(n);
    }
    return left;
}

int main(int ac, char** av) 
{
    if (ac != 2) {
        return 1;
    }

    char *input = av[1];
    node *tree = parse_expr(&input);

    if (!tree) {
        destroy_tree(tree);
        return 1;
    }
    else if (*input) {
        unexpected(*input);
        destroy_tree(tree);
        return 1;
    }

    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
}