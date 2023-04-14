# InternetOfHives
Internet of Hives is a DIY bee hive monitoring solution

IoH consists of three components:

The Hive Monitor:
    Based on Xiao nrf52840/nrf52840 sense series of microcontrollers
    AHT10(20?) and/or BMP280 environmental sensors (Still doing some proto-typing)
    Rechargeable Lion battery
    5V Solar panel

The Apiary Monitor:
    Based on NEXTION 915 LoRa/WiFi/BLE Esp32 (https://www.amazon.com/gp/product/B07HJ49VN8)
    Rechargeable Lion Battery
    5V Solar Panel

Analytics Portal:
    Web Based analytics portal that collects information from the Apiary Monitor
    Grafana Based
    Designed to be run on RPi or lightweight linux lampstack


4/14/2023
Initial phases of discovery

Taking a crash course in Arduino BLE as well as other aspects (battery charging, data logging, Web Software dev)
Initial setup of the repo and structure.