
typedef enum { 
	constant, identifier, operation 
} nodeType;

struct node {
	nodeType type;
	int value;
	int index;
	int opr;
	int ops;
	struct node **childs;
};
