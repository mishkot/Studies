// https://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf

// https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html#Using-Assembly-Language-with-C



#include <cstdio>

int
main()
{ //{{{
    printf("Hello!\n");

    unsigned cycles_low, cycles_high;

    // 3.2.1
    asm volatile ("CPUID\n\t"
                  "RDTSC\n\t"
                  "mov %%edx, %0\n\t"
                  "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
                        "%rax", "%rbx", "%rcx", "%rdx");

    printf("cycles_low: %u, cycles_high: %u\n", cycles_low, cycles_high);

    asm volatile ("CPUID\n\t"
                  "RDTSC\n\t"
                  "mov %%edx, %0\n\t"
                  "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
                        "%rax", "%rbx", "%rcx", "%rdx");

    printf("cycles_low: %u, cycles_high: %u\n", cycles_low, cycles_high);
} //}}}
