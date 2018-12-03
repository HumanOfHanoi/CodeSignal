std::vector<std::vector<int>> constructSubmatrix(std::vector<std::vector<int>> matrix, std::vector<int> rowsToDelete, std::vector<int> columnsToDelete) {
	  //delete row
	for (int k = 0; k < rowsToDelete.size(); ++k){
		if (matrix.size() > rowsToDelete[k] && k < 1){
			matrix.erase(matrix.begin() + rowsToDelete[k]);
		}
		else{
			matrix.erase(matrix.begin() + rowsToDelete[k] - 1);
		}
	}
	//delete column
	for (int n = 0; n < matrix.size(); ++n){
		for (int t = 0; t < columnsToDelete.size(); ++t){
			if (matrix[n].size() > columnsToDelete[t] && t<1){
				matrix[n].erase(matrix[n].begin() + columnsToDelete[t]);
			}
			else{
				matrix[n].erase(matrix[n].begin() + columnsToDelete[t] - 1);
			}
		}
	}
	
	return matrix;
}