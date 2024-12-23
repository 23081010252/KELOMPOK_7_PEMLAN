void saveFile() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Gagal membuka file data!\n");
        return;
    }
    
    int i;
    for (i = 0; i < jumlahBarang; i++) {
        fprintf(file, "%d %s %s %d %s %s\n", barang[i].id, barang[i].nama, barang[i].kategori,
                barang[i].jumlah, barang[i].lokasi, barang[i].tanggal);
    }
    fclose(file);
}

void readFile() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return;

    jumlahBarang = 0;
    while (fscanf(file, "%d %49s %49s %d %49s %19s",
                  &barang[jumlahBarang].id, barang[jumlahBarang].nama, barang[jumlahBarang].kategori,
                  &barang[jumlahBarang].jumlah, barang[jumlahBarang].lokasi,
                  barang[jumlahBarang].tanggal) == 6) {
        jumlahBarang++;
    }
    fclose(file);
}
