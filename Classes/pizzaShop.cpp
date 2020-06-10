/* Name: <fill me in>
   Date: <fill me in>
   Desc: <fill me in>
*/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Topping {
private:
	string name;
	float cost_per_lb;

public:
	Topping(string nameTopping, float costTopping) {
		name = nameTopping;
		cost_per_lb = costTopping;
	}

	string getName() {
		return name;
	}

	float getCostPerLb() {
		return cost_per_lb;
	}
};

class PizzaSize {
private:
	int size;
	float cost_per_size;

public:
	PizzaSize(int sizePizza, float costPizzaSize) {
		size = sizePizza;
		cost_per_size = costPizzaSize;
	}

	PizzaSize() {
	}

	int getSize() {
		return size;
	}

	float getCostPerSize() {
		return cost_per_size;
	}
};

class Pizza {
private:
	PizzaSize sizePizza;
	string sauce;
	vector<Topping> toppings;

public:
	Pizza(PizzaSize size, string sauce_temp) {
		sauce = sauce_temp;
		sizePizza = size;
	}

	float getPrice() {
		float price = sizePizza.getCostPerSize();

		for (unsigned i = 0; i < toppings.size(); i++) {
			price = price + toppings[i].getCostPerLb();
		}

		return  price;
	}

	string getSauce() {
		return sauce;
	}

	void addTopping(Topping t) {
		toppings.push_back(t);
	}

	string getDescription() {
		stringstream s;
		s << sizePizza.getSize();
		string ret = s.str() + "\" pizza with " + sauce + " sauce, topped with: ";
		for (unsigned i = 0; i < toppings.size(); i++) {
			ret += toppings[i].getName() + ", ";
		}
		return ret;
	}
};

int main() {

	vector<Topping> toppings;

	toppings.push_back(Topping("pepperoni", 5.72));
	toppings.push_back(Topping("mushrooms", 3.24));
	toppings.push_back(Topping("olives", 4.21));
	toppings.push_back(Topping("pineapple", 2.99));

	vector<PizzaSize> sizes;
	sizes.push_back(PizzaSize(5, 8));
	sizes.push_back(PizzaSize(8, 10));
	sizes.push_back(PizzaSize(12, 12));


	vector<string> sauces;
	sauces.push_back("red");
	sauces.push_back("brown");
	sauces.push_back("white");

	cout << "Welcome to the Pizza Shop!" << endl << endl;
	cout << "This program will let you customize a pizza" << endl;
	cout << "and find the price." << endl << endl;


	int sizes_i = 0;
	PizzaSize ps;
	cout << "What size would you like?" << endl;
	for (unsigned i = 0; i < sizes.size(); i++) {
		cout << i << ": " << sizes[i].getSize() << endl;
	}
	cin >> sizes_i;
	if (sizes_i >= 0 && sizes_i < sizes.size()) {
		ps = sizes[sizes_i];
	}

	int sauce = 0;
	do {
		cout << "What sauce would you like?" << endl;
		for (unsigned i = 0; i < sauces.size(); i++) {
			cout << i << ": " << sauces[i] << endl;
		}
		cin >> sauce;
	} while (sauce < 0 || sauce >= sizes.size());

	Pizza narucenapizza(ps, sauces[sauce]);

	int topping_i = 0;
	while (1) {
		cout << "Current Pizza: " << narucenapizza.getDescription();
		cout << "Price: $" << narucenapizza.getPrice() << endl;
		cout << "What topping(s) woud you like, or -1 to finish?" << endl;
		for (unsigned i = 0; i < toppings.size(); i++) {
			cout << i << ": " << toppings[i].getName() << endl;
		}
		cin >> topping_i;
		if (topping_i == -1)break;
		if (topping_i >= 0 && topping_i < toppings.size()) {
			narucenapizza.addTopping(toppings[topping_i]);
		}
	};

	cout << "Thank you for your order, here is your receipt: " << endl;
	cout << narucenapizza.getDescription();
	cout << "\nTotal: $" << narucenapizza.getPrice() << endl;
	system("pause");
	return 0;
}
