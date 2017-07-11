//copyright(c) Tricia.2017

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//三转轮密码机加密函数
void EncryptFile (char buffer[], int FileSize)
{
    int i, j, m;
    int flag = -1, num = 0;
    int sRotor[26][2];
    int mRotor[26][2];
    int fRotor[26][2];
    int arr[1][2];

    sRotor[0][0] = 24; sRotor[0][1] = 21;
    sRotor[1][0] = 25; sRotor[1][1] = 3;
    sRotor[2][0] = 26; sRotor[2][1] = 15;
    sRotor[3][0] = 1; sRotor[3][1] = 1;
    sRotor[4][0] = 2; sRotor[4][1] = 19;
    sRotor[5][0] = 3; sRotor[5][1] = 10;
    sRotor[6][0] = 4; sRotor[6][1] = 14;
    sRotor[7][0] = 5; sRotor[7][1] = 26;
    sRotor[8][0] = 6; sRotor[8][1] = 20;
    sRotor[9][0] = 7; sRotor[9][1] = 8;
    sRotor[10][0] = 8; sRotor[10][1] = 16;
    sRotor[11][0] = 9; sRotor[11][1] = 7;
    sRotor[12][0] = 10; sRotor[12][1] = 22;
    sRotor[13][0] = 11; sRotor[13][1] = 4;
    sRotor[14][0] = 12; sRotor[14][1] = 11;
    sRotor[15][0] = 13; sRotor[15][1] = 5;
    sRotor[16][0] = 14; sRotor[16][1] = 17;
    sRotor[17][0] = 15; sRotor[17][1] = 9;
    sRotor[18][0] = 16; sRotor[18][1] = 12;
    sRotor[19][0] = 17; sRotor[19][1] = 23;
    sRotor[20][0] = 18; sRotor[20][1] = 18;
    sRotor[21][0] = 19; sRotor[21][1] = 2;
    sRotor[22][0] = 20; sRotor[22][1] = 25;
    sRotor[23][0] = 21; sRotor[23][1] = 6;
    sRotor[24][0] = 22; sRotor[24][1] = 24;
    sRotor[25][0] = 23; sRotor[25][1] = 13;

    mRotor[0][0] = 26; mRotor[0][1] = 20;
    mRotor[1][0] = 1; mRotor[1][1] = 1;
    mRotor[2][0] = 2; mRotor[2][1] = 6;
    mRotor[3][0] = 3; mRotor[3][1] = 4;
    mRotor[4][0] = 4; mRotor[4][1] = 15;
    mRotor[5][0] = 5; mRotor[5][1] = 3;
    mRotor[6][0] = 6; mRotor[6][1] = 14;
    mRotor[7][0] = 7; mRotor[7][1] = 12;
    mRotor[8][0] = 8; mRotor[8][1] = 23;
    mRotor[9][0] = 9; mRotor[9][1] = 5;
    mRotor[10][0] = 10; mRotor[10][1] = 16;
    mRotor[11][0] = 11; mRotor[11][1] = 2;
    mRotor[12][0] = 12; mRotor[12][1] = 22;
    mRotor[13][0] = 13; mRotor[13][1] = 19;
    mRotor[14][0] = 14; mRotor[14][1] = 11;
    mRotor[15][0] = 15; mRotor[15][1] = 18;
    mRotor[16][0] = 16; mRotor[16][1] = 25;
    mRotor[17][0] = 17; mRotor[17][1] = 24;
    mRotor[18][0] = 18; mRotor[18][1] = 13;
    mRotor[19][0] = 19; mRotor[19][1] = 7;
    mRotor[20][0] = 20; mRotor[20][1] = 10;
    mRotor[21][0] = 21; mRotor[21][1] = 8;
    mRotor[22][0] = 22; mRotor[22][1] = 21;
    mRotor[23][0] = 23; mRotor[23][1] = 9;
    mRotor[24][0] = 24; mRotor[24][1] = 26;
    mRotor[25][0] = 25; mRotor[25][1] = 17;

    fRotor[0][0] = 1; fRotor[0][1] = 8;
    fRotor[1][0] = 2; fRotor[1][1] = 18;
    fRotor[2][0] = 3; fRotor[2][1] = 26;
    fRotor[3][0] = 4; fRotor[3][1] = 17;
    fRotor[4][0] = 5; fRotor[4][1] = 20;
    fRotor[5][0] = 6; fRotor[5][1] = 22;
    fRotor[6][0] = 7; fRotor[6][1] = 10;
    fRotor[7][0] = 8; fRotor[7][1] = 3;
    fRotor[8][0] = 9; fRotor[8][1] = 13;
    fRotor[9][0] = 10; fRotor[9][1] = 11;
    fRotor[10][0] = 11; fRotor[10][1] = 4;
    fRotor[11][0] = 12; fRotor[11][1] = 23;
    fRotor[12][0] = 13; fRotor[12][1] = 5;
    fRotor[13][0] = 14; fRotor[13][1] = 24;
    fRotor[14][0] = 15; fRotor[14][1] = 9;
    fRotor[15][0] = 16; fRotor[15][1] = 12;
    fRotor[16][0] = 17; fRotor[16][1] = 25;
    fRotor[17][0] = 18; fRotor[17][1] = 16;
    fRotor[18][0] = 19; fRotor[18][1] = 19;
    fRotor[19][0] = 20; fRotor[19][1] = 6;
    fRotor[20][0] = 21; fRotor[20][1] = 15;
    fRotor[21][0] = 22; fRotor[21][1] = 21;
    fRotor[22][0] = 23; fRotor[22][1] = 2;
    fRotor[23][0] = 24; fRotor[23][1] = 7;
    fRotor[24][0] = 25; fRotor[24][1] = 1;
    fRotor[25][0] = 26; fRotor[25][1] = 14;

    for (i = 0; i < FileSize; i++) {     //将文档所有A~Z的字母转为1~26的数字表示
        if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] -= 64;
        }
        else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] -= 96;
        }
    }

    for (i = 0; i < FileSize; i++) {     //明密文转换
        num++;     //记录加密次数
        if (buffer[i] >= 1 && buffer[i] <= 26) {
            m = sRotor[buffer[i] - 1][0];
            for (j = 0; j < 26; j++) {
                flag++;
                if (sRotor[j][1] == m) {
                    m = sRotor[j][1];
                    break;
                }
            }
            m = mRotor[flag][0];
            flag = -1;
            for (j = 0; j < 26; j++) {
                flag++;
                if (mRotor[j][1] == m) {
                    m = mRotor[j][1];
                    break;
                }
            }
            m = fRotor[flag][0];
            flag = -1;
            for (j = 0; j < 26; j++) {
                flag++;
                if (fRotor[j][1] == m) {
                    m = fRotor[j][1];
                    break;
                }
            }
            buffer[i] = flag + 49 + '0';     //密文输出为字母
            flag = -1;     //flag回到初始值
            arr[0][0] = fRotor[25][0];     //快轮转动一个位置
            arr[0][1] = fRotor[25][1];
            for (j = 25; j > 0; j--) {
                fRotor[j][0] = fRotor[j - 1][0];
                fRotor[j][1] = fRotor[j - 1][1];
            }
            fRotor[0][0] = arr[0][0];
            fRotor[0][1] = arr[0][1];

            if (num % 26 == 0) {     //若快轮已转动一圈则中轮转动一个位置
                arr[0][0] = mRotor[25][0];     //中轮转动一个位置
                arr[0][1] = mRotor[25][1];
                for (j = 25; j > 0; j--) {
                    mRotor[j][0] = mRotor[j - 1][0];
                    mRotor[j][1] = mRotor[j - 1][1];
                }
                mRotor[0][0] = arr[0][0];
                mRotor[0][1] = arr[0][1];
            }

            if (num % (26 * 26) == 0) {     //若中轮已转动一圈则慢轮转动一个位置
                arr[0][0] = sRotor[25][0];     //慢轮转动一个位置
                arr[0][1] = sRotor[25][1];
                for (j = 25; j > 0; j--) {
                    sRotor[j][0] = sRotor[j - 1][0];
                    sRotor[j][1] = sRotor[j - 1][1];
                }
                sRotor[0][0] = arr[0][0];
                sRotor[0][1] = arr[0][1];
            }
        }
    }

    buffer[FileSize] = '\0';
}

//三转轮密码机解密函数
void DecryptFile (char buffer[], int FileSize) {
    int i, j, m;
    int flag = -1, num = 0;
    int sRotor[26][2];
    int mRotor[26][2];
    int fRotor[26][2];
    int arr[1][2];

    sRotor[0][0] = 24; sRotor[0][1] = 21;
    sRotor[1][0] = 25; sRotor[1][1] = 3;
    sRotor[2][0] = 26; sRotor[2][1] = 15;
    sRotor[3][0] = 1; sRotor[3][1] = 1;
    sRotor[4][0] = 2; sRotor[4][1] = 19;
    sRotor[5][0] = 3; sRotor[5][1] = 10;
    sRotor[6][0] = 4; sRotor[6][1] = 14;
    sRotor[7][0] = 5; sRotor[7][1] = 26;
    sRotor[8][0] = 6; sRotor[8][1] = 20;
    sRotor[9][0] = 7; sRotor[9][1] = 8;
    sRotor[10][0] = 8; sRotor[10][1] = 16;
    sRotor[11][0] = 9; sRotor[11][1] = 7;
    sRotor[12][0] = 10; sRotor[12][1] = 22;
    sRotor[13][0] = 11; sRotor[13][1] = 4;
    sRotor[14][0] = 12; sRotor[14][1] = 11;
    sRotor[15][0] = 13; sRotor[15][1] = 5;
    sRotor[16][0] = 14; sRotor[16][1] = 17;
    sRotor[17][0] = 15; sRotor[17][1] = 9;
    sRotor[18][0] = 16; sRotor[18][1] = 12;
    sRotor[19][0] = 17; sRotor[19][1] = 23;
    sRotor[20][0] = 18; sRotor[20][1] = 18;
    sRotor[21][0] = 19; sRotor[21][1] = 2;
    sRotor[22][0] = 20; sRotor[22][1] = 25;
    sRotor[23][0] = 21; sRotor[23][1] = 6;
    sRotor[24][0] = 22; sRotor[24][1] = 24;
    sRotor[25][0] = 23; sRotor[25][1] = 13;

    mRotor[0][0] = 26; mRotor[0][1] = 20;
    mRotor[1][0] = 1; mRotor[1][1] = 1;
    mRotor[2][0] = 2; mRotor[2][1] = 6;
    mRotor[3][0] = 3; mRotor[3][1] = 4;
    mRotor[4][0] = 4; mRotor[4][1] = 15;
    mRotor[5][0] = 5; mRotor[5][1] = 3;
    mRotor[6][0] = 6; mRotor[6][1] = 14;
    mRotor[7][0] = 7; mRotor[7][1] = 12;
    mRotor[8][0] = 8; mRotor[8][1] = 23;
    mRotor[9][0] = 9; mRotor[9][1] = 5;
    mRotor[10][0] = 10; mRotor[10][1] = 16;
    mRotor[11][0] = 11; mRotor[11][1] = 2;
    mRotor[12][0] = 12; mRotor[12][1] = 22;
    mRotor[13][0] = 13; mRotor[13][1] = 19;
    mRotor[14][0] = 14; mRotor[14][1] = 11;
    mRotor[15][0] = 15; mRotor[15][1] = 18;
    mRotor[16][0] = 16; mRotor[16][1] = 25;
    mRotor[17][0] = 17; mRotor[17][1] = 24;
    mRotor[18][0] = 18; mRotor[18][1] = 13;
    mRotor[19][0] = 19; mRotor[19][1] = 7;
    mRotor[20][0] = 20; mRotor[20][1] = 10;
    mRotor[21][0] = 21; mRotor[21][1] = 8;
    mRotor[22][0] = 22; mRotor[22][1] = 21;
    mRotor[23][0] = 23; mRotor[23][1] = 9;
    mRotor[24][0] = 24; mRotor[24][1] = 26;
    mRotor[25][0] = 25; mRotor[25][1] = 17;

    fRotor[0][0] = 1; fRotor[0][1] = 8;
    fRotor[1][0] = 2; fRotor[1][1] = 18;
    fRotor[2][0] = 3; fRotor[2][1] = 26;
    fRotor[3][0] = 4; fRotor[3][1] = 17;
    fRotor[4][0] = 5; fRotor[4][1] = 20;
    fRotor[5][0] = 6; fRotor[5][1] = 22;
    fRotor[6][0] = 7; fRotor[6][1] = 10;
    fRotor[7][0] = 8; fRotor[7][1] = 3;
    fRotor[8][0] = 9; fRotor[8][1] = 13;
    fRotor[9][0] = 10; fRotor[9][1] = 11;
    fRotor[10][0] = 11; fRotor[10][1] = 4;
    fRotor[11][0] = 12; fRotor[11][1] = 23;
    fRotor[12][0] = 13; fRotor[12][1] = 5;
    fRotor[13][0] = 14; fRotor[13][1] = 24;
    fRotor[14][0] = 15; fRotor[14][1] = 9;
    fRotor[15][0] = 16; fRotor[15][1] = 12;
    fRotor[16][0] = 17; fRotor[16][1] = 25;
    fRotor[17][0] = 18; fRotor[17][1] = 16;
    fRotor[18][0] = 19; fRotor[18][1] = 19;
    fRotor[19][0] = 20; fRotor[19][1] = 6;
    fRotor[20][0] = 21; fRotor[20][1] = 15;
    fRotor[21][0] = 22; fRotor[21][1] = 21;
    fRotor[22][0] = 23; fRotor[22][1] = 2;
    fRotor[23][0] = 24; fRotor[23][1] = 7;
    fRotor[24][0] = 25; fRotor[24][1] = 1;
    fRotor[25][0] = 26; fRotor[25][1] = 14;

    for (i = 0; i < FileSize; i++) {     //将文档所有A~Z的字母转为1~26的数字表示
        if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] -= 64;
        }
        else if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] -= 96;
        }
    }

    for (i = 0; i < FileSize; i++) {     //密明文转换
        num++;     //记录解密次数
        if (buffer[i] >= 1 && buffer[i] <= 26) {     //if条件跳过空格以及标点符号
            m = fRotor[buffer[i] - 1][1];
            for (j = 0; j < 26; j++) {
                flag++;
                if (fRotor[j][0] == m) {
                    m = fRotor[j][0];
                    break;
                }
            }
            m = mRotor[flag][1];
            flag = -1;
            for (j = 0; j < 26; j++) {
                flag++;
                if (mRotor[j][0] == m) {
                    m = mRotor[j][0];
                    break;
                }
            }
            m = sRotor[flag][1];
            flag = -1;
            for (j = 0; j < 26; j++) {
                flag++;
                if (sRotor[j][0] == m) {
                    m = sRotor[j][0];
                    break;
                }
            }
            buffer[i] = flag + 49 + '0';     //密文输出为字母
            flag = -1;     //flag回到初始值
            arr[0][0] = fRotor[25][0];     //快轮转动一个位置
            arr[0][1] = fRotor[25][1];
            for (j = 25; j > 0; j--) {
                fRotor[j][0] = fRotor[j - 1][0];
                fRotor[j][1] = fRotor[j - 1][1];
            }
            fRotor[0][0] = arr[0][0];
            fRotor[0][1] = arr[0][1];

            if (num % 26 == 0) {     //若快轮已转动一圈则中轮转动一个位置
                arr[0][0] = mRotor[25][0];     //中轮转动一个位置
                arr[0][1] = mRotor[25][1];
                for (j = 25; j > 0; j--) {
                    mRotor[j][0] = mRotor[j - 1][0];
                    mRotor[j][1] = mRotor[j - 1][1];
                }
                mRotor[0][0] = arr[0][0];
                mRotor[0][1] = arr[0][1];
            }

            if (num % (26 * 26) == 0) {     //若中轮已转动一圈则慢轮转动一个位置
                arr[0][0] = sRotor[25][0];     //慢轮转动一个位置
                arr[0][1] = sRotor[25][1];
                for (j = 25; j > 0; j--) {
                    sRotor[j][0] = sRotor[j - 1][0];
                    sRotor[j][1] = sRotor[j - 1][1];
                }
                sRotor[0][0] = arr[0][0];
                sRotor[0][1] = arr[0][1];
            }
        }
    }

    buffer[FileSize] = '\0';
}

/*
//测试加密
void EncryptFile (char buffer[], int FileSize, int key) {
    int i;
    for(i=0; i<FileSize; i++) {
        if (buffer[i] >= 'A' && buffer[i] <= 'Z' || buffer[i] >= 'a' && buffer[i] <= 'z')
        buffer[i] = buffer[i] + key;
    }
    buffer[FileSize] = '\0';
}
*/

//删除文件里空格标点的函数
void FileDelete () {
    FILE *fp, *fp2;
    int p;
    char filename[20];
    char filename2[20];
    printf("加密前,文件需要删去空格以及标点,请输入要加密文件路径: \n");
    scanf("%s", filename);
    printf("\n");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error!");
    }
    printf("删去空格以及标点后,请输入需加密文件的另存为路径: \n");
    scanf("%s", filename2);
    printf("\n");
    fp2 = fopen(filename2, "w");
    if((fp = fopen(filename,"r")) != NULL) {
        while((p = fgetc(fp)) != EOF ) {
            if(p >= 65 && p <= 90 || p >= 97 && p <= 122) {
                fputc(p,fp2);
            }
        }
    }
    fclose(fp);
    fclose(fp2);
}

//打开源文件
int openSrcFile (char **buffer) {
    FILE *MyfileSrc;     //源文件指针
    char filename[20];    //文件名数组
    long int FileSize;     //记录文件的长度
    long int i,j;
    printf("请输入要加密的文件路径：\n");
    scanf("%s", filename);
    printf("\n");
    if (!(MyfileSrc = fopen(filename,"rb"))) {
        printf("Error!");
    };
    fseek(MyfileSrc, 0, SEEK_END);     //判断文件长度
    FileSize = ftell(MyfileSrc);
    fseek(MyfileSrc, 0, SEEK_SET);
    *buffer = (char*)malloc(FileSize);     //像堆区申请FileSize大小内存空间
    fread(*buffer, 1, FileSize, MyfileSrc);     //读入文件
    fclose(MyfileSrc);
    return FileSize;
}

//储存加密文件
void saveDstFile (char *buffer, int FileSize) {
    FILE *MyfileDst;     //源文件指针
    char filename[20];     //文件名数组
    printf("请输入文件加密后要生成的路径：\n");
    scanf("%s", filename);
    printf("\n");
    if (!(MyfileDst = fopen(filename,"wb"))) {
        printf("Error!");
    }
    fprintf(MyfileDst, "%s", buffer);
    printf("加密完成，请查看加密生成文件\n");
    fclose(MyfileDst);
    free(buffer);     //释放内存空间
}

void main()
{
    FILE *MyfileDst;
    char *buffer;
    long int FileSize;     //记录文本的长度
    FileDelete ();     //删去源文件的空格和标点
    FileSize = openSrcFile(&buffer);     //读入源文件
    EncryptFile (buffer, FileSize);     //加密
    //DecryptFile (buffer, FileSize);     //解密
    saveDstFile (buffer, FileSize);
}
