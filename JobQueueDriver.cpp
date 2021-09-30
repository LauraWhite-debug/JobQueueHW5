/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	JobQueue jobQueue;
	int option = 0;
	int numJobsAdd = 0;
	menu();
	cin >> option;
	while(option != 3)
	{
		if(option == 1)
		{
			cout << "Enter the number of jobs to be created:" << endl;
			cin >> numJobsAdd; 
			string currJob;
			int i = 1;
			while(i<=numJobsAdd)
			{
				cout << "job" << i << ":" << endl;
				cin >> currJob;
				jobQueue.enqueue(currJob);
				i++;
			}
		}
		else if(option == 2)
		{
			int numJobsRemove = 0;
			int j = 0;
			cout << "Enter the number of jobs to be dispatched:" << endl;
			cin >> numJobsRemove;
			while(j<numJobsRemove && !jobQueue.isEmpty())
			{
				cout << "Dispatched: " << jobQueue.peek() << endl;
				jobQueue.dequeue();
				j++;
			}
			if(jobQueue.isEmpty())
			{
				cout << "No more jobs to be dispatched from queue" << endl;
			}
		}
		menu();
		cin >> option;
	}
	if(option == 3)
	{
		cout << "Number of jobs in the queue:" << jobQueue.queueSize() << endl;
		return 0;
	}
	
	

}
