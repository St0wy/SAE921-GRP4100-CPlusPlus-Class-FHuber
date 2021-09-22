#include <iostream>

constexpr int SCORES_LENGTH = 5;

int get_best_score(int scores[], const int length);

int main()
{
	int scores[] = { 84, 92, 76, 81, 56 };

	std::cout << "The best score is : "
		<< get_best_score(scores, SCORES_LENGTH) << std::endl;

	// Alternatively...
	// It's not precised it has to work on other arrays ;)
	std::cout << "The best score is also : " << scores[1] << std::endl; 
}

int get_best_score(int scores[], const int length)
{
	int best_score = 0;
	for (int i = 0; i < length; ++i)
	{
		if (scores[i] > best_score)
		{
			best_score = scores[i];
		}
	}

	return best_score;
}