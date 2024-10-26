"""
File: sieve/sieve_of_eratosthenes.py
Description: Modular Sieve of Eratosthenes implementation to find all primes up to a given limit.
"""

from typing import List

def initialize_sieve(limit: int) -> List[bool]:
    """Initialize a boolean array for prime checking."""
    is_prime = [True] * (limit + 1)
    is_prime[0], is_prime[1] = False, False
    return is_prime

def mark_non_primes(is_prime: List[bool], limit: int) -> None:
    """Mark non-prime numbers in the array."""
    for num in range(2, int(limit**0.5) + 1):
        if is_prime[num]:
            for multiple in range(num * num, limit + 1, num):
                is_prime[multiple] = False

def extract_primes(is_prime: List[bool]) -> List[int]:
    """Extract prime numbers from the boolean array."""
    return [num for num, prime in enumerate(is_prime) if prime]

def sieve_of_eratosthenes(limit: int) -> List[int]:
    """Return a list of all prime numbers up to the specified limit."""
    is_prime = initialize_sieve(limit)
    mark_non_primes(is_prime, limit)
    return extract_primes(is_prime)

if __name__ == "__main__":
    limit = 100
    print(f"Prime numbers up to {limit}: {sieve_of_eratosthenes(limit)}")
