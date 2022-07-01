#include "../std_lib_facilities.h"
#include "chrono.h"

namespace Chrono {

// Enumeration facilities does not include auto check for reasonable values
// Build check
Month intToMonth(int i) {
    if (i<int(Month::jan) || i>int(Month::dec)) {error ("Bad Month!");}
    return Month (i);   // Gets the ith month
}

Month operator++ (Month& m) {
    m = (m==Month::dec) ? Month::jan : intToMonth(int(m)+1);
    return m;
}

ostream& operator<< (ostream& os, Month m) {
    vector<string> monthTable = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return os << monthTable[int(m) - int(Month::jan)];
}


// Date Constructor
Date::Date (int yy, Month mm, int dd)
    : y{yy}, m{mm}, d{dd} {
    if (!isValid()) throw Invalid{};
}

// Default constructor
const Date& defaultDate () {
    static Date d  = {2000, Month::jan, 1};
    return d;
}
Date::Date () {
    Date dd = defaultDate();
    y = dd.getYear();
    m = dd.getMonth();
    d = dd.getDay();
}

// Check elements of date are valid
bool Date::isValid() {
    if (y > 2022 || y < 1800) return false;
    // month check already handled by constructor of Month
    if (d > 31 || d < 1) return false;
    return true;
}

// Modify date
void Date::addDays (int n) {
    d += n;
    if (!isValid()) throw Invalid{};       // Any way to check generally, instead of per modifying function?
    return;
}

void Date::addMonths (int n) {
    for (int i=0; i < n; i++) ++m;
    return;
}

// Helper functions
ostream& operator<<(ostream& os, const Date& date) {
    return os << "\n(" << date.getYear() << ", " << date.getMonth() << ", " << date.getDay() << ")\n";
}
bool operator== (const Date& d1, const Date& d2) {
    return d1.getDay()==d2.getDay() && d1.getMonth()==d2.getMonth() && d1.getYear()==d2.getYear();
}
};

using Chrono::Date; 
using Chrono::Month; 

int main () 
try
{
    Date d1 {1998, Month::dec, 4};
    cout << d1;
    // Date d2 {1998, 31, Month::mar};   // Caught by types
    // cout << d2;
    // Date d3 {1998, Month::mar, 50};   // Caught by wrong days
    // cout << d3;
    Date d4 {};
    cout << d4;
    bool flag = d1==d4;
    cout << d1 << " == " << d4 << ": " << flag;
    d4.addDays(10);
    cout << d4;
    d4.addMonths(20);
    cout << d4;

}
catch(Date::Invalid)     // Can catch with just specifying type
{
    error("Invalid date found!");
}
