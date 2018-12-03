std::vector<int> constructArray(int size) {
	std::vector<int> res;
	int i = 1;
	int _size = size;
	while (res.size() < _size){
		res.push_back(i);		
		res.push_back(size);
		if (res.size() > _size){
			res.pop_back();
		}
		size -= 1;
		i++;
	}
	return res;
}