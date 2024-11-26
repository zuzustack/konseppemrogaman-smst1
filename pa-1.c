#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXMHS 30
#define MAXNAMAMHS 255
// Buat Struct
struct Mahasiswa
{
    char nama[MAXNAMAMHS], kodeNilai[2];
    float eval1, eval2, eval3, nilai_uas, rata_rata;
    int max, min;
};

// Membuat variable global
struct Mahasiswa kelas_b[MAXMHS];
int current = 0;

// Deklarasi fungsi
void tambahMahasiswa();
void tampilkanMahasiswa();
void rankingKelas();
void terendahTertinggi();

int main()
{
    int pil;
    while (1)
    {
        printf("Program BAAK Mahasiswa\n");
        printf("Program dibuat oleh: Muhamad Ridwan Saputra - 3124600031\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("3. Ranking Kelas\n");
        printf("4. Option Lain\n");
        printf("0. Keluar Program\n");
        printf("Masukan pilihanmu: ");
        scanf("%d", &pil);
        fflush(stdin);
        switch (pil)
        {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            tampilkanMahasiswa();
            break;
        case 3:
            rankingKelas();
            break;
        case 4:
            terendahTertinggi();
            break;
        case 0:
            printf("Terimakasihh Telah Mencoba :D\n");
            return 0;
        default:
            printf("Pilihan tidak ditemukan coba lagi\n\n\n");
            break;
        }
    }
}

void terendahTertinggi()
{
    int input;
    struct Mahasiswa min, max;
    printf("1. Rata-rata Semua Mahasiswa\n");
    printf("2. Min|Max Eval-1\n");
    printf("3. Min|Max Eval-2\n");
    printf("4. Min|Max Eval-3\n");
    printf("5. Min|Max Nilai-UAS\n");
    printf("6. Min|Max Rata-rata\n");
    printf("0. Batal\n");
    printf("Pilih-pilihanmu: ");
    scanf("%d", &input);

    min = kelas_b[0];
    float total = 0;
    max = kelas_b[0];
    switch (input)
    {
    case 1:
        for (int i = 0; i < current; i++)
        {
            total += kelas_b[i].rata_rata;
        }
        total = total / current;
        printf("Rata-Rata Nilai Semua Mahasiswa: %.2f\n", total);

        break;
    case 2:
        for (int i = 1; i < current; i++)
        {
            // Max
            if (max.eval1 < kelas_b[i].eval1)
            {
                max = kelas_b[i];
            }

            // Min
            if (min.eval1 > kelas_b[i].eval1)
            {
                min = kelas_b[i];
            }
        }

        printf("Nilai Eval-1 Tertinggi: %s\n", max.nama);
        printf("Nilai Eval-1 Terendah: %s\n", min.nama);

        break;
    case 3:
        for (int i = 1; i < current; i++)
        {
            // Max
            if (max.eval2 < kelas_b[i].eval2)
            {
                max = kelas_b[i];
            }

            // Min
            if (min.eval2 > kelas_b[i].eval2)
            {
                min = kelas_b[i];
            }
        }
        printf("Nilai Eval-2 Tertinggi: %s\n", max.nama);
        printf("Nilai Eval-2 Terendah: %s\n", min.nama);
        break;
    case 4:
        for (int i = 1; i < current; i++)
        {
            // Max
            if (max.eval3 < kelas_b[i].eval3)
            {
                max = kelas_b[i];
            }

            // Min
            if (min.eval3 > kelas_b[i].eval3)
            {
                min = kelas_b[i];
            }
        }
        printf("Nilai Eval-3 Tertinggi: %s\n", max.nama);
        printf("Nilai Eval-3 Terendah: %s\n", min.nama);
        break;
    case 5:
        for (int i = 1; i < current; i++)
        {
            // Max
            if (max.nilai_uas < kelas_b[i].nilai_uas)
            {
                max = kelas_b[i];
            }

            // Min
            if (min.nilai_uas > kelas_b[i].nilai_uas)
            {
                min = kelas_b[i];
            }
            printf("Nilai UAS Tertinggi: %s\n", max.nama);
            printf("Nilai UAS Terendah: %s\n", min.nama);
        }
        break;
    case 6:
        for (int i = 1; i < current; i++)
        {
            // Max
            if (max.rata_rata < kelas_b[i].rata_rata)
            {
                max = kelas_b[i];
            }

            // Min
            if (min.rata_rata > kelas_b[i].rata_rata)
            {
                min = kelas_b[i];
            }

            printf("Nilai Rata-rata Tertinggi: %s\n", max.nama);
            printf("Nilai Rata-rata Terendah: %s\n", min.nama);
        }
        break;
    default:
        break;
    }
}

void tambahMahasiswa()
{
    if (current < MAXMHS)
    {
        struct Mahasiswa mhs;

        // Input Nama
        printf("Masukan nama Mahasiswa: ");
        fgets(mhs.nama, MAXNAMAMHS, stdin);

        // Eval-1
        mhs.nama[strcspn(mhs.nama, "\n")] = '\0';
        printf("Masukan nilai eval-1 Mahasiswa: ");
        scanf("%f", &mhs.eval1);
        printf("Masukan nilai eval-2 Mahasiswa: ");
        scanf("%f", &mhs.eval2);
        printf("Masukan nilai eval-3 Mahasiswa: ");
        scanf("%f", &mhs.eval3);
        printf("Masukan nilai UAS Mahasiswa: ");
        scanf("%f", &mhs.nilai_uas);
        fflush(stdin);

        // Search Max
        float tmp = round(mhs.eval1);
        if (tmp < round(mhs.eval2))
        {
            tmp = round(mhs.eval2);
        }

        if (tmp < round(mhs.eval3))
        {
            tmp = round(mhs.eval3);
        }

        if (tmp < round(mhs.nilai_uas))
        {
            tmp = round(mhs.nilai_uas);
        }

        mhs.max = tmp;

        // Min
        tmp = round(mhs.eval1);
        if (tmp > round(mhs.eval2))
        {
            tmp = round(mhs.eval2);
        }

        if (tmp > round(mhs.eval3))
        {
            tmp = round(mhs.eval3);
        }

        if (tmp > round(mhs.nilai_uas))
        {
            tmp = round(mhs.nilai_uas);
        }
        mhs.min = tmp;

        // Rata Rata
        mhs.rata_rata = (mhs.eval1 + mhs.eval2 + mhs.eval3 + mhs.nilai_uas) / 4;

        // Notasi Nilai
        if (mhs.rata_rata > 86)
        {
            mhs.kodeNilai[0] = 'A';
        }
        else if (mhs.rata_rata >= 81)
        {
            mhs.kodeNilai[0] = 'A';
            mhs.kodeNilai[1] = '-';
        }
        else if (mhs.rata_rata >= 76)
        {
            mhs.kodeNilai[0] = 'A';
            mhs.kodeNilai[1] = 'B';
        }
        else if (mhs.rata_rata >= 71)
        {
            mhs.kodeNilai[0] = 'B';
            mhs.kodeNilai[1] = '+';
        }
        else if (mhs.rata_rata >= 66)
        {
            mhs.kodeNilai[0] = 'B';
        }
        else if (mhs.rata_rata >= 61)
        {
            mhs.kodeNilai[0] = 'B';
            mhs.kodeNilai[1] = 'C';
        }
        else if (mhs.rata_rata >= 56)
        {
            mhs.kodeNilai[0] = 'C';
        }
        else if (mhs.rata_rata >= 41)
        {
            mhs.kodeNilai[0] = 'D';
        }
        else if (mhs.rata_rata >= 0)
        {
            mhs.kodeNilai[0] = 'E';
        }

        kelas_b[current] = mhs;
        current += 1;
    }
}

void rankingKelas()
{
    struct Mahasiswa tempMhs;
    struct Mahasiswa cpyKelas_b[MAXMHS];

    // Copy Array
    for (int i = 0; i < current; i++)
    {
        cpyKelas_b[i] = kelas_b[i];
    }

    // Bubble Sort
    for (int i = 0; i < current; i++)
    {
        for (int j = 0; j < current; j++)
        {
            if (cpyKelas_b[i].rata_rata > cpyKelas_b[j].rata_rata)
            {
                tempMhs = cpyKelas_b[i];
                cpyKelas_b[i] = cpyKelas_b[j];
                cpyKelas_b[j] = tempMhs;
            }
        }
    }

    printf("Ranking Kelas-B Berdasarkan Rata-rata: \n");
    printf("No\tNama\tEval-1\tEval-2\tEval-3\tUAS\tMIN\tMAX\tRata-rata\tHuruf\n");
    for (int i = 0; i < current; i++)
    {
        printf("%d.\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%d\t%d\t%.2f\t\t%s\n", i + 1, cpyKelas_b[i].nama, cpyKelas_b[i].eval1, cpyKelas_b[i].eval2, cpyKelas_b[i].eval3, cpyKelas_b[i].nilai_uas, cpyKelas_b[i].min, cpyKelas_b[i].max, cpyKelas_b[i].rata_rata, cpyKelas_b[i].kodeNilai);
    }
}

void tampilkanMahasiswa()
{
    printf("Kumpulan Kelas-B: \n");
    printf("No\tNama\tEval-1\tEval-2\tEval-3\tUAS\tMIN\tMAX\tRata-rata\tHuruf\n");
    for (int i = 0; i < current; i++)
    {
        printf("%d.\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%d\t%d\t%.2f\t\t%s\n", i + 1, kelas_b[i].nama, kelas_b[i].eval1, kelas_b[i].eval2, kelas_b[i].eval3, kelas_b[i].nilai_uas, kelas_b[i].min, kelas_b[i].max, kelas_b[i].rata_rata, kelas_b[i].kodeNilai);
    }
}