#include <iostream>
#include "Queue.h"

void directions(int& theInt);
void intInputValidation(int& theInt);

int main() {
    Queue<int> myQueue;
    int input, answer;
    bool done = false;
    while (!done){
        directions(input);
        intInputValidation(input);
        switch (input)
        {
        case 1:
            std::cout << "Enter a number to add: ";
            std::cin >> answer;
            intInputValidation(answer);
            myQueue.enqueue(answer);
            break;

        case 2:
            myQueue.dequeue();
            break;

        case 3:
            myQueue.printQueue();
            break;

        case 4:
            std::cout << "First item is: ";
            try
            {
                myQueue.peekFront();
            }
            catch(const std::logic_error& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;

        case 5:
            std::cout << "Last item is: ";
            try
            {
                myQueue.peekBack();
            }
            catch(const std::logic_error& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
            
        case 6:
            std::cout << "Size of queue is: " << myQueue.size() << std::endl;
            break;
        
        case 7:
            done = true;
            break;
        }
    }
}

void directions(int& theInt){
    std::cout << "-----------------------------------\n"
                 "To add to the queue press \"1\"\n"
                 "To remove from the queue press \"2\"\n"
                 "To print the queue press \"3\"\n"
                 "To see first item press \"4\"\n"
                 "To see last item press \"5\"\n"
                 "To see size of queue press \"6\"\n"
                 "To quit the program press \"7\"\n"
                 "-----------------------------------\n";
                 std::cin >> theInt;
}

void intInputValidation(int& theInt){
    while (!std::cin.good() || std::cin.peek() == ' '){
        std::cout << "ERROR: Incorrect data entered!\n"
                     "-----------------------------------\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');
        std::cout << "Re-enter number: ";
        std::cin >> theInt;
        }
}