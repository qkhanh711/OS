#include <stdio.h>

// Giải thuật mô phỏng:
// - Bước 01: Tạo ra một số tiến trình.
// - Bước 02: Lấy PID và thời gian phục vụ (thời gian CPU) đối với mỗi tiến trình.
// - Bước 03: Ban đầu, thời gian chờ của tiến trình đầu tiên là bằng 0 và tổng thời gian của tiến trình đầu tiên là thời gian thực hiện của tiến trình đó.
// - Bước 04: Tính toán tổng thời gian và thời gian thực hiện tiến trình đối với các tiến trình còn lại.
// - Bước 05: Thời gian chờ của một tiến trình là tổng thời gian thực hiện của các tiến trình trước đó.
// - Bước 06: Tổng thời gian của một tiến trình được tính bằng cách cộng thời gian chờ và thời gian thực hiện.
// - Bước 07: Tổng thời gian chờ được tính bằng cách cộng thời gian chờ của các tiến trình.
// - Bước 08: Tổng thời gian thực hiện được tính bằng cách cộng tất cả tổng thời gian của mỗi tiến trình..
// - Bước 09: Thời gian chờ đợi trung bình được tính bằng cách lấy tổng thời gian chờ chia cho số tiến trình. 
// - Bước 10: Tính thời gian thực hiện trung bình bằng cách chia tổng thời gian thực hiện cho số tiến trình.
// - Bước 11: Hiển thị kết quả ra màn hình.

int proc[1000], burst_time[1000];
int waiting_time[1000], turn_around_time[1000];

int main() {
    int n;
    scanf("%d", &n);
    printf("Enter the processes and their burst times\n");
    for (int i = 0; i < n; i++) scanf("%d", &proc[i]);
    for (int i = 0; i < n; i++) scanf("%d", &burst_time[i]);
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    for (int i = 0; i < n; i++) turn_around_time[i] = waiting_time[i] + burst_time[i];
    int total_w = 0, total_tat = 0;
    printf("Processes  Burst   Waiting  Turn around \n");
    for (int i = 0; i < n; i++) {
        total_w += waiting_time[i];
        total_tat += turn_around_time[i];
        printf(" %d\t  %d\t\t %d \t%d \n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }
    printf("Average waiting time = %f\n", (float)total_w / (float)n);
    printf("Average turn around time = %f\n", (float)total_tat / (float)n);
}