/* Name: <Ante Lucev>
   Date: <1/29/2017>
   Desc: <The objective of this homework is to write 
   a inventory tracking program which follows a list 
   of parameters.>
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

struct inventory_t {
	string name;
	unsigned price;
	unsigned age;
};

vector<inventory_t> inventory;

int select_menu() {
	int choice;
    cout << "\nOptions:\n";
    cout << "1) Enter Tool\n2) Query Tool Name\n";
    cout << "3) Tools within price range\n";
    cout << "4) Stats\n5) Print All Tools\n6) Quit\n";
    cout << "Enter choice: ";
	cin >> choice;
	return choice;
}

void enter_tool(){
    inventory_t tool;
    cout << "\n1) Entering Tool\n";
    cout << "Tool name: ";
	cin >> tool.name;
    
    cout << "Tool price: ";
    cin >> tool.price;
    
    cout << "Tool age: ";
    cin >> tool.age;
    
	inventory.push_back(tool);

	cout << "\nThere are now " << inventory.size() << " tools stored.\n";

}

void print_tool(inventory_t tool) {
	cout << "Tool name: ";
	cout << tool.name;

	cout << "\nTool price: ";
	cout << tool.price;

	cout << "\nTool age: ";
	cout << tool.age << endl << endl;
}

void query_tool(){
	string name;
	cout << "\n2) Querying Tools with name: ";
	cin >> name;
		
	for(inventory_t inv: inventory) {
		if (name == inv.name) {
			print_tool(inv);
		}
			
	}
}

void tools_range(){
    unsigned min = 0;
    unsigned max = 0;
	int count = 0;

    cout << "\n3) Tools within price range:\n";
    cout << "Enter min price: ";
    cin >> min;
    cout << "Enter max price: ";
    cin >> max;

	for(inventory_t inv: inventory) {
		if (min <= inv.price && max >= inv.price) {
			print_tool(inv);
			count++;
		}
	}
	cout << "Found " << count << " tools in price range " << min << "-" << max << endl;
}

void stats(){
	int sum = 0;
	inventory_t oldest = inventory[0];
	inventory_t most_expensive = inventory[0];
	
	cout << "\n4) Stats:\n";
	for(inventory_t inv: inventory) {
		sum = sum + inv.price;
		if (oldest.age < inv.age) {
			oldest = inv;
		}
		if (most_expensive.price < inv.price) {
			most_expensive = inv;
		}
	}
	
	cout << "Oldest tool:\n";
	print_tool(oldest);
	cout << "Most expensive tool:\n";
	print_tool(most_expensive);
	cout << "Total price of all tools: $" << sum << endl;

}

void print_all() {
	cout << "\n5) Printing All Tools:\n";

	for(inventory_t inv: inventory) {
			print_tool(inv);
	}
}



int main() {
	int choice = 0;
	while (choice != 6) {
		choice = select_menu();

		switch (choice) {
		case 1:
			enter_tool();
			break;

		case 2:
			query_tool();
			break;

		case 3:
			tools_range();
			break;

		case 4:
			stats();
			break;

		case 5:
			print_all();
			break;

		case 6:
			return 0;
		
		default:
			return 0;
		}
	}
	system("pause");
}
