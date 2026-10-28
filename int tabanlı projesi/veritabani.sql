-- iletisim.php formunun kullandığı tablo (XAMPP / phpMyAdmin üzerinden içe aktarılabilir)
CREATE DATABASE IF NOT EXISTS proje1 CHARACTER SET utf8mb4 COLLATE utf8mb4_turkish_ci;
USE proje1;

CREATE TABLE IF NOT EXISTS iletisim (
  id INT AUTO_INCREMENT PRIMARY KEY,
  adsoyad VARCHAR(100) NOT NULL,
  telefon VARCHAR(20),
  email VARCHAR(100),
  konu VARCHAR(150),
  mesaj TEXT,
  tarih TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
