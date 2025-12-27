#include <Servo.h>

// Definisi Pin
const int pinTrig = 7;
const int pinEcho = 6;
const int pinServo = 9;
const int pinRelayMerah = 5; // Relay yang mengatur LED Merah
const int pinLEDHijau = 3;
const int pinLEDKuning = 4;
const int pinBuzzer = 11;

Servo palang;

void setup() {
  // Inisialisasi Serial Monitor
  Serial.begin(9600);

  // Inisialisasi Pin
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinRelayMerah, OUTPUT);
  pinMode(pinLEDHijau, OUTPUT);
  pinMode(pinLEDKuning, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  // Inisialisasi Servo
  palang.attach(pinServo);
  
  // Kondisi Awal (Palang Tertutup)
  palang.write(0); 
  digitalWrite(pinRelayMerah, HIGH); // LED Merah Nyala (Relay Aktif)
  digitalWrite(pinLEDHijau, LOW);
  digitalWrite(pinLEDKuning, LOW);
  
  Serial.println("Sistem Palang Parkir Ready...");
}

void loop() {
  long durasi, jarak;

  // Membaca Jarak dari Sensor Ultrasonik
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  durasi = pulseIn(pinEcho, HIGH);
  jarak = (durasi / 2) / 29.1;

  Serial.print("Jarak Objek: ");
  Serial.print(jarak);
  Serial.println(" cm");

  // Logika Palang Parkir
  if (jarak > 0 && jarak < 15) { // Jika ada mobil terdeteksi (kurang dari 15cm)
    Serial.println("Mobil Terdeteksi! Membuka Palang...");

    // Bunyi Buzzer singkat sebagai tanda
    digitalWrite(pinBuzzer, HIGH);
    delay(200);
    digitalWrite(pinBuzzer, LOW);

    // Proses Membuka
    digitalWrite(pinRelayMerah, LOW);  // Matikan LED Merah via Relay
    digitalWrite(pinLEDKuning, HIGH); // Kuning nyala saat proses gerak
    palang.write(90);                 // Buka palang (90 derajat)
    delay(1000);                      // Tunggu palang selesai naik
    
    digitalWrite(pinLEDKuning, LOW);
    digitalWrite(pinLEDHijau, HIGH);  // Hijau Nyala (Silahkan Masuk)
    
    delay(5000); // Waktu tunggu mobil lewat (5 detik)
    
    Serial.println("Menutup Palang...");
    digitalWrite(pinLEDHijau, LOW);
    digitalWrite(pinLEDKuning, HIGH);
    palang.write(0);                  // Tutup palang (0 derajat)
    delay(1000);
    
    digitalWrite(pinLEDKuning, LOW);
    digitalWrite(pinRelayMerah, HIGH); // LED Merah Nyala Kembali
  }

  delay(200); // Delay kecil untuk stabilitas sensor
}
