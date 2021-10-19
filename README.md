# WiFi Cert Middleware for ModusToolbox SDK

## Overview

The WiFi Cert middleware provides an easy way to test WFA cert such as 802.11n-PSK, WPA2 Enterprise security, PMF, WPA3 and 802.11AC using ModusToolbox SDK.

The WiFi Cert middleware consists of the following components:

- Sigma Control API specification (CAPI) commands and command handler functions to process commands to and from a test agent.

- WiFi Cert middleware Porting Layer to interface  with Wi-Fi and network layer functionality across SDKs such as FreeRTOS.

## Features

This library provides the library functions used by the WiFi Cert Tester tool to execute WFA Certification test suites for 802.11n PSK, Enterprise security, PMF, WPA3, and 802.11AC.

## Requirements

- [ModusToolbox® software](https://www.cypress.com/products/modustoolbox-software-environment) v2.4

- Programming Language: C

## Supported Platforms

This library and its features are supported on the following Cypress platforms:

- [PSoC&trade; 6 Wi-Fi Bluetooth&reg; prototyping kit](https://www.cypress.com/CY8CPROTO-062-4343W) (CY8CPROTO-062-4343W)

- [PSoC&trade; 62S2 Wi-Fi Bluetooth&reg; pioneer kit](https://www.cypress.com/CY8CKIT-062S2-43012)  (CY8CKIT-062S2-43012)

- [PSoC&trade; PSoC6 Development Kit](https://www.cypress.com/part/cy8ceval-062s2)(CY8CEVAL-062S2) + [Sterling LWB5Plus](https://www.mouser.com/new/laird-connectivity/laird-connectivity-sterling-lwb5plus) (CY8CEVAL-062S2-LAI-4373M2)

## Integration Notes

- The WiFi Cert Test Middleware library has been designed to work with ModusToolbox SDK.

* The library has been integrated into WiFi Cert Tester tool for ModusToolbox SDK.

* You only need to include this library in the required ecosystem to use these utilities. Depending on the ecosystem, the respective source files will be picked up and linked, using the `COMPONENT_ model_`.


## Supported Software and Tools
ToolChain | OS
----------|---
GCC_ARM  IAR and ARMC6 | FreeRTOS
------
