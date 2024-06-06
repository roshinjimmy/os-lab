#!/bin/bash

# Function to print numbers from 1 to 100
print_numbers() {
    echo "Printing numbers from 1 to 100:"
    for i in {1..100}
    do
        echo $i
    done
}

# Function to find the factorial of a number
factorial() {
    number=$1
    fact=1
    for (( i=1; i<=number; i++ ))
    do
        fact=$((fact * i))
    done
    echo "Factorial of $number is $fact"
}

# Function to find the sum of digits of a number
sum_of_digits() {
    number=$1
    sum=0
    while [ $number -gt 0 ]
    do
        digit=$((number % 10))
        sum=$((sum + digit))
        number=$((number / 10))
    done
    echo "Sum of digits of $1 is $sum"
}

# Main script
echo "Select an option:"
echo "1. Print numbers from 1 to 100"
echo "2. Find factorial of a number"
echo "3. Find sum of digits of a number"
read -p "Enter your choice (1/2/3): " choice

case $choice in
    1)
        print_numbers
        ;;
    2)
        read -p "Enter a number to find its factorial: " num
        factorial $num
        ;;
    3)
        read -p "Enter a number to find the sum of its digits: " num
        sum_of_digits $num
        ;;
    *)
        echo "Invalid choice"
        ;;
esac
