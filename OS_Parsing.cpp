// Parsing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>

char** parseCommandLine(std::string aCommandLine) {
    std::list<std::string> container;
    std::string hold = "";
    for (auto& ch : aCommandLine) {
        if (ch == ' ' || ch == '<' || ch == '>' || ch == '|') {
            if (hold != "")                                                              //prevents empty strings
                container.push_back(hold);
            hold = "";
        }
        else {
            hold = hold + ch;
        }
    }
    container.push_back(hold);

    char** ret = new char* [container.size() + 1];                                           //ret is an array of pointers
    int stop = container.size();
    for (int i = 0; i < stop; i++) {                                       //making cstrings

        char* temp = new char[container.front().size() + 1];
        for (int j = 0; j <= container.front().size(); j++) {
            *(temp + j) = container.front()[j];
        }
        *(temp + container.front().size() + 1) = '\0';
        container.pop_front();

        *(ret + i) = temp;

    }
    char* empty = new char[1];
    *(empty) = '\0';
    *(ret + stop) = empty;

    return ret;
}


int main()
{
    std::string test = "grep x < myfile.textbfin > myfile.out";
    char** tes = parseCommandLine(test);
    int i = -1;
    char* helper = *tes;
    int j = 0;

    while (i != 0) {
        i = 0;
        helper = *(tes + j);
        while (*(helper + i) != '\0') {
            std::cout << *(helper + i);
            i++;
        }
        j++;
        std::cout << std::endl;
    }


}

