struct node {

	int val;
	int flag;
	char op;
	struct node* left;
	struct node* right;

};

#define YYSTYPE struct node *

