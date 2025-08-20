use std::io;

// Function to check if a number is prime
fn is_prime(n: u64) -> bool {
    if n <= 1 {
        return false;
    }
    if n <= 3 {
        return true;
    }
    if n % 2 == 0 || n % 3 == 0 {
        return false;
    }
    let mut i = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 {
            return false;
        }
        i += 6;
    }
    true
}

// Function to generate all primes up to a given limit using Sieve of Eratosthenes
fn generate_primes(limit: u64) -> Vec<u64> {
    let mut sieve = vec![true; (limit + 1) as usize];
    sieve[0] = false;
    sieve[1] = false;

    let mut p = 2;
    while p * p <= limit {
        if sieve[p as usize] {
            let mut i = p * p;
            while i <= limit {
                sieve[i as usize] = false;
                i += p;
            }
        }
        p += 1;
    }

    sieve.iter()
        .enumerate()
        .filter(|&(_, &is_prime)| is_prime)
        .map(|(i, _)| i as u64)
        .collect()
}

// Function to find the next prime after a given number
fn next_prime(mut n: u64) -> u64 {
    loop {
        n += 1;
        if is_prime(n) {
            return n;
        }
    }
}

// Function to factorize a number into its prime factors
fn prime_factors(mut n: u64) -> Vec<u64> {
    let mut factors = Vec::new();

    // Factor out 2s
    while n % 2 == 0 {
        factors.push(2);
        n /= 2;
    }

    // Factor odd numbers
    let mut i = 3;
    while i * i <= n {
        while n % i == 0 {
            factors.push(i);
            n /= i;
        }
        i += 2;
    }

    if n > 2 {
        factors.push(n);
    }

    factors
}

fn main() {
    println!("Welcome to the Prime Number Utility in Rust!");

    loop {
        println!("\nChoose an option:");
        println!("1. Check if a number is prime");
        println!("2. Generate all primes up to a limit");
        println!("3. Find the next prime after a number");
        println!("4. Factorize a number into prime factors");
        println!("5. Exit");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let choice = input.trim().parse::<u32>().unwrap_or(0);

        match choice {
            1 => {
                println!("Enter a number:");
                input.clear();
                io::stdin().read_line(&mut input).expect("Failed to read input");
                let number = input.trim().parse::<u64>().unwrap_or(0);
                if is_prime(number) {
                    println!("{} is a prime number.", number);
                } else {
                    println!("{} is NOT a prime number.", number);
                }
            }
            2 => {
                println!("Generate primes up to:");
                input.clear();
                io::stdin().read_line(&mut input).expect("Failed to read input");
                let limit = input.trim().parse::<u64>().unwrap_or(0);
                let primes = generate_primes(limit);
                println!("Primes up to {}: {:?}", limit, primes);
            }
            3 => {
                println!("Enter a number:");
                input.clear();
                io::stdin().read_line(&mut input).expect("Failed to read input");
                let number = input.trim().parse::<u64>().unwrap_or(0);
                let next = next_prime(number);
                println!("Next prime after {} is {}", number, next);
            }
            4 => {
                println!("Enter a number to factorize:");
                input.clear();
                io::stdin().read_line(&mut input).expect("Failed to read input");
                let number = input.trim().parse::<u64>().unwrap_or(0);
                let factors = prime_factors(number);
                println!("Prime factors of {}: {:?}", number, factors);
            }
            5 => {
                println!("Exiting program. Goodbye!");
                break;
            }
            _ => println!("Invalid choice. Please try again."),
        }
    }
}
