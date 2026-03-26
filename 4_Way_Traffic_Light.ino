// Pin LED
// Utara
const int LHUpin = 2;
const int LKUpin = 3;
const int LMUpin = 4;

// Timur
const int LHTpin = 5;
const int LKTpin = 6;
const int LMTpin = 7;

// Selatan
const int LHSpin = 8;
const int LKSpin = 9;
const int LMSpin = 10;

// Barat
const int LHBpin = 11;
const int LKBpin = 12;
const int LMBpin = 13;

void setup() {
  pinMode(LHUpin, OUTPUT); pinMode(LKUpin, OUTPUT); pinMode(LMUpin, OUTPUT);
  pinMode(LHTpin, OUTPUT); pinMode(LKTpin, OUTPUT); pinMode(LMTpin, OUTPUT);
  pinMode(LHSpin, OUTPUT); pinMode(LKSpin, OUTPUT); pinMode(LMSpin, OUTPUT);
  pinMode(LHBpin, OUTPUT); pinMode(LKBpin, OUTPUT); pinMode(LMBpin, OUTPUT);

  semuaMerah();
}

void loop() {
  // Urutan searah jarum jam
  aktifkanSimpang(LMUpin, LKUpin, LHUpin); // Utara
  aktifkanSimpang(LMTpin, LKTpin, LHTpin); // Timur
  aktifkanSimpang(LMSpin, LKSpin, LHSpin); // Selatan
  aktifkanSimpang(LMBpin, LKBpin, LHBpin); // Barat
}

// Set semua lampu merah
void semuaMerah() {
  // Semua MERAH nyala
  digitalWrite(LMUpin, HIGH);
  digitalWrite(LMTpin, HIGH);
  digitalWrite(LMSpin, HIGH);
  digitalWrite(LMBpin, HIGH);

  // Kuning mati
  digitalWrite(LKUpin, LOW);
  digitalWrite(LKTpin, LOW);
  digitalWrite(LKSpin, LOW);
  digitalWrite(LKBpin, LOW);

  // Hijau mati
  digitalWrite(LHUpin, LOW);
  digitalWrite(LHTpin, LOW);
  digitalWrite(LHSpin, LOW);
  digitalWrite(LHBpin, LOW);
}

// Fungsi untuk 1 simpang aktif
void aktifkanSimpang(int merah, int kuning, int hijau) {
  semuaMerah();

  // Matikan merah di sisi aktif
  digitalWrite(merah, LOW);

  // Hijau nyala 5 detik
  digitalWrite(hijau, HIGH);
  delay(5000);
  digitalWrite(hijau, LOW);

  // Kuning kedip 3 kali
  for (int i = 0; i < 3; i++) {
    digitalWrite(kuning, HIGH);
    delay(300);
    digitalWrite(kuning, LOW);
    delay(300);
  }

  // Kembali merah
  digitalWrite(merah, HIGH);
}