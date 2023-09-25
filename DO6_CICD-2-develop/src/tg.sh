#!/bin/bash

# TELEGRAM_BOT_TOKEN = "6219873459:AAFLbcp9gR6PB1B4VT7n3SW4vkxK23F2U2A"
# TELEGRAM_USER_ID = "-905954807"

URL="https://api.telegram.org/bot6219873459:AAFLbcp9gR6PB1B4VT7n3SW4vkxK23F2U2A/sendMessage"
TEXT="$1 $CI_JOB_STATUS"

curl -s -d  "chat_id=-905954807&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
