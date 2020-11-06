//Shang-Chun, Lin   CS162 program5
#include "list.h"

activity::activity()
{
	name[0] = '\0';
	descript[0] = '\0';
	often[0] = '\0';
}

void activity::add()
{
	cout<<"Please enter a name of the activity."<<endl;
	cin.get(name,21,'\n');
	cin.ignore(100,'\n');
	cout<<"Please enter a description of the activity."<<endl;
	cin.get(descript,131,'\n');
	cin.ignore(150,'\n');
	cout<<"Please enter how often do you participate the activity."<<endl;
	cin.get(often,21,'\n');
	cin.ignore(100,'\n');	
}

void activity::display()
{
	cout<<"Name : "<<name<<endl
	<<"Description : "<<descript<<endl
	<<"How often : "<<often<<endl;
}

int activity::remove_name(char test_name[])
{
	if(strcmp(name,test_name) == 0)
	{
		name[0] = '\0';
		descript[0] = '\0';
		often[0] = '\0';
		return 1;
	}
	return 0;
}

void activity::remove()
{
	name[0] = '\0';
	descript[0] = '\0';
	often[0] = '\0';
}

list::list()
{
	head = NULL;
	size = 0;
}

void list::add_array()
{
	node * current;
	node * temp;

	if(!head)
	{
		head = new node;
		head->data.add();
		head->next = NULL;
		++size;

		cout<<"Now you have this data in the LLL."<<endl;
		head->data.display();
	}

	else if(!head->next)
	{
		current = new node;
		current->data.add();
		current->next = NULL;
		head->next = current;
		++size;

		cout<<"Now you have this data in the LLL."<<endl;
		current->data.display();
	}
	
	else
	{
		current = head;
		while(current->next)
		{
			current = current->next;
		}

		temp = new node;
		temp->data.add();
		temp->next = NULL;
		current->next = temp;
		++size;

		cout<<"Now you have this data in the LLL."<<endl;
		temp->data.display();
	}
	return;	
}

void list::display_array()
{
	node * current = head;
	while(current)
	{
		current->data.display();
		current = current->next;
	}
	if(!head)
	{
		cout<<"The list is empty."<<endl;
	}
	return;
}

void list::remove_item(char test_name[])
{
	node * current = head->next;
	node * temp = head;
	int counter = 0;	//count how many times does those two pointers move	
	if(!head)
	{
		return;
	}
	else if(!head->next)
	{
		if(head->data.remove_name(test_name) == 1)
		{
			delete head;
			head = NULL;
			size = 0;
		}
	}
	else	//size>=2
	{
		while(current->data.remove_name(test_name) == 0)			//let current point at the node which we want to delete
		{
			current = current->next;
			temp = temp->next;
			++counter;
		}
		if(size-counter==2)	//delete the last node
		{
			delete current;
			temp->next = NULL;
			--size;
		}
		else if(size-counter>2)	//delete a node in the middle
		{
			temp->next = current->next;
			delete current;
			--size;
		}
	}

	return;	
}

int list::count()
{
	int counter = 0;
	node * current = head;	
	while(current)
	{
		++counter;
		current = current->next;
	}
	return counter;
}

void list::release()
{
	if(!head)
	{
		return;
	}
	while(head)
	{	
		if(!head->next)
		{
			head->data.remove();
			delete head;
			head = NULL;
		}
		else
		{
			node * current = head->next;
			head->data.remove();
			delete head;
			head = current;
		}
	}
	return;
}

list::~list()
{
	if(head != NULL)
	{
		delete head;
		head = NULL;
	}
}

