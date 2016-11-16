#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* Reverse Polish Notation calculator */

int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop(); // to guarantee operation order
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: divide by zero\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100 // max stack size

int sp = 0; // stack pointer
double val[MAXVAL]; // stack

/* push: push f to stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp ++] = f;
  else
    printf("error: stack full\n");
}

/* pop: pop and return top stack value */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c; // not a number
  i = 0;
  if (isdigit(c)) // collect integer part
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') // collect integer part
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c != EOF)
    ungetch(c);
  return NUMBER;
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
