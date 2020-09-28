#include<iostream>
#include<string>
#include<vector>

int count = 0;

int** Array2D(int row, int col)
{
	count = 0;
	int** row_p = new int*[row];
	int* col_p;
	for(int i=0; i<row; i++)
	{
		col_p = new int[col];
		for(int j=0; j<col; j++)
		{
			col_p[j] = count;
			count++;
		}
		row_p[i] = col_p;
	}

	return row_p;
}

int*** Array3D(int dir_x, int dir_y, int dir_z)
{
	count = 0;
	int*** dirx = new int**[dir_x];
	int** diry; 
	int* dirz;
	for(int i=0; i<dir_x; i++)
	{
		diry = new int*[dir_x];
		for(int j=0; j<dir_y; j++)
		{
			dirz = new int[dir_z];
			for(int k=0; k<dir_z; k++)
			{
				dirz[k] = count;
				count++;
			}
			diry[j] = dirz;
		}
		dirx[i] = diry;
	}
	return dirx;
}

void PrintArray2D(int **array2d, int row, int col)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			std::cout << "[" << i << "]" << "[" << j << "]" <<  array2d[i][j] << std::endl;
		}
	}	
	std::cout << "---------------------------" << std::endl;
}

void PrintArray3D(int ***array3d, int dir_x, int dir_y, int dir_z)
{
	for(int i=0; i<dir_x; i++)
	{
		for(int j=0; j<dir_y; j++)
		{
			for(int k=0; k<dir_z; k++)
				std::cout << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << array3d[i][j][k] << std::endl;
		}
	}
	std::cout << "---------------------------" << std::endl;
}

int main()
{
	int** array2d;
	int*** array3d;
	array2d=Array2D(4,3);
	PrintArray2D(array2d,4,3);
	array3d=Array3D(3,4,2);
	PrintArray3D(array3d,3,4,2);
	array3d=Array3D(5,3,4);
	PrintArray3D(array3d,5,3,4);

	return 0;
}
