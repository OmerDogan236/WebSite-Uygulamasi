<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {font-family: Arial, Helvetica, sans-serif;}
* {box-sizing: border-box;}

input[type=text], select, textarea {
  width: 100%;
  padding: 12px;
  border: 1px solid #ccc;
  border-radius: 4px;
  box-sizing: border-box;
  margin-top: 6px;
  margin-bottom: 16px;
  resize: vertical;
}

input[type=submit] {
  background-color: #04AA6D;
  color: white;
  padding: 12px 20px;
  border: none;
  border-radius: 4px;
  cursor: pointer;
}

input[type=submit]:hover {
  background-color: #45a049;
}

.container {
  border-radius: 5px;
  background-color: #f2f2f2;
  padding: 20px;
}
</style>
</head>
<body>

<h3>KULLANICI İLETİŞİM FORMU</h3>

<div class="container">
  <form action="iletisim.php" method="post">

    <label for="fname">Ad Soyad</label>
    <input type="text" id="fname" name="isim" placeholder="ad soyad..">
    
    <label for="lname">Telefon</label>
    <input type="text" id="lname" name="tel" placeholder="telefon..">
    
    <label for="country">E-mail</label>
    <input type="text" id="lname" name="mail" placeholder="e-mail..">
    
    <label for="country">Konu</label>
    <input type="text" id="lname" name="konu" placeholder="konu..">
    
    
    <label for="subject">Mesaj</label>
    <textarea id="subject" name="mesaj" placeholder="mesajınızı giriniz.." style="height:200px"></textarea>
    
    <input type="submit" value="Gönder">

    

  </form>
</div>

</body>
</html>

<?php

include("baglanti.php");

if(isset($_POST["isim"],$_POST["tel"],$_POST["mail"],$_POST["konu"],$_POST["mesaj"]))
{
  $adsoyad=$_POST["isim"];
  $telefon=$_POST["tel"];
  $email=$_POST["mail"];
  $konu=$_POST["konu"];
  $mesaj=$_POST["mesaj"];
  // Form verisi sorguya doğrudan eklenmiyor; hazırlanmış sorgu SQL enjeksiyonunu engeller
  $ekle=$baglan->prepare("INSERT INTO iletisim(adsoyad,telefon,email,konu,mesaj) VALUES (?,?,?,?,?)");
  $ekle->bind_param("sssss",$adsoyad,$telefon,$email,$konu,$mesaj);

if($ekle->execute())
{

  echo "<script> alert ('mesaj gönderildi..') </script>";

}

$ekle->close();
}
?>