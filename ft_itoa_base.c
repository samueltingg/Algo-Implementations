/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:41:16 by sting             #+#    #+#             */
/*   Updated: 2023/11/06 11:06:28 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_length_base(int num, int base)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while ((unsigned int)num > 0)
	{
		num = num / base;
		count++;
	}
	return (count);
}

static int	check_count_base(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
		count++;
	}
	if (count < 2)
		return (0);
	return (count);
}

char	*ft_itoa_base(int num, char *base)
{
	char	*str;
	int		i;
	long	nb;
    long    base_len;

    base_len = check_count_base(base);
	nb = (long)num;
	str = (char *)malloc(sizeof(char) * (count_length_base(nb, base_len) + 1));
	if (str == NULL)
		return (NULL);
	str[count_length_base(nb, base_len)] = '\0';
	i = count_length_base(nb, base_len) - 1;
	if (nb == 0)
	{
		str[0] = '0';
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i--] = base[nb % base_len];
		nb = nb / base_len;
	}
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
//     int num = -255;
//     char    *base = "0123456789abcdef";
//     char    *ptr = ft_itoa_base(num, base);
//     printf ("%s\n", ptr);
//     printf ("hex len: %i\n", count_length_base(num, check_count_base(base)));

//     free (ptr);
//     return (0);
// }

/*
- line 51: nb > 0 instead of i > 0 to cater for both +ve & -ve num
	when num +ve, while(i<0) only run till i = 1, skipping index 0
*/