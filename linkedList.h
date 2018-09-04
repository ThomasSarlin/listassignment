typedef void* value;

typedef struct node {
	void* value;
	struct node* next;
	struct node* prev;
}node;

typedef node * node_position;

typedef struct list {
	struct node* head;
}list;
typedef list * linkedList;

/*
* Returns a empty list
*/

linkedList linkedList_create(void);
bool linkedList_isEmpty(linkedList);
bool linkedList_hasNext(node_position);
node_position next(node_position);
node_position first(linkedList);
node_position add(value);
void linkedList_clear(linkedList);
