#include "Car.h"

#include <utility>

Car::Car()
	: brand_("NO BRAND"), model_("NO MODEL"), release_year_("NO  RELEASE YEAR")
{
}

Car::Car(std::string brand, std::string model, std::string release_year)
	: brand_(std::move(brand)),
	model_(std::move(model)),
	release_year_(std::move(release_year))
{
}

std::string Car::to_string() const
{
	return brand_ + " " + model_ + " de " + release_year_;
}

std::string Car::get_brand() const
{
	return brand_;
}

std::string Car::get_model() const
{
	return model_;
}

std::string Car::get_release_year() const
{
	return release_year_;
}
