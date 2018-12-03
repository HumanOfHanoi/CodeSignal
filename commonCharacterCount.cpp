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