bool almostIncreasingSequence(std::vector<int> sequence) {
	bool isOrdered = false;
	std::vector<int> arrTg;
	if (inOrder(sequence) == true) {
		return true;
	}
	else {
		for (int i = 0; i < sequence.size(); i++) {
			int testNum = sequence.at(i);
			if (inOrder(sequence) == true) {
				isOrdered = true;
			}
			else {
				sequence.splice(i, 0, testNum[0]);
			}
		}
	}
	return isOrdered;
}

bool inOrder(std::vector<int> anArray) {
	for (int i = 0; i < anArray.size(); i++) {
		if (anArray[i] >= anArray[i + 1]) {
			return false;
		}
	}
	return true;
}