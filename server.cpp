#include "server.h"
#include "httplib.h"
#include <memory>

void ServerApp::iniciar() {

    sistema.adicionarAluno(std::make_shared<Aluno>(1,"Carlos","3A"));
    sistema.adicionarAluno(std::make_shared<Aluno>(2,"Maria","2B"));

    httplib::Server svr;

    svr.Get("/alunos", [&](const httplib::Request&, httplib::Response& res) {
        res.set_content(sistema.listarAlunosJSON(), "application/json");
    });

    svr.listen("0.0.0.0", 8080);
}