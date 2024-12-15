#include "uiGui.h"
void next_frame_task_cb(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    switch (code)
    {
    case LV_EVENT_READY:
    {
        printf("----gif play finsh----\n");
 
        UiGui::GetInstance.Init();
        break;
    }
    default:
        break;
    }
}

static lv_obj_t *gif_anim = NULL;
void Lvgl_kaijiGif(void){
  
    LV_IMG_DECLARE(kaiji_gif);
    // lv_obj_t *img;
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), 0);
    gif_anim = lv_gif_create(lv_scr_act());

        /* add event to gif_anim */
    lv_obj_add_event_cb(gif_anim, next_frame_task_cb, LV_EVENT_ALL, NULL);

    lv_gif_set_src(gif_anim, &kaiji_gif);
    lv_obj_set_pos(gif_anim, 0, 0);
    vTaskDelay(pdMS_TO_TICKS(10));
    if (gif_anim == NULL) {
    // 处理错误，例如打印错误消息或退出程序
    printf( "gif_anim is NULL\n");
    
    }
    ((lv_gif_t *)gif_anim)->gif->loop_count = 1;
}

UiGui::UiGui()
{
    
    Lvgl_kaijiGif();

}
UiGui::~UiGui()
{

    
}


void UiGui::set_notificationLabel(char *str)
{

    lv_label_set_text(ui_notificationLabel, str);

}

void UiGui::set_netLabel(char *str)
{

    lv_label_set_text(ui_netLabel, str);

}

void UiGui::set_set_volLabel2(char *str)
{
    lv_label_set_text(ui_volLabel2, str);
}


void UiGui::set_AI_Content(char *str);
{
    lv_textarea_set_text(ui_AITextArea, str);
}

void UiGui::set_user_Content(char *str);
{
    lv_textarea_set_text(ui_userTextArea, str);
}

void UiGui::add_AI_Content(char *str);
{
    lv_textarea_add_text(ui_AITextArea, str);
}

void UiGui::add_user_Content(char *str);
{
    lv_textarea_add_text(ui_userTextArea, str);
}

void UiGui::set_chargeBarValue(uint8_t val);
{
    lv_bar_set_value(ui_changeBar, val, LV_ANIM_OFF)
}

void UiGui::goto_screen_QRcode();
{
    _ui_screen_change(&ui_QRcode, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_QRcode_screen_init);
}



void UiGui::goto_screen_menu();
{
    _ui_screen_change(&ui_menu, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_menu_screen_init);
}

void UiGui::goto_screen_main();
{
    _ui_screen_change(&ui_main, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_main_screen_init);
}

void UiGui::Init()
{

    ui_init();
    /*下面可对初始页面进行更改*/
    
}