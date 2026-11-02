/*
 * Course: COEN 2220 - Programming 2
 * Name: [Aida S.. Mendoza Gonzalez]
 * Lab: Lab 11 - Recursion and Merge Sort
 * Description: Desde 0 code usingg what we learn.
 * Due date: [3 de noviembre de 2026]
 */
#include <iostream>
#include <string>
using namespace std;

struct OrderPreview
{
int orderId;
string orderType;
string status;
string building;
int priority; 
};

int main()
{
    const int MAX = 4;
    OrderPreview orders[MAX] =
    {
        {10, "DELIVERY", "PENDING", "Engineering", 3},
        {11, "DELIVERY", "IN_PROGRESS", "Library", 2},
        {12, "DINE_IN", "PENDING", "StudentCenter", 4},
        {13, "DELIVERY", "COMPLETED", "Engineering", 1}
    };

    OrderPreview* view[MAX];
    int viewCount = 0;
    cout << "Original orders before building the view:\n";
    for (int i = 0; i < MAX; i++)
    {
        cout << "ID: " << orders[i].orderId
             << " | Status: " << orders[i].status
             << endl;
    }
    // Build the filtered view
    for (int i = 0; i < MAX; i++)
    {
        bool active =
            orders[i].status == "PENDING" || // es lo mismo que hacer if else if else. declaras que el bool active es eso si es lo que declare
            orders[i].status == "IN_PROGRESS";

        if (orders[i].orderType == "DELIVERY" && active) // si es "string" o active
        {
            view[viewCount] = &orders[i];
            viewCount++;
        }
    }
    cout << "Selected DELIVERY orders:"<< endl;
    for (int i = 0; i < viewCount; i++)
    {
        cout << "ID: " << view[i]->orderId << endl;
    }

    cout << "Original orders after building the view: "<< endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "ID: " << orders[i].orderId
             << " | Status: " << orders[i].status
             << endl;
    }

    cout << "FIFO explanation:"<<endl;
    cout << "The original collection was not reordered. "
         << "The report uses borrowed pointers, so the operational "
         << "FIFO sequence remains unchanged. "<<endl;

    
    return 0;
}