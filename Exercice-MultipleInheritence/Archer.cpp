#include "Archer.h"

Archer::Archer()
	: Archer(DEFAULT_NB_ARROWS)
{
}

Archer::Archer(const int nb_arrows)
	: nb_arrows_(nb_arrows)
{
}

int Archer::get_nb_arrows() const
{
	return nb_arrows_;
}

void Archer::shoot(Race& opponent)
{
	if (nb_arrows_ > 0)
	{
		opponent.recieve_damage(ARROWS_DAMAGE);
		nb_arrows_--;
	}
}
