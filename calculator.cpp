#include "calculator.hpp"
#include <fstream> //allows access to all components of header fstream
#include <iostream> //allows acces to all components of header iostream
#include <sstream> //allows acces to all components of header sstream
#include <string> //allows access to all components of header string
#include <vector> //allows access to all components of header vector 
#include <typeinfo>

double parse_number(const std::string &expression){

}

//main function that deals with file and calls functions
int main(){
    std::ifstream file; //creates an ifstream variable called file (for reading from files)
    std::string file_name; //initializes string file_name
    std::cout << "Enter the name of your file: " << std::endl; //asks user for file name as input
    std::cin >> file_name; //stores user input in file_name
    
    file.open(file_name); //opens file file_name
    //error checking if file opened correctly
    if (!file.is_open()){ //True if file is not open //got this function from Google AI Overview
        std::cout << "Error opening the file." << std::endl; //displays error with file
        return 0; //return to terminate main program
    }

    std::vector<std::string> str_nums; //a vector of a vector of characters that will store the puzzle
    std::string line; //variable line ~ type: string

    while (std::getline(file, line)) { // while loop to get each line from the file
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); // remove any trailing newline characters
        std::stringstream ss(line); // creates a stringstream of line called ss
        for (int i = 0; i < line.size(); i++) { //iterate from 0 to line.size()
            str_nums.push_back(line); //add line[i] to row
        }
    }

    bool sign_exists_already = false;
    bool valid_num = true; 
    for (int i = 0; i < str_nums.size(); i++){ //iterate through str_num
        
        for (int j = 0; j < str_nums.size(); j++){ //iterate through each character of str_num[i]
            //error checking of more than one sign or decimal
            if (str_nums[i][j] == '+' || str_nums[i][j] == '-' || str_nums[i][j] == '.'){
                if (sign_exists_already){
                    std::cout << "invalid double" << std::endl;
                    valid_num = false;
                }
                sign_exists_already = true;
            }
            //error checking if not a number, sign, or period
            if (str_nums[i][j] != '+' && str_nums[i][j] != '-' && str_nums[i][j] != '.' && str_nums[i][j] != '0' && str_nums[i][j] != '1' && str_nums[i][j] != '2' && str_nums[i][j] != '3' && str_nums[i][j] != '4' && str_nums[i][j] != '5' && str_nums[i][j] != '6' && str_nums[i][j] != '7' && str_nums[i][j] != '8' && str_nums[i][j] != '9'){
                std::cout << "invalid double" << std::endl;
                valid_num = false;
            }
        }
        if (valid_num){
            double num = parse_number(str_nums[i]);
            std::cout << num << " + " << "-123.456: " << (num + -123.456) << std::endl;
        }
        valid_num = true;

    }
}