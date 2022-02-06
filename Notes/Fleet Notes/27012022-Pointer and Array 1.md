# 27012022-Pointer and Array 1
27012022-2240
Tags: #pointer #array

## Array
- Suatu data yang memiliki tipe data yang sama dan disimpan di memori secara tersusun.
- Sifatnya dalam C/C++:
	- Harus memiliki tipe data yang sama dengan ukuran yang sama
	- Menggunakan integer sebagai index
	- **SEMUA** tipe data, struct, dan class dapat digunakan sebagai Array kecuali `void`.
	- Index pertama dari array tersebut dimulai dari angka 0.
- Array digunakan untuk mengorganisir suatu variabel yang memiliki tujuan yang sama
	- Contoh: Memroses 1000 nilai mahasiswa
		- Ketimbang membuat variabel sendiri satu persatu untuk setiap mahasiswa, kita dapat menggunakan array dengan syntax `nilaiMahasiswa[1000]`
		- Sehingga kita tidak perlu mengingat masing-masing nama variabel dari nilai mahasiswa tersebut, dan dapat menggunakan suatu angka integer (`nilaiMahasiswa[20]`) untuk mengakses nilainya.

### Penggunaan
Format deklarasi:
```c
// tipe_data nama_variabel[panjang]
int student_score[1000];
```
Mengisi nilai:
```c
// nama_variabel[index] dimana indexnya adalah angka integer
student_score[20] = 20;
```

Mengakses nilai:
```c
// Kurang lebih sama seperti proses pengisian nilai
int nilai = student_score[20];
```


## Pointer
- Sebuah variabel yang menyimpan alamat dari variabel yang ditunjuk.
- Sifatnya dalam C/C++:
	- Pointer **menyimpan alamat**, bukan nilai.
	- Berdasarkan alamat tersebut, kita bisa mengakses nilainya.
	- Jika nilai variabel dari alamatnya berubah, maka variabel pointer yang menunjuknya juga akan berpengaruh
	- Hanya bisa menunjuk variabel yang memiliki tipe data yang sama.
- Kenapa dan kapan dipakai?
	- Kita mau *mengoper* variabel ke suatu function dan memodifikasi variabel tersebut secara langsung tanpa perlu membuat duplikatnya.
	- Pointer digunakan ketika kita mau melacak perubahan yang terjadi pada suatu variabel dalam suatu posisi memori.
	
### Penggunaan
> INGAT,
> & (ampersand) = mengakses alamatnya
> * (bintang) = mengakses nilai dari pointer/alamat

Format deklarasi:
```c
// tipe_data *name
int *data
```
Mengisi nilai:
```c
data = &var // jika variabelnya udah ada
int *ptData = &data // bisa juga kalau sekalian dengan deklarasi variabel
```

Mengakses nilai:
```c
printf("%d", data); // akan mengoutput alamatnya di memori
printf("%d", *data); // akan mengoutput nilai dari alamatnya
```

