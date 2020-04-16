//
//  main.cpp
//  balancedBrackets
//
//  Created by adeeb mohammed on 15/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

// time complexit is o(n) space complexity is o(n)

bool balancedBrackets(std::string str) {
    std::string openingBrackets = "{([";
    std::string closingBrackets = "})]";
    std::unordered_map<char,char> matchingBrackets = {{')','('},{'}','{'},{']','['}};
    std::vector<char> bracketStack = {};
    for(auto ch: str){
        if(openingBrackets.find(ch) != std::string::npos){
            bracketStack.push_back(ch);
        }else if(closingBrackets.find(ch) != std::string::npos){
            if(!bracketStack.size()){
                bracketStack.clear();
                return false;
            }
            if(matchingBrackets[ch] == bracketStack.back()){
                bracketStack.pop_back();
            }else{
                matchingBrackets.clear();
                return false;
            }
            
        }
        
    }
    
    if(bracketStack.size() == 0){
        matchingBrackets.clear();
        return true;
    }
    matchingBrackets.clear();
    return false;
}



int main(int argc, const char * argv[]) {
    std::cout << "Program to check whether the brackets are balanced or not"  << std::endl;
    std::cout << balancedBrackets(")[]}");
    return 0;
}
