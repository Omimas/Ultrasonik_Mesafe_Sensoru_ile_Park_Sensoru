// Pin tanımlamaları
const int trigPin = 2;   // Ultrasonik sensörün tetik pini
const int echoPin = 3;   // Ultrasonik sensörün echo pini
const int buzzerPin = 4; // Buzzer pini

// Park sensörü eşik değerleri (cm olarak)
const int minDistance = 20;     // Minimum mesafe
const int maxDistance = 100;    // Maksimum mesafe

void setup() {
  // Pin modları ayarlanıyor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Seri haberleşme başlatılıyor
  Serial.begin(9600);
}

void loop() {
  // Mesafe ölçülüyor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Mesafe ekrana yazdırılıyor
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Mesafe kontrolü yapılıyor
  if (distance < minDistance) {
    // Engelleme sesi çalınıyor
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
  }
  
  // 2 saniye gecikme
  delay(2000);
}
