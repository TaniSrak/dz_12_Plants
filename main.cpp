#include <iostream>
#include <string>
#include <vector>

// Базовый класс для растений
class Plants {
protected:
    std::string size;
    std::string color;
    int maxFruits;

public:
    Plants(std::string s, std::string c, int max) : size(s), color(c), maxFruits(max) {}

    virtual ~Plants() {}

    // Виртуальная функция для сбора плодов
    virtual void collectFruits() = 0;

    std::string getSize() const { return size; }

    std::string getColor() const { return color; }

    int getMaxFruits() const { return maxFruits; }

    int getAvailableFruits(int currentFruits) const {
        return maxFruits - currentFruits;
    }
};

// Базовый класс для плодов
class Harvest {
protected:
    std::string name;
    double weight;
    std::string color;

public:
    Harvest(std::string n, double w, std::string c) : name(n), weight(w), color(c) {}

    std::string getName() const { return name; }

    double getWeight() const { return weight; }

    std::string getColor() const { return color; }
};

// Класс яблоня
class AppleTree : public Plants {
private:
    int currentFruits;
public:
    AppleTree(std::string s, std::string c, int max) : Plants(s, c, max) {}

    // Метод для добавления плодов на дерево
    void addFruits(int num) {
        currentFruits -= num;
    }
    // Метод для срывания яблок с дерева
    void pickApples(int num) {
        if (num <= currentFruits) {
            std::cout << "Сорвано " << num << " яблок с " << size << " яблони" << std::endl;
            currentFruits -= num;
        }
        else {
            std::cout << "С " << size << " яблони сорвали " << currentFruits << " яблок" << std::endl;
            currentFruits = 0;
        }
    }

    // Реализация сбора плодов для яблони
    void collectFruits() override {
        std::cout << "Собраны яблоки с " << size << " яблони, " << color << " цвета." << std::endl;
        currentFruits = 0;
    }
    // Метод для получения доступного количества плодов
    int getAvailableFruits() const {
        return Plants::getAvailableFruits(currentFruits);
    }
};

// Класс плода яблони
class Apple : public Harvest {
public:
    Apple(std::string n, double w, std::string c) : Harvest(n, w, c) {}
};

// Фабрика
class AppleFactory {
public:
    static Apple* createApple(double weight, std::string color) {
        return new Apple("Яблоко", weight, color);
    }
};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

    AppleTree appleTree("большой", "зеленого", 0);

    appleTree.collectFruits();

    Apple* apple = AppleFactory::createApple(0.1, "зеленый");
    std::cout << "Название плода: " << apple->getName() << std::endl;
    std::cout << "Вес плода: " << apple->getWeight() << " кг" << std::endl;
    std::cout << "Цвет плода: " << apple->getColor() << std::endl;

    appleTree.addFruits(10);
    std::cout << "Доступное количество плодов на яблоне: " << appleTree.getAvailableFruits() << std::endl;
    appleTree.pickApples(5);
    
    std::cout << "Доступное количество плодов на яблоне после срывания: " << appleTree.getAvailableFruits() << std::endl;



    delete apple;

	return 0;
}