/*����7-2�������������쳲��������е�ǰn������1��n��46������1, 1, 2, 3, 5, ��,55��
 * ����ÿ�д�ӡ5�����ĸ�ʽ�����������һ�е��������5������Ҳ��Ҫ���С�*/

/* �����������쳲��������� */
# include <stdio.h>

# define MAXN 46                               /* ������ų���MAXN */

int main() {
    int i, n;

    /* �����ʼ��������쳲���������ǰ������ */
    int fib[MAXN] = {1, 1};


    /* ��ʾ����n */
    printf("Enter n: ");
    scanf("%d", &n);

    if (n >= 1 && n <= 46) {
        /* ����쳲���������ʣ���n-2���� */
        for (i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        /* ���쳲��������� */
        for (i = 0; i < n; i++) {
            printf("%11d", fib[i]);

            /* ÿ���5�����ͻ���(��Ϊi��0��ʼ����iΪ4ʱ�Ѿ������5���������Լ�1) */
            if ((i + 1) % 5 == 0) {
                printf("\n");
            }
        }

        /* �����������5�ı��������� */
        if (n % 5 != 0) {
            printf("\n");
        }
    } else {
        /* ���������ʾ */
        printf("Invalid Value.\n");
    }

    return 0;
}