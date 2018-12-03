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