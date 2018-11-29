#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
	std::vector<std::string> longestStringsArray;
	int lenStringTmp = inputArray.at(0).length();
	longestStringsArray.push_back(inputArray.at(0));
	for (int i = 1; i < inputArray.size(); i++){
		int lenString = inputArray.at(i).length();
		if (lenString > lenStringTmp){
			longestStringsArray.clear();
			lenStringTmp = lenString;
			longestStringsArray.push_back(inputArray.at(i));
		}
		else if (lenString == lenStringTmp){
			longestStringsArray.push_back(inputArray.at(i));
			lenStringTmp = lenString;
		}
	}

	return longestStringsArray;
}

std::vector<std::string> lietke(std::string str, int number, std::vector<std::string> &charactersArray){

	int startIndex = 0;
	while (startIndex < str.length()){
		std::string _str = str.substr(startIndex, number);
		bool exists = std::find(std::begin(charactersArray), std::end(charactersArray), _str) != std::end(charactersArray);
		if (!exists){
			charactersArray.push_back(_str);
		}
		startIndex += 1;
	}

	return charactersArray;
}

int commonCharacterCount(std::string s1, std::string s2) {
	int numberCount = 0;
	int result[26] = { 0 };
	for (int i = 0; i < s1.length(); ++i){
		char s = s1.at(i);
		result[s - 'a']++;
	}

	for (int j = 0; j < s2.length(); ++j){
		char _s = s2.at(j);
		if (result[_s - 'a'] > 0){
			numberCount++;
			result[_s - 'a']--;
		}
	}

	return numberCount;
}

int arrayPacking(std::vector<int> a) {
	int len = a.size();
	cout << len << endl;
	int ans = 0;
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		ans += (a[i] << j);
		j += 8;
	}
	return ans;
}

int rangeBitCount(int a, int b) {
	int sum = 0;
	std::string bit8Str = "";

	for (int i = a; i <= b; ++i){
		std::bitset<8> bin_x(i);
		bit8Str += bin_x.to_string();
	}

	for (int j = 0; j < bit8Str.length(); ++j){
		int _val = bit8Str[j] - '0';
		sum += _val;
	}
	return sum;
}

int mirrorBits(int a) {
	int b = 0;
	while (a)
	{
		b <<= 1;
		b |= a & 1;
		a >>= 1;

	}
	return b;
}

int zigzac(std::vector<int> a){
	int res = 0;
	int _zigzag = 0;
	std::vector<std::string> fStr;
	if (a.size() <= 2){
		return 1;
	}

	for (int i = 0; i < a.size() - 1; ++i){
		if (a[i] < a[i + 1]){
			fStr.push_back("L");
		}
		else if (a[i] > a[i + 1]){
			fStr.push_back("W");
		}
		else{
			fStr.push_back("D");
		}
	}

	for (int j = 0; j < fStr.size() - 1; ++j){
		if (fStr[j] != fStr[j + 1] && fStr[j] != "D" && fStr[j + 1] != "D"){
			res++;
		}
		else if (fStr[j] == fStr[j + 1] || fStr[j] == "D" || fStr[j + 1] == "D"){
			if (_zigzag <= res){
				_zigzag = res;
			}
			res = 0;
		}
	}

	return (_zigzag + 2);
}

int longestSequence(std::vector<int> a) {

	int best = 1;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			int diff = a[j] - a[i];
			if (diff == 0) {
				continue;
			}
			int cur = 1;
			int last = a[i];
			for (int k = j; k < a.size(); k++) {
				if (a[k] - last == diff) {
					cur++;
					last = a[k];
				}
			}
			if (cur > best) {
				best = cur;
			}
		}
	}

	return best;
}

std::vector<int> constructArray(int size) {
	std::vector<int> res;
	int i = 1;
	int _size = size;
	while (res.size() < _size){
		res.push_back(i);		
		res.push_back(size);
		if (res.size() > _size){
			res.pop_back();
		}
		size -= 1;
		i++;
	}
	return res;
}

std::vector<std::vector<int>> constructSubmatrix(std::vector<std::vector<int>> matrix, std::vector<int> rowsToDelete, std::vector<int> columnsToDelete) {
	std::vector<std::vector<int>> subMatrix;
	int rows = matrix.size();
	int columns = matrix[0].size();
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < columns; ++j){
		
		}
	}

	return subMatrix;
}

std::vector<int> digitRootSort(std::vector<int> a) {
	int sum;
	std::vector<std::string> digitStr;
	for (int i = 0; i < a.size(); ++i){
		std::string str = std::to_string(a[i]);
		sum = 0;
		for (int j = 0; j < str.length(); ++j){
			int value = (str[j] - '0');
			sum += value;
		}
		std::string sumStr = std::to_string(sum);
		str += ("-" + sumStr);
		digitStr.push_back(str);
	}

	for (int k = 0; k < digitStr.size() - 1; ++k){
		for (int t = k + 1; t < digitStr.size(); ++t){
			std::string value = digitStr[k].substr(0, digitStr[k].find("-"));
			std::string _sum = digitStr[k].substr(digitStr[k].find("-") + 1, digitStr[k].length());
			int val1 = atoi(value.c_str());
			int sum1 = atoi(_sum.c_str());

			std::string value2 = digitStr[t].substr(0, digitStr[t].find("-"));
			std::string _sum2 = digitStr[t].substr(digitStr[t].find("-") + 1, digitStr[t].length());
			int val2 = atoi(value2.c_str());
			int sum2 = atoi(_sum2.c_str());

			if (sum1 > sum2 || (sum1 == sum2 && val1 > val2)){
				std::string tmp;
				tmp = digitStr[k];
				digitStr[k] = digitStr[t];
				digitStr[t] = tmp;
			}
		}
	}
	a.clear();
	for (int n = 0; n < digitStr.size(); ++n){
		std::string value = digitStr[n].substr(0, digitStr[n].find("-"));
		int val = atoi(value.c_str());
		a.push_back(val);
	}
	return a;
}

int additionWithoutCarrying(int param1, int param2) {
	std::string number1 = std::to_string(param1);
	std::string number2 = std::to_string(param2);

	std::string strNum1 = "";
	std::string strNum2 = "";
	if (number1.length() < number2.length()){
		int eq = number2.length() - number1.length();
		for (int i = 0; i < eq; ++i){
			strNum1 += "0";
		}
		strNum1 += number1;
		strNum2 += number2;
	}
	else{
		int eq = number1.length() - number2.length();
		for (int i = 0; i < eq; ++i){
			strNum2 += "0";
		}
		strNum1 += number1;
		strNum2 += number2;
	}

	std::string resStr = "";
	for (int j = strNum2.length() - 1; j >= 0; j--){
		int number = ((strNum2[j] - '0') + (strNum1[j] - '0')) % 10;
		resStr += std::to_string(number);
	}

	reverse(resStr.begin(), resStr.end());

	return atoi(resStr.c_str());
}


void main(){
	/*std::string s1 = "aabcc";
	std::string s2 = "adcaa";
	std::vector<int> a = { 24, 85, 0 };*/

	//cout << mirrorBits(97);
	std::vector<int> _a = { 2, 1, 4, 4, 1, 4, 4, 1, 2, 0, 1, 0, 0, 3, 1, 3, 4, 1, 3, 4 };
	std::vector<int> b = { 13, 20, 7, 4 };
	int param1 = 456;
	int param2 = 1734;
	additionWithoutCarrying(param1, param2);
	digitRootSort(b);
	constructArray(7);

	getchar();
}