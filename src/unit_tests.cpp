#include <gtest/gtest.h>
#include "matrix.h"

class Add_RowTest: public ::testing::Test {
	public:
		Matrix<double>* mat_ans;
		const size_t n = 2;
		const double mat_ref[2][2] = {{4, 6}, {3, 4}};
	
	void SetUp() {
		std::vector<std::vector<double>> vec;
        for (int i = 0; i < 2; i++){
        	std::vector<double> new_row;
            vec.push_back(new_row);
        }
        vec[0].push_back(1);
        vec[0].push_back(2);
        vec[1].push_back(3);
        vec[1].push_back(4);
       	mat_ans = new Matrix<double>(n, vec);
		mat_ans->add_row(0, 1);
	}
};

TEST_F(Add_RowTest, test1) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ASSERT_EQ(cmp_dbl(mat_ref[i][j], (*mat_ans)[i][j]), 0);
		}
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

