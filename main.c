#define F_CPU 12000000UL
#include <avr/io.h>
#include <util/delay.h>  // Include for delays

// Function to calculate the GP series
void calculate_gp(unsigned long a, unsigned long r, unsigned int n, unsigned long *result) {
	for (unsigned int i = 0; i < n; i++) {
		result[i] = a;  // Store the current term in the result array
		a *= r;         // Calculate the next term
	}
}

int main(void) {
	// GP parameters
	unsigned long a = 2;      // First term
	unsigned long r = 3;      // Common ratio
	unsigned int n = 5;       // Number of terms
	unsigned long gp[10];     // Array to store GP terms (adjust size if needed)

	// Calculate GP series
	calculate_gp(a, r, n, gp);

	// Initialize PORTB for debugging (LED display)
	DDRB = 0xFF;  // Set PORTB as output

	// Display GP terms on LEDs (8-bit truncated values)
	for (unsigned int i = 0; i < n; i++) {
		PORTB = (gp[i] & 0xFF);  // Send lower 8 bits to PORTB
		_delay_ms(1000);         // Delay to observe each term
	}

	while (1) {
		// Infinite loop to prevent program termination
	}

	return 0;
}
