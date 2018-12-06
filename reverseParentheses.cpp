std::string reverseParentheses(std::string s) {
    std::string reverseStr = "";
    std::vector<int> indexBracket;
    for(int i=0; i< s.length(); ++i){
        if(s[i] == '('){
            indexBracket.push_back(i);
        }else if(s[i] == ')'){
            int sizeOfArr = indexBracket.size();
            reverse(s.begin() + indexBracket[sizeOfArr - 1], s.begin() + i);
            indexBracket.pop_back();
        }
    }
    for(int i=0; i< s.length(); ++i){
        if(s[i] != '(' && s[i] != ')'){
            reverseStr += s[i];
        }
    }
    return reverseStr;
}
