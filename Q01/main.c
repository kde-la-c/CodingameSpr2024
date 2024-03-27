#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>


/**
 * The height of each building.
 */
typedef struct intArray {
	int length;
	int* items;
} intArray;

/**
 * Representation of the n buildings
 */
typedef struct stringArray {
	int length;
	char** items;
} stringArray;

void	print_ret(intArray ret)
{
	for (int i = 0; i < ret.length; i++)
	{
		printf(">%i\n", ret.items[i]);
	}
}

intArray buildingHeights(int n, stringArray building_map)
{
	intArray *int_array = ft_calloc(1, sizeof(intArray));

	int_array->items = ft_calloc(sizeof(int), n);
	int_array->length = building_map.length;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; building_map.items[i][j] == '*'; j++)
		{
			int_array->items[i]++;
		}
	}

	return (*int_array);
}

int	main()
{
	intArray	ret;
	stringArray	map;
	char		**items = ft_split("********** ,**********************************************     ,******************************************      ,***********      ,********************************   ,**    ,**************************   ,********************************************      ,*********     ,******************************", ',');

	map.length = 10;
	map.items = items;
	ret = buildingHeights(5, map);
	print_ret(ret);
	return (0);
}