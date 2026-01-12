unsigned long timerMobilHilang = 0;
bool mobilTerdeteksi = false;

void loop() {
  long durasi = 0;
  long jarak = 0;

  // Mengukur jarak
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  durasi = pulseIn(pinEcho, HIGH);
  jarak = (durasi / 2) / 29.1;

  if (jarak > 0 && jarak < 15) {
    // Mobil terdeteksi
    mobilTerdeteksi = true;
    timerMobilHilang = millis();  // Reset timer
    Serial.println("Mobil Terdeteksi!");

    // Fase Persiapan
    digitalWrite(pinRelayMerah, LOW);
    digitalWrite(pinLEDKuning, HIGH);
    digitalWrite(pinBuzzer, HIGH);

    // Gerak membuka
    if (posisi < 90) {
      for (; posisi <= 90; posisi++) {
        palang.write(posisi);
        delay(15);
      }
    }

    digitalWrite(pinLEDKuning, LOW);
    digitalWrite(pinLEDHijau, HIGH);
    digitalWrite(pinBuzzer, LOW);

  } else {
    // Mobil tidak terdeteksi
    mobilTerdeteksi = false;
    
    //menutup 
    if (millis() - timerMobilHilang >= 3000 && posisi > 0) {
      digitalWrite(;pinLEDHijau, LOW);
      digitalWrite(pinRelayMerah, HIGH);
      digitalWrite(pinBuzzer, HIGH);

      for (; posisi >= 0; posisi--) {
        palang.write(posisi);
        delay(15);
      }

      digitalWrite(pinBuzzer, LOW);
    }
  }
}


