class SensorNivel:
    def __init__(
        self,
        tag: str,
        valor: float,
        unidade: str = ""
    ):
        self._tag = tag
        self._valor = valor
        self._unidade = unidade
        self._ativo = False
        self._total_leituras = 0

    @property
    def tag(self) -> str:
        return self._tag

    @property
    def valor(self) -> float:
        return self._valor

    @property
    def unidade(self) -> str:
        return self._unidade

    @property
    def ativo(self) -> bool:
        return self._ativo

    def ativar(self) -> None:
        self._ativo = True

    def desativar(self) -> None:
        self._ativo = False

    @property
    def total_leituras(self):
        return self._total_leituras

    def registrar_leitura(self, valor) -> bool:
        if not self._ativo:
            return False

        if valor < 0.0 or valor > 100.0:
            return False

        self._valor = valor
        self._total_leituras += 1

        return True

    def resumo(self) -> str:
        sufixo = f" {self._unidade}" if self._unidade else ""
        estado = "ativo" if self._ativo else "inativo"
        return (
            f"{self._tag}: {self._valor:g}{sufixo}"
            f" | {estado}"
            f" | leituras: {self._total_leituras}"
    )