from sensor_nivel import SensorNivel


def main():
    sensor = SensorNivel("LT-101", 42.5, "%")

    print(sensor.resumo())

    sensor.ativar()
    aceita = sensor.registrar_leitura(55.0)

    print(f"Leitura aceita: {aceita}")
    print(sensor.resumo())


if __name__ == "__main__":
    main()