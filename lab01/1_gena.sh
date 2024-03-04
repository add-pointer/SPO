#!/bin/bash
# Получаем хэш md5sum файла /etc/passwd и отбираем первые 6 символов
unique_id=$(md5sum /etc/passwd | cut -c 1-6)
echo "Уникальный идентификатор системы: $unique_id"