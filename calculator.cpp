#include "calculator.hpp" //includes calculator.hpp header file
#include <fstream> //allows access to all components of header fstream
#include <iostream> //allows acces to all components of header iostream
#include <sstream> //allows acces to all components of header sstream
#include <string> //allows access to all components of header string
#include <vector> //allows access to all components of header vector 
#include <cmath> //allows access to all components of header cmath

//parse_number function takes the address of a string and parses it into a double 
double parse_number(const std::string &expression){ //returns a double 
    double result = 0; //holds result of parsing string into a double
    char sign = ' '; //holds the sign

    //find index of decimal 
    int period = -1; //variable stores location of decimal
    for (int i = 0; i < expression.size(); i++){ //for loop iterates from 0 to expression.size()
        if (expression[i] == '.'){ //True if expression[i] == '.'
            period = i; //stores i in period
        }
    }

    //check for sign and deal with it 
    //determine starting index
    int start = 0; //holds starting index
    if (expression[0] == '+'){ //True if at first index expression is '+'
        sign = '+'; //sets sign to +
        start = 1; //start is at 1
    } else if (expression[0] == '-'){ //True if at first index expression is '='
        sign = '-'; //sets sign to -
        start = 1; //start is at 1
    }

    //look at num of numbers before decimal
    bool zeros = true; //bool holds whether a number other than 0 has been reached (don't want to count the two 0s before the one in 001.1 for example bc it will mess up the calculation)
    int n = 0; //stores nums before decimal
    //n is working
    if (period != -1){ //True if period is not equal to -1 which means there is a decimal in expression
        for (int j = start; j < period; j++){ //for loop iterates from start to period
            if (expression[j] != '0'){ //True if expression[j] is not equal to 0
                zeros = false; //sets zeros to false bc now hit other numbers 
            }
            if (!zeros){ //True if zeros is False
                n += 1; //add one to n
            }
        }
    } else { //runs if there is no period in expression
        for (int s = start; s < expression.size(); s++){ //for loop iterates from start to expression.size()
            if (expression[s] != '0'){ //True if expression[s] is not equal to 0
                zeros = false; //sets zeros to false bc now hit other numbers 
            }
            if (!zeros){ //True if zeros is False 
                n += 1; //add one to n
            }
        }
    }

    //do calculation with this number ~ try creating pars again?
    std::vector<char> nums; //vector of chars called nums 
    bool period_yet = false; //period_yet set to false ~ stores if hit decimal yet 
    int index = 0; //int index set to 0
    if (period != -1){ //True if period is not equal to -1
        for (int t = (period-n); t < expression.size(); t++){ //for loop from (period-n) to expression.size() ~ want to get valid numbers before period so subtract n to get them
            char exp = expression[t]; //exp holds char at expression[t]
            double c; //c holds what double value to use in calculation
            if (exp == '0'){ //True if exp is 0
                c = 0; //set c to 0
                index += 1; //increment index by 1
            } else if (exp == '1'){ //True if exp is 1
                c = 1; //set c to 1
                index += 1; //increment index by 1
            } else if (exp == '2'){ //True if exp is 2
                c = 2; //set c to 2
                index += 1; //increment index by 1
            } else if (exp == '3'){ //True if exp is 3
                c = 3; //set c to 3
                index += 1; //increment index by 1
            } else if (exp == '4'){ //True if exp  is 4
                c = 4; //set c to 4
                index += 1; //increment index by 1
            } else if (exp == '5'){ //True if exp is 5
                c = 5; //set c to 5
                index += 1; //increment index by 1
            } else if (exp == '6'){ //True if exp is 6
                c = 6; //set c to 6
                index += 1; //increment index by 1
            } else if (exp == '7'){ //True if exp is 7
                c = 7; //set c to 7
                index += 1; //increment index by 1
            } else if (exp == '8'){ //True if exp is 8
                c = 8; //set c to 8
                index += 1; //increment index by 1
            } else if (exp == '9'){ //True if exp is 9
                c = 9; //set c to 9
                index += 1; //increment index by 1
            } else if (exp == '.' && !period_yet){ //true if exp is . and period_yet is false 
                period_yet = true; //sets period_yet to true
                //index isn't incremented bc haven't used it in calculation yet
            }
            if (c != ' '){ //True if c is not ' '
                result = result + c*pow(10,n-index); //result = result + expression[t] * pow(10, n-index) ~ does the calculation
            }
            c = ' '; //resets c to ' '
        }
    } else {
        for (int l = start; l < expression.size(); l++){
            char exp = expression[l];
            double c; 
            if (exp == '0'){ //True if exp is 0
                c = 0; //set c to 0
                index += 1; //increment index by 1
            } else if (exp == '1'){ //True if exp is 1
                c = 1; //set c to 1
                index += 1; //increment index by 1
            } else if (exp == '2'){ //True if exp is 2
                c = 2; //set c to 2
                index += 1; //increment index by 1
            } else if (exp == '3'){ //True if exp is 3
                c = 3; //set c to 3
                index += 1; //increment index by 1
            } else if (exp == '4'){ //True if exp  is 4
                c = 4; //set c to 4
                index += 1; //increment index by 1
            } else if (exp == '5'){ //True if exp is 5
                c = 5; //set c to 5
                index += 1; //increment index by 1
            } else if (exp == '6'){ //True if exp is 6
                c = 6; //set c to 6
                index += 1; //increment index by 1
            } else if (exp == '7'){ //True if exp is 7
                c = 7; //set c to 7
                index += 1; //increment index by 1
            } else if (exp == '8'){ //True if exp is 8
                c = 8; //set c to 8
                index += 1; //increment index by 1
            } else if (exp == '9'){ //True if exp is 9
                c = 9; //set c to 9
                index += 1; //increment index by 1
            }
            result = result + c*pow(10,(expression.size()-l-1));//result = result + expression[t] * pow(10, n-index) ~ does the calculation
        }
    }

    if (sign == '-'){ //if sign is negative return result times -1
        return result*-1;
    }
    return result; //returns result if sign is not negative or if sign doesn't exist 
}

//main function that deals with file and calls functions
int main(){
    std::ifstream file; //creates an ifstream variable called file (for reading from files)
    std::string file_name; //initializes string file_name
    std::cout << "Enter the name of your file: " << std::endl; //asks user for file name as input
    std::cin >> file_name; //stores user input in file_name
    
    file.open("lab10.txt"); //opens file file_name
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
        str_nums.push_back(line); //add line[i] to row
    }

    bool valid_num = true; //valid_num stores value true 
    bool period = false; //period holds value false 
    
    for (int i = 0; i < str_nums.size(); i++){ //iterate through str_num
        std::cout << "\ncurrent num: " << str_nums[i] << std::endl; //displays num from file 
        for (int j = 0; j < str_nums[i].size(); j++){ //iterate through each character of str_num[i]
            //error checking of more than one sign or decimal
            char c = str_nums[i][j]; //sets c to str_nums[i][j]
            //check if sign and if there is sign is it valid
            if (c == '+' || c == '-'){ //True if c is equal to + or c is equa lto -
                if (j != 0){ //True if j is not equal to 0
                    valid_num = false; //sets valid_num to false 
                }
            }
            if (c == '.'){ //True if c is equal to .
                if (period){ //True if period ~ checks if there are more than one decimals
                    valid_num = false; //if there are two of more decimals in the line from the file it is an invalid number so valid_num is set to false 
                } 
                period = true; //sets period to true 
            }
            //error checking if not a number, sign, or period
            if (c != '+' && c != '-' && c != '.' && c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9'){
                valid_num = false; //sets valid_num to false 
            }
        }
        if (valid_num){ //True if valid_num
            double num = parse_number(str_nums[i]); //calls parse_number function to parse str_nums[i] and return it as a double 
            std::cout << "\n" << num << " + " << "-123.456: " << (num + -123.456) << std::endl; //displays result of num + -123.456
        } else { //True if not a valid_num
            std::cout << "Not a valid double." << std::endl; //displays that this is not a valid double 
        }

        //reset the bools
        valid_num = true; //valid _num is set to true
        period = false; //period is set to false 

    }
}