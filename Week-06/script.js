const anggotaForm = document.querySelector("#anggota");
const anggotaInput = document.querySelector("#input-jumlahAnggota");

function addAnggota(val) {
  function createInput(i) {
    const textbox = document.createElement("input");
    const label = document.createElement("label");
    const base = document.createElement("div");

    base.className = "form-floating mb-3"

    textbox.type = "text";
    textbox.className = "form-control";
    textbox.placeholder = `Anggota Kelompok ${i}`;
    textbox.id = `input-anggota${i}`;

    label.htmlFor = `input-anggota${i}`;
    label.textContent = `Anggota Kelompok ${i}`;
    base.append(textbox, label);
    return base;
  }

  if (anggotaForm.innerHTML != '' ) {
    anggotaForm.innerHTML = '';
    if (val == 0 || val == '') return;
  }

  const heading = document.createElement("h4");
  heading.textContent = "Anggota Kelompok";
  heading.className = 'mt-4 mb-3'
  anggotaForm.appendChild(heading);

  for (let i = 1; i <= val; i++) {
      anggotaForm.appendChild(createInput(i));
  }
  
  const button = document.createElement('button');
  button.textContent = "Daftar Kelompok";
  button.className = "btn btn-primary";
  anggotaForm.appendChild(button);
}

anggotaInput.addEventListener("change", (e) => {
  addAnggota(anggotaInput.value);
});
