#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void play_game()
{
    char *questions[] = {
        "Pulau Komodo terletak di provinsi?\nA. Bali\nB. NTT\nC. NTB\nD. Jawa Timur\n",
        "Siapa presiden indonesia ketiga?\nA. BJ. Habibi\nB. Soekarno\nC. Joko Widodo\nD. Abdurrahman Wahid\n",
        "Apa singkatan dari MPR?\nA. Majelis Perwakilan Rakyat\nB. Majelis Permusyawaratan Rakyat\nC. Majelis Perhimpunan Rakyat\nD. Majelis Perserikatan Rakyat\n",
        "Pada tanggal berapakah Hari Lahir Pancasila diperingati?\nA. 17 Agustus\nB. 1 Maret\nC. 1 Juni\nD. 1 Desember\n",
        "Tanah yang baik untuk pertanian adalah… \nA. Humus\nB. Pasir\nC. Liat\nD. Cadas\n"};

    char *answers[] = {
        "B",
        "A",
        "B",
        "C",
        "A"};
    int score = 0;
    int points[] = {
        20,
        10,
        20,
        20,
        30};

    printf("Score Anda = %d\n", score);

    for (int i = 0; i < 5; i++)
    {
        printf("Pertanyaan %d:\n%s", i + 1, questions[i]);

        char answer[2];
        scanf("%s", answer);
        if (strcmp(answer, answers[i]) == 0)
        {
            score += points[i];
            printf("-----------------------\n");
            printf("Jawaban Anda benar!\n");
            printf("-----------------------\n");
        }
        else
        {
            printf("-----------------------\n");
            printf("Jawaban Anda salah.\n");
            printf("-----------------------\n");
        }
    }
    printf("Skor Anda: %d\n", score);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("gagal masuk");
    }

    char usernameinput[20], passwordinput[20];
    strcpy(usernameinput, argv[1]);
    strcpy(passwordinput, argv[2]);

    // untuk memasukan password ke dalam file bin
    /**FILE *fpw = fopen("database/login.bin", "wb");
    char login[20] = "Alfi@Contoh";

    fwrite(login, sizeof(char), sizeof(login) / sizeof(char), fpw);

    fclose(fpw);*/
    FILE *fpr;
    if ((fpr = fopen("database/login.bin", "rb")) == NULL)
    {
        printf("Couldn't open database");
        return EXIT_FAILURE;
    }
    char akun[20];
    fread(akun, sizeof(akun), sizeof(akun) / sizeof(char), fpr);
    fclose(fpr);

    char *string[3];
    char username[20], password[20];
    int ctrl = 0;

    string[0] = strtok(akun, "@");
    while (string[ctrl++] != NULL)
    {
        string[ctrl] = strtok(NULL, "@");
    }

    strcpy(username, string[0]);
    strcpy(password, string[1]);

    if (strcmp(usernameinput, username) == 0 && strcmp(passwordinput, password) == 0)
    {
        printf("Selamat Datang %s\n", username);
        play_game();
    }
    else
    {
        printf("Username dan password anda salah");
    }

    return 0;
}