# MQTT-DMD for ESP8266

![](https://github.com/byronin/MQTT-DMD/blob/main/Hardware/images/P10.png)
## Contents
- PCB [Hardware](https://github.com/byronin/MQTT-DMD/tree/main/Hardware "Hardware") files prepared for controlling the P10 Display.
- [Arduino library](https://github.com/byronin/MQTT-DMD/tree/main/Lib%26Software "Arduino library")  for using P10 Display with Mqtt.

## Sponsor
[![](https://github.com/byronin/MQTT-DMD/blob/main/Hardware/PCBWay_logo.png)](https://www.pcbway.com/)
#### Thanks to PCBWay for handling PCB production.

## Hardware & BOM
![PCBs](https://github.com/byronin/MQTT-DMD/blob/main/Hardware/images/Board1.png "PCBs")
 [![This PCB Desing with Eagle ](https://www.snapeda.com/static/img/eda/eagle.png "PCB Desing with Eagle ")](https://www.autodesk.com/products/eagle/free-download "This PCB Desing with Eagle ") 
  ##### This PCB Desing with Eagle  
  
  ## Schematic
[![](https://github.com/byronin/MQTT-DMD/blob/main/Hardware/Schematic.png)](https://github.com/byronin/MQTT-DMD/blob/main/Hardware)

  
| PCB Components  | Package |Piece || PCB Components  | Package |Piece |  
| ------------- | ------------- |------------- |---------| ------------- | ------------- |------------- |
| ESP8266 Wi-Fi Module  | 12E | 1 pcs  || LM1117-3v3 | SOT-223  | 1 pcs |
| SS14/SS36 Diode  | DO-214AC | 1 pcs || 3v3 Zener Diode  | SOD80C | 1 pcs |
| MAX485-RS485 | SOP 8  | 1 pcs  || 100uf Cap | PANASONIC_D   | 2 pcs |
| 100nf Cap mlcc | 0603  | 3 pcs || 10K Resistor  | 0603  | 8 pcs  |
| 1K Resistor | 0603  | 2 pcs || 120R Resistor  | 0603  | 2 pcs  |
| RED LED  | 0603  | 1 pcs || BLUE LED  | 0603  | 1 pcs  |
| Screw Terminal  | 3.5mm DIP  | 2 pcs  || Header 2x8 FML | 2.54-180  | 1 pcs  |
| Header 1x4 ML  | 2.54-90  | 1 pcs  || Header 1x2 ML  | 2.54-180  | 2 pcs  |
| JUMPER 1x2   | 2.54  | 2 pcs  |  

[You can look BOM.txt for details.](https://github.com/byronin/MQTT-DMD/blob/main/Hardware/BOM.txt "You can look BOM.txt")  

## Test 
[![](https://github.com/byronin/MQTT-DMD/blob/main/Hardware/images/Full_asmb.png)](https://github.com/byronin/MQTT-DMD/blob/main/Hardware/images)

#### Shopping List

| Product  | Link |
| ------------- | ------------- |
|P10 Display|[ Link](https://tr.aliexpress.com/item/1005003237909713.html?spm=a2g0o.productlist.0.0.37e759f1OWtOJo&algo_pvid=ac306e69-5e60-4847-98bb-0beb025dface&algo_exp_id=ac306e69-5e60-4847-98bb-0beb025dface-14&pdp_ext_f=%7B%22sku_id%22%3A%2212000024792668676%22%7D&pdp_npi=2%40dis%21TRY%21%21114.7%21%21%21209.95%21%21%402101d8b516565254069212787e109b%2112000024792668676%21sea " Link")|
| LM2596 |[Link](https://tr.aliexpress.com/item/33004374185.html?spm=a2g0o.productlist.0.0.584a4eb1nGv9CS&algo_pvid=40dddc8f-dfae-4d0d-81c2-a52a0aa0245e&algo_exp_id=40dddc8f-dfae-4d0d-81c2-a52a0aa0245e-0&pdp_ext_f=%7B%22sku_id%22%3A%2267088944738%22%7D&pdp_npi=2%40dis%21TRY%21%2113.03%21%21%2126.97%21%21%402101d8b516565255629607266e109b%2167088944738%21sea "Link")|
| Power Jack |[Link](https://tr.aliexpress.com/item/32990462283.html?spm=a2g0o.productlist.0.0.5e2518e2hOOmew&algo_pvid=7db638d6-f6c6-42c6-8043-efdd9c457ccb&algo_exp_id=7db638d6-f6c6-42c6-8043-efdd9c457ccb-17&pdp_ext_f=%7B%22sku_id%22%3A%2266856598002%22%7D&pdp_npi=2%40dis%21TRY%21%2131.28%21%21%21%21%21%402101d8b516565256348121673e109b%2166856598002%21sea "Link")  |
| 12V 3A Power Supply  | [Link](https://tr.aliexpress.com/item/32961533195.html?spm=a2g0o.productlist.0.0.2d7946ffUO6err&algo_pvid=a5d9bf34-bb2b-44ef-beb8-4b2c94ddd551&algo_exp_id=a5d9bf34-bb2b-44ef-beb8-4b2c94ddd551-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000021653748461%22%7D&pdp_npi=2%40dis%21TRY%21%2168.92%21%21%2168.22%21%21%402101d8b516565257067844445e109b%2112000021653748461%21sea "Link")  |


## Software & Library

- The project runs via the [Arduino IDE](https://www.arduino.cc/en/software "Arduino IDE"). If it is not installed, install it.
- Install [ESP8266](https://github.com/esp8266/Arduino "ESP8266") to Arduino.
- Install the [Pubsubclient Lib.](https://github.com/knolleary/pubsubclient "Pubsubclient Lib.") to Arduino.
- Install the [RoninDMD.zip](https://github.com/byronin/MQTT-DMD/blob/main/Lib%26Software/RoninDMD.zip "RoninDMD.zip") with library manager.
- You can connect with any MQTT client application. [MQTTool](https://apps.apple.com/us/app/mqttool/id1085976398 "MQTTool") application and [HiveMQ Public Broker](https://www.hivemq.com/public-mqtt-broker/ "HiveMQ Public Broker") were used in the testing phase of this project. Special thanks [@bjpetit](https://github.com/bjpetit "@bjpetit") .



