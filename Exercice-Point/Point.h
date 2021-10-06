#pragma once
class Point
{
	double x_;
	double y_;

public:
	Point();
	Point(double x, double y);

	void move(double dx, double dy);
	void print() const;
	[[nodiscard]] double distance(Point other) const;
	[[nodiscard]] Point center_point(Point other) const;

	[[nodiscard]] double get_x() const;
	[[nodiscard]] double get_y() const;
};

