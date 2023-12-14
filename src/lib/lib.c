#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PANEL_LED_WIDTH     8 /* width of a panel in number of LEDs */
#define PANEL_LED_HEIGHT    8 /* height of a panel in number of LEDs */
#define MATRIX_PANEL_WIDTH  5 /* width of matrix in number of panels */
#define MATRIX_PANEL_HEIGHT 3 /* height of matrix in number of panels */

/* pre-calculated for speed */
#define MATRIX_LED_HEIGHT 24 /* height of matrix in number of LEDs */
#define MATRIX_LED_WIDTH  40 /* width of matrix in number of LEDs */

uint16_t ceilDiv(uint16_t dividend, uint16_t divisor);

/* use main for testing */
int main() {

    /* testing coord2Index */
    // TODO: correctness and speed

    /* PANEL_WIDTH = 2, MATRIX_WIDTH = 3, MATRIX_HEIGHT = 2:
     *
     * x/y| 0 1 2 3 4 5
     * ---+------------
     *  0 | 1 2 9 A H I
     *  1 | 3 4 B C J K
     *  2 | 5 6 D E L M
     *  3 | 7 8 F G N O
     */

    return 0;
}

/* ceiling division (division with rounding up) */
uint16_t ceilDiv(uint16_t dividend, uint16_t divisor) {
    if (divisor == 0) return 0; /* x/0 := 0 */
    //if (divisor == 1) return dividend; /* quicker if p(divisor=1) > 0.5 */


    /* The machine cuts all decimals and therefore always rounds down.
     * Statement: ∀z∈Z, ∀n∈Z*: ⌊(z+n-1)/n⌋ = ⌈z/n⌉
     *
     * Proof: 
     *   1. Let z/n ∈ Z:
     *     ⌊(z+n-1)/n⌋ = ⌊z/n +  (n-1)/n⌋          ∣  ∀s∈Z, ∀t∈R: ⌊s + t⌋ = s + ⌊t⌋
     *                 =  z/n + ⌊(n-1)/n⌋          ∣  (n-1)/n < 1
     *                 =  z/n
     *                 = ⌈z/n⌉
     *
     *   2. Let z/n ∈ R\Z:
     *     Let a∈Z, b∈R\Z so that z = a + b, n ∣ a, and b < n:
     *     ⌊(z+n-1)/n⌋ = ⌊   z/n     - 1/n  + n/n⌋
     *                 = ⌊ (a+b)/n   - 1/n⌋ +  1
     *                 = ⌊a/n +  b/n - 1/n⌋ +  1   ∣  n ∣ a <=> a/n ∈ Z
     *                 =  a/n + ⌊b/n - 1/n⌋ +  1   ∣  b < n => b-1 < n <=> (b-1)/n < 1
     *                 =  a/n               +  1   ∣  a = z-b <=> a/n = (z-b)/n <=> ⌊a/n⌋ = ⌊z/n - b/n⌋ <=> a/n = ⌊z/n⌋
     *                 = ⌊z/n⌋              +  1   ∣  b != 0 => ⌊z/n⌋ < z/n
     *                 = ⌈z/n⌉
     *
     * qed.
     */
    return (dividend + divisor - 1) / divisor; 
}

/* transforms (x, y) in index of LED array */
// TODO: implement lookup table calculated at runtime
uint16_t coord2Index(uint16_t x, uint16_t y) { /* for us args as uint8_t are also fine */
    //return (floor(x / PANEL_LED_WIDTH) * (PANEL_LED_HEIGHT * MATRIX_PANEL_HEIGHT) + y) * PANEL_LED_WIDTH + x % PANEL_LED_WIDTH;

    uint8_t x_mod_PANEL_LED_WIDTH = x % PANEL_LED_WIDTH; /* pre-calculate for speed */
    return (x + 1) * MATRIX_LED_HEIGHT + y * (PANEL_LED_WIDTH - x_mod_PANEL_LED_WIDTH) - (MATRIX_LED_HEIGHT - 1 - y) * x_mod_PANEL_LED_WIDTH;
}
