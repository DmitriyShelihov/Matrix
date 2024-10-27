#pragma once

#include <iostream>
#include <vector>
#include <cmath>

const double double_tolerance = 1e-10;

int cmp_dbl(double a, double b) {
	if (std::fabs(a-b) < double_tolerance) 
		return 0;
	if (a-b > double_tolerance) 
		return 1;
	return 2;
}

template <typename T>     //T is a number
class Matrix {
	private:
		size_t _n;
		std::vector<std::vector<T>> _data;
	public:
		Matrix(size_t sz, std::vector<std::vector<T>>& data) 
			: _n(sz), _data(data) {}	//ctor
		Matrix(size_t sz, bool k) : _n(sz) {		//ctor. if k == 0 -> O, k == 1 -> E
			for (int i = 0; i < _n; ++i) {
				std::vector<T> new_row;
				_data.push_back(new_row);
				for (int j = 0; j < _n; ++j) {
					if (i == j && k == 1)
						_data[i].push_back(1);
					else 
						_data[i].push_back(0);
				}
			}
		}
		
		std::vector<T> operator[](int x) {
			return _data[x];
		}
		
		void mul_row(double a, size_t i);
		void add_row(size_t target, size_t adding);
		void sub_row(size_t target, size_t subbing);
		int find_nonzero(size_t col);			//ret = -1 if not found
		void swap_rows(size_t a, size_t b);

		T det();

		void dump();
};

template <typename T>
void Matrix<T>::dump() {
	for (int i = 0; i < _n; ++i) {
		for (int j = 0; j < _n; ++j) {
			std::cout << _data[i][j] << ", ";
		}
		std::cout << "\n";
	}
}

template <typename T>
T Matrix<T>::det() {
	//convert
	double coeff = 1;
	int cur_col = 0;
	while (cur_col < _n) {
		int nonzero = this->find_nonzero(cur_col);
		std::cout << "cur_col = " << cur_col << "nonzero is " << nonzero << "\n"; 
		if (nonzero == -1 && cmp_dbl(_data[cur_col][cur_col], 0) == 0)
			return 0;
		if (cmp_dbl(_data[cur_col][cur_col], 0) == 0 && nonzero != -1) {
			this->swap_rows(0, nonzero);
			coeff*=-1;
		}
		coeff *= 1/(_data[cur_col][cur_col]);
		this->mul_row(1/(_data[cur_col][cur_col]), cur_col);
		std::cout << "After normalize" << "\n";
		this->dump();
		for (int i = 0; i < _n; ++i) {
			if (cmp_dbl(_data[i][cur_col], 0) != 0 && i != cur_col) {
				double save = _data[i][cur_col];
				this->mul_row(save, cur_col);
				this->dump();
				this->sub_row(i, cur_col);
				this->dump();
				this->mul_row(1/save, cur_col);
				this->dump();
			}
			this->dump();
		}
		cur_col++;
	}
	return 1/coeff;
}

template <typename T>
void Matrix<T>::mul_row(double a, size_t i) {
	for (int j = 0; j < _n; ++j) {
		_data[i][j] *= a;
	}
}

template <typename T>
void Matrix<T>::add_row(size_t a, size_t b) {
	for (int i = 0; i < _n; ++i) {
		_data[a][i] += _data[b][i];
	}
}

template <typename T>
void Matrix<T>::sub_row(size_t a, size_t b) {
	for (int i = 0; i < _n; ++i) {
		_data[a][i] -= _data[b][i];
	}
}

template <typename T>
int Matrix<T>::find_nonzero(size_t col) {
	for (int i = 0; i < _n; ++i) {
		if (cmp_dbl(_data[i][col], 0) != 0 && i != col)
			return i;
	}
	return -1;
}

template <typename T>
void Matrix<T>::swap_rows(size_t a, size_t b) {
	for (int col = 0; col < _n; ++col) {
		double save = _data[a][col];
		_data[a][col] = _data[b][col];
		_data[b][col] = save;
	}
}
