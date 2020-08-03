/*
 * ===================================================================
 *
 *       Filename:  database.h
 *
 *    Description:  Declaring MySQL class for using database.
 *
 *        Created:  Friday 22 February 2013 12:48:40  IST
 *       Compiler:  gcc
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

 /**-------------------------------------------------------------------
  *  Include database-detail.h and other files
  *------------------------------------------------------------------*/

#include "header.h"
#include "database-detail.h"
#include <vector>

  /**
   * ===================================================================
   *        Class:  MySQL
   *  Description:  MySQL class for database accessability
   * ===================================================================
   */

class MySQL
{
protected:
    /** MySQL connectivity Variables */
    MYSQL* connect;
    MYSQL_RES* res_set;
    MYSQL_ROW row;

    unsigned int i;

public:
    /** MySQL Constructor */
    MySQL();

    /** Function to show tables in database */
    void ShowTables();
    char* stringChar(string a);
    void question1();
    void question2(); 
    void question3();
    void question4();
    void question5();
    void question6();
    void question7();
    void question8();
    void question9();
    void question10();
    void question11();
    void question12();
    void question13();
    void question14();
    void question15();
    void question16();
    void question17();
    void question18();
    void question19();
    void question20();
    void question21();
    void question22();
    void question23();
    void question24();
    void question25();
    void question26();
    /** MySQL Destructor */
    ~MySQL();
};
