#include <iostream>
#include <map>
#include <string>

std::multimap<std::string, double>::const_iterator find_closest_date(const std::string& date, const std::multimap<std::string, double>& btcData)
{
    // Find the first date in the multimap that is not less than the given date
    std::multimap<std::string, double>::const_iterator lower = btcData.lower_bound(date);

    if (lower != btcData.end() && lower->first == date) {
        // Exact match found
        std::cout << "Exact date found: " << lower->first << " | " << lower->second << std::endl;
    } 
    else if (lower != btcData.begin()) {
        
        --lower;
        std::cout << "Closest next date: " << lower->first << " | " << lower->second << std::endl;
    } 
    else {
        // If we reach the end, it means the date is after all the entries in the map
        std::cout << "No match found; reached the end of the data." << std::endl;
    }
    return lower;
}

int main()
{
    std::multimap<std::string, double> btcData;
    // Populate the multimap with sample data
    btcData.insert(std::make_pair("2011-01-01", 1.2));
    btcData.insert(std::make_pair("2011-01-04", 1.0));
    btcData.insert(std::make_pair("2012-01-11", 7.1));
    btcData.insert(std::make_pair("2011-01-07", 3.0));
    btcData.insert(std::make_pair("2011-01-10", 3.0));

    // Example: finding closest date to input
    std::string inputDate = "2012-01-11";
    std::multimap<std::string, double>::const_iterator lower = find_closest_date(inputDate, btcData);
    std::cout << lower->second << std::endl;

    return 0;
}



/*

2

4-----------

5
*/