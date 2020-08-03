/*
 * ===================================================================
 *
 *       Filename:  database-main.cpp
 *
 *    Description:  Main Method
 *
 *        Created:  Thursday 28 February 2013 10:53:59  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

 /**-------------------------------------------------------------------
  *  \mainpage MySQL Connectivity with C++
  *
  *  This is a working code example of using C++ to interface with MySQL.
  *  Steps:
  *
  *  \li Download this code \n
  *      $ git clone https://github.com/megha55/mysql-with-cpp.git
  *
  *  \li For installing MySQL Connector for C++ \n
  *      $ make install
  *
  *  \li Change database details in database-detail.h file.
  *
  *  \li To run example \n
  *      $ make
  *
  *------------------------------------------------------------------*/

  /**-------------------------------------------------------------------
   *  Include required header files
   *------------------------------------------------------------------*/

#include "database.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    MySQL Mysql;
    int input = 0;
    std::cout << "*******************************************\n";
    std::cout << "* Welcome to the Book Store!              *\n";
    std::cout << "* press 1 if you our book store manager   *\n";
    std::cout << "* press 2 if you our book store employee  *\n";
    std::cout << "*******************************************\n";
    std::cin >> input;

    if (input == 1) {
        while (input != 99) {
            std::cin.clear();
            std::cout << "\n***********************************************************************************************************\n"
                << "* Please choose one of the following:                                                                     *\n"
                << "* 1) Show the oldest customer                                                                             *\n"
                << "* 2) Show all orders                                                                                      *\n"
                << "* 3) List of the 3 customers who have purchased the most books ever                                       *\n"
                << "* 4) Customer order history                                                                               *\n"
                << "* 5) Shipping cost calculation                                                                            *\n"
                << "* 6) Has a customer ever split a book purchase for multiple shipments?                                    *\n"
                << "* 7) What is the amount of shipments made by Xpress in a particular month                                 *\n"
                << "* 8) The total money transferred to the store account via the Bit app per month                           *\n"
                << "* 9) Transactions made during the last year with a larger profit than the average transaction profit     *\n"
                << "* 10) Several shipments have been made during the last 12 months through each company                     *\n"
                << "* 11) View shipments that included 2 different editions of the same book                                  *\n"
                << "* 12) View customers who have not made a purchase in the last two years                                   *\n"
                << "* 13) How many books did the store purchase between dates and how much did it pay for them                *\n"
                << "* 14) The store profits from sales in a particular month                                                  *\n"
                << "* 15) Average monthly transactions                                                                        *\n"
                << "* 16) The gross salary of an employee in a particular month                                               *\n"
                << "* 99) End the program                                                                                     *\n"
                << "***********************************************************************************************************\n"
                << "Your Choice is: ";

            std::cin >> input;
            cin.ignore(INT_MAX, '\n');
            switch (input) {

            case 1:
                Mysql.question2();
                break;
            case 2:
                Mysql.question4();
                break;
            case 3:
                Mysql.question7();
                break;
            case 4:
                Mysql.question9();
                break;
            case 5:
                Mysql.question11();
                break;
            case 6:
                Mysql.question12();
                break;
            case 7:
                Mysql.question14();
                break;
            case 8:
                Mysql.question15();
                break;
            case 9:
                Mysql.question16();
                break;
            case 10:
                Mysql.question17();
                break;
            case 11:
                Mysql.question18();
                break;
            case 12:
                Mysql.question19();
                break;
            case 13:
                Mysql.question22();
                break;
            case 14:
                Mysql.question23();
                break;
            case 15:
                Mysql.question24();
                break;
            case 16:
                Mysql.question25();
                break;
            case 99:
                continue;
            default:
                std::cout << " You enterd a wrong input!" << endl;
                input = 27;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }

            input = 0;
            while (input != 1) {
                std::cout << "Press 1 to Return To the Main Menu.\n " << endl;
                std::cin >> input;
                std::cin.clear();
            }
        }
    }
    if (input == 2) {
        while (input != 99) {
            std::cout << "\n***********************************************************************************************************\n"
                << "* Please choose one of the following:                                                                     *\n"
                << "* 1) Check if book In Stock                                                                               *\n"
                << "* 2) Show the oldest book in the supply                                                                   *\n"
                << "* 3) How many copies of book X sold by the store                                                                       *\n"
                << "* 4) Who is the most read writer between the dates X and Y                                                *\n"
                << "* 5) Who is the author with the largest number of translations currently in stock                         *\n"
                << "* 6) What is the status of a particular shipment                                                          *\n"
                << "* 7) Customers who placed orders and did not pick up in the last 14 days                                  *\n"
                << "* 8) Number of books in the warehouse on a monthly basis                                                  *\n"
                << "* 9) Orders history by customer name                                                                      *\n"
                << "* 99) End the program                                                                                     *\n"
                << "***********************************************************************************************************\n"
                << "Your Choice is: ";

            std::cin >> input;
            switch (input) {
            case 1:
                Mysql.question1();
                break;
            case 2:
                Mysql.question3();
                break;
            case 3:
                Mysql.question5();
                break;
            case 4:
                Mysql.question6();
                break;
            case 5:
                Mysql.question8();
                break;
            case 6:
                Mysql.question13();
                break;
            case 7:
                Mysql.question20();
                break;
            case 8:
                Mysql.question21();
                break;
            case 9:
                Mysql.question10();
                break;
            case 99:
                continue;
            default:
                std::cout << " You enterd a wrong input!" << endl;
                input = 27;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }

            input = 0;
            while (input != 1) {
                std::cout << "Press 1 to Return To the Main Menu.\n " << endl;
                std::cin >> input;
                std::cin.clear();
            }
        }
    }


    std::cout << "Hope you enjoy!!\nGoodbye!" << endl;

    return 0;
}