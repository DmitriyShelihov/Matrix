#include <matrix.h>
#include <fstream>

int main(int argc, char** argv) {
	if (argc <= 1)
		return 0;
	int ntests = atoi(argv[1]);
	if (ntests < 1)
		return 0;
	for (int k = 0; k < ntests; ++k) {
		std::ifstream in("Tests/test" + std::to_string(k) + ".txt");
		int N = 0;
		in >> N;

		std::vector<std::vector<int>> vec;
		for (int i = 0; i < N; ++i) {
			std::vector<int> new_row;
			vec.push_back(new_row);
			int elem = 0;
			for (int j = 0; j < N; ++j) {
				in >> elem;
				vec[i].push_back(elem);
			}
		}
		in.close();

		Matrix<int> mat(N, vec);

		std::ofstream out("Ans/test" + std::to_string(k) + "_ans.txt");
		out << static_cast<long long>(mat.det());
		out.close();
	}
	return 0;
}
