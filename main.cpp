#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
	virtual std::shared_ptr<Harvest> GetHarvest() = 0; //исправила

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
	std::shared_ptr<Harvest> GetHarvest() override //исправила
	{
		if (harvestCount_ > 0)
		{
			harvestCount_--;
			return std::make_shared<Apple>("Apple", 50, "Red"); //исправила
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

	setlocale(LC_ALL, "Russian");

	/*AppleTree at = AppleTree(5, "Green", "Big");
	Harvest* h = at.GetHarvest();
	if (h != nullptr)
	{
		std::cout << h->GetName();
	}*/

	//Apple* ha = (Apple)at.GetHarvest();

	std::unique_ptr<Tree> appleTree = std::make_unique<AppleTree>(10, "Green", "Large");

	std::vector<std::shared_ptr<Harvest>> harvests;

	// Собираем урожай с дерева
	while (auto harvest = appleTree->GetHarvest()) {
		// Добавляем урожай в вектор
		harvests.push_back(harvest);
	}

	std::cout << "Собранный урожай: Name: " << harvests[0]->GetName() << ", Weight: " << harvests[0]->GetWeight() << ", Color: " << harvests[0]->GetColor() << std::endl;


	return 0;
}