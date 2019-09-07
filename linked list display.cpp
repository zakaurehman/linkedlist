// linked list display.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
using namespace std;

struct node
{
	int data;
	struct node *next;
}*first=NULL;

void creat(int a[],int n)
{
	struct node *t,*last;
	first=new node;
	first->data=a[0];
	first->next=NULL;
	last=first;
	for(int i=1; i<n; i++)
	{
		      t=new node;
		      t->data=a[i];
		      t->next=NULL;
		      last->next=t;
		      last=t;
     }
}
void display(struct node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
void sort(struct node *p)
{
	struct node *q,*temp;
	temp=new node;
	temp->data=NULL;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				temp->data=p->data;
				p->data=q->data;
				q->data=temp->data;
			}
			q=q->next;
		}
		p=p->next;
	}
}
int count(struct node *p)
{
	if(p==0)
		return 0;
	else
	return count(p->next)+1;
}
int add(struct node *q)
{
	int sum=0;
	while(q!=NULL)
	{
		sum=sum+q->data;
		q=q->next;
	}
	return sum;
}
void max(struct node *t)
{
	int max=0;
	while(t!=0)
	{
		if(max < t->data)
			max=t->data;
		    t=t->next;
			}
	cout<<"The maximum number in a linked list is ="<<max;
}
void search(struct node *p,int num)
{
	int flage=0;
	while(p!=0)
	{
		if(num==p->data)
		cout<<"The number is"<<" "<<num;
		p=p->next;
		flage=1;
	}
	if(flage==0)
	cout<<"You Entered wrong number";
}
   
int _tmain(int argc, _TCHAR* argv[])
{
	int res1,res2,num;
	int a[10]={7,4,3,5,8,6,11,9,10,2};
	creat(a,10);
		display(first);
		cout<<endl;
		sort(first);
		cout<<endl;
		display(first);
		cout<<endl;
		res1=count(first);
		cout<<"sum of node in linked list is"<<" "<<res1;
		cout<<endl;
		res2=add(first);
		cout<<"sum of all data in a linked list = "<<" "<<res2;
		cout<<endl;
		max(first);
		cout<<endl;
		cout<<"Enter number for searching in linked list";
		cin>>num;
		search(first,num);
		cout<<endl;
		system("pause");
	return 0;
}

