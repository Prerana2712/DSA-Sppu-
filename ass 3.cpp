#include <iostream>
#include <string.h>

using namespace std;

class stack
{
	int data;//when we push character it goes as ascii value
	stack *top,*link;
	
	public:
	stack()
	{
		top=NULL;
	}

	void push(int);
	void pop();
	char* postfix(char[]);
	int priority(char);
	char* reverse(char[]);
    void postfixevaluate(char[]);
    void prefixevaluate(char[]);
};


void stack::push(int item)
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


int stack::priority(char x)
{
	if(x=='^')
	{
		return 3;
	}
	else if((x=='*') ||(x=='/'))
	{
		return 2;
	}
	else if((x=='+' )||(x=='-'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char* stack::postfix(char inf[])
{
	int i=0,j=0,instack,incoming;
	char postfix[20];
	while(inf[i]!='\0')
	{
		if(!isalnum(inf[i]))
		{
			if(inf[i]=='(')
			{
				push(inf[i]);
				i++;
			}
			else
			{
				if(top==NULL)
				{
					push(inf[i]);
					i++;
				}
				else
				{
					if(inf[i]==')')
					{
						while(top->data!='(')
						{
							postfix[j]=top->data;
							j++;
							pop();
						}
						pop();
						i++;
					}
					else
					{
						instack=priority(top->data);
						incoming=priority(inf[i]);
						
						while(top!=NULL && instack>=incoming)
						{
							postfix[j]=top->data;
							j++;
							pop();
							
							if(top!=NULL)
							{
								instack=priority(top->data);
						    	incoming=priority(inf[i]);
							}
						}
					 	push(inf[i]);
						i++;
					}
				}
			}
		}
		else
		{
			postfix[j]=inf[i];
			i++;j++;
			
		}
	}
	while(top!=NULL)
	{
		postfix[j]=top->data;
		pop();
		j++;
	}
	postfix[j]='\0';
	return postfix;
}


int calculate(int m,int n,char operand)
{
	if(operand=='/' && n != 0)
	{
		return (m/n);
    }
	else if(operand=='-')
	{
		return (m-n);
	}
	else if(operand=='*')
	{
		return (m*n);
	}
	else
	{
	 return (m+n);
    }
}
void stack::postfixevaluate(char postfix[])
{
	int no,m,n,result,ans;
	int i=0;
	do
	{	
		while(isalnum(postfix[i]))
		{
			if(isdigit(postfix[i]))
			{
				push(postfix[i]);
			}
			else
			{
				cout<<"\nEnter the value(numeral) "<<postfix[i]<<" : ";
				cin>>no;
				push(no);
			}
			i++;
		}
		n = top->data;
		pop();
		m = top->data;
		pop();
		result = calculate(m, n , postfix[i]);
		i++;	
		push(result);
	}while(postfix[i] != '\0');
			
		ans = top->data;
		cout<<"\nPostfix evaluation is:"<<ans;
		pop();	
}

char* stack::reverse(char val[])
{
	
	int i,j=0;
	char temp[10];
	int len=strlen(val);
    for(i=len-1;i>=0;i--)
	{
		if(val[i]=='('){
			temp[i]=')';
			
		}
	
		
		else if(val[i]==')')
		{
			temp[i]='(';
		}
		else
		{
			temp[j]=val[i];
	   		
        }
        j++;
	}
    temp[j]='\0';
    return temp;
   
}


void stack::prefixevaluate(char prefix[])
{
	int no,m,n,result;
	int ans;
	int l=strlen(prefix);
	cout<<l;
		char x;

	int i;
	for(i=l-1;i>=0;i--)
	{
		if(isalpha(prefix[i]))
		{
		
			cout<<"\nEnter the value(numeral) "<<prefix[i]<<" : ";
			cin>>no;
			push(no);
		}
		 
      else
        {
		m = top->data;
		pop();
		n = top->data;
		pop();
		result = calculate(m,n,prefix[i]);
		push(result);
	}
		

     ans = top->data;
		cout<<"\nPrefix Evaluated :"<<ans;
		pop();	 


}
}

int main()
{
	char* pref;
	int j;
	char inf[10];
	char* post;
	char* store_rev;
	char* prefix;
	char* temp;
	char* store;
	
	cout<<"Enter infix expression:";
	cin>>inf;//accepting the infix expression
	stack s;
	int l;
	do{
		cout<<"\nenter the operation to be performed\n1)Postfix\n2)Postfix evaluation\n3)Prefix\n4)prefix evaluation\n5)Exit\n(1,2,3,4,5)";
		cin>>l;
		switch(l)
		{
			case 1:
		        post=s.postfix(inf);
		        cout<<"postfix array is:"<<post;
				break;
			case 2:
				post =s.postfix(inf);		
				s.postfixevaluate(post);
				break;	
			case 3:
				store_rev=s.reverse(inf);
			    temp=s.postfix(store_rev);
			    prefix=s.reverse(temp);
			    
				cout << "Prefix Form Is: " <<prefix;
                break;
            case 4:
            	store_rev=s.reverse(inf);
			    temp=s.postfix(store_rev);
			    prefix=s.reverse(temp);
			   	s.prefixevaluate(prefix);
            	break;
            case 5:
            	cout<<"the end";
            	break;
            default:
            	cout<<"wrong choice";
            	
		}
	}while(l!=5);

    
}

