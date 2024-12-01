


/*Ram Tripathi 22HEL2231 
 * Factorial Calculation Program
 * Resolves unused variable warning by using the 'result'
 */
#define F_CPU 12000000UL
#include <avr/io.h>
#include <util/delay.h>  // For hardware-based delay simulation

// Function to calculate factorial iteratively
unsigned long factorial(unsigned int n) {
    unsigned long result = 1;
    for (unsigned int i = 1; i <= n; i++) {
        result *= i;  // Multiply result by the current number
    }
    return result;
}

int main(void) {
    // Variables
    unsigned int number = 5;  // Change this value to test different inputs
    unsigned long result = 0;

    // Initialize PORTB for LED (hardware-specific use case, optional)
    DDRB = 0xFF;  // Set PORTB as output (for LEDs)

    // Calculate factorial
    result = factorial(number);

    // Use the result meaningfully (example: blink an LED based on result)
    while (1) {
        PORTB = (result & 0xFF);  // Assign the lower 8 bits of result to PORTB
        _delay_ms(500);
        PORTB = 0x00;  // Turn off all LEDs
        _delay_ms(500);
    }

    return 0;
}
