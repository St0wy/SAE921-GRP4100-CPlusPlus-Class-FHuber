#pragma once
#include <ostream>

class Point
{
	double x_;
	double y_;

public:
	Point();
	Point(double x, double y);

	void move(double dx, double dy);

	[[nodiscard]] double get_x() const;
	[[nodiscard]] double get_y() const;

	void print() const;
	void input();

	[[nodiscard]] double distance(Point other) const;
	[[nodiscard]] Point center_point(Point other) const;

	Point operator+(const Point& other) const;
	std::partial_ordering operator<=>(const Point& other) const;
};

std::ostream& operator<<(std::ostream& stream, const Point& other);

