#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class Product
{
public:
    string name;
    int id, quantity;
    double price;

    Product(string n, int x, int q, double p){name = n; id = x; quantity = q; price = p;}
};

class Inventory
{
public:
    vector<Product> inv;
    void addProduct();
    void searchProduct();
    void editProduct();
    void deleteProduct();
    void displayData();
    int getId();
};

Inventory inventory;

int main()
{
    int choice;

    while(choice != 6)
    {
        cout << setprecision(2) << fixed;
        cout << "Product Inventory System\n";
        cout << "===========================\n";
        cout << "1.Add Product\n";
        cout << "2.Search Product\n";
        cout << "3.Edit Product\n";
        cout << "4.Delete Product\n";
        cout << "5.Display All Products\n";
        cout << "6.Exit\n";
        cout << "===========================\n";
        cin >> choice;
        cin.ignore();
        cout << "\n\n";
        switch(choice)
        {
            case 1:
                inventory.addProduct();
                break;
            case 2:
                inventory.searchProduct();
                break;
            case 3:
                inventory.editProduct();
                break;
            case 4:
                inventory.deleteProduct();
                break;
            case 5:
                inventory.displayData();
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Choice does not exist, try again!\n\n\n";
                break;
        }
    }

    return 0;
}

int Inventory::getId()
{
    int index;
    for(unsigned int i = 0; i < inv.size(); i++)
    {
        inv[i].id = i;
        index = inv[i].id;
    }
    return index;
}

void Inventory::displayData()
{
    if(!inv.empty())
    {
        for(unsigned int i = 0; i < inv.size(); i++)
        {
            cout << "\n";
            cout << "[Product name: " << inv[i].name << "]" << endl;
            cout << "[Product id: " << inv[i].id << "]" << endl;
            cout << "[Product quantity: " << inv[i].quantity << "]" << endl;
            cout << "[Product price: " << inv[i].price << "]" << endl;
            cout << "\n";
        }
    }else{
        cout << "There are no products in the inventory!\n\n\n";
    }

}

void Inventory::addProduct()
{
        string _name;
        int _id, _quantity, amount, counter = 0;
        double _price;

        cout << "How many products would you like to add?\n";
        cin >> amount;

        while(counter < amount)
        {
            cout << "\n\n";
            cin.ignore();
            cout << "Product name: ";
            getline(cin, _name);
            cout << "Product quantity: ";
            cin >> _quantity;
            cout << "Product price: ";
            cin >> _price;
            cout << "\n";
            Product newProduct(_name, _id, _quantity, _price);
            inv.push_back(newProduct);
            _id = getId();
            cout << "Product added!\n";
            cout << "\n";
            counter++;
        }


}

void Inventory::searchProduct()
{

    if(!inv.empty())
    {
        int input;

        cout << "\n\nProduct id: ";
        cin >> input;
        for(unsigned int i = 0; i < inv.size(); i++)
        {
            if(input == inv[i].id)
            {
                cout << "\n\n";
                cout << "[Product name: " << inv[i].name << "]"<< endl;
                cout << "[Product quantity: " << inv[i].quantity << "]" << endl;
                cout << "[Product price: " << inv[i].price << "]" << endl;
                cout << "[Product id: " << inv[i].id << "]" << endl;
                cout << "\n";
            }else
            {
                cout << "\n\nNo product with that id exists!\n\n\n";

            }
        }
    }else{
        cout << "There are no products in the inventory!\n\n\n";
    }

}

void Inventory::editProduct()
{
    if(!inv.empty())
    {
        int input, selection, newQuantity, newPrice;
        string newName;
        cout << "Product id: ";
        cin >> input;
        for(unsigned int i = 0; i < inv.size(); i++)
        {
            if(input == inv[i].id)
            {
                cout << "Choose which data you would like to change.\n";
                cout << "1.Product name\n";
                cout << "2.Product quantity\n";
                cout << "3.Product price\n\n";
                cin >> selection;
                cin.ignore();
                switch(selection)
                {

                    case 1:

                        cout << "New product name: ";
                        getline(cin, newName);
                        inv[i].name = newName;
                        cout << "\n\nProduct name changed!\n\n";
                        break;


                    case 2:

                        cout << "New product quantity: ";
                        cin >> newQuantity;
                        inv[i].quantity = newQuantity;
                        cout << "\nProduct quantity changed!\n\n";
                        break;


                    case 3:

                        cout << "New product price: ";
                        cin >> newPrice;
                        inv[i].price = newPrice;
                        cout << "\n\nProduct price changed!\n\n";
                        break;

                    default:
                        cout << "\n\nInvalid selection\n";
                        break;
                }


            }
        }
    }else{
        cout << "There are no products in the inventory!\n\n\n";
    }


}

void Inventory::deleteProduct()
{
    if(!inv.empty())
    {
        int input, index;
        cout << "Enter the product id: ";
        cin >> input;
        for(unsigned int i = 0; i < inv.size(); i++)
        {
            if(input == inv[i].id)
            {
                index = inv[i].id - 1;
                inv.erase(inv.begin() + inv[index].id);
                cout << "\n\nProduct data is deleted!\n\n";
                cout << "\n";
            }
        }
    }else{
        cout << "There are no products in the inventory!\n\n\n";
    }


}

