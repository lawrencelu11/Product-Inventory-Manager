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

    Product(string n, int x, int q, double p)
    {
        name = n;
        id = x;
        quantity = q;
        price = p;
    }
};

class Inventory
{
public:
    vector<Product> inv;
    void AddProduct();
    void SearchProduct();
    void EditProduct();
    void DeleteProduct();
    void DisplayData();
    int GetId();
};

int Inventory::GetId()
{
    int index;
    for(unsigned int i = 0; i < inv.size(); i++)
    {
        inv[i].id = i;
        index = inv[i].id;
    }
    return index;
}

void Inventory::DisplayData()
{
    for(unsigned int i = 0; i < inv.size(); i++)
    {
        cout << "Product name: " << inv[i].name << endl;
        cout << "Product id: " << inv[i].id << endl;
        cout << "Product quantity: " << inv[i].quantity << endl;
        cout << "Product price: " << inv[i].price << endl;
        cout << "\n";
    }
}

void Inventory::AddProduct()
{
    string _name;
    int _id, _quantity, amount, counter = 0;
    double _price;
    cout << "How many products would you like to add?\n";
    cin >> amount;

    while(counter < amount)
    {
        cout << "\n";
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
        _id = GetId();
        cout << "Product added!\n";
        cout << "\n";
        counter++;
    }

}

void Inventory::SearchProduct()
{
    int input;
    cout << "Product id: ";
    cin >> input;
    if(!inv.empty())
    {
        for(unsigned int i = 0; i < inv.size(); i++)
        {
            if(input == inv[i].id)
            {
                cout << "\n";
                cout << "Product name: " << inv[i].name << endl;
                cout << "Product quantity: " << inv[i].quantity << endl;
                cout << "Product price: " << inv[i].price << endl;
                cout << "Product id: " << inv[i].id << endl;
                cout << "\n";
            }
        }
    }else{
        cout << "There is currently no products in the inventory.\n";
    }
}

void Inventory::EditProduct()
{
    int input, selection, newQuantity, newPrice;
    string newName;
    cout << "Product id: ";
    cin >> input;
    for(unsigned int i = 0; i < inv.size(); i++)
    {
        if(input == inv[i].id)
        {
            cout << "1.Product name\n";
            cout << "2.Product quantity\n";
            cout << "3.Product price\n";
            cin >> selection;
            switch(selection)
            {

                case 1:
                    {
                        cout << "New product name: ";
                        getline(cin, newName);
                        inv[i].name = newName;
                        break;
                    }

                case 2:
                    {
                        cout << "New product quantity: ";
                        cin >> newQuantity;
                        inv[i].quantity = newQuantity;
                        break;
                    }

                case 3:
                    {
                        cout << "New product price: ";
                        cin >> newPrice;
                        inv[i].price = newPrice;
                        break;
                    }

                default:
                    cout << "Invalid selection\n";
                    break;
            }
        }
    }
}

void Inventory::DeleteProduct()
{
    int input, index;
    cout << "Enter the product id: ";
    cin >> input;

    for(unsigned int i = 0; i < inv.size(); i++)
    {
        if(!inv.empty() && index == inv[i].id)
        {
            index = inv[i].id;
        }
    }

    inv.erase(inv.begin() + inv[index].id);
    cout << "Product data is deleted!\n";
    cout << "\n";
}

Inventory inventory;

int main()
{
    int choice;
    while(choice != 5)
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
        switch(choice)
        {
            case 1:
                inventory.AddProduct();
                break;
            case 2:
                inventory.SearchProduct();
                break;
            case 3:
                inventory.EditProduct();
                break;
            case 4:
                inventory.DeleteProduct();
                break;
            case 5:
                inventory.DisplayData();
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Choice does not exist, try again!\n";
                cout << "\n";
                break;
        }
    }

    return 0;
}
