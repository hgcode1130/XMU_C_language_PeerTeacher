//#include<stdio.h>
//#include<cstring>
//int main()
//{
//	//9787302481447
//	char a[50];
//	scanf_s("%s", a);
//	int cnt = 0 , len = strlen(a);
//	int s1 = 0, s2 = 0, c;
//	for (int i = 0; i < len; i++)
//	{
//		if (a[i] >= '0' && a[i] <= '9')
//		{
//			++cnt;
//			if (cnt == 13)
//			{
//				c = a[i] - '0';
//				break;
//			}
//			if (cnt % 2)
//			{
//				s1 += a[i] - '0';
//			}
//			else s2 += a[i] - '0';
//		}
//	}
//	if (c == 10 - (s2 * 3 + s1) % 10)
//	{
//		printf("1");
//	}
//	else printf("0");
//	return 0;
//}
