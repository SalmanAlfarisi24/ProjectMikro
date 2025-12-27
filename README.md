Seluruh komponen proyek Palang Pintu Parkir menggunakan Arduino Uno, Sensor Ultrasonik, Servo, Buzzer, LED, dan Relay 1 Channel.
Berikut adalah urutan pemasangan kabelnya secara lengkap:
1. Jalur Daya Utama (Breadboard)
 * Tarik kabel dari pin 5V Arduino ke jalur merah (+) di samping breadboard.
 * Tarik kabel dari pin GND Arduino ke jalur biru (-) di samping breadboard.
   (Semua komponen akan mengambil daya (+) dan (-) dari jalur ini).
2. Sensor Ultrasonik (HC-SR04)
 * Pin VCC sensor ke jalur merah (+) breadboard.
 * Pin Trig sensor ke Pin 7 Arduino.
 * Pin Echo sensor ke Pin 6 Arduino.
 * Pin GND sensor ke jalur biru (-) breadboard.
3. Motor Servo (SG90)
 * Kabel Oranye (Sinyal) ke Pin 9 Arduino.
 * Kabel Merah (VCC) ke jalur merah (+) breadboard.
 * Kabel Cokelat/Hitam (GND) ke jalur biru (-) breadboard.
4. Relay 1 Channel (Mengatur LED Merah)
Sisi Input (Ke Arduino):
 * Pin VCC Relay ke jalur merah (+) breadboard.
 * Pin GND Relay ke jalur biru (-) breadboard.
 * Pin IN (Sinyal) Relay ke Pin 5 Arduino.
Sisi Output (Saklar LED Merah):
 * Hubungkan kabel jumper dari jalur merah (+) breadboard ke terminal COM (tengah) pada blok terminal biru Relay.
 * Hubungkan terminal NO (Normally Open) pada Relay ke kaki panjang (Anoda) LED Merah. (Gunakan resistor 220 ohm di antara terminal NO dan LED agar LED tidak putus).
 * Hubungkan kaki pendek (Katoda) LED Merah ke jalur biru (-) breadboard.
5. LED Hijau & Kuning (Indikator Tambahan)
 * LED Hijau: Kaki panjang ke Pin 3 Arduino (melalui resistor 220 ohm), kaki pendek ke jalur biru (-) breadboard.
 * LED Kuning: Kaki panjang ke Pin 4 Arduino (melalui resistor 220 ohm), kaki pendek ke jalur biru (-) breadboard.
6. Buzzer (Alarm)
 * Kaki Positif (+) Buzzer ke Pin 11 Arduino.
 * Kaki Negatif (-) Buzzer ke jalur biru (-) breadboard.
Cara Kerja Rangkaian Ini:
 * Kondisi Standby: Palang (Servo) tertutup (0 derajat). Relay aktif sehingga LED Merah menyala (Tanda Berhenti).
 * Mobil Terdeteksi: Saat sensor Ultrasonik membaca jarak < 15cm, Buzzer berbunyi singkat, Servo bergerak membuka (90 derajat), Relay memutus arus sehingga LED Merah mati, dan LED Hijau menyala (Tanda Silakan Masuk).
 * Mobil Lewat: Setelah jeda waktu tertentu, palang kembali menutup, LED Hijau mati, dan Relay kembali menyalakan LED Merah.
Pastikan semua sambungan kabel kencang dan tidak ada kabel terbuka yang saling bersentuhan (korsleting).
