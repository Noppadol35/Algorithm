#include <stdio.h>

#define MAX 64

/* ฟังก์ชันบวกเมตริกซ์: C = A + B */
void add(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

/* ฟังก์ชันลบเมตริกซ์: C = A - B (จำเป็นสำหรับ Strassen) */
void sub(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
    // Base case: ถ้าขนาดเมตริกซ์คือ 1x1
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2; // ขนาดของเมตริกซ์ย่อย

    // ประกาศตัวแปรสำหรับเมตริกซ์ย่อยและเมตริกซ์ชั่วคราว
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int TmpA[MAX][MAX], TmpB[MAX][MAX]; // ตัวแปรพักค่าสำหรับการบวก/ลบก่อนคูณ

    // แบ่งเมตริกซ์ A และ B เป็น 4 ส่วน
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // --- คำนวณ M1 ถึง M7 ตามสูตร Strassen ---

    // M1 = (A11 + A22) * (B11 + B22)
    add(k, A11, A22, TmpA);
    add(k, B11, B22, TmpB);
    strassen(k, TmpA, TmpB, M1);

    // M2 = (A21 + A22) * B11
    add(k, A21, A22, TmpA);
    strassen(k, TmpA, B11, M2);

    // M3 = A11 * (B12 - B22)
    sub(k, B12, B22, TmpB);
    strassen(k, A11, TmpB, M3);

    // M4 = A22 * (B21 - B11)
    sub(k, B21, B11, TmpB);
    strassen(k, A22, TmpB, M4);

    // M5 = (A11 + A12) * B22
    add(k, A11, A12, TmpA);
    strassen(k, TmpA, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    sub(k, A21, A11, TmpA);
    add(k, B11, B12, TmpB);
    strassen(k, TmpA, TmpB, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    sub(k, A12, A22, TmpA);
    add(k, B21, B22, TmpB);
    strassen(k, TmpA, TmpB, M7);

    // --- คำนวณ C ย่อย จากค่า M ---
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

    // C11 = M1 + M4 - M5 + M7
    add(k, M1, M4, TmpA);
    sub(k, TmpA, M5, TmpB);
    add(k, TmpB, M7, C11);

    // C12 = M3 + M5
    add(k, M3, M5, C12);

    // C21 = M2 + M4
    add(k, M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    sub(k, M1, M2, TmpA);
    add(k, TmpA, M3, TmpB);
    add(k, TmpB, M6, C22);

    // รวมเมตริกซ์ย่อยกลับเป็นเมตริกซ์ C
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main()
{
    int n = 4;

    int A[MAX][MAX] = {
        {1, 0, 1, 0},
        {2, 0, 2, 0},
        {3, 0, 3, 0},
        {4, 0, 0, 0}};

    int B[MAX][MAX] = {
        {-1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 0}};

    int C[MAX][MAX] = {0};

    // เรียกใช้ฟังก์ชัน Strassen
    strassen(n, A, B, C);

    // แสดงผลลัพธ์
    printf("Result Matrix C:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}