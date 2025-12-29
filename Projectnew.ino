#include <Servo.h>

const int pinTrig = 7;
const int pinEcho = 6;
const int pinServo = 9;
const int pinRelayMerah = 5; 
const int pinLEDHijau = 3;
const int pinLEDKuning = 4;
const int pinBuzzer = 11;

Servo palang;

// Variabel untuk menyimpan posisi servo saat ini
int posisi = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinRelayMerah, OUTPUT);
  pinMode(pinLEDHijau, OUTPUT);
  pinMode(pinLEDKuning, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  palang.attach(pinServo);
  
  // KONDISI AWAL
  palang.write(0); 
  digitalWrite(pinRelayMerah, HIGH); 
  digitalWrite(pinLEDHijau, LOW);
  digitalWrite(pinLEDKuning, LOW);
  
  Serial.println("Sistem Palang Smooth Siap...");
}

void loop() {
  long durasi, jarak;

  // Baca Sensor
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  durasi = pulseIn(pinEcho, HIGH);
  jarak = (durasi / 2) / 29.1;

  if (jarak > 0 && jarak < 15) { 
    Serial.println("Mobil Terdeteksi!");

    // 1. FASE PERSIAPAN (Kuning Nyala)
    digitalWrite(pinRelayMerah, LOW);  
    digitalWrite(pinLEDKuning, HIGH);  
    
    // 2. GERAKAN MEMBUKA
    for (posisi = 0; posisi <= 90; posisi += 1) { 
      palang.write(posisi);              
      delay(15); // Semakin besar angkanya, semakin lambat/halus gerakannya
    }
    
    // 3. FASE TERBUKA (Hijau Nyala)
    digitalWrite(pinLEDKuning, LOW);   
    digitalWrite(pinLEDHijau, HIGH);   
    
    delay(5000); // Tunggu mobil lewat

    // 4. FASE MENUTUP (Merah Nyala)
    digitalWrite(pinLEDHijau, LOW);    
    digitalWrite(pinRelayMerah, HIGH); 
    
    // GERAKAN MENUTUP
    for (posisi = 90; posisi >= 0; posisi -= 1) { 
      palang.write(posisi);              
      delay(15); // Samakan kecepatannya
    }
  }
}
