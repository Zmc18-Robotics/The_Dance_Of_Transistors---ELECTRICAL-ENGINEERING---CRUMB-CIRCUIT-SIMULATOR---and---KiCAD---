// Program untuk menyalakan 13 lampu secara berurutan
// Arduino Nano
// Pin 3, 2, dan 13 memiliki delay khusus 1 detik

// Definisi pin lampu
int lampu[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 13}; // Pin untuk lampu 1-13
int jumlahLampu = 13;
int delayTime = 100; // Delay 100ms (0.1 detik) antar lampu
int delayKhusus = 1000; // Delay 1 detik untuk pin 3, 2, dan 13

void setup() {
  // Inisialisasi semua pin sebagai output
  for (int i = 0; i < jumlahLampu; i++) {
    pinMode(lampu[i], OUTPUT);
    digitalWrite(lampu[i], LOW); // Matikan semua lampu di awal
  }
}

void loop() {
  // Menyalakan lampu secara berurutan dari 1 sampai 13
  for (int i = 0; i < jumlahLampu; i++) {
    // Matikan semua lampu terlebih dahulu
    for (int j = 0; j < jumlahLampu; j++) {
      digitalWrite(lampu[j], LOW);
    }
    
    // Nyalakan lampu ke-i
    digitalWrite(lampu[i], HIGH);
    
    // Cek apakah pin saat ini adalah pin 3, 2, atau 13
    if (lampu[i] == 3 || lampu[i] == 2 || lampu[i] == 13) {
      delay(delayKhusus); // Delay 1 detik untuk pin khusus
    } else {
      delay(delayTime); // Delay 0.1 detik untuk pin lainnya
    }
  }
}