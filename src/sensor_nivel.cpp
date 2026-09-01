#include "sensor_nivel.hpp"

#include <iomanip>
#include <sstream>
#include <utility>

namespace {
std::string formatarValor(double valor) {
    std::ostringstream saida;
    saida << std::setprecision(12) << valor;
    return saida.str();
}
}

SensorNivel::SensorNivel(
    std::string tagInicial,
    double valorInicial,
    std::string unidadeInicial
)
    : tag_(std::move(tagInicial)),
      valor_(valorInicial),
      unidade_(std::move(unidadeInicial)),
      ativo_(false),
      total_leituras_(0) {
}

std::string SensorNivel::tag() const {
    return tag_;
}

double SensorNivel::valor() const {
    return valor_;
}

std::string SensorNivel::unidade() const {
    return unidade_;
}

bool SensorNivel::estaAtivo() const {
    return ativo_;
}

void SensorNivel::ativar() {
    ativo_ = true;
}

void SensorNivel::desativar() {
    ativo_ = false;
}

bool SensorNivel::registrarLeitura(double valor) {
    if (!ativo_) {
        return false;
    }

    if (valor < 0.0 || valor > 100.0) {
        return false;
    }

    valor_ = valor;
    total_leituras_++;

    return true;
}

int SensorNivel::totalLeituras() const {
    return total_leituras_;
}

std::string SensorNivel::resumo() const {
    const std::string sufixo = unidade_.empty() ? "" : " " + unidade_;
    const std::string estado = ativo_ ? "ativo" : "inativo";

    return tag_ + ": "
        + formatarValor(valor_)
        + sufixo
        + " | "
        + estado
        + " | leituras: "
        + std::to_string(total_leituras_);
}