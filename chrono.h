
#include "../std_lib_facilities.h"

namespace Chrono{

enum class Month {   // Enumeration to easily convert from number to month
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};

class Date {
    public:
    Month getMonth() const { return m; };
    int getDay() const { return d; };
    int getYear() const { return y; };
    void addDays(int n);
    void addMonths(int n);
    Date ();
    Date (int, Month, int);
    class Invalid{};

    private:
    int y, d;
    Month m;
    bool isValid();
};
}    // Chrono