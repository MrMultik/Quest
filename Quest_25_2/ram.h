#pragma once

void ram_write(int index, int value);   // записать значение в €чейку index (0..7)
int  ram_read(int index);               // прочитать значение из €чейки index