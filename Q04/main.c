#include "../libft/libft.h"

/**
 * The parameters of the largest circle [centerRow, centerCol, radius].
 */
typedef struct intArray {
	int length;
	int* items;
} intArray;

/**
 * Pixels of the image, given row by row from top to bottom.
 */
typedef struct stringArray {
	int length;
	char** items;
} stringArray;

void	print_ret(intArray ret)
{
	for (int i = 0; i < ret.length; i++)
	{
		printf("%i\n", ret.items[i]);
	}
	
}

/**
 * @param n_rows The height of the image.
 * @param n_cols The width of the image.
 * @param image Pixels of the image, given row by row from top to bottom.
 * @return The parameters of the largest circle [centerRow, centerCol, radius].
 */
intArray findLargestCircle(int n_rows, int n_cols, stringArray image) {
	// Write your code here
	int			linelen = 0, biggest = 0;
	intArray	int_array = {3, malloc(sizeof(int) * 3)};

	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			if (j && image.items[i][j] == image.items[i][j - 1])
				linelen++;
			else if (linelen > biggest)
				biggest = linelen;
		}
		linelen = 0;
	}
	printf("linelen : %i\n", biggest);

	return int_array;
}

int	main()
{
	stringArray		arg;
	intArray		ret;

	arg.items = ft_split("bbCCCCC3cC3c 1CAABBBC3c3c aCAAbbbC312A aCCBbabCB111 3CBBbbbC2C12 CCBAca3C2a1C 2ACCCCCaaaaa b33ccccccccc", ' ');
	arg.length = 8;

	ret = findLargestCircle(8, 12, arg);
	print_ret(ret);
}