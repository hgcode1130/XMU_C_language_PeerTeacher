/*����6-1�� ��СдӢ����ĸת����
 * ����һ���ַ��������еĴ�д��ĸת��Ϊ��Ӧ��Сд��ĸ�������Сд��ĸת��Ϊ��Ӧ�Ĵ�д��ĸ������������ַ���ԭ����� */

/* ��СдӢ����ĸת�� */
#include <stdio.h>

int main() {
    /* ����һ���ַ�����ch */
    char ch;

    /* ������ʾ */
    printf("Input characters: ");

    /* ����һ���ַ����������� ch */
    ch = getchar();

    /* �Ƚ�ch�� '\n'����������ַ����ǻس�ʱ������ѭ�������س�����ѭ������ */
    while (ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') {           /* ���ch�Ǵ�д��ĸ */
            ch = ch - 'A' + 'a';                /* ��д��ĸת��ΪСд��ĸ */

        } else if (ch >= 'a' && ch <= 'z') {    /* ���ch��Сд��ĸ */
            ch = ch - 'a' + 'A';                /* Сд��ĸת��Ϊ��д��ĸ */
        }

        putchar(ch);                            /* ���ת������ַ� */

        ch = getchar();                         /* ������һ���ַ� */
    }

    return 0;
}