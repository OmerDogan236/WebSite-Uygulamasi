# WebSite-Uygulamasi – FitPlan

İnternet Tabanlı Programlama dersi dönem projesi. FitPlan; vücut ölçülerinden yağ oranını hesaplayan ve sonuca göre beslenme programı öneren bir web sitesidir.

## İçerik

| Klasör / dosya | Açıklama |
|---|---|
| `int tabanlı projesi/FitWebSite/` | Sitenin HTML / CSS arayüzü |
| `int tabanlı projesi/iletisim.php` | İletişim formu; mesajları MySQL'e kaydeder |
| `int tabanlı projesi/baglanti.php` | Veritabanı bağlantısı |
| `int tabanlı projesi/veritabani.sql` | Formun kullandığı tablo |
| `int tabanlı projesi/int tabanlı projesi/` | Proje raporu, sunum ve tanıtım videosu |

## Teknolojiler

HTML, CSS, JavaScript, PHP, MySQL

## Çalıştırma (XAMPP)

1. XAMPP'te Apache ve MySQL'i başlatın.
2. phpMyAdmin'den `veritabani.sql` dosyasını içe aktarın.
3. `int tabanlı projesi` klasörünü `htdocs` altına kopyalayıp `http://localhost/.../iletisim.php` adresini açın.

Veritabanı bilgileri `DB_HOST`, `DB_USER`, `DB_PASS`, `DB_NAME` ortam değişkenlerinden okunur; tanımlı değilse XAMPP varsayılanları (`root`, şifresiz) kullanılır. Form verileri hazırlanmış sorgularla (prepared statement) kaydedilir.
