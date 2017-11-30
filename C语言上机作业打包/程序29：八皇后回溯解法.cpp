#include<iostream>
const int length = 8;

int counter = 0;//��ʼ��������

bool Check(int matrix[], int row)//����Check��������ʺ�λ���Ƿ���� 
{
	int i = 0;
	for (i = 0;i <= row - 1;i++)
	{
		if (matrix[i] == matrix[row] || row - i == matrix[row] - matrix[i] || i - row == matrix[row] - matrix[i])
			return false;//����������һ����һ���㣬������������
	}
	return true;
}

void EightQueen(int matrix[], int row)
{
	int i = 0, j = 0;
	for (i = 0;i<length;i++)
	{
		matrix[row] = i;
		if (Check(matrix, row) && row <= length - 1)//����Ҫ�� 
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
				EightQueen(matrix, row + 1);//Ѱ����һ�з���λ�õĻʺ�
		}
	}
}

int main(int argc, char* argv[])
{
	int matrix[length] = { 0 };
	EightQueen(matrix, 0);//���±�Ϊ0Ҳ����һ�п�ʼѰ��

	printf("We have solved the problem!\n");
	return 0;
}