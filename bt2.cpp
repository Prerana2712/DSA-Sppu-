#include <iostream>

using namespace std;

class tree
{
	char data;
	tree *left,*right;
	char* create(char);
	void expression(char[]);
};
class stack
{
	char data;
	tree *t;
	stack *top,*link;
		public:
	stack()
	{
		top=NULL;
	}
	void push(char);
	void pop();
};
void stack::push(char item)
{
	stack *newnode=new stack();
	newnode->data=item;
    newnode->link=NULL;
    
	if(top==NULL)
	{
    	top = newnode;
	}
	else
	{
	    newnode->link=top;
		top = newnode;
	}
}
void stack::pop()
{
	
	if (top==NULL)
	{
		cout<<"stack is empty";
	}
    else
    {
    stack *ptr = top;
	top=top->link;
	
	delete ptr;
	}
		
}


char* tree ::create(char operand)
{
	tree *newnode=new tree();
	newnode->data=operand;
	newnode->left=NULL;
	newnode->right=NULL;
	return *newnode; 
}
void tree ::expression(char postfix[])
{
	int i;
	int ans;
	while(postfix[i]='\0')
	{
		if(isalnum(postfix[i]))
		{
			create(postfix[i]);
			push(newnode);
			
		}
		else
		{
			newnode=create(postfix[i]);
			newnode->right=top->t;
			pop();
			newnode->left=top->t;
			push(newnode);
		}
		i++;
	}
	ans=top->data;
	cout<<"tree expression is:"<<ans;
}

int main()
{
	tree t1;
	stack s1;
	char postfix;
	cout<<"enter the postfix expression:";
	cin>>postfix;
//	t1.create(postfix)
	t1.expression(postfix);
	
}

