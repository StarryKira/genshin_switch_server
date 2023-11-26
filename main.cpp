#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

char filename[MAX_FILENAME_LENGTH];
char tempFilename[MAX_FILENAME_LENGTH];
char line[MAX_LINE_LENGTH];

#define MAX_FILENAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

    int main()
    {
        printf("   ____                        _       _             ____    _                    _       _ \n"
               "  / ___|   ___   _ __    ___  | |__   (_)  _ __     / ___|  | |_    __ _   _ __  | |_    | |\n"
               " | |  _   / _ \\ | '_ \\  / __| | '_ \\  | | | '_ \\    \\___ \\  | __|  / _` | | '__| | __|   | |\n"
               " | |_| | |  __/ | | | | \\__ \\ | | | | | | | | | |    ___) | | |_  | (_| | | |    | |_    |_|\n"
               "  \\____|  \\___| |_| |_| |___/ |_| |_| |_| |_| |_|   |____/   \\__|  \\__,_| |_|     \\__|   (_)   ");
        char filename[MAX_FILENAME_LENGTH];
        char tempFilename[MAX_FILENAME_LENGTH];
        char line[MAX_LINE_LENGTH];

        // 获取用户输入的文件位置
        printf("please input your genshin input location");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);

        // 去除文件位置中的换行符
        size_t length = strlen(filename);
        if (filename[length - 1] == '\n') {
            filename[length - 1] = '\0';
        }

        // 打开文件
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("no file named config.ini");
        }

        // 创建一个临时文件以保存修改后的内容
        sprintf(tempFilename, "%s_temp", filename);
        FILE *tempFile = fopen(tempFilename, "w");
        if (tempFile == NULL) {
            perror("临时文件创建失败");
            fclose(file);
        }

      
        for (int i = 1; i <= 3; ++i) {
            if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
                perror("文件读取失败");
                fclose(file);
                fclose(tempFile);
                remove(tempFilename);
            }

            // 修改第三行
            if (i == 3) {

                // 将行写入临时文件
                fputs("cps=bilibili", tempFile);
            }

            // 复制剩余的文件内容
            while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
                fputs(line, tempFile);
            }

            // 关闭文件
            fclose(file);
            fclose(tempFile);

            // 删除原文件并将临时文件重命名为原文件
            remove(filename);
            if (rename(tempFilename, filename) != 0) {
                perror("文件重命名失败");
            }

            printf("文件修改成功！\n");
            system("YuanShen.exe");
            return 0;
        }
    }
