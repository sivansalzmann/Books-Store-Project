/*
 * ===================================================================
 *
 *       Filename:  database.cc
 *
 *    Description:  Definition of MySQL Class for accessing database
 *
 *        Created:  Friday 22 February 2013 02:07:49  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

/**-------------------------------------------------------------------
 *  Include mysql.h file local header file(declaration of class)
 *------------------------------------------------------------------*/

#include "database.h"
#include <vector>
#include <string>
#include<stdio.h> 



/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: MySQL()
 * Description:  Constructor to initialize database conectivity
 *--------------------------------------------------------------------
 */

MySQL :: MySQL()
{
    connect = mysql_init(NULL);
    if ( !connect )
    {
        cout << "MySQL Initialization Failed";
    }   

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);
    
    if ( connect )
    {
        cout << "Connection Succeeded\n";
    }
    
    else
    {
        cout << "Connection Failed\n";
    }
}

/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: ShowTables()
 * Description:  Show tables in database
 *--------------------------------------------------------------------
 */

 // CPP program to convert string 
 // to char array 




void MySQL :: ShowTables()
{
    /** Add MySQL Query */
    mysql_query (connect,"show tables");                              
                                                                          
    i = 0;
                                                                         
    res_set = mysql_store_result(connect);                              
                                                                          
    unsigned int numrows = mysql_num_rows(res_set);                   
                                                                          
    cout << " Tables in " << DATABASE << " database " << endl;        
                                                                         
    while (((row=mysql_fetch_row(res_set)) != NULL))
    {                                                                 
        cout << row[i] << endl;                                       
    }

}



/**
 *--------------------------------------------------------------------
 *       Class:  MySQL
 *      Method:  MySQL :: ~MySQL()
 * Description:  Destructor of MySQL class for closing mysql
 *               connection
 *--------------------------------------------------------------------
 */

MySQL :: ~MySQL()
{
    mysql_close (connect);
}


char* MySQL::stringChar(string a)
{
    int n = a.length();

    char* char_array = new char [n + 1];

    strcpy(char_array, a.c_str());

    return char_array;
}


void MySQL::question1()
{
    string first = "SELECT DISTINCT supply_location from book inner join supply on book.supply_id = supply.supply_id and book_title ='";
    string last = "' where supply.supply_location = 'store' or supply.supply_location; ";
    char input[250];
    cout << "Which book do you want to search in the supply" << endl;
    cin.ignore();
    cin.getline(input, 250);
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The book " << input <<" is at " << row[0] << endl;
    }
    else
    {
        cout << endl << "This book: " << input << " is not exist in the store supply" << endl ;
    }

    system("pause");
}

void MySQL::question2()
{
    string first = "select person_first_name,person_last_name,min(customer_join_date) from customer inner join person on person.person_id = customer.person_id; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The oldest customer is " << row[0] << " "<< row[1] << " he joined in " << row[2] << endl;
    }

    system("pause");
}

void MySQL::question3()
{
    string first = "select book_title,book_author,min(supply_date) from supply inner join book on supply.supply_id = book.supply_id where supply_location = 'store' or supply_location = 'storage'; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The oldest oldest book is " << row[0] <<" the book author is " << row[1] << endl;
    }

    system("pause");
}

void MySQL::question4()
{
    string first = "select book.book_title,book.book_author,person_first_name,person_last_name,order_date from _order inner join book on _order.book_id = book.book_id inner join customer on customer.customer_id = _order.customer_id inner join person on person.person_id = customer.person_id order by order_date; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "book title\t " << " book author\t " << "person first name\t " << "person last name\t " << "order date\t " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << "\t" << row[4] << endl;
    }

    system("pause");
}

void MySQL::question5()
{
    string first = "select book_title,book_author,count(book.book_title) from book inner join buy_book_store on book.book_id = buy_book_store.book_id and book.book_title = '";
    char input[250];
    string last = "';";
    cout << "Enter a book name to check how many copies sold:" << endl;
    cin.ignore();
    cin.getline(input, 250);
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The book " << input << " is sold " << row[2] << " times " << endl;
    }
    else
    {
        cout << endl << "This book: "<< input << " is not exist in the store supply" << endl;
    }

    system("pause");
}

void MySQL::question6()
{
    string first = "SELECT  book.book_author, max(supply.supply_sold) FROM    book INNER JOIN _order ON book.book_id = _order.order_id INNER JOIN supply ON book.supply_id = supply.supply_id WHERE   supply.supply_date BETWEEN '";
    string input;
    string input2;
    string sec = "' AND '";
    string last = "';";
    cout << "Most comment author between Enter start date: YYYY-MM-DD" << endl;
    cin >> input;
    cout << "Enter end date:" << endl;
    cin >> input2;
    first = first + input + sec + input2 + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The book author is " << row[0] << endl << "between " << input << " and " << input2 << endl << "have the highest number of readings that is " << row[1] << endl;
    }
    else
    {
        cout << endl << "You typed the wrong dates:" << input << " and " <<input2 << endl;
    }

    system("pause");
}

void MySQL::question7()
{
    string first = "select person.person_first_name,person.person_last_name,sum(transactions.transactions_book_sold)   from transactions inner join customer on transactions.customer_id = customer.customer_id inner join person on person.person_id = customer.person_id group by transactions.customer_id order by sum(transactions.transactions_book_sold) desc limit 3; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "person first name\t" << "person last name\t" << "number of books\t" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << "\t" << row[2] << endl;
    }

    system("pause");
}

void MySQL::question8()
{
    string first = "SELECT		book.book_title,publisher.publisher_translator_name , count(publisher.publisher_translator_name)  FROM 		book INNER JOIN	supply ON supply.supply_id = book.supply_id and supply.supply_location = 'store' or supply.supply_location = 'storge' INNER JOIN publisher ON publisher.book_id = publisher.publisher_id GROUP BY		publisher.publisher_translator_name ORDER BY count(publisher.publisher_translator_name) desc limit 1; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The book with the biggest num of translations is: " << row[0] << endl <<"the translator name is: " << row[1] << endl <<"the number of translations is: " << row[2] << endl;
    }


    system("pause");
}

void MySQL::question9()
{
    string first = "select book.book_title,date(transaction_date),store.store_book_price_sell from transactions inner join customer on customer.customer_id = transactions.customer_id inner join person on person.person_id = customer.person_id inner join delivery on delivery.transactions_id = transactions.transactions_id inner join buy_book_store on buy_book_store.transactions_id = transactions.transactions_id inner join book on book.book_id = buy_book_store.book_id or book.book_id = delivery.book_id inner join store on store.buy_book_store_id = buy_book_store.buy_book_store_id or store.delivery_id = delivery.delivery_id where person.person_first_name = '";
    string sec = "' and person.person_last_name = '";
    string input;
    string input2;
    string last = "' group by book_title order by transactions.transaction_date;";
    cout << " Customer Purchase history. Please enter first name: " << endl;
    cin >> input;
    cout << "Please enter last name: " << endl;
    cin >> input2;
    first = first + input + sec + input2 + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "book title\t " << "transaction date\t " << " book price\t" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << "\t" << row[2] << endl;
    }
    else
    {
        cout << endl << "This customer: " << input << " " << input2 << " is not exist in the store data base" << endl;
    }
    system("pause");
}


void MySQL::question10()
{
    string first = "select person.person_first_name,person.person_last_name,book.book_title, order_date,supply.supply_location, transactions.transactions_id from _order INNER JOIN customer ON customer.customer_id = _order.customer_id inner join person on person.person_id = customer.person_id INNER JOIN book ON book.book_id = _order.book_id INNER JOIN supply ON supply.supply_id = book.supply_id INNER JOIN buy_book_store ON buy_book_store.book_id = book.book_id INNER JOIN delivery ON delivery.book_id = book.book_id INNER JOIN transactions on customer.customer_id = transactions.customer_id where customer.customer_id = '";
    string input;
    string last = "' and supply.supply_location = 'store' or supply.supply_location = 'storge' group by order_id order by order_date; ";
    cout << "Enter a customer ID to see purchase by date:" << endl;
    cin >> input;
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "customer name: " << row[0] << " " << row[1] << endl <<"book title is: " << row[2] << endl << "the order date is: " << row[3] << endl << "supply location:" << row[4] << endl << "is he buy the book?"<< row[5] << endl;
    }
    else
    {
        cout << endl << "The customer with ID " << input << " is not exist" << endl;
    }

    system("pause");
}

void split(vector<string>& strings, char str[])
{
    char* word = strtok(str, "-,\n");

    for (int i = 0; word != NULL; i++)
    {
        strings.push_back(word);
        word = strtok(NULL, "-,\n");
    }
}

void splitStrSpace(vector<string>& strings, char str[])
{
    char* word = strtok(str, " \n");

    for (int i = 0; word != NULL; i++)
    {
        strings.push_back(word);
        word = strtok(NULL, " \n");
    }
}




void MySQL::question11()
{
    fflush(stdin);
    const int Isrel_post_courier_service = 10;
    const int Isrel_post_registered_mail = 15;
    const int Isrel_post_fast_courier_service = 20;
    const int Xpress_collecting_point = 8;
    const int xpress_home_delivery = 30;

    string first = "select distinct delivery_tracking_number,book.book_author, book_details.book_details_book_weight from delivery inner join book on book.book_id = delivery.book_id inner join book_details on book.book_details_id = book_details.book_details_id where book_title = '";
    string sec = "' or book_title = '";
    string last = "' group by delivery_id; ";

    char str[200] = { 0 };
    vector <string> strings;

    std::cout << "Choose book title for delivery" << endl;
    std::cout << "enter books titles with ',' between :  " << endl;
    fgets(str, 150, stdin);
    split(strings, str);

    int input = 0;
    bool run = true;

    while (run)
    {
        std::cout << "What delivery options would you like?" << endl;
        std::cout << "1: Isrel post courier service" << endl;
        std::cout << "2: Isrel post registered mail" << endl;
        std::cout << "3: Isrel post fast courier service" << endl;
        std::cout << "4: Xpress collecting point" << endl;
        std::cout << "5: Xpress home delivery" << endl;
        std::cout << "please enter the number of option you wish to use:" << endl;
        cin >> input;

        if (input >= 1 && input <= 5)
            run = false;
    }


    string tmp = strings[0];

    for (int i = 1; i < strings.size(); i++)
        tmp += (sec + strings[i]);
    first += tmp + last;


    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);

    string weight;
    string::size_type size;
    float s_weight = 0;

    if (res_set != nullptr && res_set->row_count != 0)
    {
        while (((row = mysql_fetch_row(res_set)) != NULL)) {
            weight = row[2];
            s_weight += std::stof(weight, &size);
            weight.clear();
        }

    }


    switch (input)
    {
    case 1:
        s_weight *= Isrel_post_courier_service;
        break;

    case 2:
        s_weight *= Isrel_post_registered_mail;
        break;

    case 3:
        s_weight *= Isrel_post_fast_courier_service;
        break;

    case 4:
        s_weight *= Xpress_collecting_point;
        break;

    case 5:
        s_weight *= xpress_home_delivery;
        break;
    };

    cout << "the total price is: " << s_weight << endl;

    system("pause"); system("cls");;

}

void MySQL::question12()
{
    string first = "select person.person_first_name,person.person_last_name ,date(transaction_date), transactions_price, transactions_book_sold, count(delivery.delivery_id) from transactions inner join customer on customer.customer_id = transactions.customer_id inner join person on person.person_id = customer.person_id inner join delivery on delivery.transactions_id = transactions.transactions_id where  customer.customer_id =";
    string last = " group by transactions.transactions_id having count(delivery.delivery_id) > 1; ";
    string input;
    cout << "check if customer split his delivery. please enter ID:" << endl;
    cin >> input;
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "customer name: " << row[0] << " " << row[1] << endl << "the order date is: " << row[2] << endl << "transactions price: " << row[3] << endl << "transactions book sold:" << row[4] << endl << "how much deliveries?" << row[5] << endl;
    }
    else
    {
        cout << endl << "The customer with ID " << input << " is not exist" << endl;
    }


    system("pause");
}

void MySQL::question13()
{
    string first = "select delivery_status from delivery where delivery_tracking_number = '";
    string input;
    string last = "'; ";
    cout << "Enter a tracking number to see delivery status:" << endl;
    cin >> input;
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "delivery tracking number: " << input << endl;
        cout << "delivery status: " << row[1];
    }
    else
    {
        cout << endl << "The delivery with delivery number " << input << " is not exist" << endl;
    }


    system("pause");
}

void MySQL::question14()
{
    string first = "select month(transaction_date),transactions_book_sold,sum(transactions_price) from transactions inner join delivery on delivery.transactions_id = transactions.transactions_id inner join post_type on delivery.post_type_id = post_type.post_type_id where post_type_company = 'Xpress' and month(transaction_date) =";
    string last = ";";
    string input;
    cout << "Summery of Xpress shipping by month, please enter a month number: mm" << endl;
    cin >> input;
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The month is: " << row[0] << endl << "transactions book sold:" << row[1] << endl << "sum of transactions: " << row[2] << endl;
    }
    else
    {
        cout << endl << "Data per month " << input << " is not exist" << endl;
    }


    system("pause");
}

void MySQL::question15()
{
    string first = "select month(transaction_date), sum(transactions_price) from transactions  WHERE transactions_payment_method = 'Bit' and month(transaction_date) = ";
    string last = ";";
    string input;
    cout << "Summery of money transfer by Bit for a month, please enter month number: mm" << endl;
    cin >> input;
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The month is: " << row[0] << endl << "sum of transactions: " << row[1] << endl;
    }
    else
    {
        cout << endl << "In month " << input << " there were no transactions made using the Beat app" << endl;
    }

    system("pause");
}

void MySQL::question16()
{
    string first = "select transactions.transactions_id,transactions.transactions_book_sold,transactions.transaction_date, sum(store_book_price_sell - store_book_price_buy) as sum_transactions from store INNER JOIN buy_book_store ON buy_book_store.buy_book_store_id = store.buy_book_store_id INNER JOIN delivery ON delivery.delivery_id = store.delivery_id INNER JOIN transactions ON delivery.transactions_id = transactions.transactions_id or buy_book_store.transactions_id = transactions.transactions_id group by store_id having transaction_date >= date_sub(now(), interval 12 month) and sum_transactions > (select avg(store_book_price_sell - store_book_price_buy) as avg_store from store)";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "transaction id\t " << "transaction book sold\t " << " transaction date\t" << " sum of transactions\t" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << endl;
    }


    system("pause");
}

void MySQL::question17()
{
    string first = "select post_type_company,count(post_type_company) FROM post_type INNER JOIN	delivery ON post_type.post_type_id = delivery.post_type_id INNER JOIN transactions ON  transactions.transactions_id = delivery.transactions_id where transaction_date >= date_sub(now(), interval 12 month) group by post_type_company;";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "post type company\t " << "count deliveries\t " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << endl;
    }

    system("pause");
}

void MySQL::question18()
{
    string first = "select count(publisher_name),delivery_id,book_title,publisher_name from delivery INNER JOIN	book ON delivery.book_id = book.book_id INNER JOIN	publisher ON book.book_id = publisher.book_id group by book_title having count(publisher_name) > 1; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "number of addutions\t " << "delivery id\t " << "book title\t "<< "publisher name\t " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << endl;
    }

    system("pause");
}

void MySQL::question19()
{
    string first = "select person_first_name,person_last_name from transactions inner join customer on transactions.customer_id = customer.customer_id inner join person on customer.person_id = person.person_id where transaction_date < '2018-07-30' group by person.person_id; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "customer name\t " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << endl;
    }

    system("pause");
}

void MySQL::question20()
{
    string first = "select person.person_first_name,person.person_last_name, DATEDIFF(order_date_arrive, transactions.transaction_date) from _order inner join customer on _order.customer_id = customer.customer_id inner join person on person.person_id = customer.person_id inner join transactions on transactions.transactions_id = _order.transactions_id where DATEDIFF(order_date_arrive, transactions.transaction_date) > 14; ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "customer name\t " << "Number of days between order and purchase\t" << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << " " << row[1] << "\t" << row[2] << endl;
    }
}

void MySQL::question21()
{
    string first = "SELECT supply_location,YEAR(supply_date),MONTH(supply_date),sum(supply_quantity) FROM supply where supply_location = 'storage' GROUP BY YEAR(supply_date), MONTH(supply_date) ORDER BY YEAR(supply_date); ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "supply location\t " << "year\t " << "book title\t " << "month\t " << "sum of supply quantity\t " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << "\t" << row[4] << endl;
    }

    system("pause");
}

void MySQL::question22()
{
    string first = "select book_in_store_date between '";
    string sec = "' and '";
    string thr = "', count(book.book_id), sum(store.store_book_price_buy) from book_in_store inner join store on store.store_id = book_in_store.store_id inner join book on book.book_id = book_in_store.book_id where book_in_store_date between '";
    string fo = "' and '";
    string last = "';";
    string input;
    string input2;
    cout << " Store book purchase between dates. Please enter first date:yyyy-mm-dd " << endl;
    cin >> input;
    cout << "Please enter second date: " << endl;
    cin >> input2;
    first = first + input + sec + input2 + thr + input + fo + input2 + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "The number of books the store purchased: " << row[1] << endl << "The amount the store paid for the books: " << row[2] << endl;
    }
    else
    {
        cout << endl << "The start date or the date date you enterd: " << input << " " << input2 << " are Invalid" << endl;
    }

    system("pause");
}

void MySQL::question23()
{
    string first = "select sum_pay_month,sum_sell_month,sum_sell_month-sum_pay_month as profit from(select sum(store_payment_electric_bill) + sum(store_payment_water_bill) + sum(store_payment_rent) + sum(store_payment_tax)+ sum(store_payment_other) + sum(store_payment_home_number) + sum(store_payment_phone_number) AS sum_pay_month,sum(store_book_price_sell) - sum(store_book_price_buy) + sum(transactions_price) AS sum_sell_month from store_payment inner join store on store_payment.store_id = store.store_id inner join buy_book_store on buy_book_store.buy_book_store_id = store.buy_book_store_id inner join delivery on delivery.delivery_id = store.delivery_id inner join transactions on transactions.transactions_id = delivery.transactions_id or buy_book_store.transactions_id = transactions.transactions_id where store_payment_month = ";
    string sec = " and store_payment_year = ";
    string last = ") as a;";
    string input;
    string input2;
    cout << "Choose a month to see store profit: mm" << endl;
    cin >> input;
    cout << "Choose a year to see store profit: yyyy" << endl;
    cin >> input2;
    first = first + input + sec + input2 + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "store payment per month: " << row[0] << endl << "store profits per month: " << row[1] << endl << "net store profits per month: " << row[2] << endl;
    }
    else
    {
        cout << endl << "The start month or the year date you enterd: " << input << " " << input2 << " are Invalid " << endl;
    }
}

void MySQL::question24()
{
    string first = "SELECT YEAR(transaction_date),MONTH(transaction_date), AVG(transactions_price) FROM transactions GROUP BY YEAR(transaction_date), MONTH(transaction_date) ORDER BY YEAR(transaction_date); ";
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        cout << "year\t " << "month\t " << "avg\t " << endl;
        while (((row = mysql_fetch_row(res_set)) != NULL))
            cout << "\t" << row[0] << "\t" << row[1] << "\t" << row[2] << endl;
    }

    system("pause");
}

void MySQL::question25()
{
    string first = "select person_first_name, person_last_name, sum(employee_working_hours)*30 from person inner join employee on person.person_id = employee.person_id where person.person_first_name = '";
    string sec = "' and person.person_last_name = '";
    string last = "';";
    string input;
    string input2;
    cout << "Enter an employee to see month paycheck,first name: " << endl;
    cin >> input;
    cout << "last name: " << endl;
    cin >> input2;
    first = first + input + sec + input2 + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "Employee name: " << row[0] << " " << row[1] << endl << "The employee's salary per month "<< row[2] << endl;
    }
    else
    {
        cout << endl << "The employee you enterd is not exist: " << input << " " << input2 << endl;
    }
}


void MySQL::question26()
{
    string first = "select person_first_name,person_last_name,count(transactions_id) from person INNER JOIN	employee ON person.person_id = employee.person_id INNER JOIN	transactions ON employee.employee_id = transactions.employee_id where month(transaction_date) =";
    string last = " having  max(transactions_id); ";
    string input;
    cout << "Employee with the most transactions per month, please enter month number: mm " << endl;
    cin >> input;
    first = first + input + last;
    char* all = stringChar(first);
    mysql_query(connect, all);
    delete all;

    res_set = mysql_store_result(connect);
    cout << endl;
    if (res_set != nullptr && res_set->row_count != 0) {
        row = mysql_fetch_row(res_set);
        cout << "Employee name: " << row[0] << " " << row[1] << endl << "The amount of transactions: " << row[2] << endl;
    }
    else
    {
        cout << endl << "The employee you enterd is not exist: " << input << endl;
    }

    system("pause");
}