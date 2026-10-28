<?php

// Bağlantı bilgileri ortam değişkenlerinden okunur; tanımlı değilse yerel XAMPP varsayılanları kullanılır.
// Gerçek bir sunucunun şifresini bu dosyaya yazmayın.
$vt_sunucu=getenv("DB_HOST") ?: "localhost";
$vt_kullanici=getenv("DB_USER") ?: "root";
$vt_sifre=getenv("DB_PASS") ?: "";
$vt_adi=getenv("DB_NAME") ?: "proje1";

mysqli_report(MYSQLI_REPORT_OFF);
$baglan=mysqli_connect($vt_sunucu,$vt_kullanici,$vt_sifre,$vt_adi);
if(!$baglan)
{
    // Hata ayrıntısı ziyaretçiye gösterilmez, sunucu loguna yazılır
    error_log("veritabanı bağlantısı başarısız: ".mysqli_connect_error());
    die("veritabanı bağlantısı başarısız...");
}
$baglan->set_charset("utf8mb4");

?>
