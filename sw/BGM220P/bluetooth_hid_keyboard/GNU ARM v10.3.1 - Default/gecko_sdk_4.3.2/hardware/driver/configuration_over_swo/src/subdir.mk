################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2/hardware/driver/configuration_over_swo/src/sl_cos.c 

OBJS += \
./gecko_sdk_4.3.2/hardware/driver/configuration_over_swo/src/sl_cos.o 

C_DEPS += \
./gecko_sdk_4.3.2/hardware/driver/configuration_over_swo/src/sl_cos.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.3.2/hardware/driver/configuration_over_swo/src/sl_cos.o: C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2/hardware/driver/configuration_over_swo/src/sl_cos.c gecko_sdk_4.3.2/hardware/driver/configuration_over_swo/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DBGM220PC22HNA=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"B:\Repositories\ece-445l-final-project-ad_jm_mj_ew\sw\BGM220P\bluetooth_hid_keyboard\config" -I"B:\Repositories\ece-445l-final-project-ad_jm_mj_ew\sw\BGM220P\bluetooth_hid_keyboard\config\btconf" -I"B:\Repositories\ece-445l-final-project-ad_jm_mj_ew\sw\BGM220P\bluetooth_hid_keyboard" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//app/common/util/app_assert" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//app/common/util/app_log" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//protocol/bluetooth/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//protocol/bluetooth/bgstack/ll/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//hardware/board/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/button/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//hardware/driver/configuration_over_swo/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/sl_cryptoacc_library/include" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/sl_cryptoacc_library/src" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/debug/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/emdrv/dmadrv/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/emdrv/common/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/plugin/fem_util" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//app/bluetooth/common/gatt_service_device_information" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/iostream/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/sl_mbedtls_support/config" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/sl_mbedtls_support/config/preset" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/sl_mbedtls_support/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//util/third_party/mbedtls/include" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//util/third_party/mbedtls/library" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/mpu/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/emdrv/nvm3/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/power_manager/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/sl_psa_driver/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/common" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/protocol/ble" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/protocol/wmbus" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/protocol/sidewalk" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/plugin/rail_util_power_manager_init" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/se_manager/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/se_manager/src" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"C:/Users/plays/SimplicityStudio/SDKs/gecko_sdk_2//platform/security/sl_component/sl_protocol_crypto/src" -I"B:\Repositories\ece-445l-final-project-ad_jm_mj_ew\sw\BGM220P\bluetooth_hid_keyboard\autogen" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.2/hardware/driver/configuration_over_swo/src/sl_cos.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


