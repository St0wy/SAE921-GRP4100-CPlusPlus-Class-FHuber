#include "Point.h"

#include <iostream>
#include <cmath>

Point::Point()
	:x_(0), y_(0)
{
}

Point::Point(const double x, const double y)
	: x_(x), y_(y)
{
}

void Point::move(const double dx, const double dy)
{
	x_ += dx;
	y_ += dy;
}

void Point::print() const
{
	std::cout << "X : " << x_ << ", Y : " << y_ << std::endl;
}

void Point::input()
{
	std::cin >> x_;
	std::cin >> y_;
}

double Point::distance(const Point other) const
{
	const double diff_x = other.x_ - x_;
	const double diff_y = other.y_ - y_;
	return sqrt(diff_x * diff_x + diff_y * diff_y);
}

Point Point::center_point(const Point other) const
{
	return Point((x_ + other.x_) / 2.0, (y_ + other.y_) / 2.0);
}

double Point::get_x() const
{
	return x_;
}

double Point::get_y() const
{
	return y_;
}
