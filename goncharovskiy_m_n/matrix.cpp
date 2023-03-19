class MatrixS {
private:
	ptrdiff_t m_ = 0;
	ptrdiff_t n_ = 0;
	std::vector<int> matrix_;

public:
	MatrixS() = default;
	MatrixS(const ptrdiff_t& m, const ptrdiff_t& n) {
		int var = 1;
		m_ = m;
		n_ = n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix_.push_back(var);
				var += 1;
			}
		}
	}
	~MatrixS() = default;
	MatrixS(const MatrixS& other) {
		this->m_ = other.m_;
		this->n_ = other.n_;
		this->matrix_ = other.matrix_;
	}
	MatrixS& operator=(const MatrixS& other) {
		this->m_ = other.m_;
		this->n_ = other.n_;
		this->matrix_ = other.matrix_;
		return *this;
	}

	int& at(ptrdiff_t m, ptrdiff_t n) {
		return matrix_[(m * this->n_) + n];
	}
	void print() {
		for (int i = 0; i < m_; i++) {
			for (int j = 0; j < n_; j++) {
				std::cout << matrix_[(i * n_) + j] << "  ";
			}
			std::cout << std::endl;
		}
	}
	void ssize() {
		std::cout <<'{' << m_ << 'x' << n_<< '}' << std::endl;
	}
	void resize(const ptrdiff_t new_m, const ptrdiff_t new_n) {
		if (new_m < this->m_ && new_n < this->n_) {
			MatrixS copy = *this;
			this->matrix_.clear();
			for (int i = 0; i < new_m; i++) {
				for (int j = 0; j < new_n; j++) {
					matrix_.push_back(copy.at(i, j));
				}
			}
		}
		this->m_ = new_m;
		this->n_ = new_n;
	}
};
