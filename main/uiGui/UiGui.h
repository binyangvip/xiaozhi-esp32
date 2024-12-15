#ifndef UI_GUI_H
#define UI_GUI_H
#include "ui.h"
#include "ui_helpers.h"
LV_FONT_DECLARE(ui_font_Font1);
#define ALL_WIFI_ICON ""
#define WIFI_ICON_H ""
#define WIFI_ICON_M ""
#define WIFI_ICON_L ""
#define WIFI_ICON_N ""
#define ALL_VOLUMN_ICON ""
#define VOLUMN_ICON_Y ""
#define VOLUMN_ICON_N ""


class UiGui {
private:


const char *wifiIcon[] = {WIFI_ICON_H,WIFI_ICON_M,WIFI_ICON_L,WIFI_ICON_N};
const char *volumnIcon[] = {VOLUMN_ICON_Y,VOLUMN_ICON_N};   

public:
    static UiGui& GetInstance() {
        static UiGui instance;
        return instance;
    }
    UiGui();//构造函数：直接播放开机动画
    virtual ~UiGui();
    
    enum WifiIcon {
    WifiHigh,
    WifiMid,
    WifiLow,
    WifiNull
};

    enum VolumnIcon {
        VolumnYes,
        VolumnNO,

    };

    void Init();
    void set_notificationLabel(char *str);//设置通知标签
    void set_netLabel(char *str);//设置网络标签，三种信号质量
    void set_volLabel2(char *str);//设置音量标签，1个静音，1个有音量
    void set_AI_Content(char *str);
    void set_user_Content(char *str);
    void add_AI_Content(char *str);
    void add_user_Content(char *str);
    void set_chargeBarValue(uint8_t val);
    void goto_screen_QRcode();
    void goto_screen_main();
    void goto_screen_menu();


};

#endif // UI_GUI_H
