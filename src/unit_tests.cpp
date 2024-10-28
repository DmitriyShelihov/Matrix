#include <gtest/gtest.h>
#include "matrix.h"

::testing::AssertionResult MAT_EQ(Matrix<double>* const mat_ans, size_t n, double mat_ref[]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (cmp_dbl(mat_ref[i*n+j], (*mat_ans)[i][j]) != 0)
				return ::testing::AssertionFailure();
		}
	}
	return ::testing::AssertionSuccess();
}

class Add_RowTest: public ::testing::Test {
	public:
		Matrix<double>* mat_ans;
	protected:
		const size_t n = 2;
		double mat_ref[2][2] = {{4, 6}, {3, 4}};
	
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
	MAT_EQ(mat_ans, n, reinterpret_cast<double*>(mat_ref));
}

class Mul_RowTest: public ::testing::Test {
	public: 
		Matrix<double>* mat_ans;
	protected:
		const size_t n = 3;
		double mat_ref[3][3] = {{1, 2, 3}, {4, 4, 6}, {7, 8, 9}};
	void SetUp() {
		std::vector<std::vector<double>> vec;
		for (int i = 0; i < 3; ++i) {
			std::vector<double> new_row;
			vec.push_back(new_row);
		}
		vec[0].push_back(1); vec[0].push_back(2); vec[0].push_back(3);
		vec[1].push_back(-2); vec[0].push_back(-2); vec[0].push_back(-3);
		vec[2].push_back(7); vec[2].push_back(8); vec[2].push_back(9);

		mat_ans = new Matrix<double>(n, vec);
		mat_ans->mul_row(-2, 1);
	}
};

TEST_F(Mul_RowTest, test2) {
	MAT_EQ(mat_ans, n, reinterpret_cast<double*>(mat_ref));
}

class Find_NonzeroTest: public ::testing::Test {
	public: 
		int ans1;
		int ans2;
		int ans3;
	protected:
		const size_t n = 3;
		const int ans_ref1 = 1;
		const int ans_ref2 = 2;
		const int ans_ref3 = -1;
	void SetUp() {
		std::vector<std::vector<double>> vec;
        for (int i = 0; i < n; ++i) {
        	std::vector<double> new_row;
 			vec.push_back(new_row);
        }
        vec[0].push_back(0); vec[0].push_back(0); vec[0].push_back(0);
        vec[1].push_back(1); vec[0].push_back(0); vec[0].push_back(0);
        vec[2].push_back(0); vec[2].push_back(5); vec[2].push_back(0);
 
        Matrix<double>* mat_ans = new Matrix<double>(n, vec);
        ans1 = mat_ans->find_nonzero(0);
        ans2 = mat_ans->find_nonzero(1);
        ans3 = mat_ans->find_nonzero(2);
	}
};

TEST_F(Find_NonzeroTest, test3) {
	ASSERT_EQ(ans1, ans_ref1);
	ASSERT_EQ(ans2, ans_ref2);
	ASSERT_EQ(ans3, ans_ref3);
}

class Swap_RowsTest: public ::testing::Test {
	public: 
		Matrix<double>* mat_ans;
	protected:
		const size_t n = 3;
		double mat_ref[3][3] = {{4, 5, 6}, {1, 2, 3}, {7, 8, 9}};
	void SetUp() {
		std::vector<std::vector<double>> vec;
        for (int i = 0; i < n; ++i) {
 			std::vector<double> new_row;
			vec.push_back(new_row);
 		}
 		vec[0].push_back(1); vec[0].push_back(2); vec[0].push_back(3);
		vec[1].push_back(4); vec[0].push_back(5); vec[0].push_back(6);
 		vec[2].push_back(7); vec[2].push_back(8); vec[2].push_back(9);
		mat_ans = new Matrix<double>(n, vec);
		mat_ans->swap_rows(0, 1);
	}
};

TEST_F(Swap_RowsTest, test4) {
	MAT_EQ(mat_ans, n, reinterpret_cast<double*>(mat_ref));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

