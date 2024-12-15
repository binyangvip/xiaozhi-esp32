SET(SOURCES screens/ui_main.c
    screens/ui_QRcode.c
    screens/ui_menu.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_download_png.c
    images/ui_img_logo1_png.c
    fonts/ui_font_iconFont.c)

add_library(ui ${SOURCES})
