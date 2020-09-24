#include <iostream>
int find_max(int, int, int); // �� �� �߿��� �ִ��� ���ϴ� �Լ�
int find_min(int, int, int); // �� �� �߿��� �ּڰ��� ���ϴ� �Լ�
int big_c(int, int, int); // �ִ������� ���ϴ� �Լ�
int les_c(int, int, int); // �ּҰ������ ���ϴ� �Լ�
int main() {
	int num1, num2, num3; 
	scanf_s("%d", &num1); scanf_s("%d", &num2); scanf_s("%d", &num3); // �Էµ� �� ���� ���ڸ� ���� num1, num2,num3�� �����մϴ�. 
	printf("�ּҰ������ %d�Դϴ�.", les_c(num1, num2, num3)); // �ּҰ������ ���ϴ� �Լ��� �Էµ� num1 , num2, num3�� ���� �������ݴϴ�.
	return 0;
}

int find_max(int x, int y, int z) {
	int max; // �ִ��� ������ ���� max�� �����մϴ�.
	if (x > y) // ���� x�� y���� ũ�ٸ�
		max = x; //max���� x�� �ǰ�
	else // ���� y�� x���� ũ�ų� ���ٸ�
		max = y; // max���� y�� �˴ϴ�
	if (z > max) // ���� z���� max���� ũ�� �ȴٸ�
		max = z; // max���� z�� �˴ϴ�.
	return max; // ���� max���� ��ȯ���ݴϴ�.
}
int find_min(int x, int y, int z) {
	int min; // �ּڰ��� ������ ���� min�� �����մϴ�.
	if (x < y) // ���� x�� y���� �۴ٸ�
		min = x; // min���� x�� �ǰ�
	else // ���� y�� x���� �۰ų� ���ٸ�
		min = y; //min���� y�� �˴ϴ�.
	if (z < min) // ���� z���� min���� �۴ٸ�
		min = z; // min���� z�� �˴ϴ�.
	return min; // ���� min���� ��ȯ���ݴϴ�.
}




int big_c(int a, int b, int c)
{
	int min = find_min(a, b, c); // ���� min���� �Լ� find_min�� ��ȯ���� �����ϴ�. 
	int i = 2; //�ִ������� ���ϱ����ؼ� ���������� ���ڸ� 2���� �����ؾ��ϹǷ� ���� i�� 2�� ������ ����˴ϴ�.
	int biggest_common= 1; // �ִ������� ���� ���� ���� biggest_common�� �������ݴϴ�. �� ������ ���� ����������������, ������ ���⶧���� ������ ���� 1�� �������ݴϴ�.
	
	while (i <= min) // i�� ���� �ּڰ��� �� ������ while���� �����ݴϴ�.
	{
		if (a % i == 0 && b % i == 0 && c % i == 0) // a������, b������, c������ ��� �������� ���� ���� ���,
		{		
			biggest_common = i;	 // �� ���� i���� �ִ������� �������ݴϴ�.
		}
	
		i++; // i���� 1�� �����ݴϴ�.

		
	}
	return biggest_common; // ������ �ִ������� ���� ��ȯ���ݴϴ�.
}

int les_c(int a, int b, int c)
{
	int biggest_common = big_c(a, b, c); // ���� biggest_common�� biggest_common�� �Լ� ��ȯ���� �����ϹǷ�, �ִ������Դϴ�. 
	a = a / biggest_common; // a�� �ִ������� �����ݴϴ�.
	b = b / biggest_common; // b�� �ִ������� �����ݴϴ�.
	c = c / biggest_common; // c�� �ִ������� �����ݴϴ�.
	int answer; // �ּҰ������ ������ ���� answer�� �������ݴϴ�.
	int max = find_max(a, b, c); // ���� max���� �Լ� find_max�� ��ȯ���� �����ϴ�. 
	for (int i = 2; i <= max; i++) // ���� i�� ���� 2�� �ʱ�ȭ �� ��, max���� �� ������ �ݺ��ϵ��� ���ǽ��� �����Ͽ�, i�� ���� 1�� �����ϴ� for���� �����߽��ϴ�. 
	{
		if (a % i == 0 || b % i == 0 || c % i == 0) { // ���� a,b,c�� �ϳ��� ���������� ���� �ִٸ�
			if (a % i == 0)  // ���������� ���ڰ� a���
				a = a / i; // a�� ���� a�� i�� ���������� �� ���� ������ �����մϴ�.
			if (b % i == 0)// ���������� ���ڰ� b���
				b = b / i; // b�� ���� b�� i�� ���������� �� ���� ������ �����մϴ�.
			if (c % i == 0) // ���������� ���ڰ� c���
				c = c / i; // c�� ���� c�� i�� ���������� �� ���� ������ �����մϴ�.
			biggest_common *= i; // �׸��� �ִ������� i�� �����ݴϴ�.
		}
	}
	answer = a * b * c * biggest_common; // �տ� for������ ���� ���� biggest_common�� ���� �� �������� �� �� (a,b,c)�� ������ ���� ���� answer�� �����մϴ�.
	return answer; // ���� answer�� ���� ��ȯ���ݴϴ�.
}
