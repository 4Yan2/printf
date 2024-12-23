#include <stdio.h>      // pour comparer avec printf
#include "ft_printf.h"      // pour utiliser ft_printf

int main(void)
{
    int ret_ft;
    int ret_orig;

    // Test 1 : affichage simple
    ret_ft = ft_printf("Hello world!\n");
    ret_orig = printf("Hello world!\n");
    printf("Retour ft_printf : %d | Retour printf : %d\n\n", ret_ft, ret_orig);

    // Test 2 : quelques conversions
    ret_ft = ft_printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Hex: %x\n", 'A', "Test", -42, 42U, 255U);
    ret_orig = printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Hex: %x\n", 'A', "Test", -42, 42U, 255U);
    printf("Retour ft_printf : %d | Retour printf : %d\n\n", ret_ft, ret_orig);

    // Test 3 : pointeurs
    void *ptr = &ret_ft;
    ret_ft = ft_printf("Pointer: %p\n", ptr);
    ret_orig = printf("Pointer: %p\n", ptr);
    printf("Retour ft_printf : %d | Retour printf : %d\n\n", ret_ft, ret_orig);

    return 0;
}