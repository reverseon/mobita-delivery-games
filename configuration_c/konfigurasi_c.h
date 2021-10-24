typedef struct jumlahPesanan jumlahPesanan;
struct jumlahPesanan
{
    int time;
    char pickup;
    char dropoff;
    char itemtype;
    int timelimit;
};

jumlahPesanan* konfigurasiC(int* arrlen);
// Mereturn array of struct yang terbentuk
// lalu menggantii arrlen menjadi panjang array of struct
