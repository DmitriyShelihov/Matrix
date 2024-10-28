#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	if (argc <= 1)
		return 0;
	int ntests = atoi(argv[1]);

	if (ntests > 20) {
		std::cout << "Are you sure?\nPress 1/0 if yes/not\n";
		bool res = 0;
		std::cin >> res;
		if (res == 0) {
			std::cout << "Stopped\n";
			return 0;
		}
	}

	for (int i = 0; i < ntests; i++) {
		std::ofstream out("Tests/test" + std::to_string(i) + ".txt");
		
		size_t n = rand()%10 + 1;
		out << n << "\n";
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				out << rand()%50 << " ";
			}
			out << "\n";
		}
		
		out.close();
	}	
	return 0;
}
