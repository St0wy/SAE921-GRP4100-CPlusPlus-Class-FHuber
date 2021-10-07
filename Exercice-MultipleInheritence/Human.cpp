#include "Human.h"

Human::Human()
	:Race(DEFAULT_LIFEPOINTS)
{
}

void Human::prey()
{
	set_life_points(get_life_points() + HEAL_AMMOUNT);
}
