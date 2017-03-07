#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <time.h>

// get a random item from a provided list of strings
void getItem (std::vector <std::string> items) {
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
    std::vector <std::string> filenames;

    // continue asking user for input until user enters a number, or 'done'
    for (bool done = false; !done;) {
        // ask the user for a file or number
        std::cout << "Enter a number or filename, or 'done' to end input.\n> ";
        std::cin >> input;

        bool isNum = true;
        // check if all characters in the input are digits
        for (unsigned int i = 0; i < input.size (); ++i){
            if (!(std::isdigit (input[i])))
                isNum = false;
        }
        // if input can be parsed into an int, simply output a random number in that range, (1 - x)
        if (isNum) {
            int maxNum = std::atoi (input.c_str ());
            // seed by time
            srand (time(NULL));
            srand (rand());
            // generate and output the number
            int itemNum = rand () % maxNum + 1;
            std::cout << itemNum << std::endl;
            // wait for user input so they can read the output
            system("pause");
            // if a number is given, simply return and ignore any files entered.
            return 0;
        }

        // if not a number, check if 'done'
        // if not done, store the filename to be opened later
        if (input == "done") {
            done = true;
        } else {
            filenames.push_back (input);
        }
    }

    // once input is completed, try to open each file given
    std::vector<std::string> items;

    for (unsigned int i = 0; i < filenames.size (); ++i) {
        std::ifstream fileIn;
        // attempt to open each file in turn
        fileIn.open (filenames[i].c_str());
        // if open was successful, read each line of the file into the vector of items
        while (std::getline(fileIn, input)) {
            items.push_back(input);
        }
    }

    // call the helper to get and output an item
    getItem(items);
    // wait for user input so they can read the output
    system("pause");

    return 0;
}
