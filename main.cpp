#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <time.h>

// get a random item from a provided list of strings
void getItem (std::vector<std::string> items) {
    // seed rand() by time
    srand (time(NULL));
    srand (rand());
    std::string epName;
    // get a random number
    int itemNum = rand () % items.size ();
    // output the item at that position in the list
    std::cout << items[itemNum] << std::endl;
}

// build up a vector holding each line from the given file
int main(int argc, char** argv){
    std::string input;
    // ask the user for a file
    std::cout << "What file?\n> ";
    std::cin >> input;

    // if input can be parsed into an int, simply output a random number in that range, (1 - x)
    bool isNum = true;
    // do this by checking if all characters in the input are digits
    for (int i = 0; i < input.size(); ++i){
        if (!(std::isdigit(input[i])))
            isNum = false;
    }
    // get and output the random number
    if (isNum) {
        int maxNum = std::atoi (input.c_str());
        // seed by time
        srand (time(NULL));
        srand (rand());
        // generate and output the number
        int itemNum = rand () % maxNum + 1;
        std::cout << itemNum;
        return 0;
    }

    // otherwise, try to open the file
    std::ifstream fileIn;
    try {
        fileIn.open (input.c_str());
    } catch (exception e) {
        // output error  message on exception
        std::cerr << "Could not open file: " << input << std::endl;
    }
    std::vector<std::string> items;
    // read each line of the file into the vector
    while (std::getline(fileIn, input)) {
        items.push_back(input);
    }
    // call the helper to get and output an item
    getItem(items);

    return 0;
}
