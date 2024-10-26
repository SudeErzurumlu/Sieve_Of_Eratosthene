/*
File: sieve_cpp/sieve_of_eratosthenes.cpp
Description: Modular C++ implementation of the Sieve of Eratosthenes to find primes up to a given limit.
*/

#include <iostream>  // for input-output operations
#include <vector>    // for using vector container

std::vector<bool> initialize_sieve(int limit) {
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    return is_prime;
}

void mark_non_primes(std::vector<bool>& is_prime, int limit) {
    for (int num = 2; num * num <= limit; ++num) {
        if (is_prime[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                is_prime[multiple] = false;
            }
        }
    }
}

std::vector<int> extract_primes(const std::vector<bool>& is_prime) {
    std::vector<int> primes;
    for (int i = 2; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

std::vector<int> sieve_of_eratosthenes(int limit) {
    std::vector<bool> is_prime = initialize_sieve(limit);
    mark_non_primes(is_prime, limit);
    return extract_primes(is_prime);
}

int main() {
    int limit = 100;
    std::vector<int> primes = sieve_of_eratosthenes(limit);
    
    std::cout << "Prime numbers up to " << limit << ": ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
