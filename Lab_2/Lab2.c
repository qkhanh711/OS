#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    printf("hello world \n");
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child \n");
        char *pathprogram = "/bin/ls";
        char *argopt = "-lt";
        char *argdes = ".";
        execl(pathprogram, pathprogram, argopt, argdes, NULL);
        printf("this shouldn't print out");

    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent\n");
    }
    return 0;
}

// Biên dịch chương trình bằng lệnh gcc, ví dụ: gcc lab2_1.c -o r

// Thực hiện lệnh: ./r và quan sát kết quả.

 

// Ý 2:

// Viết shell script, ví dụ đặt tên lab2_2.sh với nội dung như bên dưới:

// #! /bin/sh
// # Chuong trinh sh dau tien

// ls -lt

 

// Save file và ra bên ngoài thực hiện lệnh ls sẽ thấy file lab2_2.sh chưa có quyền chạy. Nếu chạy file ./lab2_2.sh sẽ báo lỗi.

// Sau đó thực hiện lệnh: chmod +x lab2_2.sh, cho phép file có quyền thực thi, sau khi ls sẽ thấy file chuyển màu sang màu khác (màu xanh nghĩa là có quyền thực thi). Thực hiện chạy: ./lab2_2.sh để xem kết quả.