typedef struct node *link;

struct node {
  int item;
  link next;
};

typedef link Node;

void initNodes(int);
void freeNodes(void);
link newNode(int);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);

link Next(link);
int Item(link);
