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