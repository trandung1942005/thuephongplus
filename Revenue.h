#ifndef REVENUE_H
#define REVENUE_H

#include <vector>
#include <string>

class Revenue {
private:
    std::vector<double> monthlyRevenue; // Stores revenue for each month
public:
    Revenue();
    void addRevenue(double amount, int month); // Adds revenue for a specific month
    void displayRevenue(bool ascending) const; // Displays revenue sorted by ascending or descending order
    double checkRevenueForMonth(int month) const; // Checks revenue for a specific month
};

#endif // REVENUE_H
