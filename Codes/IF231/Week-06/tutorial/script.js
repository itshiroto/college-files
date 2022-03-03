function ubahNodeValue() {
  a = document.getElementById("menu").getElementsByTagName("a")[2].firstChild;
  a.nodeValue = "Foto";
  b = "<p>Galeri berubah menjadi Foto</p>";
  document.getElementById("sisip").innerHTML = b;
}

function periksaProperti() {
  a = document.getElementById("menu").getElementsByTagName("a")[2].firstChild;
  b = "<p>nodeName : " + a.nodeName;
  b += "<br />nodeType : " + a.nodeType;
  b += "<br />nodeValue : " + a.nodeValue + "</p>";
  document.getElementById("sisip").innerHTML = b;
}

function ubahAtribut() {
  a = document.getElementById("menu").getElementsByTagName("li")[3].firstChild;
  a.setAttribute("href", "https://facebook.com");
  b = "<p>Link dari Galeri telah berubah dari galeri.html menjadi facebook.com</p>";
  document.getElementById("sisip").innerHTML = b;
}

function tambahAnak() {
  a = document.createElement("li");
  b = document.createTextNode("Tambah anak lagi");
  a.appendChild(b);

  c = document.getElementById("menu");
  c.appendChild(a);

  d = "<p> anak dari menu bertambah</p>";
  document.getElementById("sisip").innerHTML = d;
}

function bikinKembaran() {
  a = document.getElementById("menu").getElementsByTagName("li")[3];
  b = a.cloneNode(true);
  c = document.getElementById("menu");
  c.appendChild(b);

  d = "<p>Galeri berhasil di kloning dan jadi anak bontot</p>";
  document.getElementById("sisip").innerHTML = d;
}

function sisipAnak() {
  a = document.createElement("li");
  b = document.createTextNode("Anak Sisipan");
  a.appendChild(b);
  c = document.getElementById("menu");
  d = c.getElementsByTagName("li")[4]
  c.insertBefore(a,d);

  e = "<p>Berhasil nyisipin anak antara Galeri dan Testimonial</p>";
  document.getElementById("sisip").innerHTML = e;
}

function gantiAnak() {
  a = document.getElementById("menu");
  b = a.getElementsByTagName("li")[5];
  c = document.createElement("li");
  d = document.createTextNode("Anak Baru");

  c.appendChild(d);
  a.replaceChild(c,b);

  d = "<p>Menu yang ke-6 diganti jadi Anak Baru</p>";
  document.getElementById("sisip").innerHTML = d;
}
