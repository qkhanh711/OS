#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int Max[MAX_PROCESSES][MAX_RESOURCES];
int Allocation[MAX_PROCESSES][MAX_RESOURCES];
int Need[MAX_PROCESSES][MAX_RESOURCES];
int Available[MAX_RESOURCES];

bool isSafe(int process, int request[]) {
    int Work[MAX_RESOURCES];
    int Finish[MAX_PROCESSES];
    int i, j;

    for (i = 0; i < resources; i++) {
        Work[i] = Available[i];
    }

    for (i = 0; i < processes; i++) {
        Finish[i] = false;
    }

    for (i = 0; i < resources; i++) {
        if (request[i] > Need[process][i]) {
            return false;
        }
    }

    for (i = 0; i < resources; i++) {
        if (request[i] > Work[i]) {
            return false;
        }
    }

    for (i = 0; i < resources; i++) {
        Work[i] -= request[i];
        Allocation[process][i] += request[i];
        Need[process][i] -= request[i];
    }

    int count = 0;
    while (count < processes) {
        bool found = false;
        for (i = 0; i < processes; i++) {
            if (!Finish[i]) {
                bool canFinish = true;
                for (j = 0; j < resources; j++) {
                    if (Need[i][j] > Work[j]) {
                        canFinish = false;
                        break;
                    }
                }
                if (canFinish) {
                    for (j = 0; j < resources; j++) {
                        Work[j] += Allocation[i][j];
                    }
                    Finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    if (count < processes) {
        for (i = 0; i < resources; i++) {
            Work[i] += request[i];
            Allocation[process][i] -= request[i];
            Need[process][i] += request[i];
        }
        return false;
    }

    return true;
}

int main() {
    int thang_sinh = 7;  
    int ngay_sinh  = 11;  
    int N = thang_sinh + ngay_sinh;

    int m = 2 + (N % 3);

    int n = 3 + (N % 3);

    int k = 15 + (N % 7);

    processes = n;
    resources = m;

    printf("So luong tien trinh (n): %d\n", n);
    printf("So luong tai nguyen (m): %d\n", m);
    printf("Tong so tai nguyen (k): %d\n", k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Max[i][j] = (rand() % (k + 1));
            Allocation[i][j] = (rand() % (Max[i][j] + 1));
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        Available[i] = k;
        for (int j = 0; j < n; j++) {
            Available[i] -= Allocation[j][i];
        }
    }

    printf("Ma tran Max:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", Max[i][j]);
        }
        printf("\n");
    }

    printf("Ma tran Allocation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", Allocation[i][j]);
        }
        printf("\n");
    }

    printf("Ma tran Need:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }

    printf("Ma tran Available:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", Available[i]);
    }
    printf("\n");

    int process = 0;  
    int request[MAX_RESOURCES];
    
    // Nhập yêu cầu từ người dùng
    printf("Nhap yeu cau Request cua tien trinh %d:\n", process);
    for (int i = 0; i < resources; i++) {
        scanf("%d", &request[i]);
    }

    // Kiểm tra xem yêu cầu có được đáp ứng hay không
    if (isSafe(process, request)) {
        printf("Yeu cau duoc chap nhan.\n");
    } else {
        printf("Yeu cau khong duoc chap nhan.\n");
    }

    return 0;
}
