#!/bin/bash

nuskalo_url="https://www.njuskalo.hr/"

page_content=$(curl -s "$nuskalo_url")

echo "$page_content" | grep -Po '<img[^>]+class="itemImage"[^>]+alt="\K[^"]+' | awk '!x[$0]++'
