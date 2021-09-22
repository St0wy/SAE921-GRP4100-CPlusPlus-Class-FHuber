#include <iostream>
#include <string>

constexpr int MAX_MULT_TABLE = 12;

template<std::size_t N, std::size_t M>
void fill_mult_table(int(&arr)[N][M]);

template<std::size_t N, std::size_t M>
void print_mult_table(int(&arr)[N][M]);

int main()
{
	int mult_table[MAX_MULT_TABLE][MAX_MULT_TABLE];
	fill_mult_table(mult_table);
	print_mult_table(mult_table);
}

template<std::size_t N, std::size_t M>
void fill_mult_table(int(&arr)[N][M])
{
	for (std::size_t x = 0; x < N; ++x)
	{
		for (std::size_t y = 0; y < M; ++y)
		{
			// Add 1 because we want to go from 1 - 12
			arr[x][y] = (x + 1) * (y + 1);
		}
	}
}

template<std::size_t N, std::size_t M>
void print_mult_table(int(&arr)[N][M])
{
	// Get the size of the biggest number, to format the other ones
	const std::size_t max_char_num = std::to_string(N * M).length();

	for (std::size_t y = 0; y < M; ++y)
	{
		std::cout << "[";
		for (std::size_t x = 0; x < N; ++x)
		{
			std::string num_string = std::to_string(arr[x][y]);
			const std::size_t num_preceding_zeros = max_char_num - num_string.length();

			for (std::size_t i = 0; i < num_preceding_zeros; ++i)
			{
				std::cout << "0";
			}

			std::cout << num_string;

			// Don't print on the last one
			if (x < N - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}
}