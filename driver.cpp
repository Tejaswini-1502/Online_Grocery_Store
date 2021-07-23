#include <iostream>

#include <fstream>

#include <iomanip>

#include "class.h"



using namespace std;

using namespace GSP;





namespace design

{

    //display design

    void display(char c = '=')

    {

        for (int i = 0; i < 30; i++)

        {

            cout << c;

        }

    }

}





void GSP ::allocateJob(Groceryque &g, DeliveryBoys &d1, DeliveryBoys &d2, DeliveryBoys &d3);

int Groceryque::rear = -1;

int Groceryque::front = -1;

int Customer ::myFeedBack = 0;

int Customer ::count_cust = 0;







int main()

{

    cout << "\n\n";

    design::display();

    cout << " Welcome to GROCERYQUE ";

    design::display();

    cout << "\n\n";

    int i = -1, n, j, quantity;

    int count_cust = 0;

    int post_fb;

    char y;



    Groceryque g;

    DeliveryBoys d1("Tom", "+91 2468101214", "Emp01", -1);

    DeliveryBoys d2("Alex", "+91 3691215182", "Emp02", -1);

    DeliveryBoys d3("Robert", "+91 4812202428", "Emp03", -1);

    Customer c[9];



    do

    {

        ++i;

        cout << "PLEASE ENTER YOUR ORDER \n\n";

        //input by the user about his/her details and the products he/she wants to buy

        c[i].read();

        j = g.enqueue(&c[i]);

        if (j == -1)

        {

            break;

        }

        count_cust = ++c[i]; //counting the number of customers

        g.p->readFile();

        cout << "Enter number of products you want to purchase: ";

        cin >> n;

        c[i].numProd(n);

        for (int j = 0; j < n; j++)

        {

            g.p[j].read();

            cout << "Enter quantity: ";

            cin >> quantity;

            c[i] += g.p[j] * quantity;

        }

        c[i].display(g.p);

        post_fb = c[i].giveFeedBack();

        cout << "\n\nThe order will be delivered by tomorrow 9 AM\n\n";

        cout << "Any more customers ?? (y/n) : ";

        cin >> y;

        cout << "\n\n";



    } while (y == 'y');



    allocateJob(g, d1, d2, d3);



    design::display('+');

    cout << " JOB DISTRIBUTION ";

    design::display('+');

    cout << "\n\n";



    (d1).display();

    (d2).display();

    (d3).display();



    (d1).deliverProducts(d2, d3);



    design::display('+');

    cout << " REVIEWS ";

    design::display('+');

    cout << "\n\n";

    cout << post_fb << " out of " << count_cust << " customers have given positive feedback !\n\n";

    design::display();

    cout << " All orders delivered !! ";

    design::display();

    cout << "\n\n";

    return 0;

}
