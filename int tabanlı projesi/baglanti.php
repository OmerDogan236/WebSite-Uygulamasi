<?php

$vt_sunucu="localhost";
$vt_kullanici="root";
$vt_sifre="";
$vt_adi="proje1";

$baglan=mysqli_connect($vt_sunucu,$vt_kullanici,$vt_sifre,$vt_adi);
$baglan->set_charset("utf8");
if(!$baglan)
{
    die("veritabanı bağlantısı başarısız...".mysqli_connect_error());  
}
else
{
    echo"veritabanı bağlantısı başarılı...";
}

?>