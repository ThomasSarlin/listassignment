typedef void* value;
typedef bool compareFunc(value,value);
typedef void swapFunc(value,value);
typedef struct node {
	void* value;
	struct node* next;
	struct node* prev;
}node;
typedef node* node_pos;
typedef struct list {
	struct node* head;
}list;

list* list_create(void);
bool list_isEmpty(list*);
bool list_hasNext(node_pos);
node_pos list_next(node_pos);
node_pos list_prev(node_pos);
node_pos list_first(list*);
node_pos list_last(list*);
node_pos list_insert(node_pos,value);
value list_inspect(node_pos);
void list_clear(list*);
void list_sort(list*,compareFunc,swapFunc);
