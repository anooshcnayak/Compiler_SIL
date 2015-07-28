typedef enum { 
	constant, identifier, array, operation, boole
} nodeType;

typedef enum { 
	integer, boolean
} dataType;

struct Gsymbol {

dataType type;
char *name; // name of ID
int size;  // for arrays
int *ptr; // Address of the Identifier in Memory
struct Gsymbol *next; // Pointer to next Symbol Table Entry */

};

struct node {
	
	nodeType type;
	int value;
	char *name;
	int	 oper;
	int ops; // no of operands
	struct node **childs;

};

struct retnode {

	int val;
	dataType type;
};

