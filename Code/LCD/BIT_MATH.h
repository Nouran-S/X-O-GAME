#ifndef BIT_MATH_H
#define BIT_MATH_H

#define Set_bit(n, b) (n = n | (1 << b))

#define Clear_bit(n, b) (n = n & ~(1 << b))

#define Toggel_bit(n, b) (n = n ^ (1 << b))

#define Get_bit(n, b) (n = (n >> b) & 1)

#endif
