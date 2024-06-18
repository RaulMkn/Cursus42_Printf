/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:19:36 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/12 18:32:56 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_c(va_list args, char c, int *stopper)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putpointer_fd(va_arg(args, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunsigned_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		return (ft_putexa_fd(va_arg(args, unsigned int), 1, c));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else
	{
		*stopper = 1;
		return (0);
	}
}

int	ft_printf(char const *c, ...)
{
	int			i;
	int			count;
	va_list		args;
	static int	stopper;

	i = 0;
	count = 0;
	stopper = 0;
	va_start(args, c);
	while (c[i] && !stopper)
	{
		if (c[i] == '%')
		{
			count += handle_c(args, c[i + 1], &stopper);
			i++;
		}
		else
		{
			count += ft_putchar_fd(c[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*
int main()
{
    int entero = 42564;
    char caracter = 'A';
    char *cadena = "Hola, mundo!";
    char *cadena_larga = "Este es un string extremadamente largo";
    char *cadena_vacia = "";
    unsigned int unsigned_entero = 121212;
    void *puntero = &entero;
    void *puntero_null = NULL;
    int num_negativo = -42;
    int int_max = INT_MAX;
    int int_min = INT_MIN;
    unsigned int uint_max = UINT_MAX;

    int original_ret, mi_ret;

    printf("%s\n", "Prueba de impresión de caracteres");
    printf("Original printf:\n");
    original_ret = printf("Caracter: %c\n", caracter);
    printf("Return: %d\n", original_ret);
    original_ret = printf("%c\n", caracter);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Caracter: %c\n", caracter);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("%c\n", caracter);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de cadenas");
    printf("Original printf:\n");
    original_ret = printf("Cadena: %s\n", cadena);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena: %s\n", cadena);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de cadenas largas");
    printf("Original printf:\n");
    original_ret = printf("Cadena larga: %s\n", cadena_larga);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena larga: %s\n", cadena_larga);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de cadenas vacías");
    printf("Original printf:\n");
    original_ret = printf("Cadena vacía: %s\n", cadena_vacia);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Cadena vacía: %s\n", cadena_vacia);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de punteros");
    printf("Original printf:\n");
    original_ret = printf("Puntero: %p\n", puntero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Puntero: %p\n", puntero);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de puntero NULL");
    printf("Original printf:\n");
    original_ret = printf("Puntero NULL: %p\n", puntero_null);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Puntero NULL: %p\n", puntero_null);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de números decimales (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Entero: %d\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero: %d\n", entero);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de enteros (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Entero: %i\n", entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero: %i\n", entero);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de números decimales negativos");
    printf("Original printf:\n");
    original_ret = printf("Número negativo: %d\n", num_negativo);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Número negativo: %d\n", num_negativo);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de números sin signo (base 10)");
    printf("Original printf:\n");
    original_ret = printf("Unsigned Entero: %u\n", unsigned_entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Unsigned Entero: %u\n", unsigned_entero);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de enteros máximos y mínimos");
    printf("Original printf:\n");
    original_ret = printf("Entero máximo: %d\n", int_max);
    printf("Return: %d\n", original_ret);
    original_ret = printf("Entero mínimo: %d\n", int_min);
    printf("Return: %d\n", original_ret);
    original_ret = printf("Unsigned Entero máximo: %u\n", uint_max);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Entero máximo: %d\n", int_max);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("Entero mínimo: %d\n", int_min);
    printf("Return: %d\n", mi_ret);
    mi_ret = ft_printf("Unsigned Entero máximo: %u\n", uint_max);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de números hexadecimales en minúsculas");
    printf("Original printf:\n");
    original_ret = printf("Hexadecimal (minúsculas): %x\n", unsigned_entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hexadecimal (minúsculas): %x\n", unsigned_entero);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de números hexadecimales en mayúsculas");
    printf("Original printf:\n");
    original_ret = printf("Hexadecimal (mayúsculas): %X\n", unsigned_entero);
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Hexadecimal (mayúsculas): %X\n", unsigned_entero);
    printf("Return: %d\n\n", mi_ret);

    printf("%s\n", "Prueba de impresión de porcentaje");
    printf("Original printf:\n");
    original_ret = printf("Porcentaje: %%\n");
    printf("Return: %d\n", original_ret);

    printf("Mi ft_printf:\n");
    mi_ret = ft_printf("Porcentaje: %%\n");
    printf("Return: %d\n\n", mi_ret);


    // Comparación de printf original y ft_printf con solo un porcentaje
    printf("===== COMPARACIÓN DE PORCENTAJE =====\n");
    original_ret = printf("x \n");
    printf("Original Return: %d\n", original_ret);
    mi_ret = ft_printf("hola muy buenas % hola \n");
    printf("Mi printf Return: %d\n\n", mi_ret);
    
    // Comparación de printf original con una cadena
    printf("===== COMPARACIÓN DE CADENA =====\n");
    original_ret = printf("Original: %i\n", printf("Hola\n"));
    printf("Original Return: %d\n", original_ret);
    mi_ret = printf("mi print: %i\n", ft_printf("Hola\n"));
    printf("Mi printf Return: %d\n\n", mi_ret);

    // Comparación de printf original con un entero
    printf("===== COMPARACIÓN DE ENTERO =====\n");
    original_ret = printf("Original: %i\n", printf("%i\n", entero));
    printf("Original Return: %d\n", original_ret);
    mi_ret = printf("mi print: %i\n", ft_printf("%i\n", entero));
    printf("Mi printf Return: %d\n\n", mi_ret);

    return 0;
*/
