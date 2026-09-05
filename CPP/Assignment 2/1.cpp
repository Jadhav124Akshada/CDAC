#include <iostream>
#include <string>

using namespace std;

int currentId = 1001;

class ims {
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    ims() {
        productId = currentId++;
    }

    void acceptDetails() {
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << productId << "\t"
             << name << "\t\t"
             << price << "\t"
             << quantity << "\t"
             << totalValue();

        if (quantity < 10) {
            cout << " <- LOW STOCK";
        }
        cout << endl;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    string getName() const {
        return name;
    }
};

double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate) {
    double base = qty * unitPrice;
    return base + (base * taxRate);
}

double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * (discountPercent / 100.0));
}

int main45() {
    const int size = 5;
    ims product[size];

    cout << "=== Enter Details for 5 Products ===" << endl;
    for(int i = 0; i < size; i++) {
        cout << "\nProduct " << (i + 1) << ":" << endl;
        product[i].acceptDetails();
    }

    cout << "\n===== INVENTORY REPORT =====" << endl;
    cout << "ID\tName\t\tPrice\tQty\tTotal Value" << endl;
    cout << "--------------------------------------------------" << endl;

    for(int i = 0; i < size; i++) {
        product[i].displayDetails();
    }

    int highestIndex = 0;
    double maxVal = product[0].totalValue();
    for(int i = 1; i < size; i++) {
        double currentVal = product[i].totalValue();
        if(currentVal > maxVal) {
            maxVal = currentVal;
            highestIndex = i;
        }
    }
    cout << "\nHighest Value Product: " << product[highestIndex].getName()
         << " (Rs. " << maxVal << ")" << endl;

    int threshold;
    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "Low Stock (threshold: " << threshold << "): ";
    bool first = true;
    for(int i = 0; i < size ; i++) {
        if(product[i].isLowStock(threshold)) {
            if(!first) {
                cout << ", ";
            }
            cout << product[i].getName();
            first = false;
        }
    }
    cout << endl;

    cout << "\n===== REORDER COSTS & DISCOUNTS =====" << endl;
    cout << "Reorder Cost (Int Qty): " << reorderCost(1, 1.50) << endl;
    cout << "Reorder Cost (Fractional Qty): " << reorderCost(1.50, 2.05) << endl;
    cout << "Reorder Cost with Tax (18%): " << reorderCost(5, 1.5, 0.1) << endl;
    cout << "Price with Default Discount (10%): " << applyDiscount(2.0) << endl;
    cout << "Price with Custom Discount (25%): " << applyDiscount(2.0, 2.0) << endl;

    return 0;
}
