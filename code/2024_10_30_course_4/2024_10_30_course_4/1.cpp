//#include<stdio.h>
//
//int main()
//{
//	for (int i = 100; i <= 999; i++)
//	{
//		//���� �ж��Ƿ��� ����
//		//Ȼ�����ж��Ƿ��ǻ���
//		int flag1 = 0, flag2 = 1;
//		for (int j = 2; j <= i / j; j++)
//		{
//			if (i % j == 0)
//			{
//				flag1 = 1;
//				break;
//			}
//		}
//		//
//		int a[3] , cnt = 0;
//		int t = i;
//		while (t)
//		{
//			a[cnt++] = t % 10;
//			t /= 10;
//		}
//		for (int j = 0; j < 3 / 2; j++)
//		{
//			if (a[j] != a[3 - j - 1])
//			{
//				flag2 = 0;
//				break;
//			}
//		}
//		if (flag1 && flag2) printf("�ǻ�������");
//		else printf("���ǻ�������");
//	}
//	return 0;
//}