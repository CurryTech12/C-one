/*
This lab reads a secret message line by line and adds the digits to get a number 
this number we would get would we would then add each digit to get the code
this code would then be changed into a Roman Numeral Value line for each newline
CECS 275 Spring 2024
@authors Brandon J
@authors Daniel B
Revision 1.2.3
Last updatesd 2/21/24 7:00 - 8:55pm
Copyright no one is allowed to distrbute or copy this code
*/

#include <iostream>
#include <string>
#include <fstream>
#include "myUtlis.h"
using namespace std;

int mySecretCode(string fileName);//define the prototyps the order of functions
string number_to_roman(int number,string numerals);

int main(){
     while(true){
        //display menu
        menu();
        int choice;
        cout << "Choice: ";//ask the user to chose an option from menu
        cin >> choice;//take the value 
        ofstream output;
        ifstream input;
        string fakeDataFileName = "fake_data.txt";
        switch(static_cast<Option>(choice)){
            case Option::NONE:
                break;
            case Option::GENERATE_DATA:
                //debug
                //cout << generateARandomMessage(10) << endl;
                generateFakeData(output,fakeDataFileName,1,10,100);//generates fake data to txt file called fake_data
                //when user press option 1
                break;
            case Option::EXTRACT_DATA:
                break;
            case Option:: PROCESS_DATA:
                mySecretCode("input.txt");//calls the function and passes the input file to be open and processed
                //when the user presses 3
                break;
            case Option:: EXIT:
                cout << "Thank you for using our program\n";
                exit(0);//when user presses four exits program
                break;
            default:
                break;        
        
       
        }
    }
    return 0;
}

int mySecretCode(string fileName){//allows a string datatype file which is the input
    ifstream input;//define ifstream input so we can open it
    input.open(fileName);//opens whatever txt file which is the variable filename
    if(!input){
        cout << "File cannot be opened!!!" << endl;
    }
    cout << "Data processing.... " << endl;
    ofstream output;
    output.open("processed_data");//opens output file
    /*
    define datatypers needed for program*/

    string numerals,numeral_out;
    unsigned long long int sumMessage;
    unsigned long long int total = 0;
    int eachDigitTotal = 0;
    int remain, numOfLine = 1,romanNum,remainAfter;
    
    while(input){//if there is some input loop through it all
        char c;//define c to be a char type
        c = input.peek();// let c be equal to a value that we peek 
        if(c >= 48 && c <= 57){//ASCII value if between 48 - 57 its a number 
            input >> sumMessage;//take all intergers until fails meaning 123 takes it 
            total += sumMessage;//then add them together ex 123 + 123 + etc ....
        }else if (c == 10 || c == -1){//if newline detected ACII 10 print out the message line/code/numeral
            //cout << total << endl; debug purposes
            //if c == -1 that means file ends print out the last line as well if theres not a newline after
            while(total != 0){//total is not equal to zero
                remain = total % 10;//dvide total by mod to get remainder
                eachDigitTotal += remain;//update it to eachDigitTotal
                total = total / 10;//divide total by 10 to get next number ex 356 / 10 aprrox 35
            }
            //if(eachDigitTotal == 0){
            //}
            if(eachDigitTotal >= 0){
                //cout << "Message " << numOfLine << ": " << endl;//debug purposes
                output << "Message " << numOfLine << ": " << endl;//outputs to processed data folder the number of line
                //cout << "Code: " << eachDigitTotal << endl; debug purposes
                output << "Code: " << eachDigitTotal << endl;//outputs the code

                romanNum = eachDigitTotal % 4000;
                numeral_out = number_to_roman(romanNum,numerals);//calls the number to roman numeral funciton passes an int and string            total = 0;//resets total
                //cout << "Roman Numeral: " << numeral_out << endl; debug purposes
                output << "Roman Numeral: " << numeral_out << "\n" << endl;//outputs the roman num from the function that we called
                eachDigitTotal = 0;//resets the eachdigit total value for the next line to be read
                numOfLine += 1;//incremenets the value of how many messages read
                input.get(c);
            }
            input.get(c);//gets the newline character so buffer can move on
        }else{
            input.get(c);//gets the things that are a number or a newline and continues
        }
    }
    cout << "Successfully Processed Data!!" << endl;//once sucessfully done 
    input.close();//close input file
    output.close();//close output file
    return 0;
}
/*
This is a function that gets called inside secret code
once the code is obtained from the file we call this function
to convert it from a number to roman numerals and return that string
if number is greater than 500 we know that we can add a string
*/
string number_to_roman(int number,string numerals){
    while(number >= 1000){
        numerals += "M";
        number -= 1000;
    }
    while(number >= 900){
        numerals += "CM";
        number -= 900;
    }
    while(number >= 500){
        numerals += "D";
        number -= 10;
    }
    while(number >= 400){
        numerals += "CD";
        number -= 400;
    }
    while(number >= 100){
        numerals += "C";
        number -= 100;
    }
    while(number >= 90){
        numerals += "XC";
        number -= 90;
    }
    while(number >= 50){
        numerals += "L";
        number -= 50;
    }
    while(number >= 40){
        numerals += "XL";
        number -= 40;
    }
    while(number >= 10){
        numerals += "X";
        number -= 10;
    }
    while(number >= 9){
        numerals += "IX";
        number -= 9;
    }
    while(number >= 5){
        numerals += "V";
        number -= 5;
    }
    while(number >= 4){
        numerals += "IV";
        number -= 4;
    }
    while(number >= 1){
        numerals += "I";
        number -= 1;
    }
    return numerals;//return a string 
}