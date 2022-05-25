#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> myQueue;
    std::string answer;
    int answerTwo;
    while (answer != "quit"){
        do{
            std::cout << "Enter enqueue to add to queue "
            "dequeue to subtract from queue \n"
            "peekfront to see first item, "
            "peekback to see last item, \n"
            "clear to clear list, "
            "size to see size of list, "
            "and quit to quit\n";
            std::cin >> answer;
        } while ((answer != "enqueue") && (answer != "dequeue") 
                && (answer != "peekfront") && (answer != "peekback")
                && (answer != "quit") && (answer != "clear")
                && (answer != "size"));
        if (answer == "enqueue"){
            std::cout << "what number would you like to add?\n";
            std::cin >> answerTwo;
            myQueue.enqueue(answerTwo);
        }
        else if (answer == "peekfront"){
            std::cout << "Front item is: " << myQueue.peekFront() 
            << std::endl;
        }
        else if (answer == "peekback"){
            std::cout << "back item is: " << myQueue.peekBack()
            << std::endl;
        }
        else if (answer == "dequeue"){
            myQueue.dequeue();
        }
        else if (answer == "clear"){
            myQueue.~Queue();
        }
        else{
            std::cout << "Size of queue is: " << myQueue.size() <<
            std::endl;
        }

    }
}   