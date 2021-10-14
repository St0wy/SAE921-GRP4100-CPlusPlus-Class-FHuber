#pragma once
class Item
{
public:
	Item() = default;
	virtual ~Item() = default;
	Item(const Item& item) = default;
	Item(Item&&) = default;

	Item& operator=(const Item& other) = default;
	Item& operator=(Item&& other) noexcept = default;

	virtual void use() = 0;
};

