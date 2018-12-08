bool increaseNumberRoundness(int n) {
   bool res = false;
	int notZeroIndex = -1;
	std::string numberRound = std::to_string(n);
	for (int i = numberRound.length() - 1; i >= 0; --i){
		int number = numberRound[i] - '0';
		if (number != 0){
			notZeroIndex = i;
			break;
		}
	}
	if (notZeroIndex == -1){
		return false;
	}

	for (int i = notZeroIndex; i >= 0; --i){
		int zeroNumber = numberRound[i] - '0';
		if (zeroNumber == 0){
			res = true;
			break;
		}
	}

	return res;
}
