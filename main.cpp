//Shang-Chun, Lin   CS162 program5
#include "list.h"

int main()
{
	list my_list;

	int answer = 0;
	char test_name[21];

	cout<<"What do you want to do? Type 1 to add new item to the list, 2 to display all the activities,"<<endl
        <<" 3 to search a name and delete it , 4 to count and show the number of items in the list, and"<<endl
	<<" 5 to release all items in the list, and 6 to quit."<<endl;
        cin>>answer;
        cin.ignore(100,'\n');

	while(answer != 6)
	{
		if(answer == 1)
		{
			my_list.add_array();
		}
	
		if(answer == 2)
		{
			my_list.display_array();
		}
		
		if(answer == 3)
		{
			cout<<"Please enter a name to search and delete it in the LLL."<<endl;
			cin.get(test_name,21,'\n');
			cin.ignore(100,'\n');

			my_list.remove_item(test_name);
		}

		if(answer == 4)
		{
			cout<<"Now you have "<<my_list.count()<<" items in the list."<<endl;
		}
		
		if(answer == 5)
		{
			cout<<"Now you have destroyed the list."<<endl;
			my_list.release();
			my_list.display_array();
		}

		cout<<"Do you want to continue on using this program? If no, enter 6."<<endl;
		cout<<"Otherwise, Type 1 to add new item to the list, 2 to display all the activities,"<<endl
                <<" 3 to search a name and delete it, 4 to count and show the number of items in the list,"<<endl
		<<" and 5 to release all items in the list."<<endl;
		cin>>answer;
                cin.ignore(100,'\n');
	}

	return 0;
}
