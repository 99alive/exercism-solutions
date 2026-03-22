#include <cmath>

// Task 1: daily_rate calculates the daily rate (8 hours/day)
double daily_rate(double hourly_rate) {
    return hourly_rate * 8.0;
}

// Task 2: apply_discount calculates the price after a percentage discount
double apply_discount(double before_discount, double discount) {
    // Discount is a percentage (e.g., 25.0 for 25%)
    double factor = 1.0 - (discount / 100.0);
    return before_discount * factor;
}

// Task 3: monthly_rate calculates the discounted monthly rate (22 days/month)
// The result is rounded up (ceiling).
int monthly_rate(double hourly_rate, double discount) {
    double daily = daily_rate(hourly_rate);
    double monthly_full_price = daily * 22.0;
    double discounted_price = apply_discount(monthly_full_price, discount);
    
    // std::ceil returns a double, so we cast to int
    return static_cast<int>(std::ceil(discounted_price));
}

// Task 4: days_in_budget calculates how many complete days a budget covers
// The result is rounded down (floor).
int days_in_budget(int budget, double hourly_rate, double discount) {
    double daily = daily_rate(hourly_rate);
    double discounted_daily = apply_discount(daily, discount);
    
    // Divide budget by the cost of one discounted day
    double total_days = budget / discounted_daily;
    return static_cast<int>(std::floor(total_days));
}