#include "../std_lib_facilities.h"
namespace Chrono {


enum class Month {   // Enumeration to easily convert from number to month
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};

// Enumeration facilities does not include auto check for reasonable values
// Build check
Month intToMonth(int i) {
    if (i<int(Month::jan) || i>int(Month::dec)) {error ("Bad Month!");}
    return Month (i);   // Gets the ith month
}

class Date {
    public:
    int getMonth() const { return int(m); };
    int getDay() const { return d; };
    int getYear() const { return y; };
    void addDays(int n);
    Date (int, int, int);
    class Invalid{};

    private:
    int y, d;
    Month m;
    bool isValid();
};

Date::Date (int yy, int mm, int dd)
    : y{yy}, m{intToMonth(mm)}, d{dd} {
    if (!isValid()) throw Invalid{};
}

bool Date::isValid() {
    if (m > Month::dec || m < Month::jan) return false;    // Can compare months directly
    if (d > 31 || d < 1) return false;
    return true;
}

void Date::addDays (int n) {
    d += n;
}

ostream& operator<<(ostream& os, const Date& date) {
    return os << "\n(" << date.getYear() << ", " << date.getMonth() << ", " << date.getDay() << ")\n";
}
};

using Chrono::Date; 

int main () 
try
{
    Date d1 {1998, 12, 4};
    cout << d1;
    Date d2 {1998, 31, 12};
    cout << d2;
    Date d3 {1998, 3, 50};
    cout << d3;
}
catch(Date::Invalid)     // Can catch with just specifying type
{
    error("Invalid date found!");
}
