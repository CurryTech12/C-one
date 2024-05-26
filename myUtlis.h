#ifndef MY_UTILS_H//defines are header files also called the guards
#define MY_UTILS_H//if else makes this compile once
#include <string>
#include <iostream>
#include <fstream>
enum class Option{
    NONE,
    GENERATE_DATA,
    EXTRACT_DATA,
    PROCESS_DATA,
    EXIT
};
std::string optionToString(Option o);
void menu();
void showBanner();
std::string generateARandomMessage(int lengthOfMessage);
void generateFakeData(std::ofstream& output, std::string outputFileName, int numOfmessages, int lowerbound, int upperbound);


std::string optionToString(Option o){
    switch(o){
        case Option::NONE:
            return"";
        case Option::GENERATE_DATA:
            return "Generate Data";
        case Option::EXTRACT_DATA:
            return "Extract Data";
        case Option:: PROCESS_DATA:
            return "Processed Data";
        case Option:: EXIT:
            return "Exit";
        default:
            return "Invalid Option"; 
    }
}

void menu(){
    showBanner();
    for(Option op = Option::GENERATE_DATA; op <= Option::EXIT; op = static_cast<Option>(static_cast<int>(op) + 1)){
        std::cout << static_cast<int>(op)<< ". " << optionToString(op) << std::endl;
    }
}

void showBanner(){
    std::cout << "*******************************************************************\n";
    std::cout << "*                                                                 *\n";
    std::cout << "*                    DATA PROCESSOR PROGRAM                       *\n";
    std::cout << "*                                                                 *\n";
    std::cout << "*******************************************************************\n";
}

std::string generateARandomMessage(int lengthOfMessage){
    std::string characters = "ABCDEFGHIJKLMNOPGRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
    std::string result = "";
    for(int i = 0; i < lengthOfMessage; ++i){
        int randNum = rand() % (characters.length());
        result += characters[randNum];
    }
    return result;
}

void generateFakeData(std::ofstream& output, std::string outputFileName, int numOfmessages, int lowerbound, int upperbound){
    output.open(outputFileName.c_str());
    for(int i = 0; i < numOfmessages; ++i){
        int numOfChars = rand() % (upperbound - lowerbound + 1) + lowerbound;
        if(i != 0){
            output << std:: endl << std:: endl;
        }
        output << generateARandomMessage(numOfChars);
    }
    output.close();
}
#endif