#!/bin/bash

TIME=60

TELEGRAM_BOT_TOKEN="6372930979:AAFLJeMWxSi0btJ1cEMp69YkVWy-jta33pg"
TELEGRAM_USER_ID="1651990942"

URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="Deploy status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
