#include <iostream>
#include <vector>
#include <cmath>


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}


int calculateDateDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
    const int daysInYear = 365;
    int totalDays1 = 0, totalDays2 = 0;

    
    for (int y = 0; y < year1; ++y) {
        totalDays1 += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month1; ++m) {
        totalDays1 += getDaysInMonth(m, year1);
    }
    totalDays1 += day1;

    
    for (int y = 0; y < year2; ++y) {
        totalDays2 += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month2; ++m) {
        totalDays2 += getDaysInMonth(m, year2);
    }
    totalDays2 += day2;

    
    return std::abs(totalDays2 - totalDays1);
}


double calculateAverage(const std::vector<int>& array) {
    if (array.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (int num : array) {
        sum += num;
    }
    return sum / array.size();
}


void countElements(const std::vector<int>& array, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int num : array) {
        if (num > 0) {
            ++positiveCount;
        }
        else if (num < 0) {
            ++negativeCount;
        }
        else {
            ++zeroCount;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int day1 = 1, month1 = 1, year1 = 2000;
    int day2 = 1, month2 = 1, year2 = 2025;
    int dateDifference = calculateDateDifference(day1, month1, year1, day2, month2, year2);
    std::cout << "Разница между датами: " << dateDifference << " дней\n";

    
    std::vector<int> array = { 1, 2, 3, 4, 5 };
    double average = calculateAverage(array);
    std::cout << "Среднее арифметическое массива: " << average << "\n";

    
    std::vector<int> array2 = { 1, -2, 0, 3, -4, 0, 5 };
    int positiveCount, negativeCount, zeroCount;
    countElements(array2, positiveCount, negativeCount, zeroCount);
    std::cout << "Положительных элементов: " << positiveCount << "\n";
    std::cout << "Отрицательных элементов: " << negativeCount << "\n";
    std::cout << "Нулевых элементов: " << zeroCount << "\n";

    return 0;
}
