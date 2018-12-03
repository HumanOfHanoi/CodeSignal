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


