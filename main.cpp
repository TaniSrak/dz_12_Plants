#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Harvest
{
public:
	virtual int GetWeight()=0;
	virtual std::string GetName()=0;
	virtual std::string GetColor()=0;

protected:
	std::string name_;
	int weight_;
	std::string color_;
};

class Apple : public Harvest
{
public:
	int GetWeight() override
	{
		return weight_;
	}

	std::string GetName() override
	{
		return name_;
	}

	std::string GetColor() override
	{
		return color_;
	}

	Apple(std::string name, int weight, std::string color)
	{
		name_ = name;
		weight_ = weight;
		color_ = color;
	}

};

class Tree
{
public:
	virtual Harvest* GetHarvest()=0;

	Tree(int harvestCount, std::string color, std::string size)
	{
		harvestCount_ = harvestCount;
		color_ = color;
		size_ = size;
	}
protected:
	int harvestCount_;
	std::string color_;
	std::string size_;
};

class AppleTree : public Tree
{
public:
	Harvest* GetHarvest() 
	{
		if (harvestCount_ > 0)
		{
			harvestCount_--;
			return new Apple("Apple", 50, "Red");
		}
		else
		{
			return nullptr;
		}
	}

	AppleTree(int harvestCount, std::string color, std::string size) 
		: Tree(harvestCount, color, size) {}
};

int main(){

	AppleTree at = AppleTree(5, "Green", "Big");
	Harvest* h = at.GetHarvest();
	if (h != nullptr)
	{
		std::cout << h->GetName();
	}

	//Apple* ha = (Apple)at.GetHarvest();




	return 0;
}