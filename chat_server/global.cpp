#include "global.h"

QString gate_url_prefix = "";

std::function<void(QWidget*)> repolish = [](QWidget* w){
    //更新样式
    w->style()->unpolish(w);
    w->style()->polish(w);
};
