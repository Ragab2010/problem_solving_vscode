// For this challenge you will determine if a string matches a set of wildcard characters.
/*
have the function WildcardCharacters(str) read str which will contain two strings separated by a space. 
The first string will consist of the following sets of characters: +, *, and {N} which is optional. 
The plus (+) character represents a single alphabetic character, 
the asterisk (*) represents a sequence of the same character of length 3 unless it is followed by {N} which represents 
how many characters should appear in the sequence where N will be at least 1. 

Your goal is to determine if the second string exactly matches the pattern of the first string in the input.

For example: if str is "++*{5} gheeeee" then the second string in this case does match the pattern, 
so your program should return the string true. 
If the second string does not match the pattern your program should return the string false.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

/*
separate wildcard and result sub string from input
step through result string and check if it follows the rules

at each step we analyze what rule to follow
whether is single character or sequence
if sequence determine if it had default length of 3 or if it is provided with a length

the result string must be parallel to the rules provided by the wildcard
*/
string WildcardCharacters(string str) 
{
	// getting the strings to analyze
	int breakpoint = str.find(' ');
	string wildCard = str.substr(0, breakpoint);
	string result = str.substr(breakpoint + 1, str.length() - breakpoint);

	// step through the wildcard to validate the rule
	int index = 0;
	int step = 0;
	while (index < wildCard.length())
	{
		// checking symbol
		if (wildCard[index] == '+')
		{
			step++;
		}
		else if (wildCard[index] == '*')
		{
			int sequenceLenght = 3;

			// condition to analyze sequence character
			// checking if it falls under default repetition of 3 of if it was assigned a length
			if (index + 1 < wildCard.length())
			{
				// condition to get the assigned length if one is provided
				if (wildCard[index + 1] == '{')
				{
					// getting the length
					string num;
					while (wildCard[index] != '}')
					{
						if (wildCard[index] >= '0' && wildCard[index] <= '9')
						{
							num += wildCard[index];
						}

						index++;
					}

					// converting the gathered number string to an int
					istringstream convert(num);
					convert >> sequenceLenght;
				}
			}

			// first checking for out of bounds
			if (step + sequenceLenght-1 > result.length())
			{
				return "false";
			}
			else
			{
				// loop to ensure the characters are the same in a sequence
				char tempChar = result[step];
				while (sequenceLenght > 0)
				{
					if (result[step] != tempChar)
					{
						return "false";
					}

					sequenceLenght--;
					step++;
				}
			}
		}

		index++;
	}

	// ensure the traversal was parallel
	// in other words for the rules to have been met in the result string we needed to cover everything without any errors
	if (step != result.length())
	{
		return "false";
	}

	return "true";
}

bool parse_pattern(const char * patternStr ,const char * wildcardStr,int pattSize , int wildSize ){
	// create variable for numOfPlus , numOfAstrick , stepAsterick--> 3 or other
	int local_numOfPlus=0 , local_numOfAstrick =0 , local_stepAsterick=3;
	int start_wild=0;//start index of wildcardStr
	int l = 0;//start index of patternStr
	while( l< pattSize){
		if(patternStr[l] == '+'){
			local_numOfPlus++;//increment num of plus 
			//check if we have + local_numOfPlus in pattern 
			if(local_numOfPlus >0 && start_wild < wildSize){
				//if there '+'local_numOfPlus , so we check alpha accoding to it in  the wildcardStr
				if(isalpha(wildcardStr[start_wild])){
					local_numOfPlus--;//decrease local_numOfPlus by one 
					start_wild++;//increament index of wildcardStr to can go next characters
				}else{
					return false;//if there no alpha in the wildcardStr , return false
				}
			}
	//else if the pattern  is '*'
		}else if(patternStr[l] == '*'){
			local_numOfAstrick++;///increment num of astrick 
			int hh = l+1;
			//then we check if there an custom step size of astrick or no 
			if(patternStr[hh] =='{' &&( hh< pattSize)){//check the next chararacter is the custom {5} or no 
				local_stepAsterick = strtol((patternStr+hh+1) , NULL , 10);//convert it to long if found
			}else{
				local_stepAsterick=3;//if there no stom step size of astrick  , we default it by 3
			}
			//here we check if we have + local_numOfPlus in pattern 
			if(local_stepAsterick >0 && start_wild < wildSize){
				int pattern_asterick_counter =0;//create counter for count the number of step
				int l = start_wild , h = start_wild; //l , h pointer to count the step
				while(wildcardStr[l]==wildcardStr[h] && h < wildSize){
					pattern_asterick_counter++;//increment counter
					h++;//increment h pointer
				}
				start_wild=h;//update the index of the wildcardStr
				//check if counter pattern_asterick_counter count  , not the same as the local_stepAsterick custom
				if(local_stepAsterick !=pattern_asterick_counter){
					return false;
				}
			}
		}
		l++;//increment the index of patternStr
	}
	return true;
}

bool WildcardCharacters_c(const char* str){
	//check the str if it NULL
	if(str == NULL){
		return false;
	}
	//get length of the str
	int len = strlen(str);

	//find the space and pointer on it 
	auto pointer_space= find(str , str+len , ' ');
	//if there no space in string 
	if(pointer_space == nullptr){
		return false;
	}

    int endOfPattern =pointer_space -str;//end of pattern = pointer_space -pointer_to_start_string=7
	int startOfWild = endOfPattern + 1;//start of wildcardPattern = end of pattern +1 =8
	char wildcard[len -startOfWild +1];//create array of char for wildcard of 8+1=9 characters
	strcpy(wildcard , str+startOfWild);//copy the wild card from 8 to end_of_str
	int lenOfwildcard=strlen(wildcard);//get the length of the new wildcard;
	//str[startOfWild]='\0';
	
	return parse_pattern(str ,wildcard ,endOfPattern ,  lenOfwildcard);//call parser

}

int main() 
{
	cout <<"----------------------WildcardCharacters------------------------"<<endl;
	cout << WildcardCharacters("++*{5} gheeeee") << endl; // true
	cout << WildcardCharacters("+++++* abcdemmmmmm") << endl; // false
	cout << WildcardCharacters("**+*{2} mmmrrrkbb") << endl; // true
	/*WildcardCharacters_c*/
	cout <<"----------------------WildcardCharacters_c------------------------"<<endl;
	cout << std::boolalpha<<WildcardCharacters_c("++*{5} gheeeee") << endl; // true
	cout << std::boolalpha<<WildcardCharacters_c("+++++* abcdemmmmmm") << endl; // false
	cout << std::boolalpha<<WildcardCharacters_c("**+*{2} mmmrrrkbb") << endl; // true
	return 0;
}