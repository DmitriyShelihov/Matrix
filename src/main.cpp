#include <iostream>
#include <matrix.h>

int main() {
	size_t n = 0;
	std::cin >> n;

	std::vector <std::vector<int>> vec;
	for (int i = 0; i < n; i ++ ) {
		std::vector<int>vec_2;
		vec.push_back(vec_2);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int elem;
			std::cin >> elem;
			std::vector<int> &pr_vec = vec[i];
			pr_vec.push_back(elem);
		}
	}
	Matrix<int> mat(n, vec);
	std::cout << "Det is " << mat.det()  << "\n";
	return 0;
}
