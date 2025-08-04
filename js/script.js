function enviarDados() {
    const aluno = {
        nome: document.getElementById("nome").value,
        d1: parseInt(document.getElementById("d1").value),
        d2: parseInt(document.getElementById("d2").value),
        d3: parseInt(document.getElementById("d3").value),
        d4: parseInt(document.getElementById("d4").value),
        d5: parseInt(document.getElementById("d5").value),
        frequencia: parseInt(document.getElementById("frequencia").value)
    };

    fetch("http://localhost:8080/api/aluno", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(aluno)
    })
    .then(res => res.text())
    .then(msg => {
        alert(msg);
        document.getElementById("nome").value = "";
        document.getElementById("d1").value = "";
        document.getElementById("d2").value = "";
        document.getElementById("d3").value = "";
        document.getElementById("d4").value = "";
        document.getElementById("d5").value = "";
        document.getElementById("frequencia").value = "";
    })
    .catch(err => alert("Erro: " + err));
}

function listarAlunos() {
    fetch("http://localhost:8080/api/alunos")
    .then(res => res.json())
    .then(data => {
        alert("Lista completa carregada!");
        let html = "<h3>All Students:</h3><ul>";
        data.forEach(a => {
            html += `<li>${a.nome} - Média: ${a.media} - Frequência: ${a.frequencia}%</li>`;
        });
        html += "</ul>";
        document.getElementById("resultado").innerHTML = html;
    })
    .catch(err => alert("Erro: " + err));
}

function listarAcimaMedia() {
    fetch("http://localhost:8080/api/acimaMedia")
    .then(res => res.json())
    .then(data => {
        alert("Lista de alunos acima da média carregada!");
        let html = "<h3>Alunos acima da média da turma:</h3><ul>";
        data.forEach(a => {
            html += `<li>${a.nome} - Média: ${a.media}</li>`;
        });
        html += "</ul>";
        document.getElementById("resultado").innerHTML = html;
    })
    .catch(err => alert("Erro: " + err));
}

function listarBaixaFrequencia() {
    fetch("http://localhost:8080/api/baixaFrequencia")
    .then(res => res.json())
    .then(data => {
        alert("Lista de alunos com baixa frequência carregada!");
        let html = "<h3>Alunos com frequência abaixo de 75%:</h3><ul>";
        data.forEach(a => {
            html += `<li>${a.nome} - Frequência: ${a.frequencia}%</li>`;
        });
        html += "</ul>";
        document.getElementById("resultado").innerHTML = html;
    })
    .catch(err => alert("Erro: " + err));
}