#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
struct tnode *addtotree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* Binary tree node */
struct tnode {
  char *word; /* points to the text */
  int count; /* number of ocurrences */
  struct tnode *left; /* left child */
  struct tnode *right; /* right child */
};

/* Word Tally (K&R 6.5) */
int main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtotree(root, word);

  treeprint(root);
  return 0;
}

struct tnode *talloc(void);
char *sstrdup(char *);

/* addtotree: add a node with w, at or below p */
struct tnode *addtotree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) { /* new word */
    p = talloc(); /* make a new node */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++; /* increment tally for repeated word */
  else if (cond < 0) /* less than (move left) */
    p->left = addtotree(p->left, w);
  else /* greater than (move right) */
    p->right = addtotree(p->right, w);

  return p;
}

/* treeprint: in-order recursive print of tree */
void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

#include <stdlib.h>
/* talloc: make a tnode */
struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s */
char *sstrdup(char *s)
{
  char *p;
  p = (char *) malloc(strlen(s) + 1); /* the plus one is for string closing char ('\0') */
  if (p != NULL)
    strcpy(p, s);

  return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

#define BUFFSIZE 100

char buf[BUFFSIZE]; // buffer for ungetch
int bufp = 0; // buffer pointer

int getch(void) // get char from input or buffer
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back "to input"
{
  if (bufp >= BUFFSIZE)
    printf("ungetch: too many chars\n");
  else
    buf[bufp++] = c;
}
