#include <iostream>
int find_max(int, int, int); // 세 수 중에서 최댓값을 구하는 함수
int find_min(int, int, int); // 세 수 중에서 최솟값을 구하는 함수
int big_c(int, int, int); // 최대공약수를 구하는 함수
int les_c(int, int, int); // 최소공배수를 구하는 함수
int main() {
	int num1, num2, num3; 
	scanf_s("%d", &num1); scanf_s("%d", &num2); scanf_s("%d", &num3); // 입력된 세 개의 숫자를 변수 num1, num2,num3에 저장합니다. 
	printf("최소공배수는 %d입니다.", les_c(num1, num2, num3)); // 최소공배수를 구하는 함수에 입력된 num1 , num2, num3의 값을 대입해줍니다.
	return 0;
}

int find_max(int x, int y, int z) {
	int max; // 최댓값을 저장할 변수 max를 선언합니다.
	if (x > y) // 만약 x가 y보다 크다면
		max = x; //max값은 x가 되고
	else // 만약 y가 x보다 크거나 같다면
		max = y; // max값은 y가 됩니다
	if (z > max) // 만약 z값이 max보다 크게 된다면
		max = z; // max값은 z가 됩니다.
	return max; // 구한 max값을 반환해줍니다.
}
int find_min(int x, int y, int z) {
	int min; // 최솟값을 저장할 변수 min을 선언합니다.
	if (x < y) // 만약 x가 y보다 작다면
		min = x; // min값은 x가 되고
	else // 만약 y가 x보다 작거나 같다면
		min = y; //min값은 y가 됩니다.
	if (z < min) // 만약 z값이 min보다 작다면
		min = z; // min값은 z가 됩니다.
	return min; // 구한 min값을 반환해줍니다.
}




int big_c(int a, int b, int c)
{
	int min = find_min(a, b, c); // 변수 min값은 함수 find_min의 반환값과 같습니다. 
	int i = 2; //최대공약수를 구하기위해선 나뉘어지는 숫자를 2부터 시작해야하므로 변수 i는 2의 값으로 저장됩니다.
	int biggest_common= 1; // 최대공약수의 값을 받을 변수 biggest_common를 선언해줍니다. 이 변수에 값을 지정해주지않으면, 오류가 나기때문에 임의의 값인 1을 저장해줍니다.
	
	while (i <= min) // i의 값이 최솟값이 될 때까지 while문을 돌려줍니다.
	{
		if (a % i == 0 && b % i == 0 && c % i == 0) // a에서도, b에서도, c에서도 모두 나뉘어질 때가 있을 경우,
		{		
			biggest_common = i;	 // 그 때의 i값을 최대공약수로 설정해줍니다.
		}
	
		i++; // i값에 1을 더해줍니다.

		
	}
	return biggest_common; // 구해준 최대공약수의 값을 반환해줍니다.
}

int les_c(int a, int b, int c)
{
	int biggest_common = big_c(a, b, c); // 변수 biggest_common은 biggest_common의 함수 반환값을 저장하므로, 최대공약수입니다. 
	a = a / biggest_common; // a를 최대공약수로 나눠줍니다.
	b = b / biggest_common; // b를 최대공약수로 나눠줍니다.
	c = c / biggest_common; // c를 최대공약수로 나눠줍니다.
	int answer; // 최소공배수를 저장할 변수 answer을 선언해줍니다.
	int max = find_max(a, b, c); // 변수 max값은 함수 find_max의 반환값과 같습니다. 
	for (int i = 2; i <= max; i++) // 변수 i의 값을 2로 초기화 한 뒤, max값이 될 때까지 반복하도록 조건식을 설정하여, i의 값을 1씩 증가하는 for문을 선언했습니다. 
	{
		if (a % i == 0 || b % i == 0 || c % i == 0) { // 만약 a,b,c중 하나라도 나뉘어지는 수가 있다면
			if (a % i == 0)  // 나뉘어지는 숫자가 a라면
				a = a / i; // a의 값을 a에 i로 나뉘어졌을 때 나온 값으로 변경합니다.
			if (b % i == 0)// 나뉘어지는 숫자가 b라면
				b = b / i; // b의 값을 b에 i로 나뉘어졌을 때 나온 값으로 변경합니다.
			if (c % i == 0) // 나뉘어지는 숫자가 c라면
				c = c / i; // c의 값을 c에 i로 나뉘어졌을 때 나온 값으로 변경합니다.
			biggest_common *= i; // 그리곤 최대공약수에 i를 곱해줍니다.
		}
	}
	answer = a * b * c * biggest_common; // 앞에 for문으로 인해 계산된 biggest_common의 값과 다 나뉘어진 세 수 (a,b,c)를 곱해준 값을 변수 answer에 저장합니다.
	return answer; // 변수 answer의 값을 반환해줍니다.
}
