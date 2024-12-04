//
// Created by lvpra on 11/18/24.
//

#include <iostream>
#include <cmath>
#include <random>



double simulatePrice(double S0, double T, double r, double sigma, double random)
{
    return S0 * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * random);

}


int main() {
    double S0;
    std::cout << "Input S0: " << std::endl;
    std::cin >> S0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int num_simulations = 100000;
    double sum_payoff = 0.0;

    std::mt19937_64 generator(40);
    std::normal_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < num_simulations; ++i)
    {
        double random = distribution(generator);
        double ST = simulatePrice(S0, T, r, sigma, random);
        double payoff = std::max(ST - K, 0.0);
        sum_payoff += payoff;
    }

    double option_price = exp(-r * T) * (sum_payoff / num_simulations);
    std::cout << "Option Price: " << option_price << std::endl;

    return option_price;
};



