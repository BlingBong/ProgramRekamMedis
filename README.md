# Program Rekam Medis
## Project Akhir Algoritma Lanjut Menggunakan Bahasa C++

- Proyek ini mensimulasikan program sebuah data rekam medis pada sebuah rumah sakit bernama Uwu Hospital. Program ini berfungsi sebagai alat pencatatan data pasien, penampil data pasien, pencarian data pasien, pengurutan data pasien, dan penghitung pembayaran dari layanan kesehatan yang dipilih oleh pengguna.

- Pada tampilan awal, pengguna akan disambut oleh tampilan banner rumah sakit Uwu Hospital beserta daftar menu program. Pengguna diminta untuk memilih menu program dengan cara memasukkan angka sesuai dengan apa yang hendak pengguna lakukan.

   ![image](https://github.com/BlingBong/ProgramRekamMedis/assets/62862052/8d3c20fd-2246-4b22-bf71-d06feca5dbea)

- Apabila pengguna memilih menu nomor 1, tampilan akan beralih ke program untuk meng-input atau mencatat data pasien. Di menu ini, pengguna diminta memilih apakah data pasien yang akan dicatat adalah pasien rawat jalan atau pasien rawat inap. Jika memilih pasien rawat jalan, pengguna akan diminta untuk memasukkan berapa jumlah pasien yang akan didata beserta data-data pasien rawat jalan, seperti nama, jenis kelamin, alamat, serta memilih diagnosa yang telah tersedia pada tabel diagnosa. Setelah pengguna memasukkan data diagnosa, sistem akan secara otomatis mengisikan nama dokter yang menangani, harga obat serta total pembayaran. Kemudian, jika pengguna memilih pasien rawat inap, pengguna akan diminta untuk memasukkan berapa jumlah pasien yang akan didata beserta data-data pasien rawat inap, seperti nama, jenis kelamin, alamat, diagnosa, kelas ruangan yang telah tersedia dalam tabel daftar ruangan, lama menginap, serta apakah diperlukan tindakan operasi. Setelah pengguna memasukkan data diagnosa, sistem akan secara otomatis mengisikan nama dokter yang menangani dan harga obat. Sedangkan total pembayaran dihitung berdasar kelas ruangan dikali lama inap ditambah biaya operasi dan ditambah harga obat.

   ![image](https://github.com/BlingBong/ProgramRekamMedis/assets/62862052/ac51bb3a-d3c0-4506-8b17-5fc59895b536)

- Apabila pengguna memilih nomor 2, tampilan akan beralih ke program penampil data riwayat pasien. Pengguna diminta memilih akan menampilkan data riwayat pasien rawat jalan atau pasien rawat inap. Setelah pasien memilih akan ditampilkan data pasien beserta nomornya secara descending sesuai dengan waktu pencatatan data pasien tersebut, jika belum ada data pasien yang di-inputkan maka akan muncul pemberitahuan bahwa belum ada riwayat data pasien.

   ![image](https://github.com/BlingBong/ProgramRekamMedis/assets/62862052/e4038205-9244-48fe-8b5e-d959f0e983a0)

- Apabila pengguna memilih nomor 3, tampilan akan beralih ke program searching atau pencarian. Pengguna diminta untuk memilih akan melakukan pencarian data pasien berdasar nama pasien atau nama dokter. Setelah pengguna memilih, pengguna akan diminta untuk memasukkan nama yang dicari, lalu akan ditampilkan hasil pencarian dari data pasien rawat inap dan data pasien rawat jalan. Jika pada data pasien tidak ditemukan nama yang dicari, maka akan muncul pemberitahuan bahwa nama yang dicari tidak ada di daftar.

   ![image](https://github.com/BlingBong/ProgramRekamMedis/assets/62862052/374223d2-fcaf-49e8-b301-6ac4734cf6ca)

- Apabila pengguna memilih nomor 4, tampilan akan beralih ke program sorting atau pengurutan. Pengguna diminta untuk memilih akan melakukan pengurutan berdasar nama, jenis kelamin, alamat, dokter/diagnosa, atau pembayaran. Setelah pengguna memilih, akan ditampilkan hasil pengurutan berdasar kriteria yang dipilih pengguna secara ascending. Jika pada data pasien tidak ditemukan satupun data pasien, maka akan muncul pemberitahuan bahwa data pasien kosong.

   ![image](https://github.com/BlingBong/ProgramRekamMedis/assets/62862052/279e259e-7a27-461b-9673-0beb1d5678ad)

- Apabila pengguna memilih nomor 5, tampilan akan beralih ke program pembayaran. Pengguna diminta untuk memasukkan nama dan alamat pasien yang akan dibayarkan biaya perawatannya. Jika data pasien tidak ditemukan, maka akan muncul pemberitahuan bahwa pasien yang dicari tidak ada di daftar, dan pengguna diminta untuk melakukan pencarian lagi. Jika data pasien ditemukan maka akan ditampilkan data pasien. Jika data pasien ditemukan di daftar pasien rawat jalan dan rawat inap, pengguna akan diminta untuk memilih data pasien yang di daftar mana yang akan dibayarkan biaya perawatannya. Selanjutnya, pengguna memasukkan nomor pasien yang akan dibayarkan biaya perawatannya sesuai dengan data yang ditampilkan. Untuk meyakinkan pengguna, akan muncul pemberitahuan apakah data yang ditampilkan dan dipilih sudah sesuai dengan yang dicari. Jika tidak, maka pencarian pasien akan diulangi. Jika ya, maka akan ditampilkan total pembayaran dan metode pembayaran. Pengguna memilih akan melakukan pembayaran dengan metode tunai atau transfer. Jika pengguna memilih tunai, maka pengguna akan diminta untuk memasukkan nominal uang. Jika nominal uang mencukupi akan muncul pemberitahuan bahwa pembayaran berhasil beserta uang kembalian. Jika nominal uang tidak mencukupi maka akan muncul pemberitahuna bahwa nominal uang kurang, lalu pemilihan metode pembayaran akan diulangi. Sedangkan jika pengguna memilih metode transfer, maka pengguna akan diminta memasukkan nomor rekening. Lalu akan muncul pemberitahuan bahwa pembayaran berhasil dan saldo pada nomor rekening tersebut akan dikurangi sebesar total pembayaran. Setelah total pembayaran pasien dibayarkan maka keterangan total pembayaran pada data pasien akan menjadi 0 Rupiah.

   ![image](https://github.com/BlingBong/ProgramRekamMedis/assets/62862052/fd4e322b-f1fe-4b64-b177-70dfb4486d6a)

- Apabila pengguna memilih nomor 6, maka akan muncul ucapan terimakasih dan program selesai.
