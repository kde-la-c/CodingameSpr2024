#include "../libft/libft.h"

int main()
{
	int		n;
	char	type;
	int		coord;
	char	command[201];
	
	scanf("%d", &n); fgetc(stdin);
	char	mat[n + 1][n + 1];
	for (int i = 0; i < n; i++)
	{
		memset(mat[i], '.', n);
		mat[i][n] = 0;
	}
	mat[n][0] = 0;
	
	// game loop
	while (1) {
		scanf("%[^\n]", command); fgetc(stdin);
		type = command[0];
		coord = atoi(&command[2]);
		for (int i = 0; i < n; i++) {

			// Write an action using printf(). DON'T FORGET THE TRAILING \n
			// To debug: fprintf(stderr, "Debug messages...\n");


			// Print the i-th line of the image after the command was executed
			if (type == 'C')
			{
				mat[i][coord] = '#';
			}
			else if (type == 'R' && i == coord)
			{
				memset(mat[i], '.', n);
			}
			printf("%s\n", mat[i]);
		}
	}

	return 0;
}