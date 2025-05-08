#include "Revenue.h"
#include <iostream>
#include <algorithm>

Revenue::Revenue() : monthlyRevenue(12, 0.0) {} // Initialize with 12 months

void Revenue::addRevenue(double amount, int month) {
    if (month >= 1 && month <= 12) {
        monthlyRevenue[month - 1] += amount;
    }
    else {
        std::cerr << "Invalid month!" << std::endl;
    }
}

void Revenue::displayRevenue(bool ascending) const {
    std::vector<double> sortedRevenue = monthlyRevenue;
    if (ascending) {
        std::sort(sortedRevenue.begin(), sortedRevenue.end());
    }
    else {
        std::sort(sortedRevenue.rbegin(), sortedRevenue.rend());
    }
    for (size_t i = 0; i < sortedRevenue.size(); ++i) {
        std::cout << "Month " << (i + 1) << ": $" << sortedRevenue[i] << std::endl;
    }
}

double Revenue::checkRevenueForMonth(int month) const {
    if (month >= 1 && month <= 12) {
        return monthlyRevenue[month - 1];
    }
    else {
        std::cerr << "Invalid month!" << std::endl;
        return 0.0;
    }
}
