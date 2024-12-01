
document.addEventListener("DOMContentLoaded", () => {
    const wejscieZadania = document.getElementById("wejscieZadania");
    const dodajZadanie = document.getElementById("dodajZadanie");
    const listaZadan = document.getElementById("listaZadan");

    
    function dodajZadanieDoListy() {
        const tekstZadania = wejscieZadania.value.trim();
        if (tekstZadania === "") {
            alert("Wpisz treść zadania!");
            return;
        }

        
        const elementZadania = document.createElement("li");
        elementZadania.className = "zadanie";
        elementZadania.innerHTML = `
            <span>${tekstZadania}</span>
            <button class="przycisk-usun">Usuń</button>
        `;

        
        elementZadania.querySelector("span").addEventListener("click", () => {
            elementZadania.classList.toggle("zrealizowane");
        });

       
        elementZadania.querySelector(".przycisk-usun").addEventListener("click", () => {
            listaZadan.removeChild(elementZadania);
        });

        
        listaZadan.appendChild(elementZadania);

        
        wejscieZadania.value = "";
    }

    
    dodajZadanie.addEventListener("click", dodajZadanieDoListy);

    
    wejscieZadania.addEventListener("keypress", (event) => {
        if (event.key === "Enter") {
            dodajZadanieDoListy();
        }
    });
});
