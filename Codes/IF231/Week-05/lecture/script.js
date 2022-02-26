let data = [];
let namaUser = prompt("Who are you?");
const submitBtn = document.querySelector("#form-submit");
const createName = document.querySelector("#created-name");

createName.innerText = namaUser;

function addToArray(mainDB) {
    let name, address, phone, choice;
    name = document.querySelector("#form-name").value;
    address = document.querySelector("#form-address").value;
    phone = document.querySelector("#form-phone").value;
    choice = document.querySelector("#form-category").value;
    mainDB.push([name, address, phone, choice]);
    updateLength(mainDB.length);
    appendTable([name, address, phone, choice]);
    console.log(mainDB);
}

function appendTable(element) {
    const table = document.querySelector("#table");
    const row = table.insertRow(-1);
    const name = row.insertCell(0);
    const address = row.insertCell(1);
    const phone = row.insertCell(2);
    const choice = row.insertCell(3);

    name.innerText = element[0];
    address.innerText = element[1];
    phone.innerText = element[2];
    choice.innerText = element[3];
    
}

function updateLength(len) {
    const counter = document.querySelector("#count");
    counter.innerText = len;
}

submitBtn.addEventListener("click", () => addToArray(data));

