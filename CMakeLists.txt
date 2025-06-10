# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Definir USERHOME
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

# Local do pico-vscode.cmake da extensão
set(sdkVersion 1.5.1)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)

if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# Board que você usa
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importar o SDK da Raspberry Pi Pico
include(pico_sdk_import.cmake)

project(sintetizador_audio_bitdoglab C CXX ASM)

# Inicializar o SDK
pico_sdk_init()

# Adicionar executável
add_executable(sintetizador
    sintetizador.c
    adc_audio.c
    pwm_audio.c
    utils.c
)

# Nome e versão do binário
pico_set_program_name(sintetizador "sintetizador_audio_bitdoglab")
pico_set_program_version(sintetizador "0.1")

# Habilitar stdio via USB
pico_enable_stdio_uart(sintetizador 0)
pico_enable_stdio_usb(sintetizador 1)

# Bibliotecas padrão
target_link_libraries(sintetizador
    pico_stdlib
    hardware_adc
    hardware_pwm
    hardware_gpio
    hardware_i2c
)

# Incluir headers da pasta include/
target_include_directories(sintetizador PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
)

# Output final
pico_add_extra_outputs(sintetizador)
