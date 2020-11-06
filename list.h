//Shang-Chun, Lin   CS162 program5
//the purpose of this file is to create a LLL of all of my favorite things.

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int NAME = 21;
const int DESCRIPT = 131;
const int OFTEN = 21;

class activity
{
	public:
		activity();
		void add();
		void display();
		int remove_name(char test_name[]);
		void remove();
	private:
		char name[NAME];		//the name of the activity
		char descript[DESCRIPT];	//the description of the activity
		char often[OFTEN];		//how often do I participate with this	
};


struct node
{
	activity data;
	node * next;
};

class list
{
	public:
		list();
		void add_array();
		void display_array();
		void remove_item(char test_name[]);
		int count();
		void release();
		~list();

	private:
		node * head;
		int size;
};
