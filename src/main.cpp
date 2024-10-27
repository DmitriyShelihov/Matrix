#include <iostream>
#include <matrix.h>

int main() {
	size_t n = 0;
	std::cin >> n;

	std::vector <std::vector<double>> vec;
	for (int i = 0; i < n; i ++ ) {
		std::vector<double>vec_2;
		vec.push_back(vec_2);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int elem;
			std::cin >> elem;
			std::vector<double> &pr_vec = vec[i];
			pr_vec.push_back(elem);
		}
	}
	Matrix<double> mat(n, vec);
	std::cout << "Det is " << mat.det()  << "\n";
	return 0;
}
