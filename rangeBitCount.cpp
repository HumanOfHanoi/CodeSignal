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