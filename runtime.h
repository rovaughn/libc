#ifndef RUNTIME_H
#define RUNTIME_H

// https://gcc.gnu.org/onlinedocs/gccint/Integer-library-routines.html

void __stack_chk_fail(void);
int __subvsi3(int a, int b);
int __negvsi2(int a);
int __mulvsi3(int a, int b);
int __addvsi3(int a, int b);
long __negvdi2(long a);
void _start(void);
int main(void);

#endif
