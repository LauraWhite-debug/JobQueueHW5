#include "JobQueue.hpp"
#include <iostream>
#include <string>

using namespace std;

JobQueue::JobQueue()
{
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
}
bool JobQueue::isEmpty()
{
    if(counter == 0){return true;}
    else {return false;}
}
bool JobQueue::isFull()
{
    if(counter == SIZE){return true;}
    else{return false;}
}
void JobQueue::enqueue(string job)
{
    if(isFull())
    {
       cout << "Queue full, cannot add new job" << endl;
    }
    else
    {
        if(queueEnd == SIZE-1) // if queue end is at last index
        {
            queue[queueEnd] = job;
            queueEnd = 0; // wrap queue end back around to first index
        }
        else
        {
            queue[queueEnd] = job;
            queueEnd++;
        }
        counter++;
    }
}
    
void JobQueue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue empty, cannot dequeue a job" << endl;
    }
    else
    {
        queue[queueFront] = ""; // remove front element
        if(queueFront == SIZE-1) // if front is at the last index
        {
            queueFront = 0; // wrap front back around to first index
        }
        else
        {
            queueFront++;
        }
        counter--;

    }
}
string JobQueue::peek()
{
    if(isEmpty())
    {
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
    else {return queue[queueFront];}
}
int JobQueue::queueSize()
{
    if(isEmpty())
    {return 0;}
    else if(isFull())
    {return SIZE;}
    else if(getQueueEnd() > getQueueFront())
    {return queueEnd-queueFront+1;}
    else {return getQueueEnd()+SIZE-getQueueFront();}
}
 

