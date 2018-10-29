/* mbed Microcontroller Library
 * Copyright (c) 2017 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "stm32h7xx_hal.h"

void _eth_config_mac(ETH_HandleTypeDef *heth)
{
    // TODO: Check the TBC fields if they are correct or not...
    ETH_MACConfigTypeDef macconf = {
        .SourceAddrControl = ETH_SOURCEADDRESS_DISABLE, // TBC
        .ChecksumOffload = ETH_CHECKSUMOFFLAOD_ENABLE,
        .InterPacketGapVal = ETH_INTERPACKETGAP_64BIT, // TBC
        .GiantPacketSizeLimitControl = 0, // TBC
        .Support2KPacket = 0, // TBC
        .CRCStripTypePacket = 0, // TBC
        .AutomaticPadCRCStrip = ETH_AUTOMATICPADCRCSTRIP_DISABLE,
        .Watchdog = ETH_WATCHDOG_ENABLE,
        .Jabber = ETH_JABBER_ENABLE,
        .JumboPacket = 0, // TBC
        .Speed = ETH_SPEED_100M, // TBC
        .DuplexMode = ETH_FULLDUPLEX_MODE, // TBC
        .LoopbackMode = ETH_LOOPBACKMODE_DISABLE,
        .CarrierSenseBeforeTransmit = , // TBC
        .ReceiveOwn = ETH_RECEIVEOWN_ENABLE,
        .CarrierSenseDuringTransmit = 0, // TBC
        .RetryTransmission = ETH_RETRYTRANSMISSION_DISABLE,
        .BackOffLimit = ETH_BACKOFFLIMIT_10,
        .DeferralCheck = ETH_DEFFERRALCHECK_DISABLE,
        .PreambleLength = ETH_PREAMBLELENGTH_5, // TBC
        .UnicastSlowProtocolPacketDetect = 0, // TBC
        .SlowProtocolDetect = 0, // TBC
        .CRCCheckingRxPackets = 0, // TBC
        .GiantPacketSizeLimit = 0x3FFF, // TBC
        .ExtendedInterPacketGap = 0, // TBC
        .ExtendedInterPacketGapVal = 0, // TBC
        .ProgrammableWatchdog = 0, // TBC
        .WatchdogTimeout = ETH_WATCHDOGTIMEOUT_8KB, // TBC
        .PauseTime = 0,
        .ZeroQuantaPause = ETH_ZEROQUANTAPAUSE_DISABLE,
        .PauseLowThreshold = ETH_PAUSELOWTHRESHOLD_MINUS4,
        .TransmitFlowControl = ETH_TRANSMITFLOWCONTROL_DISABLE,
        .UnicastPausePacketDetect = 0, // TBC
        .ReceiveFlowControl = ETH_RECEIVEFLOWCONTROL_DISABLE,
        .TransmitQueueMode = ETH_TRANSMITTHRESHOLD_128, // TBC
        .ReceiveQueueMode = ETH_RECEIVETHRESHOLD8_32, // TBC
        .DropTCPIPChecksumErrorPacket = 0, // TBC
        .ForwardRxErrorPacket = 0, // TBC
        .ForwardRxUndersizedGoodPacket = 0 // TBC
    };

    (void) HAL_ETH_SetMACConfig(heth, &macconf);
}
