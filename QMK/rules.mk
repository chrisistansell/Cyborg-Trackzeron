# MCU name
MCU = at90usb1286

# Bootloader selection
BOOTLOADER = halfkay

# Build Options
BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
UNICODE_ENABLE = no         # Unicode
DIP_SWITCH_ENABLE = yes
COMMAND_ENABLE = no			# Enable or disable the command feature
CONSOLE_ENABLE = yes        # Enable or disable the console feature
NKRO_ENABLE = yes           # Enable or disable NKRO (N-Key Rollover) feature
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
MOUSEKEY_ENABLE = yes        # Mouse keys
QUANTUM_LIB_SRC += analog.c spi_master.c
