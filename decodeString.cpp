std::string decodeStringdecodeString(std::string s) {
	std::string decodeString = "";
	std::vector<int> indexBracket;
	std::vector<int> loopStr;
	std::string digitStr = "";
	int k;
	for (int i = 0; i < s.length(); ++i){
		if (isdigit(s[i])){
			digitStr += s[i];
			k = i;
		}
		if (s[i] == '['){
			indexBracket.push_back(i);
			loopStr.push_back(atoi(digitStr.c_str()));
			digitStr = "";
		}
		else if (s[i] == ']'){
			int sizeOfArr = indexBracket.size();
			int sizeOfArrLoop = loopStr.size();
			std::string str = s.substr(indexBracket[sizeOfArr - 1] + 1, i - indexBracket[sizeOfArr - 1] - 1);
			std::string replaceStr = "";
			for (int j = 0; j < loopStr[sizeOfArrLoop - 1]; ++j){
				replaceStr += str;
			}
			s.replace(indexBracket[sizeOfArr - 1], i - indexBracket[sizeOfArr - 1] + 1, replaceStr);
			i = k + 1;
			indexBracket.pop_back();
			loopStr.pop_back();
		}
	}
	for (int i = 0; i < s.length(); ++i){
		if (!isdigit(s[i])){
			decodeString += s[i];
		}
	}
	return decodeString;
}