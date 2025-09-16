# ESP32 UDP-UART 透明网桥

这是一个基于 ESP-IDF 的项目，实现了在 ESP32 上 UART (串口) 与 UDP 网络之间的数据透明传输功能。它作为一个桥梁，可以无缝地将串口设备接入到局域网中。

## 主要功能

- **WiFi 连接**: 启动后自动连接到预设的 WiFi 网络。
- **双向数据流**:
    1.  **UDP -> UART**: 监听指定的本地 UDP 端口，并将接收到的所有数据包通过 UART 转发出去。
    2.  **UART -> UDP**: 读取所有来自 UART 的数据，并将其通过 UDP 发送到指定的目标 IP 地址和端口。
- **低延迟**: 禁用了 WiFi 省电模式以降低网络延迟。
- **多核运行**: 将 UART->UDP 和 UDP->UART 的任务分别固定在不同的 CPU 核心上运行，以提高处理性能和稳定性。

## 配置

所有主要的配置项都在 `main/config.h` 文件中定义。在烧写固件前，请根据您的网络环境和硬件连接修改这些宏定义。

### `main/config.h`
| 宏 | 描述 | 默认值 |
|---|---|---|
| `WIFI_SSID` | 您的 WiFi 网络名称 (SSID) | `"TP-LINK_46DC"` |
| `WIFI_PASSWORD` | 您的 WiFi 密码 | `"itrlab125"` |
| `UDP_TARGET_IP` | 接收 UART 数据的目标设备 IP 地址 | `"10.1.1.100"` |
| `UDP_TARGET_PORT` | 接收 UART 数据的目标设备端口 | `14554` |
| `UDP_LOCAL_PORT` | ESP32 用于监听 UDP 数据的本地端口 | `14550` |
| `UART_NUM` | 使用的 UART 接口编号 | `UART_NUM_1` |
| `UART_BAUD_RATE` | UART 通信波特率 | `921600` |
| `UART_TX_PIN` | UART 发送引脚 (TX) | `3` |
| `UART_RX_PIN` | UART 接收引脚 (RX) | `2` |
| `TASK_STACK_SIZE` | FreeRTOS 任务堆栈大小 | `4096` |

### 项目配置

其他更底层的项目配置（例如目标 ESP32 型号等）可以通过 ESP-IDF 的配置菜单进行修改：
```bash
idf.py menuconfig
```
如:
针对ESP32S3 可以提高其默认CPU 频率:
Component -> ESP System Settings -> CPU Frequency : 240 MHZ

## 编译

在开始编译之前，请确保您已经正确安装并配置了[ESP-IDF] (https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/get-started/linux-macos-setup.html)  开发环境。

1.  **设置 ESP-IDF 环境**:
    ```bash
    . $IDF_PATH/export.sh
    ```
2.  **编译项目**:
    ```bash
    idf.py build
    ```

## 烧写

将 ESP32 开发板通过 USB 连接到您的电脑，并确定其串口设备名（例如 `/dev/ttyUSB0` 或 `COM3`）。

```bash
idf.py -p /dev/ttyUSB0 flash
```
**注意**: 请将 `/dev/ttyUSB0` 替换为您 ESP32 开发板实际的串口设备名。

## 监视串口输出

您可以使用 `idf.py` 来监视设备的串口输出，查看日志信息和程序运行状态。

```bash
idf.py -p /dev/ttyUSB0 monitor
```
