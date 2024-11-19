#include <iostream>
#include <iomanip>

class InvestmentCalculator {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

public:
    InvestmentCalculator(double initial, double monthly, double interest, int years)
        : initialInvestment(initial), monthlyDeposit(monthly), annualInterest(interest), numberOfYears(years) {}

    void printDetails(int year, double yearEndBalance, double interestEarned) const {
        std::cout << std::setw(2) << year << "\t\t$"
            << std::fixed << std::setprecision(2) << yearEndBalance << "\t\t$"
            << std::fixed << std::setprecision(2) << interestEarned << std::endl;
    }

    void calculateBalanceWithoutMonthlyDeposit() const {
        double balance = initialInvestment;
        double monthlyInterestRate = annualInterest / 100 / 12;

        std::cout << "Balance and Interest Without Additional Monthly Deposits\n";
        std::cout << "==================================================================\n";
        std::cout << "Year\t\tYear End Balance\t\tYear End Earned Interest\n";
        std::cout << "------------------------------------------------------------------\n";

        for (int year = 1; year <= numberOfYears; year++) {
            double startingBalance = balance;
            for (int month = 1; month <= 12; month++) {
                balance += balance * monthlyInterestRate;
            }
            double interestEarned = balance - startingBalance;

            printDetails(year, balance, interestEarned);
        }
    }

    void calculateBalanceWithMonthlyDeposit() const {
        double balance = initialInvestment;
        double monthlyInterestRate = annualInterest / 100 / 12;

        std::cout << "\nBalance and Interest With Additional Monthly Deposits\n";
        std::cout << "==================================================================\n";
        std::cout << "Year\t\tYear End Balance\t\tYear End Earned Interest\n";
        std::cout << "------------------------------------------------------------------\n";

        for (int year = 1; year <= numberOfYears; year++) {
            double startingBalance = balance;
            for (int month = 1; month <= 12; month++) {
                balance *= (1 + monthlyInterestRate);
                balance += monthlyDeposit;
            }
            double interestEarned = balance - startingBalance - (monthlyDeposit * 12);

            printDetails(year, balance, interestEarned);
        }
    }
};

int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int numberOfYears;

    std::cout << "********************************\n";
    std::cout << "********** Data Input **********\n";
    std::cout << "Initial Investment Amount: $";
    std::cin >> initialInvestment;
    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;
    std::cout << "Annual Interest: %";
    std::cin >> annualInterest;
    std::cout << "Number of years: ";
    std::cin >> numberOfYears;

    std::cout << std::endl;

    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);
    calculator.calculateBalanceWithoutMonthlyDeposit();
    calculator.calculateBalanceWithMonthlyDeposit();

    return 0;
}