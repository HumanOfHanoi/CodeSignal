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