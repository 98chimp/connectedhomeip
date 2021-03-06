/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef __TRANSPORT_RENDEZVOUSPARAMETERS_H__
#define __TRANSPORT_RENDEZVOUSPARAMETERS_H__

#include <transport/Base.h>

#if CONFIG_NETWORK_LAYER_BLE
#include <ble/Ble.h>
#endif // CONFIG_NETWORK_LAYER_BLE

namespace chip {

class RendezvousParameters
{
public:
    explicit RendezvousParameters(uint32_t setupPINCode) : mSetupPINCode(setupPINCode) {}

    uint32_t GetSetupPINCode() const { return mSetupPINCode; };

    bool HasDiscriminator() const { return mDiscriminator != 0; };
    uint16_t GetDiscriminator() const { return mDiscriminator; };
    RendezvousParameters & SetDiscriminator(uint16_t discriminator)
    {
        mDiscriminator = discriminator;
        return *this;
    };

    bool HasLocalNodeId() const { return mLocalNodeId.HasValue(); };
    const Optional<NodeId> GetLocalNodeId() const { return mLocalNodeId; };
    RendezvousParameters & SetLocalNodeId(NodeId nodeId)
    {
        mLocalNodeId = Optional<NodeId>::Value(nodeId);
        return *this;
    };

#if CONFIG_NETWORK_LAYER_BLE
    bool HasBleLayer() const { return mBleLayer != nullptr; };
    Ble::BleLayer * GetBleLayer() const { return mBleLayer; };
    RendezvousParameters & SetBleLayer(Ble::BleLayer * value)
    {
        mBleLayer = value;
        return *this;
    }
#endif // CONFIG_NETWORK_LAYER_BLE

private:
    Optional<NodeId> mLocalNodeId; ///< the local node id
    uint32_t mSetupPINCode  = 0;   ///< the target peripheral setup PIN Code
    uint16_t mDiscriminator = 0;   ///< the target peripheral discriminator

#if CONFIG_NETWORK_LAYER_BLE
    Ble::BleLayer * mBleLayer = nullptr;
#endif // CONFIG_NETWORK_LAYER_BLE
};
} // namespace chip

#endif // __TRANSPORT_RENDEZVOUSPARAMETERS_H__
