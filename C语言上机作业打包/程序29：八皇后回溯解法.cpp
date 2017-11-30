#include<iostream>
const int length = 8;

int counter = 0;//初始化计数器

bool Check(int matrix[], int row)//定义Check函数检验皇后位置是否合理 
{
	int i = 0;
	for (i = 0;i <= row - 1;i++)
	{
		if (matrix[i] == matrix[row] || row - i == matrix[row] - matrix[i] || i - row == matrix[row] - matrix[i])
			return false;//以上三条件一旦有一满足，即不满足题意
	}
	return true;
}

void EightQueen(int matrix[], int row)
{
	int i = 0, j = 0;
	for (i = 0;i<length;i++)
	{
		matrix[row] = i;
		if (Check(matrix, row) && row <= length - 1)//满足要求 
		{
			if (row == length - 1)
			{
				++counter;
				printf("Solution %d:\n", counter);
				for (j = 0;j<length;j++)
					printf("%4d", matrix[j]);
				printf("\n");
			}
			else
				EightQueen(matrix, row + 1);//寻找下一行符合位置的皇后
		}
	}
}

int main(int argc, char* argv[])
{
	int matrix[length] = { 0 };
	EightQueen(matrix, 0);//从下标为0也即第一行开始寻找

	printf("We have solved the problem!\n");
	return 0;
}