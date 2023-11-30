#include <string>
#include <iostream>
#include <vector>

//Returns true if there is a char vowel and returns false if not
bool is_vowel(char vowel) {
	if (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u') {
		return true;
	}
	return false;
}

//Returns true if there is not a vowel, which means it is a consonant. Returns false if it is a vowel
bool is_consonant(char consonant) {
	if (!(consonant == 'a' || consonant == 'e' || consonant == 'i' || consonant == 'o' || consonant == 'u')) {
		return true;
	}
	return false;
}

//Returns true if candidate is empty and suffix is empty
//Returns false if candidate is empty and suffix is not empty
//Returns true if candidate ends with suffix
//Returns false if all three cases don't work
bool ends_with(std::string candidate, std::string suffix) {
	if (candidate == "" && suffix == "") {
		return true;
	}
	else if (candidate == "" && !(suffix == "")) {
		return false;
	}
	else if (!(candidate == "")) {

		if (suffix == "") {
			return true;
		}
		if (candidate.length() > suffix.length()) {
			std::string test_candidate_suffix = candidate.substr(candidate.length() - suffix.length());
			if (test_candidate_suffix == suffix) {
				return true;
			}

		}



	}
	return false;
	
}

//Returns true of the last two characters of the parameter are the same consonants
bool ends_with_double_consonant(std::string double_consonant) {
	if (double_consonant.size() < 2) {
		return false;
	}
	if (!(is_consonant(double_consonant[double_consonant.size() - 1]) && is_consonant(double_consonant[double_consonant.size() - 2]))) {
		return false;
	}
	if ((double_consonant[double_consonant.size() - 1]) == (double_consonant[double_consonant.size() - 2])) {
		return true;
	}
	return false;
}

//Returns true if the first letter is a consonant, the second letter is a vowel
//and the third letter is a consonant, returns false otherwise
bool ends_with_cvc(std::string cvc) {
	
	if (cvc.length() < 3) {
		return false;
	}
	
	if ((is_consonant(cvc[cvc.length() - 1])) && (is_vowel(cvc[cvc.length() - 2])) && (is_consonant(cvc[cvc.length() - 3]))) {
		return true;
	}
	
	return false;
	
	
}

//Returns the number of consecutive vowels at the beginning of the string
int count_consonants_at_front(std::string front_consanants) {
	int consanants_number = 0;
	for (int i = 0; i < front_consanants.size(); i++) {
		if (is_consonant(front_consanants[i])) {
			consanants_number++;
		}
		else if(is_vowel(front_consanants[i])) {
			return consanants_number;
		}
	}
	return consanants_number;
}

//Returns the number of consecutive consonants at the end of the string
int count_vowels_at_back(std::string back_vowels) {
	int vowels_number = 0;
	for (int i = back_vowels.size(); i > 0; i--) {
		if (is_vowel(back_vowels[i - 1])) {
			vowels_number++;
		}
		else if (is_consonant(back_vowels[i - 1])) {
			return vowels_number;
		}
		
	}
	return vowels_number;
}

//Returns true if there is a single vowel detected, returns false otherwise
bool contains_vowel(std::string any_vowel) {
	for (int i = 0; i < any_vowel.size(); i++) {
		if (is_vowel(any_vowel[i])) {
			return true;
		}
	}
	return false;
}

//Creates a new string by removing its last suffix and replacing
//it with a new one if needed
std::string new_ending(std::string old_candidate, int suffix_length, std::string replacement) {

	if (suffix_length >= 0 && suffix_length <= old_candidate.length()) {

		//I looked up the .substr function, what it does is takes a specified amount from the string starting
		//  from 0 to whatever (old_candidate.length() - suffix_length) equals which is really cool and helpful

		std::string modified_candidate = old_candidate.substr(0, old_candidate.length() - suffix_length);
			return modified_candidate + replacement;
	}
}

