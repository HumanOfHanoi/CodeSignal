std::vector<std::string> newNumberalSystem(char number){
	std::vector<std::string> output;
	char temp[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int pos = 0;
	for (int i = 0; i < 26; ++i){
		if (temp[i] == number){
			pos = i;
			break;
		}
	}
	int mid = pos / 2;
	for (int i = 0; i <= mid; ++i){
		std::string _out = std::string(1, temp[i]) + " + " + std::string(1, temp[pos]);
		output.push_back(_out);
		pos--;
	}

	return output;
}